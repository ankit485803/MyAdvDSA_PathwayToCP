
// Qno = 69     https://leetcode.com/problems/sqrtx/description

#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>


class Solution {
public:
    int mySqrt(int x) {
        
        if(x < 2) return x;     //for 0, 2 

        int st = 2, end = x/2;
        while(st <= end) {

            int mid = st + (end - st)/2;

            long long midSq = static_cast<long long>(mid) * mid;  //use long to avoid overflow when large value

            if(midSq == x) {
                return mid;   //perfect sq root case

            } else if (midSq < x) {
                st = mid + 1;  //RIGHT SEARCH space
            } else {
                end = mid - 1;  //LEFT 
            }
        }

        return end;
    }
};


// using Binary Search, time complex = O(log(n)), space = 1
