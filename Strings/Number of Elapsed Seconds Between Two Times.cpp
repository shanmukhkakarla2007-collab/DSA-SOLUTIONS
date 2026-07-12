/*
Problem: Number of Elapsed Seconds Between Two Times

Platform: LeetCode

Difficulty: Easy

Contest: Weekly Contest 510

Approach:

1. Parse hours, minutes, and seconds from both strings.
2. Convert each time into total seconds.
3. Return the difference.

Time Complexity:
O(1)

Space Complexity:
O(1)
*/


class Solution {
public:

    int secondsBetweenTimes(string startTime, string endTime) {

        vector<int>a;

        for(int i=0;i<startTime.size();i++){
            if(startTime[i]!=':'){
                a.push_back(startTime[i]-'0');
            }
        }
        vector<int>b;

        for(int i=0;i<endTime.size();i++){
            if(endTime[i]!=':'){
                b.push_back(endTime[i]-'0');
            }
        }
        int h1=a[0]*10+a[1];
        int h2=b[0]*10+b[1];

        int m1=a[2]*10+a[3];
        int m2=b[2]*10+b[3];

        int s1=a[4]*10+a[5];
        int s2=b[4]*10+b[5];
        
        return ((h2-h1)*60*60)-(m1*60)+(m2*60)-s1+s2;
    }
};
