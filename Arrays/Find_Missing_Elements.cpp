/*
Problem:
Find Missing Elements

Platform:
LeetCode

Approach:
1. Traverse the array to find the minimum and maximum elements.
2. Store every element in a hash map for fast lookup.
3. Iterate through all numbers between the minimum and maximum values.
4. If a number is not present in the hash map, add it to the answer.
5. Return all missing elements in increasing order.

Time Complexity:
O(n + R)

where:
n = size of the array
R = max(nums) - min(nums)

Space Complexity:
O(n)

Tags:
Array, Hash Map
*/

class Solution {
public:

    vector<int> findMissingElements(vector<int>& nums) {

        int maxi = INT_MIN;
        int mini = INT_MAX;

        unordered_map<int, bool> m;

        for (int i = 0; i < nums.size(); i++) {

            maxi = max(maxi, nums[i]);
            mini = min(mini, nums[i]);

            m[nums[i]] = true;
        }

        vector<int> ans;

        for (int i = mini + 1; i < maxi; i++) {

            if (m.find(i) == m.end()) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
