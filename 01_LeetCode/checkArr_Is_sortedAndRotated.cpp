

/*


23rd Sep 2025 (Tuesday - secondPuja Maa Durja)


qno 1752   https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/

Ankit learn by observation:
If the array is sorted and then rotated, there can be at most one place where nums[i] > nums[i+1].
If such a place exists more than once, then it’s not possible to form this array by rotation.
yah place nahi hoga to fir wah nahi possible hai

Ques Ask: can we apply BinarySearch here  
Ans: Binary Search is useful when: The array (or part of it) has a monotonic property (sorted ascending/descending).
🧩 Our problem
Here we don’t need to find an index or a value, but just check if:
The array can be expressed as a sorted array rotated some number of times.
This is a   VALIDATION  problem, not a SEARCH problem.






1752. Check if Array Is Sorted and Rotated
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


*/