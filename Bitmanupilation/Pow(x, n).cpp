/*
Problem:
50. Pow(x, n)

Platform:
LeetCode

Link:
https://leetcode.com/problems/powx-n/

Difficulty:
Medium

Approach:
1. Use Binary Exponentiation (Exponentiation by Squaring) to calculate x^n.
2. Recursively calculate x^(n/2) instead of multiplying x repeatedly.
3. If n is even:
      x^n = (x^(n/2))²
4. If n is odd:
      x^n = x * (x^(n/2))²
5. For a negative exponent, convert the exponent to `long long` first
   to safely handle INT_MIN, then calculate the reciprocal:
      x^(-n) = 1 / x^n
6. This reduces the number of recursive calls from O(n) to O(log n).

Time Complexity:
O(log |n|)

Space Complexity:
O(log |n|)
- Due to the recursive call stack.

Tags:
Math, Recursion, Binary Exponentiation, Divide and Conquer
*/

class Solution {
public:

    double f(double &x, long long n) {

        if (n <= 0) {
            return 1;
        }

        double ans = f(x, n / 2);

        if (n % 2 == 0) {
            return ans * ans;
        }

        return x * ans * ans;
    }

    double myPow(double x, int n) {

        if (n < 0) {
            long long a = (long long)n;
            return 1 / f(x, -a);
        }

        return f(x, n);
    }
};