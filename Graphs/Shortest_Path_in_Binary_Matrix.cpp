/*
Problem:1091. Shortest Path in Binary Matrix

Platform:LeetCode

Link:https://leetcode.com/problems/shortest-path-in-binary-matrix/

Difficulty:Medium

Approach:
1. If the starting cell is blocked, return -1.
2. Perform Breadth-First Search (BFS) from the top-left cell.
3. Traverse all 8 possible directions (horizontal, vertical, and diagonal).
4. Use a visited matrix to avoid revisiting cells.
5. Process nodes level by level using a queue and a level marker.
6. The first time the bottom-right cell is reached, return the current path length.
7. If the destination cannot be reached, return -1.

Time Complexity:
O(N²)

Space Complexity:
O(N²)

Tags:
Graph, BFS, Matrix, Shortest Path
*/

class Solution {
public:

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        if (grid[0][0] == 1)
            return -1;

        queue<pair<int, int>> q;

        q.push({0, 0});
        q.push({-1, -1});

        vector<vector<bool>> vis(
            grid.size(),
            vector<bool>(grid[0].size(), false)
        );

        vis[0][0] = true;

        int level = 0;

        while (!q.empty()) {

            pair<int, int> temp = q.front();
            q.pop();

            if (temp.first == -1) {

                if (!q.empty()) {
                    q.push({-1, -1});
                    level++;
                }

            }
            else if (temp.first == grid.size() - 1 &&
                     temp.second == grid[0].size() - 1) {

                return level + 1;
            }
            else {

                int a = temp.first;
                int b = temp.second;

                // Up
                if (a - 1 >= 0 && !vis[a - 1][b] && grid[a - 1][b] == 0) {
                    q.push({a - 1, b});
                    vis[a - 1][b] = true;
                }

                // Down
                if (a + 1 < grid.size() && !vis[a + 1][b] && grid[a + 1][b] == 0) {
                    q.push({a + 1, b});
                    vis[a + 1][b] = true;
                }

                // Left
                if (b - 1 >= 0 && !vis[a][b - 1] && grid[a][b - 1] == 0) {
                    q.push({a, b - 1});
                    vis[a][b - 1] = true;
                }

                // Right
                if (b + 1 < grid[0].size() && !vis[a][b + 1] && grid[a][b + 1] == 0) {
                    q.push({a, b + 1});
                    vis[a][b + 1] = true;
                }

                // Top Left
                if (a - 1 >= 0 && b - 1 >= 0 &&
                    !vis[a - 1][b - 1] &&
                    grid[a - 1][b - 1] == 0) {

                    q.push({a - 1, b - 1});
                    vis[a - 1][b - 1] = true;
                }

                // Top Right
                if (a - 1 >= 0 && b + 1 < grid[0].size() &&
                    !vis[a - 1][b + 1] &&
                    grid[a - 1][b + 1] == 0) {

                    q.push({a - 1, b + 1});
                    vis[a - 1][b + 1] = true;
                }

                // Bottom Left
                if (a + 1 < grid.size() && b - 1 >= 0 &&
                    !vis[a + 1][b - 1] &&
                    grid[a + 1][b - 1] == 0) {

                    q.push({a + 1, b - 1});
                    vis[a + 1][b - 1] = true;
                }

                // Bottom Right
                if (a + 1 < grid.size() &&
                    b + 1 < grid[0].size() &&
                    !vis[a + 1][b + 1] &&
                    grid[a + 1][b + 1] == 0) {

                    q.push({a + 1, b + 1});
                    vis[a + 1][b + 1] = true;
                }
            }
        }

        return -1;
    }
};
