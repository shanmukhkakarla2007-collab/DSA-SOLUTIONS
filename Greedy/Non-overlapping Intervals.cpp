/*
Problem:435. Non-overlapping Intervals

Platform:LeetCode

Link:https://leetcode.com/problems/non-overlapping-intervals/

Difficulty:Medium

Approach:
1. Sort all intervals based on their starting time.
2. Consider the first interval as part of the answer.
3. Traverse the remaining intervals:
   - If the current interval does not overlap with the previous interval,
     update the current interval.
   - Otherwise, an overlap exists, so increment the removal count.
   - Among the two overlapping intervals, keep the one with the smaller
     ending time, as it leaves more room for future intervals.
4. Return the total number of intervals removed.

Time Complexity:
O(n log n)
- Sorting: O(n log n)
- Traversal: O(n)

Space Complexity:
O(1)
- Constant extra space (excluding the sorting algorithm).

Tags:
Greedy, Sorting, Interval
*/

class Solution {
public:

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end());

        int count = 0;

        int a = intervals[0][0];
        int b = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {

            if (intervals[i][0] >= b) {

                a = intervals[i][0];
                b = intervals[i][1];
            }
            else {

                count++;

                if (b > intervals[i][1]) {

                    a = intervals[i][0];
                    b = intervals[i][1];
                }
            }
        }

        return count;
    }
};
