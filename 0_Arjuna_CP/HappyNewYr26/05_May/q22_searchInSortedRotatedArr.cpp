

/*

22nd May 2026 (Friday from new DSA copy 03 today started springCopy plain maths)

qno 33 https://leetcode.com/problems/search-in-rotated-sorted-array/?envType=daily-question&envId=2026-05-22

33. Search in Rotated Sorted Array
Solved
Medium
Topics

Companies
There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly left rotated at an unknown index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be left rotated by 3 indices and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Example 3:

Input: nums = [1], target = 0
Output: -1
 

Constraints:

1 <= nums.length <= 5000
-104 <= nums[i] <= 104
All values of nums are unique.
nums is an ascending array that is possibly rotated.
-104 <= target <= 104
 

Seen this question in a real interview before?
1/6
Yes
No
Accepted
4,518,955/10.1M
Acceptance Rate
44.7%
Topics
Array
Binary Search


*/




class Solution {
public:
    int search(vector<int>& A, int tar) {
        int st = 0, end = A.size() - 1;

        while (st <= end) {
            int mid = st + (end - st) / 2;

            if (A[mid] == tar) { // When mid
                return mid;
            }

            // Check LEFT-HALF sorted
            if (A[st] <= A[mid]) {
                if (A[st] <= tar && tar < A[mid]) { // Apply BS in left half
                    end = mid - 1;
                } else { // Right half case
                    st = mid + 1;
                }
            } else { // RIGHT HALF
                if (A[mid] < tar && tar <= A[end]) {
                    st = mid + 1;
                } else {
                    end = mid - 1;

                }
            }
        }

        return -1; // When not found
    }
};


// approach is used modify Binary search algo
//time compl = O(log(n)) , space = O(1)



class Solution {
public:
    int search(vector<int>& nums, int target) {
        //method1: bruteForce iterate eachElem

        for(int i=0; i<nums.size(); i++) {  //tc=O(n), scO(1)
            if(nums[i] == target) {
                return i;
            } else {
                return -1;
            }
        }
    }
};

/*
Line 12: Char 5: error: non-void function does not return a value in all control paths [-Werror,-Wreturn-type]
   12 |     }
      |     ^
1 error generated.


This returns -1 immediately after checking only the first element.
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {

        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == target) {
                return i;
            }
        }

        return -1;
    }
};



class Solution {
public:
    int binarySearch(vector<int>& arr, int targ) {  //helperFunct
        int low = 0, high = arr.size() - 1;

        while(low <= high) {
            int mid = low + (high - low)/2;
            
            if(arr[mid] == targ) return mid; //case1: targ at mid 

            if(arr[mid] < targ) {  //case2: targ in rightSide so that search in rightHalf
                low = mid + 1;  //low inc to mid + 1
            } else {
                high = mid - 1;  //case3: leftHalfSearch
            }
        }

        return -1;
    }


    int search(vector<int>& nums, int target) {
        //call to main funct
    }
};


/*
why you don't call helperFun to main 
Because your binarySearch() helper works only on a completely sorted array.
But in this problem, the array is rotated sorted:



*/