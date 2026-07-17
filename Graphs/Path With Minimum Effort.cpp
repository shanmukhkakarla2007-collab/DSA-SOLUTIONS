
/*
Problem:1631. Path With Minimum Effort

Platform:LeetCode

Link:https://leetcode.com/problems/path-with-minimum-effort/

Difficulty:Medium

Approach:
1. Treat each cell as a node in a graph.
2. Use Dijkstra's Algorithm where the cost of a path is the maximum
   absolute height difference encountered along that path.
3. Maintain a distance matrix where dist[i][j] stores the minimum effort
   required to reach cell (i, j).
4. For every adjacent cell, calculate:
      effort = max(currentEffort, abs(heightDifference))
5. If the new effort is smaller than the recorded effort, update the
   distance and insert the cell into the set.
6. Continue until all reachable cells are processed.
7. The answer is the minimum effort required to reach the bottom-right cell.

Time Complexity:
O((M × N) log(M × N))

Space Complexity:
O(M × N)

Tags:
Graph, Dijkstra, Shortest Path, Matrix
*/

class Solution {
public:

    int minimumEffortPath(vector<vector<int>>& heights) {

        set<pair<int, pair<int, int>>> s;

        s.insert({0, {0, 0}});

        vector<vector<int>> dis(
            heights.size(),
            vector<int>(heights[0].size(), INT_MAX)
        );

        dis[0][0] = 0;

        while (!s.empty()) {

            auto temp = *s.begin();
            s.erase(s.begin());

            int nodeDis = temp.first;
            int i = temp.second.first;
            int j = temp.second.second;

            // Up
            if (i - 1 >= 0) {

                int effort = max(nodeDis,
                                 abs(heights[i][j] - heights[i - 1][j]));

                if (effort < dis[i - 1][j]) {

                    s.erase({dis[i - 1][j], {i - 1, j}});

                    dis[i - 1][j] = effort;

                    s.insert({effort, {i - 1, j}});
                }
            }

            // Down
            if (i + 1 < heights.size()) {

                int effort = max(nodeDis,
                                 abs(heights[i][j] - heights[i + 1][j]));

                if (effort < dis[i + 1][j]) {

                    s.erase({dis[i + 1][j], {i + 1, j}});

                    dis[i + 1][j] = effort;

                    s.insert({effort, {i + 1, j}});
                }
            }

            // Left
            if (j - 1 >= 0) {

                int effort = max(nodeDis,
                                 abs(heights[i][j] - heights[i][j - 1]));

                if (effort < dis[i][j - 1]) {

                    s.erase({dis[i][j - 1], {i, j - 1}});

                    dis[i][j - 1] = effort;

                    s.insert({effort, {i, j - 1}});
                }
            }

            // Right
            if (j + 1 < heights[0].size()) {

                int effort = max(nodeDis,
                                 abs(heights[i][j] - heights[i][j + 1]));

                if (effort < dis[i][j + 1]) {

                    s.erase({dis[i][j + 1], {i, j + 1}});

                    dis[i][j + 1] = effort;

                    s.insert({effort, {i, j + 1}});
                }
            }
        }

        return dis[heights.size() - 1][heights[0].size() - 1];
    }
};