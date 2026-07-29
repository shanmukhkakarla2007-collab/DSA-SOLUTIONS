/*
Problem:3272. Find the Count of Good Integers (Smallest Palindrome Helper)

Platform:LeetCode

Link:https://leetcode.com/problems/find-the-count-of-good-integers/

Difficulty:Hard

Approach:
1. Count the frequency of each character using an ordered map.
2. Construct the left half of the palindrome by placing half of the
   occurrences of each character in lexicographical order.
3. If the string length is odd, place the character with the odd
   frequency at the center.
4. Mirror the left half onto the right half to form the complete
   palindrome.
5. Since characters are processed in sorted order, the constructed
   palindrome is the lexicographically smallest possible palindrome.

Time Complexity:
O(n + k)
- n = length of the string
- k = number of distinct characters

Space Complexity:
O(n)

Tags:
String, Greedy, Hash Map, Palindrome
*/

class Solution {
public:

    string smallestPalindrome(string s) {

        if (s.size() == 1) {
            return s;
        }

        map<char, int> m;

        for (char ch : s) {
            m[ch]++;
        }

        string v(s.size(), ' ');

        int left = 0;
        char middle;

        for (auto it : m) {

            if (it.second % 2 != 0) {
                middle = it.first;
            }

            int cnt = it.second / 2;

            while (cnt--) {
                v[left] = it.first;
                left++;
            }
        }

        if (s.size() % 2 != 0) {
            v[left] = middle;
            left++;
        }

        int right = v.size() - 1;

        while (right >= left) {
            v[right] = v[v.size() - right - 1];
            right--;
        }

        return v;
    }
};
