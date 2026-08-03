/*
Problem:
1406. Stone Game III

Platform:
LeetCode

Link:
https://leetcode.com/problems/stone-game-iii/

Difficulty:
Hard

Approach:
1. Use recursion with memoization to simulate the optimal moves of Alice and Bob.
2. Alice can pick 1, 2, or 3 stones and aims to maximize her total score.
3. Bob also picks 1, 2, or 3 stones but plays optimally to minimize Alice's
   final score.
4. Maintain two DP arrays:
   - `dp1[i]` stores the maximum score Alice can obtain starting from index `i`
     on her turn.
   - `dp2[i]` stores the minimum score Alice can end up with starting from
     index `i` on Bob's turn.
5. Compute the total sum of all stone values.
6. Let `aliceScore` be the optimal score obtained by Alice.
7. Compare Alice's score with Bob's score (`total - aliceScore`) to determine
   the winner.

Time Complexity:
O(n)

Space Complexity:
O(n)

Tags:
Dynamic Programming, Recursion, Memoization, Game Theory, Minimax
*/

class Solution {
public:

    int f(int i, vector<int>& value, bool Alice,
          vector<int>& dp1, vector<int>& dp2) {

        if (i >= value.size()) {
            return 0;
        }

        // Alice's turn
        if (Alice) {

            if (dp1[i] != -1) {
                return dp1[i];
            }

            int a = value[i] + f(i + 1, value, !Alice, dp1, dp2);

            if (i + 1 < value.size()) {
                a = max(a,
                        value[i] + value[i + 1] +
                        f(i + 2, value, !Alice, dp1, dp2));
            }

            if (i + 2 < value.size()) {
                a = max(a,
                        value[i] + value[i + 1] + value[i + 2] +
                        f(i + 3, value, !Alice, dp1, dp2));
            }

            return dp1[i] = a;
        }

        // Bob's turn
        if (dp2[i] != -1) {
            return dp2[i];
        }

        int a = f(i + 1, value, !Alice, dp1, dp2);

        if (i + 1 < value.size()) {
            a = min(a, f(i + 2, value, !Alice, dp1, dp2));
        }

        if (i + 2 < value.size()) {
            a = min(a, f(i + 3, value, !Alice, dp1, dp2));
        }

        return dp2[i] = a;
    }

    string stoneGameIII(vector<int>& stoneValue) {

        int total = 0;

        for (int x : stoneValue) {
            total += x;
        }

        vector<int> dp1(stoneValue.size(), -1);
        vector<int> dp2(stoneValue.size(), -1);

        int aliceScore = f(0, stoneValue, true, dp1, dp2);

        return (total - aliceScore > aliceScore)
                   ? "Bob"
                   : (total - aliceScore < aliceScore)
                         ? "Alice"
                         : "Tie";
    }
};