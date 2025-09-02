


/*

2nd Sep 2025 (Tuesday) 

qno 35 https://leetcode.com/problems/search-insert-position/description/



35. Search Insert Position

Solved
Easy
Topics

Companies
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
You must write an algorithm with O(log n) runtime complexity.

 

Example 1:
Input: nums = [1,3,5,6], target = 5
Output: 2


Example 2:
Input: nums = [1,3,5,6], target = 2
Output: 1


Example 3:
Input: nums = [1,3,5,6], target = 7
Output: 4
 



Constraints:
1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums contains distinct values sorted in ascending order.
-104 <= target <= 104


*/





class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        //solve using BinarySearchAlgo
        int st=0, end=nums.size()-1;   //two pointer approach

        while(st <= end) {
            int mid = st + (end-st)/2;  //also from MID formula to handle overflow

            if(target > nums[mid]) {  //righ HALF
                st = mid+1;
            } else if(target < nums[mid]) {
                end = mid-1;
            } else {
                return mid;
            }

        }

        //Ankit ideas: then return idx from nums whose value cloaser to targert
        return st;   //if target not found then return idx wher it would be if it were insered in  order

    }
};






/*

After the loop, if the target is not found, we should return the insert position → which is simply st.

TC=O( logN), SC=O(1)



similar ques no  704  https://leetcode.com/problems/binary-search/description/

*/