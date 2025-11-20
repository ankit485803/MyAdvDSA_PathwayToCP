



/*


19th OCt 2025 (Sunday - Happy Chhoti Diwali)


qno  3397  https://leetcode.com/problems/maximum-number-of-distinct-elements-after-operations/






3397. Maximum Number of Distinct Elements After Operations
Medium
Topics

Companies
Hint
You are given an integer array nums and an integer k.

You are allowed to perform the following operation on each element of the array at most once:

Add an integer in the range [-k, k] to the element.
Return the maximum possible number of distinct elements in nums after performing the operations.

 

Example 1:
Input: nums = [1,2,2,3,3,4], k = 2
Output: 6
Explanation:
nums changes to [-1, 0, 1, 2, 3, 4] after performing operations on the first four elements.

Example 2:
Input: nums = [4,4,4,4], k = 1
Output: 3
Explanation:
By adding -1 to nums[0] and 1 to nums[1], nums changes to [3, 5, 4, 4].

 

Constraints:
1 <= nums.length <= 105
1 <= nums[i] <= 109
0 <= k <= 109


*/

class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {

        //Greedy with Two-Pointer-like Sweep over sortedArr - Appraoch
         int n = nums.size();

        // Step1: sortArr
        sort(nums.begin(), nums.end());  // O(n log n)

        int count = 1;  // At least one distinct value
        int prev = nums[0] - k;  // Smallest possible value for first element



        // Step2: Iterate through the rest
        for (int i = 1; i < n; ++i) {
            int minVal = nums[i] - k;
            int maxVal = nums[i] + k;

            if (minVal > prev) {
                // Can choose minVal to keep it unique
                count++;
                prev = minVal;
            } else if (prev < maxVal) {
                // Move to next unique value in range
                prev++;
                count++;
            }
            // else, cannot make it distinct — skip
        }

        return count;
    
        
    }
};



/*

qno  945  https://leetcode.com/problems/minimum-increment-to-make-array-unique/



945. Minimum Increment to Make Array Unique
Medium
Topics

Companies
You are given an integer array nums. In one move, you can pick an index i where 0 <= i < nums.length and increment nums[i] by 1.

Return the minimum number of moves to make every value in nums unique.

The test cases are generated so that the answer fits in a 32-bit integer.

 

Example 1:

Input: nums = [1,2,2]
Output: 1
Explanation: After 1 move, the array could be [1, 2, 3].
Example 2:

Input: nums = [3,2,1,2,1,7]
Output: 6
Explanation: After 6 moves, the array could be [3, 4, 1, 2, 5, 7].
It can be shown that it is impossible for the array to have all unique values with 5 or less moves.
 

Constraints:
1 <= nums.length <= 105
0 <= nums[i] <= 105

*/



class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {  //sc=O(1)

        //edgeCase
        if (nums.empty()) return 0;

        sort(nums.begin(), nums.end());  //tc=O(nLogN)

        //initilze
        int moves = 0;
        int prev = nums[0];

        for (int i = 1; i < nums.size(); ++i) { //tc=O(n)
            if (nums[i] <= prev) {
                moves += (prev + 1 - nums[i]);
                prev = prev + 1;
            } else {
                prev = nums[i];
            }
        }

        return moves;
    }
};
