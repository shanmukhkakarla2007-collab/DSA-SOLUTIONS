/*
Problem: 1291.Sequential Digits

Platform: LeetCode

Link: https://leetcode.com/problems/sequential-digits/

Difficulty: Medium

Approach:

1. Generate the smallest sequential number having the same number of digits
   as the lower bound.
2. Maintain:
   - x: current sequential number
   - y: increment pattern (11...1)
3. Generate the next sequential number by adding the increment pattern.
4. When the last digit becomes 9, construct the smallest sequential number
   with one additional digit.
5. Collect all numbers lying within the given range.

Time Complexity:
O(1)

Space Complexity:
O(1)

*/

class Solution {
public:

    vector<int> sequentialDigits(int low, int high) {

        vector<int> ans;

        int a = low;

        int x = 0;
        int c = 1;

        int y = 0;

        while (a > 0) {
            x = x * 10 + c;
            c++;
            y = y * 10 + 1;
            a /= 10;
        }

        int t = x;

        while (x <= high) {

            if (x >= low)
                ans.push_back(x);

            if (x % 10 == 9) {

                y = y * 10 + 1;

                int z = t % 10;

                x = t * 10 + (z + 1);

                t = x;

                continue;
            }

            x += y;
        }

        return ans;
    }
};
