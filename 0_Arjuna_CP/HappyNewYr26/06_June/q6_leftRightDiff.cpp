


/*

7th June 2026 (Saturday)


qno 2574  https://leetcode.com/problems/left-and-right-sum-differences/?envType=daily-question&envId=2026-06-07



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