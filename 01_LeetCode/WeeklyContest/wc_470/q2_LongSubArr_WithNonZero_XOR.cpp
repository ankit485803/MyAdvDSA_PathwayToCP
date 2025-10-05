


/*


https://leetcode.com/contest/weekly-contest-470/problems/longest-subsequence-with-non-zero-bitwise-xor/






Q2. Longest Subsequence With Non-Zero Bitwise XOR
Medium
4 pt.
You are given an integer array nums.
Return the length of the longest subsequence in nums whose bitwise XOR is non-zero. If no such subsequence exists, return 0.

 

Example 1:
Input: nums = [1,2,3]
Output: 2
Explanation:
One longest subsequence is [2, 3]. The bitwise XOR is computed as 2 XOR 3 = 1, which is non-zero.




Example 2:
Input: nums = [2,3,4]
Output: 3
Explanation:
The longest subsequence is [2, 3, 4]. The bitwise XOR is computed as 2 XOR 3 XOR 4 = 5, which is non-zero.

 

Constraints:
1 <= nums.length <= 105
0 <= nums[i] <= 109




my approach: step1: Find all possible subArr of nums step2: compare the Longest subArr step3: compute the XOR of the Longest subArr if( xor value != 0) { return length(LongSubArr)

else -> return 0

but not computinally corrct good approach 
*/

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {   //compress type
        int xorAll = 0;

        // Loop through the array using a simple for loop
        for (int i = 0; i < nums.size(); i++) {
            xorAll = xorAll ^ nums[i];
        }

        // Use if-else instead of ternary operator
        if (xorAll != 0) {
            return nums.size();
        } else {
            return nums.size() - 1;
        }
    }
};




class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        // Base case: all elements are 0
        bool allZero = true;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                allZero = false;
                break;
            }
        }

        if (allZero) return 0;

        // Main logic: compute XOR of all elements
        int xorAll = 0;
        for (int i = 0; i < nums.size(); i++) {
            xorAll ^= nums[i];
        }

        if (xorAll != 0) {
            return nums.size();
        } else {
            return nums.size() - 1;
        }
    }
};



// in detailing

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {

        int xorAll = 0;

        //calculate xor 
        for(int i=0; i<nums.size(); i++) {
            xorAll = xorAll ^ nums[i];
        }

        //apply condition
        if(xorAll  !=  0) {
            return nums.size();
        } else {
            return nums.size()-1;
        }
    }
};