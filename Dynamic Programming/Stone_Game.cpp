/*
Problem:
877. Stone Game

Platform:
LeetCode

Link:
https://leetcode.com/problems/stone-game/

Difficulty:
Medium

Approach:
1. Use recursion with memoization to simulate the game between Alice and Bob.
2. At every turn, a player can choose a pile either from the left end or
   the right end.
3. When it is Alice's turn:
   - Add the selected pile to Alice's score.
   - Choose the move that maximizes Alice's final score.
4. When it is Bob's turn:
   - Bob chooses the move that minimizes Alice's final score.
5. Use two DP tables:
   - `dp1[i][j]` stores the maximum score Alice can obtain from range
     [i, j] when it is Alice's turn.
   - `dp2[i][j]` stores the minimum score Alice can end up with from range
     [i, j] when it is Bob's turn.
6. Calculate the total sum of all piles.
7. Compare Alice's optimal score with Bob's score (`total - aliceScore`).
8. Return true if Alice's score is greater than Bob's score.

Time Complexity:
O(n^2)

Space Complexity:
O(n^2)
- Two DP tables are used.
- The recursion stack requires additional O(n) space.

Tags:
Dynamic Programming, Recursion, Memoization, Game Theory, Minimax
*/

class Solution {
public:

    int f(int i, int j, vector<int>& piles, bool alice,
          vector<vector<int>>& dp1, vector<vector<int>>& dp2) {

        if (i > j) {
            return 0;
        }

        // Alice's turn - maximize Alice's score
        if (alice) {

            if (dp1[i][j] != -1) {
                return dp1[i][j];
            }

            int a = piles[i] +
                    f(i + 1, j, piles, !alice, dp1, dp2);

            int b = piles[j] +
                    f(i, j - 1, piles, !alice, dp1, dp2);

            return dp1[i][j] = max(a, b);
        }

        // Bob's turn - minimize Alice's score
        if (dp2[i][j] != -1) {
            return dp2[i][j];
        }

        int a = f(i + 1, j, piles, !alice, dp1, dp2);
        int b = f(i, j - 1, piles, !alice, dp1, dp2);

        return dp2[i][j] = min(a, b);
    }

    bool stoneGame(vector<int>& piles) {

        int total = 0;

        for (int i = 0; i < piles.size(); i++) {
            total += piles[i];
        }

        vector<vector<int>> dp1(
            piles.size(),
            vector<int>(piles.size(), -1)
        );

        vector<vector<int>> dp2(
            piles.size(),
            vector<int>(piles.size(), -1)
        );

        int aliceScore = f(
            0,
            piles.size() - 1,
            piles,
            true,
            dp1,
            dp2
        );

        if (aliceScore > total - aliceScore) {
            return true;
        }

        return false;
    }
};
