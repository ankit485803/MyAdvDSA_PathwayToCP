

/*

10th May 2026 (Sunday) 8 to 9:30 AM IST
https://leetcode.com/contest/weekly-contest-501/

probNO 3925  https://leetcode.com/problems/concatenate-array-with-reverse/description/


https://leetcode.com/contest/weekly-contest-501/problems/concatenate-array-with-reverse/

Q1. Concatenate Array With Reverse
Easy
3 pt.
You are given an integer array nums of length n.

Construct a new array ans of length 2 * n such that the first n elements are the same as nums, and the next n elements are the elements of nums in reverse order.

Formally, for 0 <= i <= n - 1:

ans[i] = nums[i]
ans[i + n] = nums[n - i - 1]
Return an integer array ans.

 

Example 1:

Input: nums = [1,2,3]

Output: [1,2,3,3,2,1]

Explanation:

The first n elements of ans are the same as nums.

For the next n = 3 elements, each element is taken from nums in reverse order:

ans[3] = nums[2] = 3
ans[4] = nums[1] = 2
ans[5] = nums[0] = 1
Thus, ans = [1, 2, 3, 3, 2, 1].

Example 2:

Input: nums = [1]

Output: [1,1]

Explanation:

The array remains the same when reversed. Thus, ans = [1, 1].

 

Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 100


*/


class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {  //tc=O(n), sc=O(1)
        int n = nums.size();
        vector<int> ans(2 * n);  //createArr size = 2*n, defaultVal 

        for(int i=0; i<n; i++) {
            //step1: set first n elem in sameOrder
            ans[i] = nums[i];

            //step2: next n elem in revOrder formula n-i-1
            ans[i + n] = nums[n - i - 1];
        }

        return ans;
        
    }    
};



class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(2 * n);

        // Copy original array
        for (int i = 0; i < n; i++) {
            ans[i] = nums[i];
        }

        // Append reversed array
        for (int i = 0; i < n; i++) {
            ans[i + n] = nums[n - i - 1];
        }

        return ans;
    }
};