/*
Problem:
904. Fruit Into Baskets

Platform:
LeetCode

Link:
https://leetcode.com/problems/fruit-into-baskets/

Difficulty:
Medium

Approach:
1. Maintain two fruit types `a` and `b`, representing the two types currently
   present in the valid subarray.
2. Keep `count1` and `count2` to track the total number of fruits collected
   for these two types in the current window.
3. Maintain `c` as the most recently seen fruit type and `consecutive` as
   the number of consecutive occurrences of that fruit.
4. While traversing:
   - If the current fruit matches `a` or `b`, increase its corresponding count.
   - If one basket is empty, assign the new fruit type to that basket.
   - If a third fruit type is encountered, store the current maximum answer.
5. When a third type appears:
   - Keep the consecutive occurrences of the previously seen fruit.
   - Replace the other fruit type with the new fruit.
   - Start a new valid window containing at most two fruit types.
6. After traversal, update the answer one final time.

Time Complexity:
O(n)

Space Complexity:
O(1)

Tags:
Sliding Window, Two Pointers, Array
*/

class Solution {
public:

    int totalFruit(vector<int>& fruits) {

        int ans = INT_MIN;

        int count1 = 0;
        int count2 = 0;

        int a = -1;
        int b = -1;
        int c = -1;

        int consecutive = 0;

        for (int i = 0; i < fruits.size(); i++) {

            if (a == fruits[i]) {

                count1++;
            }
            else if (b == fruits[i]) {

                count2++;
            }
            else {

                if (a == -1) {

                    a = fruits[i];
                    count1++;
                }
                else if (b == -1) {

                    b = fruits[i];
                    count2++;
                }
                else {

                    ans = max(ans, count1 + count2);

                    a = c;
                    count1 = consecutive;

                    b = fruits[i];
                    count2 = 1;
                }
            }

            // Track consecutive occurrences of the latest fruit type
            if (fruits[i] == c) {

                consecutive++;
            }
            else {

                c = fruits[i];
                consecutive = 1;
            }
        }

        ans = max(ans, count1 + count2);

        return ans;
    }
};
