


/*


29th  Oct 2025 (Wednesday - After Chhath Puja)

qno  3354  https://leetcode.com/problems/make-array-elements-equal-to-zero/description/


3354. Make Array Elements Equal to Zero
Easy
Topics

Companies
Hint
You are given an integer array nums.

Start by selecting a starting position curr such that nums[curr] == 0, and choose a movement direction of either left or right.

After that, you repeat the following process:

If curr is out of the range [0, n - 1], this process ends.
If nums[curr] == 0, move in the current direction by incrementing curr if you are moving right, or decrementing curr if you are moving left.
Else if nums[curr] > 0:
Decrement nums[curr] by 1.
Reverse your movement direction (left becomes right and vice versa).
Take a step in your new direction.
A selection of the initial position curr and movement direction is considered valid if every element in nums becomes 0 by the end of the process.

Return the number of possible valid selections.

 

Example 1:

Input: nums = [1,0,2,0,3]

Output: 2

Explanation:

The only possible valid selections are the following:

Choose curr = 3, and a movement direction to the left.
[1,0,2,0,3] -> [1,0,2,0,3] -> [1,0,1,0,3] -> [1,0,1,0,3] -> [1,0,1,0,2] -> [1,0,1,0,2] -> [1,0,0,0,2] -> [1,0,0,0,2] -> [1,0,0,0,1] -> [1,0,0,0,1] -> [1,0,0,0,1] -> [1,0,0,0,1] -> [0,0,0,0,1] -> [0,0,0,0,1] -> [0,0,0,0,1] -> [0,0,0,0,1] -> [0,0,0,0,0].
Choose curr = 3, and a movement direction to the right.
[1,0,2,0,3] -> [1,0,2,0,3] -> [1,0,2,0,2] -> [1,0,2,0,2] -> [1,0,1,0,2] -> [1,0,1,0,2] -> [1,0,1,0,1] -> [1,0,1,0,1] -> [1,0,0,0,1] -> [1,0,0,0,1] -> [1,0,0,0,0] -> [1,0,0,0,0] -> [1,0,0,0,0] -> [1,0,0,0,0] -> [0,0,0,0,0].
Example 2:

Input: nums = [2,3,4,0,4,1,0]

Output: 0

Explanation:

There are no possible valid selections.

 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 100
There is at least one element i where nums[i] == 0.



*/


class Solution {
public:
    int countValidSelections(vector<int>& nums) {  //TC=O(n^n), sc=O(n)
        int n = nums.size();
        int count = 0;
        
 
        auto simulate = [&](int start, int direction) {
            vector<int> nums_copy = nums;   
            int curr = start;
            bool valid = true;

            
            while (curr >= 0 && curr < n) {
                if (nums_copy[curr] == 0) {
                    // Move in the same direction
                    curr += direction;

                } else {
                    // Decrease the number at the current position and reverse the direction
                    nums_copy[curr]--;
                    direction = -direction;
                    curr += direction;
                }
                
                // If we go out of bounds, the process ends
                if (curr < 0 || curr >= n) break;
            }
            

            // Check if all elements are zero
            for (int i = 0; i < n; ++i) {
                if (nums_copy[i] != 0) {
                    valid = false;
                    break;
                }
            }
            
            return valid;
        };
        

        // Try each index with nums[i] == 0 as the starting point
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                // Try moving to the right (direction = 1)
                if (simulate(i, 1)) count++;
                
                // Try moving to the left (direction = -1)
                if (simulate(i, -1)) count++;
            }
        }
        
        return count;
    }
};
