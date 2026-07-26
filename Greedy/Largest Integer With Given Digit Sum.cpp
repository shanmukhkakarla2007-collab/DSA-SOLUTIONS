/*
Problem:Q1. Largest Integer With Given Digit Sum

Platform:LeetCode Weekly Contest 512

Link:https://leetcode.com/contest/weekly-contest-512/problems/largest-integer-with-given-digit-sum/

Difficulty:Easy

Approach:
1. Initialize an array to store the digits of the required number.
2. Starting from the most significant digit, greedily place the largest
   possible digit (9) while the remaining digit sum is at least 9.
3. If the remaining sum is less than 9, place it in the current position
   and fill the remaining positions with 0.
4. If the digit sum is still positive after using all available digits,
   constructing such a number is impossible, so return -1.
5. Construct the final integer from the generated digits and return it.

Time Complexity:
O(n)

Space Complexity:
O(n)

Tags:
Greedy, Math, Number Construction
*/

class Solution {
public:

    int largestInteger(int n, int s) {

        vector<int> v(n, -1);

        int sum = s;

        for (int i = 0; i < n; i++) {

            if (sum >= 9) {
                v[i] = 9;
                sum -= 9;
            }
            else {
                v[i] = sum;
                sum -= sum;
            }
        }

        if (sum != 0) {
            return -1;
        }

        int k = 0;
        int z = 1;

        for (int i = n - 1; i >= 0; i--) {
            k += v[i] * z;
            z *= 10;
        }

        return k;
    }
};
