/*
Problem:
1248. Count Number of Nice Subarrays

Platform:
LeetCode

Link:
https://leetcode.com/problems/count-number-of-nice-subarrays/

Difficulty:
Medium

Approach:
1. Traverse the array and record the index of the next odd element for
   every previously encountered odd index using a hash map.
2. Maintain:
   - `count` : number of odd elements in the current window.
   - `s` : index of the previous odd element before the current window.
3. Expand the window by moving the right pointer.
4. Whenever the window contains exactly `k` odd numbers:
   - The number of valid starting positions equals the number of even
     elements before the first odd in the window.
   - Add `(nextOddIndex - previousOddIndex)` to the answer.
5. If the window contains more than `k` odd numbers:
   - Move the window to start after the first odd element.
   - Update the answer similarly.
6. Continue until the entire array has been processed.

Time Complexity:
O(n)

Space Complexity:
O(n)

Tags:
Sliding Window, Hash Map, Two Pointers
*/

class Solution {
public:

    int numberOfSubarrays(vector<int>& nums, int k) {

        unordered_map<int, int> m;

        int prev = -1;

        // Store the next odd index for every previous odd index
        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] % 2 != 0) {

                m[prev] = i;
                prev = i;
            }
        }

        m[prev] = nums.size();

        int count = 0;
        int s = -1;
        int ans = 0;

        for (int e = 0; e < nums.size(); e++) {

            if (nums[e] % 2 != 0) {
                count++;
            }

            if (count == k) {

                ans += (m[s] - s);
            }

            if (count > k) {

                count--;

                s = m[s];

                ans += (m[s] - s);
            }
        }

        return ans;
    }
};
