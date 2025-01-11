
// Qno 31   https://leetcode.com/problems/next-permutation/submissions

#include <iostream>
#include <vector>
using namespace std;
//yah algo to add karo
#include <algorithm>



class Solution {
    void nextPermutation(vector<int>& nums) {
        int index = -1;
        int n = nums.size() - 2;
        
        // Step 1: Find the first decreasing element from the right
        for (int i = n; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                index = i;
                break;
            }
        }
        
        // Step 2: If no such element exists, reverse the array
        if (index == -1) {
            reverse(nums.begin(), nums.end());
        } else {
            // Step 3: Find the smallest element larger than nums[index] and swap
            for (int i = nums.size() - 1; i > index; i--) {
                if (nums[i] > nums[index]) {
                    swap(nums[i], nums[index]);
                    break;
                }
            }
            // Step 4: Reverse the elements after the index
            reverse(nums.begin() + index + 1, nums.end());
        }
    }
};


// time complex =  O(n), space = O(1)

