/*
Problem:
486. Predict the Winner

Platform:
LeetCode

Link:
https://leetcode.com/problems/predict-the-winner/

Difficulty:
Medium

Approach:
1. Use recursion with memoization to simulate the game between the two players.
2. Maintain two pointers `i` and `j` representing the remaining range of elements.
3. Use `choice` to determine whose turn it is:
   - If `choice` is true, Player 1 chooses either the leftmost or rightmost
     element and tries to maximize their total score.
   - If `choice` is false, Player 2 chooses either end and tries to minimize
     the final score obtainable by Player 1.
4. Use two DP tables:
   - `dp1[i][j]` stores the maximum score Player 1 can obtain from the range
     `[i, j]` when it is Player 1's turn.
   - `dp2[i][j]` stores the minimum score Player 1 can end up with from the
     range `[i, j]` when it is Player 2's turn.
5. Calculate the total sum of all elements.
6. Let `val1` be Player 1's optimal score.
7. Player 1 wins or ties if:
      val1 >= total - val1

Time Complexity:
O(n²)

Space Complexity:
O(n²)
- Two memoization tables are used.
- Recursive call stack can take O(n) additional space.

Tags:
Dynamic Programming, Recursion, Memoization, Game Theory, Minimax
*/

class Solution {
public:

    int f(int i, int j, vector<int>& nums, bool choice,
          vector<vector<int>>& dp1, vector<vector<int>>& dp2) {

        if (i > j) {
            return 0;
        }

        // Player 1's turn - maximize Player 1's score
        if (choice) {

            if (dp1[i][j] != -1) {
                return dp1[i][j];
            }

            int a = nums[i] + f(i + 1, j, nums, !choice, dp1, dp2);
            int b = nums[j] + f(i, j - 1, nums, !choice, dp1, dp2);

            return dp1[i][j] = max(a, b);
        }

        // Player 2's turn - minimize Player 1's final score
        if (dp2[i][j] != -1) {
            return dp2[i][j];
        }

        int a = f(i + 1, j, nums, !choice, dp1, dp2);
        int b = f(i, j - 1, nums, !choice, dp1, dp2);

        return dp2[i][j] = min(a, b);
    }

    bool predictTheWinner(vector<int>& nums) {

        int total = 0;

        for (int i = 0; i < nums.size(); i++) {
            total += nums[i];
        }

        vector<vector<int>> dp1(
            nums.size(),
            vector<int>(nums.size(), -1)
        );

        vector<vector<int>> dp2(
            nums.size(),
            vector<int>(nums.size(), -1)
        );

        int val1 = f(
            0,
            nums.size() - 1,
            nums,
            true,
            dp1,
            dp2
        );

        if (total - val1 <= val1) {
            return true;
        }

        return false;
    }
};
