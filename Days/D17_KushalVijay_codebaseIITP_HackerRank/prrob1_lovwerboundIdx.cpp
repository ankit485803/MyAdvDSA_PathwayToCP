

/*




https://www.hackerrank.com/contests/codebash-iit-patna/challenges/lower-bound-index



ou are given a sorted (non-decreasing) array A of size N and an integer X. Your task is to find the smallest index i (0-based) such that A[i] >= X.

If every element in the array is smaller than X, print -1.

Input Format

First line: integer N

Second line: N space-separated integers A[i]

Third line: integer X

Constraints

1 <= N <= 2 * 10^5

-10^9 <= A[i], X <= 10^9

A is sorted in non-decreasing order

Output Format

Print a single integer: the lower bound index (0-based) or -1.

Sample Input 0

6
1 2 4 4 7 9
4
Sample Output 0

2
Explanation 0

The first position where value is ≥ 4 is index 2 (A[2] = 4).

Sample Input 1

5
1 3 5 7 9
10
Sample Output 1

-1



*/


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<long long> A(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }

    long long X;
    cin >> X;

    int l = 0, r = N - 1;
    int ans = -1;

    while(l <= r){   //binarySearch approach
        int mid = l + (r - l) / 2;

        if(A[mid] >= X){
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ans << endl;

    return 0;
}