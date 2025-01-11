
// LeetCode Que No = 238
// https://leetcode.com/problems/product-of-array-except-self/description/

#include <iostream>
#include <vector>
using namespace std;

//method 1: BRUTE-FORCE approach

//// yah code run hoga only on tes case, but not on all becase constaint 10^5
// O(n^2) complexity wala code kabhi bhi 10^5 par run nahi hoga, error dega TLE leetcode

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(i != j) {
                    ans[i] *= nums[j];
                }
            }
        }
        return ans;
    }
};


// method2 : Optimal - time complexity = O(n) and space = O(n)
//  leftPrd -- index i -- rightProd
// leftProd = Prefix, rightProd = Suffix


//step1:  prefix(i) .. O(n)

//step2: suffix (i)  ... O(n)

//step3: apply loop to print ans = prefix * suffix ... O(n)
//final time  comp = O(n) + O(n) + O(n) == O(n)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        vector<int> prefix(n, 1);
        vector<int> suffix(n, 1);

        //prefix -- step1
        for(int i=1; i<n; i++) {
            prefix[i] = prefix[i-1] * nums[i-1];
        }

        //suffix -- step2 using BACKWARD LOOP
        for(int i=n-2; i>=0; i--) {
            suffix[i] = suffix[i+1] * nums[i+1];
        }

        //step3 -- final step LOOOP 
        for(int i=0; i<n; i++) {
            ans[i] = prefix[i] * suffix[i];
        }
        return ans;
    }
   
};

// Now We have to optimise the time for space complexity to reduce from linear O(N) to constant O(1)
//not store aalg vector mai, dirctly multiply kar do, taki space compl reduce hoga

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
    
        // prefix => ans
        for(int i=1; i<n; i++) {
            ans[i] = ans[i-1] * nums[i-1];
        }

        int suffix = 1;
        //suffix 
        for(int i=n-2; i>=0; i--) {
             suffix *= nums[i+1];  //directly ith suffix
             ans[i] *= suffix;
        }
        return ans;
    }
   
};

//space complex = O(1), time = O(n) with Optimal solutin approach

