/*
Problem:
204. Count Primes

Platform:
LeetCode

Link:
https://leetcode.com/problems/count-primes/

Difficulty:
Medium

Approach:
1. Use the Sieve of Eratosthenes to efficiently identify all prime numbers
   smaller than `n`.
2. Initialize an array `isprime` where every number is initially considered
   prime.
3. Start iterating from 2.
4. If `i` is still marked as prime, mark all of its multiples as non-prime.
5. Start marking multiples from `i * i` because smaller multiples of `i`
   have already been marked by smaller prime numbers.
6. After completing the sieve, iterate from 2 to `n - 1` and count all
   numbers that are still marked as prime.
7. Return the total count of prime numbers strictly less than `n`.

Time Complexity:
O(n log log n)

Space Complexity:
O(n)

Tags:
Math, Number Theory, Sieve of Eratosthenes, Prime Numbers
*/

class Solution {
public:

    int countPrimes(int n) {

        vector<int> isprime(n + 1, 1);

        // Sieve of Eratosthenes
        for (int i = 2; i * i <= n; i++) {

            if (isprime[i] == 1) {

                for (int j = i * i; j <= n; j += i) {
                    isprime[j] = 0;
                }
            }
        }

        int count = 0;

        // Count primes strictly smaller than n
        for (int i = 2; i < n; i++) {

            if (isprime[i] == 1) {
                count++;
            }
        }

        return count;
    }
};
