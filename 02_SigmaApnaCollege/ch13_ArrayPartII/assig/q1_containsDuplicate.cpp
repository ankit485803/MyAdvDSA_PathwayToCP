

/*

7th Sep 2026 (Monday)

Leetcode probNo 217  https://leetcode.com/problems/contains-duplicate/

217. Contains Duplicate
Solved
Easy
Topics

Companies
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

 

Example 1:

Input: nums = [1,2,3,1]

Output: true

Explanation:

The element 1 occurs at the indices 0 and 3.

Example 2:

Input: nums = [1,2,3,4]

Output: false

Explanation:

All elements are distinct.

Example 3:

Input: nums = [1,1,1,3,3,4,3,2,4,2]

Output: true

 

Constraints:

1 <= nums.length <= 105
-109 <= nums[i] <= 109
 

Seen this question in a real interview before?
1/6
Yes
No
Accepted
6,939,635/10.7M
Acceptance Rate
64.7%
Topics
Array
Hash Table
Sorting

*/



class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();

        //approach: twoPoiner tc=O(n), sc=O(1)
        int i = 0, j = n-1;

        int count = 0;
        while(i <= j) {
            if(nums[i] == nums[j]) {
                count++;
            }
            i++;
            j--;
        }

        //finalAns
        if(count >= 1) {
            return true;  //yes contain duplicate
        } else {
            return false;
        }
    }
};


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;  //sc = O(n) = sc using Hash Set

        for(int num : nums) {
            if(seen.count(num)) {
                return true;
            }
            seen.insert(num);
        }

        return false;
    }
};


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {  //using sorting tc=O(nLogN), sc=O(1)
        sort(nums.begin(), nums.end());

        for(int i=0; i<nums.size() -1; i++) {
            if(nums[i] == nums[i+1]) {
                return true;
            }
        }
        return false;
    }
};