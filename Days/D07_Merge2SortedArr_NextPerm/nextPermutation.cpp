


// Qno 31   https://leetcode.com/problems/next-permutation/submissions
//return Lexicographically next

// Lexicography == meanning: jis chij ki value small h, wah pahle aa rahi h. and jis chij ki value bari h waah baad mai

//this lexicographh not only for number, but also for alphabet


/*
step1: find the pivot .. TC = O(n)
step2: right most wala elem jo pivot se bara h, usko find out karna h
step3: reverse the elem

*/
#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>

//my old solution
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index = -1;
        int n = nums.size() - 2;
        
        // Step 1: Find the first decreasing element from the right
        for (int i = n; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                index = i;
                break;
            }
        }
        
        // Step 2: If no such element exists, reverse the array
        if (index == -1) {
            reverse(nums.begin(), nums.end());
        } else {
            // Step 3: Find the smallest element larger than nums[index] and swap
            for (int i = nums.size() - 1; i > index; i--) {
                if (nums[i] > nums[index]) {
                    swap(nums[i], nums[index]);
                    break;
                }
            }
            // Step 4: Reverse the elements after the index
            reverse(nums.begin() + index + 1, nums.end());
        }
    }
};


// solutin by shardha didi

class Solution {
public:
    void nextPermutation(vector<int>& A) {

        //find the pivot - step1: TC=O(n)
        int pivot = -1, n = A.size();

        for(int i=n-1; i>=0; i--) {
            if(A[i] < A[i+1]) {
                pivot = i;
                break;
            }
        }

        if(pivot == -1) {  //edge case: when not found pivot in arr eg A = [5, 4, 3, 2, 1]
            reverse(A.begin(), A.end()); //in place change without use of extra space, c++ STL
            return;
        }


        //2nd step: NEXT LARGER ELEMENT -- TC=O(n)
        for(int i=n-1; i>pivot; i--) {
            if(A[i] > A[pivot]) {
                swap(A[i], A[pivot]);
                break;
            }
        }


        //3rd step: REVERSE WALAL STEP  -- reverse(piv+1  to n-1)    TC=O(n)
        // reverse(A.begin() + pivot + 1, A.end());


        int i = pivot+1, j = n-1;
        while(i <= j) {
            swap(A[i++], A[j--]);
        }

        
    }
};


//TC = O(n)+(n)+O(n) = O(n), SC = O(1)

class Solution {
public:
    void nextPermutation(vector<int>& A) {
        int n = A.size();
        int pivot = -1;

        // Step 1: Find the pivot
        for (int i = n - 2; i >= 0; i--) {
            if (A[i] < A[i + 1]) {
                pivot = i;
                break;
            }
        }

        // If no pivot is found, reverse the entire array
        if (pivot == -1) {
            reverse(A.begin(), A.end());
            return;
        }

        // Step 2: Find the next larger element
        for (int i = n - 1; i > pivot; i--) {
            if (A[i] > A[pivot]) {
                swap(A[i], A[pivot]);
                break;
            }
        }

        // Step 3: Reverse the suffix
        reverse(A.begin() + pivot + 1, A.end());
    }
};


//method3: dirctly give c++ STL that this next_permutiation

class Solution {
public:
    void nextPermutation(vector<int>& A) {

        //using c++ STL
        next_permutation(A.begin(), A.end());
    }
};


