


/*

6th June 2026 (Saturday)


qno 2574  https://leetcode.com/problems/left-and-right-sum-differences/?envType=daily-question&envId=2026-06-07

2574. Left and Right Sum Differences
Solved
Easy
Topics

Companies
Hint
You are given a 0-indexed integer array nums of size n.

Define two arrays leftSum and rightSum where:

leftSum[i] is the sum of elements to the left of the index i in the array nums. If there is no such element, leftSum[i] = 0.
rightSum[i] is the sum of elements to the right of the index i in the array nums. If there is no such element, rightSum[i] = 0.
Return an integer array answer of size n where answer[i] = |leftSum[i] - rightSum[i]|.

 

Example 1:

Input: nums = [10,4,8,3]
Output: [15,1,11,22]
Explanation: The array leftSum is [0,10,14,22] and the array rightSum is [15,11,3,0].
The array answer is [|0 - 15|,|10 - 11|,|14 - 3|,|22 - 0|] = [15,1,11,22].
Example 2:

Input: nums = [1]
Output: [0]
Explanation: The array leftSum is [0] and the array rightSum is [0].
The array answer is [|0 - 0|] = [0].
 

Constraints:

1 <= nums.length <= 1000
1 <= nums[i] <= 105
 
Seen this question in a real interview before?
1/6
Yes
No
Accepted
346,007/386.7K
Acceptance Rate
89.5%
Topics
Mid Level
Array
Prefix Sum
Weekly Contest 334

*/


class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) { //TC=O(n), SC=O(1)
        int n = nums.size();

        // everyElem initialized to 0 and size n
        vector<int> left(n, 0), right(n, 0), ans(n);

        //build leftSum
        for(int i=1; i<n; i++) {
            left[i] = left[i-1] + nums[i-1];
        }
        //build rightSum
        for(int i=n-2; i>=0; i--) {
            right[i] = right[i+1] + nums[i+1];
        }


        //final ans build
        for(int i=0; i<n; i++) {
            ans[i] = abs(left[i] - right[i]);
        }

        return ans;
    }
};



class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {  // tc=O(n)=sc bruteForce   WRONG
        int n = nums.size();
        vector<int> ans(n);  //take arr with n sized

        //step1: leftSum
        int leftSum = 0;
        for(int i=0; i<n; i++) {
            leftSum += 
        }

        //step2: rightSum
        int rightSum = 0;
        for()

        //final
        ans.push_back(abs(leftSum - rightSum));
        
        return ans;

    }
};



class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {  //tc=O(n^2), sc=O(1) bruteForce
        int n = nums.size();
        vector<int> ans(n);  //take arr with n sized

        for(int i=0; i<n; i++) {
            int leftSum = 0, rightSum = 0;

            //leftSide
            for(int j=0; j < i; j++) {
                leftSum += nums[j];
            }

            //rightSide
            for(int j = i+1; j<n; j++) {
                rightSum += nums[j];
            }

            ans[i] = abs(leftSum - rightSum);
        }

        return ans;

    }
};