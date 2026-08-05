/*
Problem:
3310. Remove Methods From Project

Platform:
LeetCode

Link:
https://leetcode.com/problems/remove-methods-from-project/

Difficulty:
Medium

Approach:
1. Represent the method invocations as a directed graph using an adjacency list.
   An edge u -> v means method `u` invokes method `v`.

2. Start a BFS from the suspicious method `k`.
   - Mark `k` as suspicious.
   - Every method directly or indirectly invoked by a suspicious method
     is also marked suspicious.

3. After BFS, divide the methods into:
   - Suspicious methods (`vis1[i] == true`)
   - Remaining/non-suspicious methods (`vis1[i] == false`)

4. According to the problem, suspicious methods can only be removed if no
   non-suspicious method invokes a suspicious method.

5. Traverse all non-suspicious methods and check their outgoing edges.
   - If any edge points to a suspicious method, the suspicious group cannot
     be removed.
   - In this case, return all methods.

6. Otherwise, return only the non-suspicious methods.

Time Complexity:
O(n + E)

where:
n = number of methods
E = number of invocations

Space Complexity:
O(n + E)

Tags:
Graph, BFS, Reachability
*/

class Solution {
public:

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {

        unordered_map<int, vector<int>> m;

        for (int i = 0; i < invocations.size(); i++) {
            m[invocations[i][0]].push_back(invocations[i][1]);
        }

        queue<int> q1;

        vector<int> vis1(n, false);

        vis1[k] = true;
        q1.push(k);

        // Find all suspicious methods using BFS
        while (!q1.empty()) {

            int temp = q1.front();
            q1.pop();

            for (auto i : m[temp]) {

                if (vis1[i] == false) {
                    vis1[i] = true;
                    q1.push(i);
                }
            }
        }

        vector<int> ans1;
        vector<int> ans2;

        // Store all methods and push non-suspicious methods
        // into the queue for validation
        for (int i = 0; i < n; i++) {

            ans2.push_back(i);

            if (!vis1[i]) {
                q1.push(i);
                ans1.push_back(i);
            }
        }

        bool a = true;

        // Check whether any non-suspicious method
        // invokes a suspicious method
        while (!q1.empty()) {

            int temp = q1.front();
            q1.pop();

            for (auto i : m[temp]) {

                if (vis1[i] == true) {
                    a = false;
                    break;
                }
            }
        }

        // Suspicious methods can be removed
        if (a) {
            return ans1;
        }

        // Suspicious methods cannot be removed
        return ans2;
    }
};
