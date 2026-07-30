/*
Problem:
3016. Minimum Number of Pushes to Type Word II

Platform:
LeetCode

Link:
https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/

Difficulty:
Medium

Approach:
1. Since each character in the given word is unique, assign characters to
   keypad positions greedily.
2. The first 8 characters require 1 push each.
3. The next 8 characters require 2 pushes each, and so on.
4. Traverse the word, increasing the push level after every 8 characters,
   and accumulate the total pushes.

Time Complexity:
O(n)

Space Complexity:
O(1)

Tags:
Greedy, String
*/

class Solution {
public:

    int minimumPushes(string word) {

        int count = 1;
        int ans = 0;
        int level = 1;

        for (int i = 0; i < word.size(); i++) {

            if (count > 8) {
                count = 1;
                level++;
            }

            count++;
            ans += level;
        }

        return ans;
    }
};
