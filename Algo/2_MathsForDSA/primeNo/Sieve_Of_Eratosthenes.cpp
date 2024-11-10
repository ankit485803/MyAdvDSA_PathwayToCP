
#include <iostream>
using namespace std;
#include <vector>


// the Sieve of Eratosthenes algorithm -- to find the no of prime in range given 2 no

// Qno 204.   https://leetcode.com/problems/count-primes/description/


class Solution {
public:
    int countPrimes(int n) {
        
        if (n <= 2) return 0;  // There are no primes less than 2

        vector<bool> isPrime(n+1, true);
        int count = 0;

        for(int i=2; i<n; i++) {
            if(isPrime[i]) {
                count ++;

                for(int j=i*2; j<n;  j = j+i) {
                    isPrime[j] = false;
                }
            }
        }

        return count;
    }
};

// using Sieve of Eratosthenes, TC = O(nlog log n), SC = O(n)
/* WHY

The log log n term arises because, after marking the multiples of the first few primes (like 2, 3, 5, etc.), fewer multiples need to be marked as i increases. The number of operations decreases as i grows, leading to the log log n factor.


*/