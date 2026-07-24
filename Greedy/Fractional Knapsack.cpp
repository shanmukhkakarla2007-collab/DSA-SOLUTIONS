/*
Problem:Fractional Knapsack

Platform:GeeksforGeeks

Link:https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

Difficulty:Medium

Approach:
1. Pair each item's weight with its corresponding value.
2. Sort all items in descending order of their value-to-weight ratio.
3. Traverse the sorted list:
   - If the current item can fit completely into the knapsack,
     take the entire item and reduce the remaining capacity.
   - Otherwise, take the maximum possible fraction of the item
     proportional to the remaining capacity and terminate.
4. Return the maximum total value that can be obtained.

Time Complexity:
O(n log n)
- Sorting: O(n log n)
- Traversal: O(n)

Space Complexity:
O(n)
- Used to store the weight-value pairs.

Tags:
Greedy, Sorting, Fractional Knapsack
*/

class Solution {
public:

    static bool cmd(pair<long long, long long> a, pair<long long, long long> b) {
        return (double)a.second / a.first > (double)b.second / b.first;
    }

    double fractionalKnapsack(vector<long long>& val,
                              vector<long long>& wt,
                              long long capacity) {

        vector<pair<long long, long long>> v;

        for (int i = 0; i < val.size(); i++) {
            v.push_back({wt[i], val[i]});
        }

        sort(v.begin(), v.end(), cmd);

        double maxValue = 0;
        long long remainingCapacity = capacity;

        int i = 0;

        while (i < v.size() && remainingCapacity > 0) {

            if (remainingCapacity >= v[i].first) {

                maxValue += v[i].second;
                remainingCapacity -= v[i].first;

            } else {

                maxValue += (double)remainingCapacity * v[i].second / v[i].first;
                remainingCapacity = 0;
            }

            i++;
        }

        return maxValue;
    }
};
