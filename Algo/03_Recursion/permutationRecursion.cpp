


#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>


// qno   https://leetcode.com/problems/permutations/


class Solution {
public:

    void getPers(vector<int>& nums, int idx, vector<vector<int>>& ans) {
        if (idx == nums.size()) {
            ans.push_back(nums);  // Add the current permutation to the result
            return;
        }

        for (int i = idx; i < nums.size(); i++) {
            swap(nums[idx], nums[i]);  // Swap the current element with itself or others

            // Recurse to generate all permutations from the next index
            getPers(nums, idx + 1, ans);

            // Backtrack: Undo the swap
            swap(nums[idx], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        getPers(nums, 0, ans);  // Start recursion from the first index
        return ans;
    }
};


// TC = O(n !  *n) factorial time, SC = O(n!)