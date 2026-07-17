/*
Problem:GCD Sum

Platform:LeetCode

Difficulty:Easy

Approach:
1. Traverse the array while maintaining the maximum element seen so far.
2. For each element, compute the GCD of the current maximum and the current element.
3. Store these GCD values in a separate array.
4. Sort the GCD array in ascending order.
5. Use two pointers:
   - One starting from the beginning.
   - One starting from the end.
6. Add the GCD of each pair to the answer until the pointers meet.

Time Complexity:
O(N log N)

Space Complexity:
O(N)

Tags:
Math, GCD, Sorting, Two Pointers
*/

class Solution {
public:

    long long gcdSum(vector<int>& nums) {

        int maxi = -1;
        vector<int> pgcd(nums.size());

        for (int i = 0; i < nums.size(); i++) {

            maxi = max(maxi, nums[i]);
            pgcd[i] = gcd(maxi, nums[i]);
        }

        sort(pgcd.begin(), pgcd.end());

        int i = 0;
        int j = pgcd.size() - 1;

        long long ans = 0;

        while (i < j) {

            ans += gcd(pgcd[i], pgcd[j]);
            i++;
            j--;
        }

        return ans;
    }
};
