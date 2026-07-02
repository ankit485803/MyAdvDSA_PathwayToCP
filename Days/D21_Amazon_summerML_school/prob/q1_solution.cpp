

/*
Problem Statement
You have an array A of size N. You can swap any adjacent elements any number of times (meaning you can rearrange the array in any order).

Given a positive odd integer K, you need to arrange the array to maximize the value of:

Maximize: (Sum of any subsequence of size K) - (Sum of middle elements of all subarrays of size K)

Where:
For a subarray of size K, the middle element is at index floor(K/2) (0-based indexing).

Example: For K=5, subarray [a, b, c, d, e], middle element is c (index 2).



*/


#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<long long> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    
    sort(A.begin(), A.end());
    
    int m = K/2;
    long long X = 0, Y = 0;
    
    // For X: sum of subsequence of size K
    // Take K largest elements
    for(int i = N-1; i >= N-K; i--) {
        X += A[i];
    }
    
    // For Y: sum of middle elements of all subarrays of size K
    // Middle positions: from m to N-m-1 (0-indexed)
    // Put smallest numbers in these positions
    for(int i = 0; i < N - 2*m; i++) {
        Y += A[i];
    }
    
    cout << X - Y << endl;
    
    return 0;
}