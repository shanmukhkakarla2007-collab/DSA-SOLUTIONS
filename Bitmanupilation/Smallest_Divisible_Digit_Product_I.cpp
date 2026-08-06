
/*
Problem:
3345. Smallest Divisible Digit Product I

Platform:
LeetCode

Link:
https://leetcode.com/problems/smallest-divisible-digit-product-i/

Difficulty:
Easy

Approach:
1. Start checking numbers from `n`.
2. For each number, calculate the product of all its digits.
3. Check whether the digit product is divisible by `t`.
4. If the product is divisible by `t`, return the current number.
5. Otherwise, increment the number and continue searching.
6. The first valid number found is the smallest number greater than or
   equal to `n` satisfying the required condition.

Time Complexity:
O((answer - n + 1) * log(answer))

Space Complexity:
O(1)

Tags:
Math, Brute Force, Simulation
*/

class Solution {
public:

    int f(int b) {

        int p = 1;

        while (b > 0) {
            p = p * (b % 10);
            b = b / 10;
        }

        return p;
    }

    int smallestNumber(int n, int t) {

        bool a = false;
        int b = n;

        while (!a) {

            int c = f(b);

            if (c % t == 0) {
                return b;
            }

            b++;
        }

        return -1;
    }
};