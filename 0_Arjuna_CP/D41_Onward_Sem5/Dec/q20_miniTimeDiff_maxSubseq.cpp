



/*


20th Dec 2025 (Satursday)


qno 539  https://leetcode.com/problems/minimum-time-difference/description/


539. Minimum Time Difference
Medium
Topics

Companies
Given a list of 24-hour clock time points in "HH:MM" format, return the minimum minutes difference between any two time-points in the list.
 

Example 1:

Input: timePoints = ["23:59","00:00"]
Output: 1
Example 2:

Input: timePoints = ["00:00","23:59","00:00"]
Output: 0
 

Constraints:

2 <= timePoints.length <= 2 * 104
timePoints[i] is in the format "HH:MM".



*/



class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        //step1: convert hr to min

        //step2: sortArr

        //step3: calculate AdjacementDiff
        
    }
};




#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> times;
        
        // Step1: Convert hr to min
        for (const string& time : timePoints) {
            int hours = stoi(time.substr(0, 2));
            int minutes = stoi(time.substr(3, 2));
            times.push_back(hours * 60 + minutes);
        }
        
        // Step2: sort
        sort(times.begin(), times.end());
        
        // Step3: calculate mintDiff
        int minDiff = INT_MAX;
        for (int i = 1; i < times.size(); ++i) {
            minDiff = min(minDiff, times[i] - times[i - 1]);
        }
        
        // Check the diff b/w first and the last time point, considering 1440-minute wraparound
        minDiff = min(minDiff, 1440 + times[0] - times.back());
        
        return minDiff;
    }
};






/*


qno 2099  https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/description/



2099. Find Subsequence of Length K With the Largest Sum
Easy
Topics

Companies
Hint
You are given an integer array nums and an integer k. You want to find a subsequence of nums of length k that has the largest sum.

Return any such subsequence as an integer array of length k.

A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

 

Example 1:

Input: nums = [2,1,3,3], k = 2
Output: [3,3]
Explanation:
The subsequence has the largest sum of 3 + 3 = 6.
Example 2:

Input: nums = [-1,-2,3,4], k = 3
Output: [-1,3,4]
Explanation: 
The subsequence has the largest sum of -1 + 3 + 4 = 6.
Example 3:

Input: nums = [3,4,3,3], k = 2
Output: [3,4]
Explanation:
The subsequence has the largest sum of 3 + 4 = 7. 
Another possible subsequence is [4, 3].
 

Constraints:

1 <= nums.length <= 1000
-105 <= nums[i] <= 105
1 <= k <= nums.length



*/



class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {  //tc=O(nlogN), sc=O(n)
        int n = nums.size();
        
        // Step1: Create a vector of pairs (value, index)
        vector<pair<int, int>> indexed_nums;
        for (int i = 0; i < n; ++i) {
            indexed_nums.push_back({nums[i], i});
        }
        
        // Step2: Sort the pairs by value in descending order
        sort(indexed_nums.begin(), indexed_nums.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first;
        });
        
        // Step3: Select first k elements and store their indices
        vector<int> result;
        vector<int> indices;
        for (int i = 0; i < k; ++i) {
            indices.push_back(indexed_nums[i].second);
        }
        
        // Step4: Sort indices in ascending order to maintain originalOrder
        sort(indices.begin(), indices.end());
        
        // Step5: buildResult 
        for (int i = 0; i < k; ++i) {
            result.push_back(nums[indices[i]]);
        }
        
        return result;
    }
};
