
/*
Problem:56. Merge Intervals

Platform:LeetCode

Link:https://leetcode.com/problems/merge-intervals/

Difficulty:Medium

Approach:
1. Sort all intervals based on their starting time.
2. Initialize the first interval as the current interval.
3. Traverse the remaining intervals:
   - If the current interval overlaps with the previous merged interval,
     extend the ending point using the maximum end value.
   - Otherwise, store the previous merged interval and start a new one.
4. After the traversal, add the last merged interval to the answer.
5. Return the list of merged non-overlapping intervals.

Time Complexity:
O(n log n)
- Sorting: O(n log n)
- Merging: O(n)

Space Complexity:
O(n)
- Used to store the merged intervals.

Tags:
Array, Sorting, Interval, Greedy
*/

class Solution {
public:

    vector<vector<int>> merge(vector<vector<int>>& arr) {

        sort(arr.begin(), arr.end());

        int a = arr[0][0];
        int b = arr[0][1];

        vector<vector<int>> ans;

        for (int j = 1; j < arr.size(); j++) {

            if (arr[j][0] > b) {

                ans.push_back({a, b});

                a = arr[j][0];
                b = arr[j][1];
            }
            else {

                b = max(b, arr[j][1]);
            }
        }

        ans.push_back({a, b});

        return ans;
    }
};