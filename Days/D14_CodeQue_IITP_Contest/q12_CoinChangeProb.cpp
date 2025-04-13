


/*

https://www.hackerrank.com/contests/codequest-iitp/challenges/coin-change


The Coin Change Problem
Problem
Submissions
Given an amount and the denominations of coins available, determine how many ways change can be made for amount. There is a limitless supply of each coin type.

Example


There are  ways to make change for : , , and .

Function Description

Complete the getWays function in the editor below.

getWays has the following parameter(s):

int n: the amount to make change for
int c[m]: the available coin denominations
Returns

int: the number of ways to make change
Input Format

The first line contains two space-separated integers  and , where:
 is the amount to change
 is the number of coin types
The second line contains  space-separated integers that describe the values of each coin type.

Constraints

Each  is guaranteed to be distinct.
Hints

Solve overlapping subproblems using Dynamic Programming (DP):
You can solve this problem recursively but will not pass all the test cases without optimizing to eliminate the overlapping subproblems. Think of a way to store and reference previously computed solutions to avoid solving the same subproblem multiple times. * Consider the degenerate cases:
- How many ways can you make change for  cents? - How many ways can you make change for  cents if you have no coins? * If you're having trouble defining your solutions store, then think about it in terms of the base case . - The answer may be larger than a -bit integer.

Sample Input 0

4 3


*/


#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Function to find the number of ways to make change for 'n' units using coins in 'c'
long getWays(int n, vector<long> c) {
    // Initialize dp array with 0s
    vector<long> dp(n + 1, 0);
    
    // Base case: There's one way to make 0 amount: use no coins.
    dp[0] = 1;
    
    // Iterate over each coin
    for (long coin : c) {
        // For each coin, update the dp array for amounts >= coin value
        for (int i = coin; i <= n; ++i) {
            dp[i] += dp[i - coin];  // Add the ways to make the remaining amount
        }
    }

    // dp[n] will hold the number of ways to make change for 'n' units
    return dp[n];
}



