/*
Problem:
1358. Number of Substrings Containing All Three Characters

Platform:
LeetCode

Link:
https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/

Difficulty:
Medium

Approach:
1. Use the Sliding Window technique with two pointers.
2. Maintain a frequency map for the current window.
3. Expand the window by moving the right pointer (`en`) until the window
   contains at least one occurrence of 'a', 'b', and 'c'.
4. Once a valid window is found:
   - Every substring starting from the current left pointer and ending at
     `en` or any position after `en` is also valid.
   - Add `(n - en)` to the answer.
5. Move the left pointer forward by removing its character from the
   frequency map and continue searching for the next valid window.
6. Repeat until all possible starting positions have been processed.

Time Complexity:
O(n)

Space Complexity:
O(1)

Tags:
Sliding Window, Two Pointers, Hash Map, String
*/

class Solution {
public:

    int numberOfSubstrings(string s) {

        unordered_map<char, int> m;

        int ans = 0;
        int prev = 0;

        for (int st = 0; st < s.size(); st++) {

            for (int en = prev; en < s.size(); en++) {

                m[s[en]]++;

                if (m['a'] > 0 && m['b'] > 0 && m['c'] > 0) {

                    ans += (s.size() - en);

                    prev = en;

                    m[s[en]]--;

                    break;
                }
            }

            m[s[st]]--;
        }

        return ans;
    }
};
