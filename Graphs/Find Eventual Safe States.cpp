/*
Problem:802. Find Eventual Safe States

Platform:LeetCode

Link:https://leetcode.com/problems/find-eventual-safe-states/

Difficulty:Medium

Approach:
1. Represent the graph using an adjacency list.
2. Perform DFS traversal for every unvisited node.
3. Maintain:
   - vis[]: marks nodes that have been visited.
   - dfsvis[]: marks nodes currently in the recursion stack.
   - k[]: stores whether a node is safe.
4. If a cycle is detected during DFS, mark the current node as unsafe.
5. A node is considered safe only if all of its adjacent nodes are safe.
6. Collect all nodes marked as safe.

Time Complexity:
O(V + E)

Space Complexity:
O(V + E)

Tags:Graph, DFS, Cycle Detection
*/

class Solution {
public:

    bool f(int node,
           unordered_map<int, vector<int>>& m,
           vector<bool>& vis,
           vector<bool>& dfsvis,
           vector<bool>& k) {

        vis[node] = true;
        dfsvis[node] = true;

        for (auto i : m[node]) {

            if (!vis[i]) {

                bool a = f(i, m, vis, dfsvis, k);

                if (!a) {
                    k[node] = false;
                    return false;
                }
            }
            else if (dfsvis[i]) {

                k[node] = false;
                return false;
            }
        }

        dfsvis[node] = false;
        k[node] = true;

        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        unordered_map<int, vector<int>> m;

        for (int i = 0; i < graph.size(); i++) {
            for (int j = 0; j < graph[i].size(); j++) {
                m[i].push_back(graph[i][j]);
            }
        }

        int n = graph.size();

        vector<bool> vis(n, false);
        vector<bool> dfsvis(n, false);
        vector<bool> k(n);

        for (int i = 0; i < n; i++) {

            if (!vis[i]) {
                f(i, m, vis, dfsvis, k);
            }
        }

        vector<int> ans;

        for (int i = 0; i < n; i++) {

            if (k[i])
                ans.push_back(i);
        }

        return ans;
    }
};