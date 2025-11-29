


/*


29th Nov 2025 (Satursday)


qno 3381  https://leetcode.com/problems/maximum-subarray-sum-with-length-divisible-by-k/


3381. Maximum Subarray Sum With Length Divisible by K
Medium
Topics

Companies
Hint
You are given an array of integers nums and an integer k.

Return the maximum sum of a subarray of nums, such that the size of the subarray is divisible by k.

 

Example 1:

Input: nums = [1,2], k = 1

Output: 3

Explanation:

The subarray [1, 2] with sum 3 has length equal to 2 which is divisible by 1.

Example 2:

Input: nums = [-1,-2,-3,-4,-5], k = 4

Output: -10

Explanation:

The maximum sum subarray is [-1, -2, -3, -4] which has length equal to 4 which is divisible by 4.

Example 3:

Input: nums = [-5,1,2,-3,4], k = 2

Output: 4

Explanation:

The maximum sum subarray is [1, 2, -3, 4] which has length equal to 4 which is divisible by 2.

 

Constraints:

1 <= k <= nums.length <= 2 * 105
-109 <= nums[i] <= 109


*/


class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        //myApproach bruteForce

        //step1: long long sum = 0;
        //sttep2: form subArr from nums
        //step3: check subArr.size() % k == 0; if yes return sum[subArr]
    }
};



class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        //myApproach - BruteForce which TLE error, tc=O(n^2), sc=O(1)
        long long maxSum = LLONG_MIN;
        int n = nums.size();

        //loopThrough all possible subArr
        for(int i=0; i<n; ++i) {
            long long currSum = 0;
            for(int j=i; j<n; ++j) {
                currSum += nums[j];
                
                //chek if the length of the subarray is divisible by k
                if((j - i +1) % k == 0) {
                    maxSum = max(maxSum, currSum);
                }            }
        }

        return maxSum;
    
    }
};



class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) { //tc=O(n)=sc
        int n = nums.size();

        // Step 1: Build the prefix sum array
        vector<long long> prefSum(n);
        prefSum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefSum[i] = prefSum[i - 1] + nums[i];
        }

        long long ans = LLONG_MIN; 

        // Step 2: Iterate through all possible subarray starts (up to index k-1)
        for (int start = 0; start < k; start++) {
            long long currSum = 0;

            // Step 3: For each start, move i in steps of k to get subarrays of length k
            int i = start;
            while (i < n && i + k - 1 < n) {
                int j = i + k - 1;

                // Step 4: Calculate the sum of the current subarray
                long long subSum = prefSum[j] - (i > 0 ? prefSum[i - 1] : 0);

                // Step 5: Apply Kadane's algorithm to maximize the sum 
                currSum = max(subSum, currSum + subSum);
                ans = max(ans, currSum);

                i += k;  // Move i in steps of k to ensure subarrays of length divisible by k
            }
        }

        return ans;  
    }
};
