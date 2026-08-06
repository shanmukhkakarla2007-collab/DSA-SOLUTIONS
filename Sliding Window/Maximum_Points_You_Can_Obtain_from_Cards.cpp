/*
Problem:
1423. Maximum Points You Can Obtain from Cards

Platform:
LeetCode

Link:
https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

Difficulty:
Medium

Approach:
1. Calculate the total sum of all card points.
2. Since exactly `k` cards must be taken from either end, instead of directly
   selecting those cards, find the subarray that will be left behind.
3. The size of the remaining subarray will be:
      n - k
4. Therefore, the problem becomes finding the minimum-sum contiguous subarray
   of size `n - k`.
5. Use a fixed-size sliding window to calculate the minimum sum efficiently.
6. Subtract this minimum window sum from the total sum.
7. The remaining value represents the maximum score obtainable by taking
   exactly `k` cards from the two ends.

Time Complexity:
O(n)

Space Complexity:
O(1)

Tags:
Sliding Window, Array
*/

class Solution {
public:

    int maxScore(vector<int>& v, int k) {

        int total = 0;

        for (int i = 0; i < v.size(); i++) {
            total += v[i];
        }

        int window = v.size() - k;

        if (window == 0) {
            return total;
        }

        int a = 0;
        int b = window - 1;

        int sum = 0;
        int ans = INT_MAX;

        for (int i = 0; i < window - 1; i++) {
            sum += v[i];
        }

        while (b < v.size()) {

            sum += v[b];

            ans = min(ans, sum);

            sum -= v[a];

            a++;
            b++;
        }

        return total - ans;
    }
};
