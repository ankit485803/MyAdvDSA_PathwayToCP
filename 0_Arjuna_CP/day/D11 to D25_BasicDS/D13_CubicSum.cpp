



/* 9th April 2025 (Wednesday) Day13 - arrr


https://www.geeksforgeeks.org/problems/sum-of-first-n-terms5843/1

Given an integer n, calculate the sum of series 13 + 23 + 33 + 43 + … till n-th term.

Examples:
Input: n = 5
Output: 225
Explanation: 13 + 23 + 33 + 43 + 53 = 225

*/

class Solution {
    public:
      int sumOfSeries(int n) {
          int sum = n * (n + 1) / 2;
          return sum * sum;
      }
  };
 
  














#include <iostream>
using namespace std;



/*
sum of first n natural sum : 1 + 2 + 3 +... n

method1: using formula sum = n(n+1)/2;    TC=O(1) = SC

method2: using iteration for loop -- TC=O(n), SC=O(1)
meaning  of sum += i;    sum=sum+i

difference between int and void in C++ (or C, Java, etc.), especially when used as return types of functions.


*/


int naturalSum(int n) {
    int sum = 0;  //initilize
    for(int i=1; i<=n; i++) {
        sum += i;  
    }

    return sum;
}



int main() {

    int n = 5;
    cout << "sum of first natural no = " << naturalSum(n);

    return 0;
}