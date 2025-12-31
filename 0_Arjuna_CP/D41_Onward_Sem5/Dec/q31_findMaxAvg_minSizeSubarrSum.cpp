



/*


31st Dec 2025 (Wednesday - lastDayOfThisYr & ResearchKart finalProductDelievey)



qno 643  https://leetcode.com/problems/maximum-average-subarray-i/description/




643. Maximum Average Subarray I
Easy
Topics

Companies
You are given an integer array nums consisting of n elements, and an integer k.

Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.

 

Example 1:

Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75000
Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75
Example 2:

Input: nums = [5], k = 1
Output: 5.00000
 

Constraints:

n == nums.length
1 <= k <= n <= 105
-104 <= nums[i] <= 104



*/


class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i = 0;  // Start index of the window
        int j = 0;  

        double maxAvg = -DBL_MAX;  // Initialize maxAvg with a very small value
        double currSum = 0;  

        while (j < nums.size()) {
            currSum += nums[j];  

            // If the window size is less than k, expand the window
            if (j - i + 1 < k) {
                j++;
            } else {
                // When the window size becomes equal to k, calculate the average
                maxAvg = max(maxAvg, currSum / k);
                currSum -= nums[i];
                i++;  
                j++;  
            }
        }

        return maxAvg;
    }
};




/*

qno 2090  https://leetcode.com/problems/k-radius-subarray-averages/description/


2090. K Radius Subarray Averages
Medium
Topics

Companies
Hint
You are given a 0-indexed array nums of n integers, and an integer k.

The k-radius average for a subarray of nums centered at some index i with the radius k is the average of all elements in nums between the indices i - k and i + k (inclusive). If there are less than k elements before or after the index i, then the k-radius average is -1.

Build and return an array avgs of length n where avgs[i] is the k-radius average for the subarray centered at index i.

The average of x elements is the sum of the x elements divided by x, using integer division. The integer division truncates toward zero, which means losing its fractional part.

For example, the average of four elements 2, 3, 1, and 5 is (2 + 3 + 1 + 5) / 4 = 11 / 4 = 2.75, which truncates to 2.
 

Example 1:


Input: nums = [7,4,3,9,1,8,5,2,6], k = 3
Output: [-1,-1,-1,5,4,4,-1,-1,-1]
Explanation:
- avg[0], avg[1], and avg[2] are -1 because there are less than k elements before each index.
- The sum of the subarray centered at index 3 with radius 3 is: 7 + 4 + 3 + 9 + 1 + 8 + 5 = 37.
  Using integer division, avg[3] = 37 / 7 = 5.
- For the subarray centered at index 4, avg[4] = (4 + 3 + 9 + 1 + 8 + 5 + 2) / 7 = 4.
- For the subarray centered at index 5, avg[5] = (3 + 9 + 1 + 8 + 5 + 2 + 6) / 7 = 4.
- avg[6], avg[7], and avg[8] are -1 because there are less than k elements after each index.
Example 2:

Input: nums = [100000], k = 0
Output: [100000]
Explanation:
- The sum of the subarray centered at index 0 with radius 0 is: 100000.
  avg[0] = 100000 / 1 = 100000.
Example 3:

Input: nums = [8], k = 100000
Output: [-1]
Explanation: 
- avg[0] is -1 because there are less than k elements before and after index 0.
 

Constraints:

n == nums.length
1 <= n <= 105
0 <= nums[i], k <= 105


*/


class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {  //tc=O(n), sc=O(1)
        int n = nums.size();
        vector<int> avgs(n, -1);

        // Special case
        if (k == 0) return nums;

        int windowSize = 2 * k + 1;
        if (windowSize > n) return avgs;

        long long windowSum = 0;

        // First window
        for (int i = 0; i < windowSize; i++) {
            windowSum += nums[i];
        }

        // Center of first window is index k
        avgs[k] = windowSum / windowSize;

        // Slide the window
        for (int i = windowSize; i < n; i++) {
            windowSum += nums[i];
            windowSum -= nums[i - windowSize];

            int center = i - k;
            avgs[center] = windowSum / windowSize;
        }

        return avgs;
    }
};





/*


qno 209  https://leetcode.com/problems/minimum-size-subarray-sum/



209. Minimum Size Subarray Sum
Medium
Topics

Companies
Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

 

Example 1:

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
Example 2:

Input: target = 4, nums = [1,4,4]
Output: 1
Example 3:

Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0
 

Constraints:

1 <= target <= 109
1 <= nums.length <= 105
1 <= nums[i] <= 104
 

Follow up: If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log(n)).



*/



class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {   //approach1: sliddingWindow tc=O(n), sc=O(1)
        int left = 0;
        int sum = 0;
        int minLen = INT_MAX;

        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];

            while (sum >= target) {
                minLen = min(minLen, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }

        return minLen == INT_MAX ? 0 : minLen;
    }
};


//appraoch2: binarySearch prefixSum




class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        int minLen = INT_MAX;

        for (int i = 0; i < n; i++) {
            int required = target + prefix[i];
            auto it = lower_bound(prefix.begin(), prefix.end(), required);

            if (it != prefix.end()) {
                int j = it - prefix.begin();
                minLen = min(minLen, j - i);
            }
        }

        return minLen == INT_MAX ? 0 : minLen;
    }
};




/*


qno 3364  https://leetcode.com/problems/minimum-positive-sum-subarray/description/


3364. Minimum Positive Sum Subarray 
Easy
Topics

Companies
Hint
You are given an integer array nums and two integers l and r. Your task is to find the minimum sum of a subarray whose size is between l and r (inclusive) and whose sum is greater than 0.

Return the minimum sum of such a subarray. If no such subarray exists, return -1.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [3, -2, 1, 4], l = 2, r = 3

Output: 1

Explanation:

The subarrays of length between l = 2 and r = 3 where the sum is greater than 0 are:

[3, -2] with a sum of 1
[1, 4] with a sum of 5
[3, -2, 1] with a sum of 2
[-2, 1, 4] with a sum of 3
Out of these, the subarray [3, -2] has a sum of 1, which is the smallest positive sum. Hence, the answer is 1.

Example 2:

Input: nums = [-2, 2, -3, 1], l = 2, r = 3

Output: -1

Explanation:

There is no subarray of length between l and r that has a sum greater than 0. So, the answer is -1.

Example 3:

Input: nums = [1, 2, 3, 4], l = 2, r = 4

Output: 3

Explanation:

The subarray [1, 2] has a length of 2 and the minimum sum greater than 0. So, the answer is 3.

 

Constraints:

1 <= nums.length <= 100
1 <= l <= r <= nums.length
-1000 <= nums[i] <= 1000



*/




class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);

        // Build prefix sum
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        int ans = INT_MAX;

        // Try all subarrays with length in [l, r]
        for (int i = 0; i < n; i++) {
            for (int len = l; len <= r; len++) {
                if (i + len > n) break;

                int sum = prefix[i + len] - prefix[i];
                if (sum > 0) {
                    ans = min(ans, sum);
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
