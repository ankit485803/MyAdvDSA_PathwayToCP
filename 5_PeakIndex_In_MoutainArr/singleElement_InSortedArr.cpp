

// Qno 540=  https://leetcode.com/problems/single-element-in-a-sorted-array/description/
// conept req BINARY SEARCH

#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();

        //using Linear search -- O(n) space = O(1)

        for(int i=0; i<n; i++) {
            if(i == (n-1) || nums[i] != nums[i+1]) {   //when not equal
                return nums[i];
            }
            //skip next element because it's DUPLICATE
            i++;
        }

        return -1; // This line should theoretically never be reached
        
    }
};

//method2: Binary search -- because ques mai given hai array already sorted hai -- O(log(n))
// EVEN + ELEMENT CORRECTED mai placed hia

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int st = 0, end = nums.size()-1;

        while(st < end) {
            int mid = st + (end-st)/2;

            //check EVEN
            if(mid % 2 == 1) {
                mid --;  //move to left sie jise hm esko even bana sake
            }


            //check pair is correct
            if(nums[mid] == nums[mid+1]) {
                st = mid+2;
            } else {
                end = mid;
            }
        }

        return nums[st];    //at end st = end


    }
};


// solution by Shardha didi
//A[mid - 1] != A[mid]  !=  A[mid+1]   then return mid

class Solution {
public:
    int singleNonDuplicate(vector<int>& A) {
        // we change nums to A for easy code write again again
        int n = A.size();

        if(n == 1) return A[0];

        int st = 0, end = n-1;
        while(st <= end) {
            int mid = st + (end-st) /2;

            //CORNER case or handle EDGE-CASE
            if(mid == 0 && A[0] != A[1]) return A[mid];
            if(mid == n-1 && A[n-1] != A[n-2]) return A[mid];

            if(A[mid-1] != A[mid] && A[mid] != A[mid+1]) return A[mid]; //when present at mid


            //EVEN condition
            if(mid % 2 == 0) {
                if(A[mid-1] == A[mid]) {   //left
                    end = mid - 1;
                } else {  //right
                    st = mid + 1;
                }
            } else {  //ODD 
                if(A[mid-1] == A[mid]) {  //right
                    end = mid + 1;
                } else {  //left
                    st = mid - 1;
                }
            }
        }

        return -1;  //when not found ans
    }
};

