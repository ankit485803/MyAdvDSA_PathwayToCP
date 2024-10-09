
//Qno 852  https://leetcode.com/problems/peak-index-in-a-mountain-array/description/
// concept req  Binary search and arr

// given in ques = arr is guaranteed to be a mountain array

#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>



class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        // int st = 0, end = A.size()-1;    //normal 

        //edge case - optimization
        int st = 1, end = A.size()-2;

        while(st <= end) {
            int mid = st + (end - st) / 2;

            if(A[mid-1] < A[mid] && A[mid] > A[mid + 1]) {
                return mid;
            } else if(A[mid-1] < A[mid]) { //right
                st = mid + 1;
            } else {  //left
                end = mid-1;
            }
        }
        return -1;
    }
};

//timpe cmplex = O(log(n)) , space = O(1)