


/*

19th Jan 2026 (Monday)


qno 1833    https://leetcode.com/problems/maximum-ice-cream-bars/


1833. Maximum Ice Cream Bars
Solved
Medium
Topics

Companies
Hint
It is a sweltering summer day, and a boy wants to buy some ice cream bars.

At the store, there are n ice cream bars. You are given an array costs of length n, where costs[i] is the price of the ith ice cream bar in coins. The boy initially has coins coins to spend, and he wants to buy as many ice cream bars as possible. 

Note: The boy can buy the ice cream bars in any order.

Return the maximum number of ice cream bars the boy can buy with coins coins.

You must solve the problem by counting sort.

 

Example 1:

Input: costs = [1,3,2,4,1], coins = 7
Output: 4
Explanation: The boy can buy ice cream bars at indices 0,1,2,4 for a total price of 1 + 3 + 2 + 1 = 7.
Example 2:

Input: costs = [10,6,8,7,7,8], coins = 5
Output: 0
Explanation: The boy cannot afford any of the ice cream bars.
Example 3:

Input: costs = [1,6,3,1,2,5], coins = 20
Output: 6
Explanation: The boy can buy all the ice cream bars for a total price of 1 + 6 + 3 + 1 + 2 + 5 = 18.
 

Constraints:

costs.length == n
1 <= n <= 105
1 <= costs[i] <= 105
1 <= coins <= 108
 
Discover more
ice cream
Ice Cream
Coin
Seen this question in a real interview before?
1/5
Yes
No
Accepted
185,492/250.2K
Acceptance Rate
74.1%
Topics
Array
Greedy
Sorting
Counting Sort
Weekly Contest 237


*/



class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {  //tc=O( logN), sc=O(1)
        sort(costs.begin(), costs.end());
        int maxIceBar = 0;

        for(int i=0; i<costs.size(); i++) {
            if(coins >= costs[i]) {
                coins -= costs[i];
                maxIceBar++;
            } else {
                break;
            }
        }

        return maxIceBar;
    }
};




class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {   //using countingSort
        const int MAX_COST = 100000;
        vector<int> freq(MAX_COST + 1, 0);

        // Count frequencies
        for (int cost : costs) {
            freq[cost]++;
        }

        int iceCreams = 0;

        // Buy ice creams from cheapest to most expensive
        for (int price = 1; price <= MAX_COST && coins >= price; price++) {
            if (freq[price] == 0) continue;

            int canBuy = min(freq[price], coins / price);
            coins -= canBuy * price;
            iceCreams += canBuy;
        }

        return iceCreams;
    }
};





/*


qno 2761   https://leetcode.com/problems/prime-pairs-with-target-sum/




2761. Prime Pairs With Target Sum
Medium
Topics

Companies
Hint
You are given an integer n. We say that two integers x and y form a prime number pair if:

1 <= x <= y <= n
x + y == n
x and y are prime numbers
Return the 2D sorted list of prime number pairs [xi, yi]. The list should be sorted in increasing order of xi. If there are no prime number pairs at all, return an empty array.

Note: A prime number is a natural number greater than 1 with only two factors, itself and 1.

 

Example 1:

Input: n = 10
Output: [[3,7],[5,5]]
Explanation: In this example, there are two prime pairs that satisfy the criteria. 
These pairs are [3,7] and [5,5], and we return them in the sorted order as described in the problem statement.
Example 2:

Input: n = 2
Output: []
Explanation: We can show that there is no prime number pair that gives a sum of 2, so we return an empty array. 
 

Constraints:

1 <= n <= 106
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
38,634/105.1K
Acceptance Rate
36.8%
Topics
Array
Math
Enumeration
Number Theory
Weekly Contest 352



Enumeration: Systematically checking all valid possibilities that satisfy given constraints.
Sieve of Eratosthenes: algo to find all primeNo upto n efficiently

https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes



A sieve is a tool used to separate desired particles from unwanted ones.




*/


class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) { 
        vector<vector<int>> ans; 
        if (n < 4) return ans; //baseCase: smallest primePairSum is 2+2=4 

        // Step1: Sieve of Eratosthenes techniques
        vector<bool> isPrime(n + 1, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i <= n; i++) {  //tc=O(log logN), sc=O(n)  
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        // Step2: Find valid primePairs - Enumeration
        for (int x = 2; x <= n / 2; x++) {
            if (isPrime[x] && isPrime[n - x]) {
                ans.push_back({x, n - x});
            }
        }

        return ans;
    }
};






//🔹 Brute Force Approach to Find All Primes: Check each number independently to see if it is prime
bool isPrime(int x) {
    if (x <= 1) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0)
            return false;
    }
    return true;
}


vector<int> primes;  //tc=O(n * sqrtN), sc=O(1)
for (int i = 2; i <= n; i++) {
    if (isPrime(i)) {
        primes.push_back(i);
    }
}




//optimized: sieve of erotosthene 

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<bool> isPrime(n + 1, true);

    isPrime[0] = false;
    isPrime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    // Print all prime numbers up to n
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            cout << i << " ";
        }
    }

    return 0;
}
