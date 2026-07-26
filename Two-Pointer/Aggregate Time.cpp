/*
Problem:Q2. Aggregate Time Series

Platform:LeetCode Weekly Contest 512

Link:https://leetcode.com/contest/weekly-contest-512/problems/aggregate-time-series/

Difficulty:Medium

Approach:
1. Since both time series are sorted by timestamp, use the two-pointer technique.
2. Compare the current timestamps of both series:
   - If the timestamp in the first series is smaller, combine its value with
     the current value from the second series and move the first pointer.
   - If the timestamp in the second series is smaller, combine its value with
     the current value from the first series and move the second pointer.
   - If both timestamps are equal, sum their values and move both pointers.
3. After one series is exhausted, append the remaining entries from the other
   series to the answer.
4. Return the aggregated time series.

Time Complexity:
O(n + m)

Space Complexity:
O(n + m)

Tags:
Two Pointers, Array, Merge
*/

class Solution {
public:

    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1,
                                            vector<vector<int>>& series2) {

        int i = 0;
        int j = 0;

        vector<vector<int>> ans;

        while (i < series1.size() && j < series2.size()) {

            if (series1[i][0] < series2[j][0]) {

                ans.push_back({series1[i][0],
                               series1[i][1] + series2[j][1]});
                i++;
            }
            else if (series1[i][0] == series2[j][0]) {

                ans.push_back({series1[i][0],
                               series1[i][1] + series2[j][1]});
                i++;
                j++;
            }
            else {

                ans.push_back({series2[j][0],
                               series1[i][1] + series2[j][1]});
                j++;
            }
        }

        while (i < series1.size()) {
            ans.push_back(series1[i]);
            i++;
        }

        while (j < series2.size()) {
            ans.push_back(series2[j]);
            j++;
        }

        return ans;
    }
};
