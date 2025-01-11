

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

#include <unordered_map>

//  qno 560   https://leetcode.com/problems/subarray-sum-equals-k/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;

        // Iterate over all possible starting points
        for (int i = 0; i < n; i++) {
            int sum = 0;

            // Iterate over all possible ending points
            for (int j = i; j < n; j++) {
                sum += nums[j];  // Accumulate the sum for this subarray
                if (sum == k) count++;  // If the sum equals k, increment count
            }
        }

        return count;  // Return the result
    }
};


//method1: BruteForce apporach -- TC=O(n^2), SC = O(1)


class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int n = arr.size();
        int count = 0;
        
        // Prefix sum array
        vector<int> prefixSum(n, 0);

        // Initialize the prefix sum array
        prefixSum[0] = arr[0];
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + arr[i];
        }

        // Hash map to store frequency of prefix sums
        unordered_map<int, int> m;  // PS -> frequency of prefix sums
        for (int j = 0; j < n; j++) {
            // If the prefix sum itself equals k, it's a valid subarray
            if (prefixSum[j] == k) count++;

            // Check if there's a prefix sum that makes the subarray sum equal to k
            int val = prefixSum[j] - k;
            if (m.find(val) != m.end()) {
                count += m[val];  // Add the frequency of the required prefix sum
            }

            // Increment the frequency of the current prefix sum
            m[prefixSum[j]]++;
        }

        return count;
    }
};


//metho2: Hashng -- TC = O(n) , SC = O(n), time is more SC
