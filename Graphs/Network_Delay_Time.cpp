/*
Problem:Network Delay Time

Platform:LeetCode 743

Difficulty:Medium

Approach:
1. Build the graph using an adjacency list where each node stores
   its neighbouring nodes along with edge weights.
2. Initialize a distance array with INT_MAX for all nodes.
3. Set the source node's distance to 0.
4. Use a set to always pick the node having the minimum distance.
5. For each neighbour of the current node:
   - If a shorter path is found, update its distance.
   - Remove the old distance from the set (if present).
   - Insert the updated distance into the set.
6. After Dijkstra's Algorithm finishes:
   - If any node is still unreachable, return -1.
   - Otherwise, return the maximum distance among all nodes.

Time Complexity:
O((V + E) log V)

Space Complexity:
O(V + E)

Tags:
Graph, Dijkstra, Shortest Path, Set, Adjacency List
*/

class Solution {
public:

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        // Build adjacency list
        unordered_map<int, vector<pair<int, int>>> adj;

        for (int i = 0; i < times.size(); i++) {
            adj[times[i][0]].push_back({times[i][1], times[i][2]});
        }

        // Distance array
        vector<int> dist(n + 1, INT_MAX);

        // {distance, node}
        set<pair<int, int>> st;

        dist[k] = 0;
        st.insert({0, k});

        // Dijkstra's Algorithm
        while (!st.empty()) {

            auto curr = *st.begin();
            st.erase(st.begin());

            int nodeDist = curr.first;
            int node = curr.second;

            for (auto neighbour : adj[node]) {

                int nextNode = neighbour.first;
                int edgeWeight = neighbour.second;

                if (nodeDist + edgeWeight < dist[nextNode]) {

                    if (st.find({dist[nextNode], nextNode}) != st.end()) {
                        st.erase({dist[nextNode], nextNode});
                    }

                    dist[nextNode] = nodeDist + edgeWeight;
                    st.insert({dist[nextNode], nextNode});
                }
            }
        }

        // Find the maximum shortest distance
        int ans = INT_MIN;

        for (int i = 1; i <= n; i++) {

            if (dist[i] == INT_MAX) {
                return -1;
            }

            ans = max(ans, dist[i]);
        }

        return ans;
    }
};
