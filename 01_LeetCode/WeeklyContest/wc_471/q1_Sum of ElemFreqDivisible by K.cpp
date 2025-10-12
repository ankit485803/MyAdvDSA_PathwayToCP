


/*


12th Oct 2025 (Sunday)

qno  1 https://leetcode.com/contest/weekly-contest-471/problems/sum-of-elements-with-frequency-divisible-by-k/


Q1. Sum of Elements With Frequency Divisible by K
Easy
3 pt.
You are given an integer array nums and an integer k.
Return an integer denoting the sum of all elements in nums whose frequency is divisible by k, or 0 if there are no such elements.

Note: An element is included in the sum exactly as many times as it appears in the array if its total frequency is divisible by k.
The frequency of an element x is the number of times it occurs in the array.

 

Example 1:
Input: nums = [1,2,2,3,3,3,3,4], k = 2
Output: 16
Explanation:
The number 1 appears once (odd frequency).
The number 2 appears twice (even frequency).
The number 3 appears four times (even frequency).
The number 4 appears once (odd frequency).
So, the total sum is 2 + 2 + 3 + 3 + 3 + 3 = 16.

Example 2:
Input: nums = [1,2,3,4,5], k = 2
Output: 0
Explanation:
There are no elements that appear an even number of times, so the total sum is 0.

Example 3:
Input: nums = [4,4,4,1,2,3], k = 3
Output: 12
Explanation:
The number 1 appears once.
The number 2 appears once.
The number 3 appears once.
The number 4 appears three times.
So, the total sum is 4 + 4 + 4 = 12.

 

Constraints:
1 <= nums.length <= 100
1 <= nums[i] <= 100
1 <= k <= 100©leetcode





*/


#include <unordered_map>


class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int totalSum = 0;
        
        // Step 1: Calculate the frequency of each element
        for (int num : nums) {
            freq[num]++;
        }
        
        // Step 2: find the sum of elements whose frequency is divisible by k
        for (auto& entry : freq) {
            int num = entry.first;
            int count = entry.second;
            if (count % k == 0) {
                totalSum += num * count;  // add num * frequency to the total sum
            }
        }
        
        // Step 3: Return the result
        return totalSum;
    }
};



//TC=o(n) input size
// sc=O(n) for storing the frequency map.©leetcode