
// src ques  https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

// req Concept: array  + Two pointer approach

#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int n = nums.size();
        // Handle the case for an empty array
        if (n == 0) return 0;

        int uniqueIndex = 0; // Pointer for the last unique element

        for (int i = 1; i < n; i++) { // Start from the second element
            // Check if the current element is different from the last unique element
            if (nums[i] != nums[uniqueIndex]) {
                uniqueIndex++; 
                nums[uniqueIndex] = nums[i]; // Update the value at the unique position
            }
        }

        return uniqueIndex + 1; // Return the length of unique elements
    }
};


// 2 pointer approach, time complexity = O(n), space = O(1)