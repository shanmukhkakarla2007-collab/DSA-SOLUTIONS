
/*
Problem:
3. Longest Substring Without Repeating Characters

Platform:
LeetCode

Link:
https://leetcode.com/problems/longest-substring-without-repeating-characters/

Difficulty:
Medium

Approach:
1. Use the Sliding Window technique with two pointers:
   - `start` represents the beginning of the current window.
   - `e` represents the end of the current window.
2. Maintain a hash map that stores the most recent index of each character.
3. While traversing the string:
   - If the current character has not appeared before, include it in the
     current window.
   - If it has appeared before, move `start` to one position after its
     previous occurrence.
4. Use `max(start, previousIndex + 1)` to ensure that the start pointer
   never moves backwards.
5. Update the last occurrence of the current character.
6. Keep track of the maximum window length encountered.

Time Complexity:
O(n)

Space Complexity:
O(k)
where k is the number of distinct characters stored in the hash map.

Tags:
Sliding Window, Two Pointers, Hash Map, String
*/

class Solution {
public:

    int lengthOfLongestSubstring(string s) {

        int start = 0;
        int ans = 0;

        unordered_map<char, int> m;

        for (int e = 0; e < s.size(); e++) {

            if (m.find(s[e]) == m.end()) {

                ans = max(ans, e - start + 1);
                m[s[e]] = e;
            }
            else {

                start = max(start, m[s[e]] + 1);

                ans = max(ans, e - start + 1);

                m[s[e]] = e;
            }
        }

        return ans;
    }
};