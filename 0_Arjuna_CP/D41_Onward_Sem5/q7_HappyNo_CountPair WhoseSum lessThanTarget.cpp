

/*

11th Oct 2025 (Saturday - Amazon ML Challenge start for Day1 to Day3)



qno 202   https://leetcode.com/problems/happy-number/description/


14th Oct 2025 (Tuesday)


202. Happy Number
Easy
Topics

Companies
Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.

 

Example 1:
Input: n = 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1


Example 2:
Input: n = 2
Output: false
 

Constraints:
1 <= n <= 231 - 1





*/


class Solution {
public:
    bool isHappy(int n) {
        
        //Approach - Cycle Detection using a "Seen" Arr or Hash

        // arr to track sums we've encountered, max sum size is small
        bool seen[1000] = {false};

        while(n != 1) {
            int sum = 0;

            while(n > 0) {
                int digit = n % 10;  //last digit access
                sum += digit * digit;
                n /= 10;  //remove last digit
            }

            if(seen[sum]) {
                return false;  //If this sum has already been encountered, it's a cycle
            }


            seen[sum] = true;
            n = sum; 
        }

        return true;   // If n becomes 1, it's a happy number
    }
};

//TC=O(log N), SC=O(1)



/*

https://leetcode.com/problems/count-pairs-whose-sum-is-less-than-target/description/


2824. Count Pairs Whose Sum is Less than Target
Easy
Topics

Companies
Hint
Given a 0-indexed integer array nums of length n and an integer target, return the number of pairs (i, j) where 0 <= i < j < n and nums[i] + nums[j] < target.
 

Example 1:

Input: nums = [-1,1,2,3,1], target = 2
Output: 3
Explanation: There are 3 pairs of indices that satisfy the conditions in the statement:
- (0, 1) since 0 < 1 and nums[0] + nums[1] = 0 < target
- (0, 2) since 0 < 2 and nums[0] + nums[2] = 1 < target 
- (0, 4) since 0 < 4 and nums[0] + nums[4] = 0 < target
Note that (0, 3) is not counted since nums[0] + nums[3] is not strictly less than the targe


*/


class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        
        //edgeCase
        if(nums.size() < 2) {
            return 0;
        }


        //step1: sortArr
        sort(nums.begin(), nums.end());

        int left=0, right=nums.size()-1;
        int count = 0;

        //step2: countPari using twoPointer Approach
        while(left < right) {
            if((nums[left] + nums[right]) < target) {

                count += (right - left);
                left ++;

            } else {
                right --;
            }
        }


        return count;
        
    }
};


//TC=(log N), sc=O(1)