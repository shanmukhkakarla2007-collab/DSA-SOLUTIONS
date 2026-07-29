/*
Problem:231. Power of Two

Platform:LeetCode

Link:https://leetcode.com/problems/power-of-two/

Difficulty:Easy

Approach:
1. A power of two has exactly one set bit in its binary representation.
2. For any positive power of two `n`, the expression `n & (n - 1)` clears
   its only set bit, resulting in 0.
3. First, check if `n` is positive since powers of two must be greater than 0.
4. If `(n & (n - 1)) == 0`, return true; otherwise, return false.

Time Complexity:
O(1)

Space Complexity:
O(1)

Tags:
Bit Manipulation, Math
*/

class Solution {
public:

    bool isPowerOfTwo(int n) {

        if (n <= 0) {
            return false;
        }

        int k = n & (n - 1);

        if (k == 0) {
            return true;
        }

        return false;
    }
};
