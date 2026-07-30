/*
Problem:
136. Single Number

Platform:
LeetCode

Link:
https://leetcode.com/problems/single-number/

Difficulty:
Easy

Approach:
1. Initialize the result as 0.
2. Traverse the array and perform the XOR operation with each element.
3. Since x ^ x = 0 and x ^ 0 = x, every duplicate element cancels itself.
4. The remaining value is the element that appears only once.

Time Complexity:
O(n)

Space Complexity:
O(1)

Tags:
Bit Manipulation, Array
*/

class Solution {
public:

    int singleNumber(vector<int>& nums) {

        int result = 0;

        for (int num : nums) {
            result ^= num;
        }

        return result;
    }
};