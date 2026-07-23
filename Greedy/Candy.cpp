/*
Problem:135. Candy

Platform:LeetCode

Link:https://leetcode.com/problems/candy/

Difficulty:Hard

Approach:
1. Initialize a candy array where every child starts with one candy.
2. Perform a left-to-right traversal to satisfy the condition that a child
   with a higher rating than the left neighbor receives more candies.
3. Perform a right-to-left traversal to satisfy the condition that a child
   with a higher rating than the right neighbor receives more candies.
4. During the second traversal, update the candy count only if a larger value
   is required, ensuring both left and right neighbor constraints are met.
5. Sum all the candies assigned to obtain the minimum number of candies
   required.

Time Complexity:
O(n)

Space Complexity:
O(n)

Tags:
Greedy, Array, Two Pass
*/

class Solution {
public:

    int candy(vector<int>& ratings) {

        vector<int> v(ratings.size(), 1);

        // Left to Right Traversal
        for (int i = 0; i < ratings.size(); i++) {

            if (i == 0) {

                if (i + 1 < ratings.size() && ratings[i + 1] < ratings[i]) {
                    v[i] = v[i + 1] + 1;
                }

            } else if (i == v.size() - 1) {

                if (ratings[i - 1] < ratings[i]) {
                    v[i] = v[i - 1] + 1;
                }

            } else if ((ratings[i - 1] < ratings[i]) ||
                       (ratings[i + 1] < ratings[i])) {

                if ((ratings[i - 1] < ratings[i]) &&
                    (ratings[i + 1] < ratings[i])) {

                    v[i] = 1 + max(v[i - 1], v[i + 1]);

                } else if ((ratings[i - 1] < ratings[i]) &&
                           (ratings[i + 1] >= ratings[i])) {

                    v[i] = 1 + v[i - 1];

                } else if ((ratings[i - 1] >= ratings[i]) &&
                           (ratings[i + 1] < ratings[i])) {

                    v[i] = 1 + v[i + 1];
                }
            }
        }

        // Right to Left Traversal
        for (int i = ratings.size() - 1; i >= 0; i--) {

            if (i == 0) {

                if (i + 1 < ratings.size() && ratings[i + 1] < ratings[i]) {
                    v[i] = v[i + 1] + 1;
                }

            } else if (i == v.size() - 1) {

                if (ratings[i - 1] < ratings[i]) {
                    v[i] = v[i - 1] + 1;
                }

            } else if ((ratings[i - 1] < ratings[i]) ||
                       (ratings[i + 1] < ratings[i])) {

                if ((ratings[i - 1] < ratings[i]) &&
                    (ratings[i + 1] < ratings[i])) {

                    v[i] = 1 + max(v[i - 1], v[i + 1]);

                } else if ((ratings[i - 1] < ratings[i]) &&
                           (ratings[i + 1] >= ratings[i])) {

                    v[i] = 1 + v[i - 1];

                } else if ((ratings[i - 1] >= ratings[i]) &&
                           (ratings[i + 1] < ratings[i])) {

                    v[i] = 1 + v[i + 1];
                }
            }
        }

        int totalCandies = 0;

        for (int candies : v) {
            totalCandies += candies;
        }

        return totalCandies;
    }
};
