
/*
Problem:
2220. Minimum Bit Flips to Convert Number

Platform:
LeetCode

Link:
https://leetcode.com/problems/minimum-bit-flips-to-convert-number/

Difficulty:
Easy

Approach:
1. Compare the binary representation of `start` and `goal` bit by bit.
2. If the current bits are different, increment the flip count.
3. Continue until one number becomes 0.
4. If one number still has remaining bits, count the set bits since each
   set bit requires one flip.
5. Return the total number of bit flips required.

Time Complexity:
O(log(max(start, goal)))

Space Complexity:
O(1)

Tags:
Bit Manipulation
*/

class Solution {
public:

    int minBitFlips(int start, int goal) {

        int count = 0;

        while (start > 0 && goal > 0) {

            if (start % 2 != goal % 2) {
                count++;
            }

            start /= 2;
            goal /= 2;
        }

        if (start == 0) {

            while (goal > 0) {

                if (goal % 2 == 1) {
                    count++;
                }

                goal /= 2;
            }
        }

        if (goal == 0) {

            while (start > 0) {

                if (start % 2 == 1) {
                    count++;
                }

                start /= 2;
            }
        }

        return count;
    }
};