/*
Problem:
1004. Max Consecutive Ones III

Platform:
LeetCode

Link:
https://leetcode.com/problems/max-consecutive-ones-iii/

Difficulty:
Medium

Approach:
1. Use the Sliding Window technique with two pointers:
   - `s` represents the start of the current window.
   - `e` represents the end of the current window.
2. Maintain `count` to track the number of zeros inside the current window.
3. Expand the window by moving `e`:
   - If `nums[e]` is 0, increment the zero count.
4. If the number of zeros becomes greater than `k`, shrink the window
   from the left until the window contains at most `k` zeros.
5. While shrinking:
   - If `nums[s]` is 0, decrement the zero count.
   - Move `s` forward.
6. After maintaining a valid window, update the maximum window length.
7. The longest valid window represents the maximum number of consecutive
   1s obtainable after flipping at most `k` zeros.

Time Complexity:
O(n)

Space Complexity:
O(1)

Tags:
Sliding Window, Two Pointers, Array
*/

class Solution {
public:

    int longestOnes(vector<int>& nums, int k) {

        int ans = 0;
        int s = 0;
        int count = 0;

        for (int e = 0; e < nums.size(); e++) {

            if (nums[e] == 0) {
                count++;
            }

            while (count > k) {

                if (nums[s] == 0) {
                    count--;
                }

                s++;
            }

            ans = max(ans, e - s + 1);
        }

        return ans;
    }
};


