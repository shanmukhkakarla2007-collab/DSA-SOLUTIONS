
/*

Problem:210. Course Schedule II
Platform:LeetCode
Link:https://leetcode.com/problems/course-schedule-ii/
Difficulty:Medium

Approach:
1. Construct a directed graph using an adjacency list where an edge
   u -> v indicates that course u must be taken before course v.
2. Perform DFS on every unvisited node.
3. Maintain two visited arrays:
   - vis[]: marks nodes that have been visited.
   - dfsvis[]: marks nodes currently in the recursion stack.
4. If a node is encountered that is already present in the recursion
   stack, a cycle exists, so return an empty vector.
5. After visiting all adjacent nodes, push the current node onto a stack.
6. Pop all elements from the stack to obtain the topological ordering.

Time Complexity:
O(V + E)

Space Complexity:
O(V + E)

Tags:
Graph, DFS, Topological Sort
*/

class Solution {
public:

    bool f(int node,unordered_map<int, vector<int>>& m,vector<bool>& vis,vector<bool>& dfsvis,stack<int>& s) {

        vis[node] = true;
        dfsvis[node] = true;

        for (auto i : m[node]) {

            if (!vis[i]) {

                if (f(i, m, vis, dfsvis, s))
                    return true;

            }
            else if (dfsvis[i]) {
                return true;
            }
        }

        s.push(node);
        dfsvis[node] = false;

        return false;
    }

    vector<int> findOrder(int numCourses,
                          vector<vector<int>>& prerequisites) {

        unordered_map<int, vector<int>> m;

        for (auto &edge : prerequisites) {
            m[edge[1]].push_back(edge[0]);
        }

        vector<bool> vis(numCourses, false);
        vector<bool> dfsvis(numCourses, false);

        stack<int> s;

        for (int i = 0; i < numCourses; i++) {

            if (!vis[i]) {

                if (f(i, m, vis, dfsvis, s))
                    return {};
            }
        }

        vector<int> ans;

        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }

        return ans;
    }
};