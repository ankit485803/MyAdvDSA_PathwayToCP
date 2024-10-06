
// https://leetcode.com/problems/remove-element/description
// Qno = 27

// concept req = only Arrary
// approach Brute force

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();

        //initilizer
        int index = 0;
        for(int i=0; i<n; i++) {
            //when not equal, only print that numb
            if(nums[i]  != val) {
                nums[index] = nums[i];
                index ++; 
            }
            
        }
        return index;
    }
};

//time complex = O(n), space = O(1) using Brute force approach 
