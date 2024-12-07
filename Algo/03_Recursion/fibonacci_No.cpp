

#include <iostream>
using namespace std;
#include <vector>



// qno 506  https://leetcode.com/problems/fibonacci-number/




class Solution {
public:
    int fib(int n) {
        
        if(n == 0 || n == 1) {
            return n;

        }

        return fib(n-1) + fib(n-2);
    }
};

//fibonacci series TC= O(2^n) this is very bad tc because exponential time, but reduce by DP

// SC = depth of RT + mean = O(n * 1) == O(n)


//check if arr is sorted 

bool isSorted(vector<int> arr, int n) {
    if(n == 0 || n == 1) {
        return true;

    }

    return arr[n-1] >= arr[n-2] && isSorted(arr, n-1);
}