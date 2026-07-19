/*
Problem:Check if a Knight Can Reach a Target in Even Number of Moves

Platform:LeetCode

Difficulty:Medium

Approach:
1. Start a DFS from the given starting position.
2. Mark each visited cell to avoid revisiting the same position.
3. Explore all 8 possible knight moves recursively.
4. If the target cell is reached:
   - Return true if the number of moves (level) is even.
   - Otherwise return false.
5. If none of the paths satisfy the condition, return false.

Time Complexity:
O(64)
(Since the chessboard has only 8 × 8 = 64 cells.)

Space Complexity:
O(64)
(Visited array + recursion stack.)

Tags:
Graph, DFS, Backtracking, Recursion, Chessboard
*/

class Solution {
public:

    bool f(int i, int j, int ei, int ej,
           vector<vector<bool>>& vis, int level) {

        vis[i][j] = true;

        // Reached destination
        if (i == ei && j == ej) {
            return (level % 2 == 0);
        }

        // All 8 possible knight moves

        if (i - 1 >= 0 && j - 2 >= 0 && !vis[i - 1][j - 2]) {
            if (f(i - 1, j - 2, ei, ej, vis, level + 1))
                return true;
        }

        if (i - 2 >= 0 && j - 1 >= 0 && !vis[i - 2][j - 1]) {
            if (f(i - 2, j - 1, ei, ej, vis, level + 1))
                return true;
        }

        if (i - 2 >= 0 && j + 1 < 8 && !vis[i - 2][j + 1]) {
            if (f(i - 2, j + 1, ei, ej, vis, level + 1))
                return true;
        }

        if (i - 1 >= 0 && j + 2 < 8 && !vis[i - 1][j + 2]) {
            if (f(i - 1, j + 2, ei, ej, vis, level + 1))
                return true;
        }

        if (i + 1 < 8 && j + 2 < 8 && !vis[i + 1][j + 2]) {
            if (f(i + 1, j + 2, ei, ej, vis, level + 1))
                return true;
        }

        if (i + 2 < 8 && j + 1 < 8 && !vis[i + 2][j + 1]) {
            if (f(i + 2, j + 1, ei, ej, vis, level + 1))
                return true;
        }

        if (i + 2 < 8 && j - 1 >= 0 && !vis[i + 2][j - 1]) {
            if (f(i + 2, j - 1, ei, ej, vis, level + 1))
                return true;
        }

        if (i + 1 < 8 && j - 2 >= 0 && !vis[i + 1][j - 2]) {
            if (f(i + 1, j - 2, ei, ej, vis, level + 1))
                return true;
        }

        return false;
    }

    bool canReach(vector<int>& start, vector<int>& target) {

        vector<vector<bool>> vis(8, vector<bool>(8, false));

        return f(start[0], start[1], target[0], target[1], vis, 0);
    }
};
