

/* 1st April (Tuesday) Day 11 - Basic Arr and solve TUF sheet

Given a positive integer n, The task is to find the value of Σi F(i) where i is from 1 to n and function F(i) is defined as the sum of all divisors of i.

Examples:

Input: n = 4
Output: 15
Explanation:
F(1) = 1
F(2) = 1 + 2 = 3
F(3) = 1 + 3 = 4
F(4) = 1 + 2 + 4 = 7
So, F(1) + F(2) + F(3) + F(4)
    = 1 + 3 + 4 + 7 = 15




*/


#include <bits/stdc++.h>
using namespace std;



void printDivisors(int n) {
    vector<int> divisors;
    int sum = 0;
    
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            divisors.push_back(i);  // Store divisor as a arr
            sum += i;  // Add divisor to sum
        }
    }

    //this is very imp step 
    cout << "Divisors: ";
    for (int d : divisors) {
        cout << d << " ";
    }
    cout << endl;

    cout << "Sum of Divisors: " << sum << endl;

}





int main() {
    int n = 4;
    printDivisors(n);
    return 0;
}


/*
Optimized Approach - O(N) using a Prefix Sum Technique
Instead of calculating divisors separately for each number, we can efficiently compute F(i) for all i from 1 to N in O(N) time using a smart trick.

https://www.geeksforgeeks.org/problems/sum-of-all-divisors-from-1-to-n4738/1


*/

int sumOfDivisors(int n) {
    vector<int> sum(n + 1, 0);
    
    // Calculate sum of divisors for every number from 1 to N
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            sum[j] += i;  // i is a divisor of j
        }
    }
    
    // Compute final sum of all F(i)
    int totalSum = 0;
    for (int i = 1; i <= n; i++) {
        totalSum += sum[i];
    }

    return totalSum;
}