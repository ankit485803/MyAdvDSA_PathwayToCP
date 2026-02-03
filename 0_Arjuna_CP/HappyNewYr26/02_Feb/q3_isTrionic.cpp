


/*


3rd Feb 2026 (Tuesday)


qno 3637  https://leetcode.com/problems/trionic-array-i/?envType=daily-question&envId=2026-02-03

3637. Trionic Array I
Solved
Easy
Topics

Companies
Hint
You are given an integer array nums of length n.

An array is trionic if there exist indices 0 < p < q < n − 1 such that:

nums[0...p] is strictly increasing,
nums[p...q] is strictly decreasing,
nums[q...n − 1] is strictly increasing.
Return true if nums is trionic, otherwise return false.

 

Example 1:

Input: nums = [1,3,5,4,2,6]

Output: true

Explanation:

Pick p = 2, q = 4:

nums[0...2] = [1, 3, 5] is strictly increasing (1 < 3 < 5).
nums[2...4] = [5, 4, 2] is strictly decreasing (5 > 4 > 2).
nums[4...5] = [2, 6] is strictly increasing (2 < 6).
Example 2:

Input: nums = [2,1,3]

Output: false

Explanation:

There is no way to pick p and q to form the required three segments.

 

Constraints:

3 <= n <= 100
-1000 <= nums[i] <= 1000
 
Discover more
Trionic
LeetCode API access
Seen this question in a real interview before?
1/5
Yes
No
Accepted
113,543/234.9K
Acceptance Rate
48.3%
Topics
Mid Level
Array
Weekly Contest 461


*/


//Approach (Simply simulation)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();

        int i = 0;

        //Increasing
        while(i+1 < n && nums[i] < nums[i+1])
            i++;

        if(i == 0 || i == n-1)
            return false;
        
        //Decreasing
        while(i+1 < n && nums[i] > nums[i+1])
            i++;
        
        if(i == n-1)
            return false;
        
        //Increasing
        while(i+1 < n && nums[i] < nums[i+1])
            i++;
        

        return i == n-1;
    }
};
