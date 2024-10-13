
// Qno 76.   https://leetcode.com/problems/sort-colors/
//concept req= Binary search and basic fundamental

#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>

//method1: Brute force -- use in build funt of c++ i.e.   sort(num.begin(), num.end())  -- which time comp= O(nlog(n)), spcac=O(1)
//but ques mai puchle ga without use of BUILD-IN-FUNCT or LIBRARY solve 

//method2: Optimize-- mai time compl= O(n), first store countOfZero, ones, twos by loop then OVERWRITE elem

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();

        //initilize 0th, 1th, 2nd
        int count0 = 0, count1 = 0, count2 = 0;

        //store the freq by counting -- O(n)
        for(int i=0; i<n; i++) {
            if(nums[i] == 0) count0++;
            else if(nums[i] == 1) count1++;
            else count2++;
        } 

        //step2: OVER-RIDING of original arr  ---- O(n)
        int idx = 0;

        for(int i=0; i<count0; i++) {
            nums[idx++] = 0;
        }
        for(int i=0; i<count1; i++) {
            nums[idx++] = 1;
        }
        for(int i=0; i<count2; i++) {
            nums[idx++] = 2;
        }
    }
};

//overall time compl = O(n) + O(n) = O(n), space= O(1)




//method3: 
// Hint given in ques==  Follow up: Could you come up with a one-pass algorithm using only constant extra space?


/*
The one-pass algorithm for sorting colors, commonly known as the Dutch National Flag (DNF) algorithm, 
efficiently sorts an array containing three distinct values (in this case, 0s, 1s, and 2s) in a single traversal. 


step1: take 3 pointers (low, mid, high) and move zerros from 0 to l-1, ones from l to m-1, and twos from h+1 to n-1
step2: unsorted arr jo hoga from m to l, esmo jaise jaise loop age chalega wah empty ho jayega area


*/



class Solution {
public:
    void sortColors(vector<int>& A) {
        int n = A.size();
        
        //solution by DNF (Dutch National Flag) algo
        int mid = 0, high = n-1, low = 0;

        while(mid <= high) {
            if(A[mid] == 0) {   //1st case
                swap(A[low], A[mid]);
                mid++; low++;

            } else if(A[mid] == 1) {  //2nd case
                mid++;
            } else {  //3rd case
                swap(A[high], A[mid]);
                high--;
            }

        }
    }
};

// solution using single loop (while) -- time complx = O(n), space = O(1)

