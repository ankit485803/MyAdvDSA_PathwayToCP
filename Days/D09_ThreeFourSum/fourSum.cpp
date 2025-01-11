
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>


// qno 18.  https://leetcode.com/problems/4sum/



class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int tar) {
        vector<vector<int>> ans;
        int n = nums.size();

        // Sort the array to make the two-pointer technique possible-- O(nlogn)
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) { //O(n^3)
            // Skip duplicates for the first number
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            // Loop through the second number
            for (int j = i + 1; j < n; j++) {
                // Skip duplicates for the second number
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int p = j + 1, q = n - 1;

                // Use two-pointer technique to find the other two numbers
                while (p < q) {
                    long long sum = (long long)nums[i] + (long long)nums[j] +
                                    (long long)nums[p] + (long long)nums[q];

                    if (sum < tar) {
                        p++;  // Increase the sum by moving the left pointer
                    } else if (sum > tar) {
                        q--;  // Decrease the sum by moving the right pointer
                    } else {
                        // Found a valid quadruplet, add it to the result
                        ans.push_back({nums[i], nums[j], nums[p], nums[q]});

                        // Skip duplicates for the third number
                        while (p < q && nums[p] == nums[p + 1]) p++;
                        // Skip duplicates for the fourth number
                        while (p < q && nums[q] == nums[q - 1]) q--;

                        p++; q--;  // Move both pointers inward
                    }
                }
            }
        }

        return ans;
    }
};


// TC = O(nlogn + n^3) , SC = O(uniqueGroup)