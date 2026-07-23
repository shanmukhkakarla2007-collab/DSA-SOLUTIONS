
/*
Problem:57. Insert Interval

Platform:LeetCode

Link:https://leetcode.com/problems/insert-interval/

Difficulty:Medium

Approach:
1. Treat the given intervals and the new interval as two sorted lists.
2. Merge both lists into a temporary array while maintaining sorted order.
3. If an overlap occurs during merging, combine the intervals by updating
   the starting and ending points.
4. Perform a second traversal on the merged list to merge any remaining
   overlapping intervals.
5. Return the final list of non-overlapping intervals.

Time Complexity:
O(n)

Space Complexity:
O(n)

Tags:
Array, Interval, Greedy, Merge Intervals
*/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newIntervals) {

        vector<vector<int>> newintervals;
        newintervals.push_back(newIntervals);

        vector<vector<int>> temp;

        int i = 0;
        int j = 0;

        // Merge intervals and new interval
        while (i < intervals.size() && j < newintervals.size()) {

            if (intervals[i][1] < newintervals[j][0]) {

                temp.push_back(intervals[i]);
                i++;

            }
            else if (intervals[i][0] > newintervals[j][1]) {

                temp.push_back(newintervals[j]);
                j++;

            }
            else {

                temp.push_back({
                    min(intervals[i][0], newintervals[j][0]),
                    max(intervals[i][1], newintervals[j][1])
                });

                i++;
                j++;
            }
        }

        while (i < intervals.size()) {
            temp.push_back(intervals[i]);
            i++;
        }

        while (j < newintervals.size()) {
            temp.push_back(newintervals[j]);
            j++;
        }

        // Merge overlapping intervals
        vector<vector<int>> answer;

        int start = temp[0][0];
        int end = temp[0][1];

        for (int k = 1; k < temp.size(); k++) {

            if (temp[k][0] > end) {

                answer.push_back({start, end});

                start = temp[k][0];
                end = temp[k][1];
            }
            else {

                end = max(end, temp[k][1]);
            }
        }

        answer.push_back({start, end});

        return answer;
    }
};