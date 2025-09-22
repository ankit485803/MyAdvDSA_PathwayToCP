


/*

22nd Sep 2025 (Monday - firstPuja Maa Durja) 

qno 153  https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/

 The key characteristic is that while the entire array isn't sorted, 
 there are still sorted portions within it, which allows for efficient searching and finding the minimum element

yah sorted hoga Ankit bhai jab waska position correct nahi ho in rotated SortedArr



*/



class Solution {
public:
    int findMin(vector<int>& nums) {
        int st = 0, end = nums.size() - 1;
        
        while (st < end) {
            int mid = st + (end - st) / 2;

            // If mid element is greater than rightmost, min is in right half
            if (nums[mid] > nums[end]) {
                st = mid + 1;
            } else {
                // Otherwise, min is in left half (including mid)
                end = mid;
            }
        }
        
        // At the end, st == end -> pointing to minimum
        return nums[st];
    }
};

//tc=O(log N), sc=O(1)c