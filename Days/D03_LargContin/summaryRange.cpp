
// https://leetcode.com/problems/summary-ranges/description/
// No= 228

// concept req = Arrary

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ranges;
        if (nums.empty()) return ranges;

        int n = nums.size();
        int start = nums[0];

        for (int i = 0; i < n; i++) {
            // Check if it's the last element or if the next element is not consecutive
            if (i == n - 1 || nums[i] + 1 != nums[i + 1]) {
                // If start equals current number, it's a single number
                if (start == nums[i]) {
                    ranges.push_back(to_string(start));
                } else {
                    ranges.push_back(to_string(start) + "->" + to_string(nums[i]));
                }

                
                // Update start for the next potential range
                if (i < n - 1) {
                    start = nums[i + 1];
                }
            }
        }
        return ranges;
    }
};

