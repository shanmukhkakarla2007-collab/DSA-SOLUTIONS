/*
Problem:
78. Subsets

Platform:
LeetCode

Link:
https://leetcode.com/problems/subsets/

Difficulty:
Medium

Approach:
1. Use recursion with backtracking to generate all possible subsets.
2. At each index, there are two choices:
   - Include the current element in the subset.
   - Exclude the current element from the subset.
3. When all elements have been processed, store the current subset.
4. Since each element has two choices, all 2ⁿ subsets are generated.

Time Complexity:
O(n × 2ⁿ)

Space Complexity:
O(n)
(Recursion stack + current subset)

Tags:
Backtracking, Recursion, Array
*/

class Solution {
public:

    void f(int idx, vector<int>& nums, vector<vector<int>>& ans, vector<int>& a) {

        if (idx >= nums.size()) {
            ans.push_back(a);
            return;
        }

        // Include current element
        a.push_back(nums[idx]);
        f(idx + 1, nums, ans, a);

        // Exclude current element
        a.pop_back();
        f(idx + 1, nums, ans, a);
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> a;

        f(0, nums, ans, a);

        return ans;
    }
};
