

/*

23rd May 2026 (Saturday)

qno 1752  https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/?envType=daily-question&envId=2026-05-23
already solved on 2nd Feb 2026, 23rd Sep 2025

1752. Check if Array Is Sorted and Rotated
Solved
Easy
Topics

Companies
Hint
Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.

There may be duplicates in the original array.

Note: An array A rotated by x positions results in an array B of the same length such that B[i] == A[(i+x) % A.length] for every valid index i.

 

Example 1:

Input: nums = [3,4,5,1,2]
Output: true
Explanation: [1,2,3,4,5] is the original sorted array.
You can rotate the array by x = 2 positions to begin on the element of value 3: [3,4,5,1,2].
Example 2:

Input: nums = [2,1,3,4]
Output: false
Explanation: There is no sorted array once rotated that can make nums.
Example 3:

Input: nums = [1,2,3]
Output: true
Explanation: [1,2,3] is the original sorted array.
You can rotate the array by x = 0 positions (i.e. no rotation) to make nums.
 

Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 100
 

Seen this question in a real interview before?
1/6
Yes
No
Accepted
923,581/1.6M
Acceptance Rate
56.7%
Topics
Mid Level
Array
Weekly Contest 227


*/


class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int count = 0;  // to count the number of "drops" (nums[i] > nums[i+1])
        
        // Traverse the entire array
        for (int i = 0; i < n; i++) {
            // Compare current element with the next one (circular using % n)
            if (nums[i] > nums[(i + 1) % n]) {
                count++;  // found a "drop" in order
            }
        }
        
        // If there is more than 1 drop, it's not a sorted-then-rotated array
        return count <= 1;
    }
};


//tc=O(n), sc=O(1)
// This is a   VALIDATION  problem, not a SEARCH problem. so not prefer BinarySearch here



class Solution {
public:
    //helperFunct
    vector<int> bubbleSort(vector<int>& arr) {
        int n = arr.size();

        for(int i=0; i<n; i++) {  //nestedLoop tc=O(n^2)
            for(int j=0; j < n - i - 1; j++) {
                if(arr[j] > arr[j+1]) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }

        return arr;   //sortedArr
    }

    bool check(vector<int>& nums) {
        //bruteForce appraoch- check arr sortable or not if yes return true else false
        
    }
};


/*concepts
A sorted and rotated array can have at most one “drop” where: nums[i]>nums[(i+1)%n]
So just count the number of drops.

why almost 1
return count <= 1;

Because in a sorted non-decreasing array, elements increase (or stay equal).
After rotation, the order is still sorted except at one breaking point where the largest element connects to the smallest element.



means:
0 drops → already sorted
1 drop → sorted + rotated
2+ drops → invalid



*/

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        for(int i = 0; i < n; i++) {
            if(nums[i] > nums[(i + 1) % n]) {
                count++;
            }
        }

        return count <= 1;
    }
};


class Solution {
public:
    bool check(vector<int>& nums) {  //tc=O(n), sc=O(1)
        int countD = 0; //no of drop
        int n = nums.size();

        for(int i=0; i<nums.size(); i++) {
            if(nums[i] > nums[(i + 1) % n]) {
                countD++;
            }
        }

        return countD <= 1;
    }
};