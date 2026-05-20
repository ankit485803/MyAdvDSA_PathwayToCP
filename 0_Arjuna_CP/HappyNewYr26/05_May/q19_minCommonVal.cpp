

/*

19th May 2026 (Tuesday)

qno 2540  https://leetcode.com/problems/minimum-common-value/description/?envType=daily-question&envId=2026-05-19
already solved on 4th Nov 2025

Code
Testcase
Testcase
Test Result
2540. Minimum Common Value
Solved
Easy
Topics

Companies
Hint
Given two integer arrays nums1 and nums2, sorted in non-decreasing order, return the minimum integer common to both arrays. If there is no common integer amongst nums1 and nums2, return -1.

Note that an integer is said to be common to nums1 and nums2 if both arrays have at least one occurrence of that integer.

 

Example 1:

Input: nums1 = [1,2,3], nums2 = [2,4]
Output: 2
Explanation: The smallest element common to both arrays is 2, so we return 2.
Example 2:

Input: nums1 = [1,2,3,6], nums2 = [2,3,4,5]
Output: 2
Explanation: There are two common elements in the array 2 and 3 out of which 2 is the smallest, so 2 is returned.
 

Constraints:

1 <= nums1.length, nums2.length <= 105
1 <= nums1[i], nums2[j] <= 109
Both nums1 and nums2 are sorted in non-decreasing order.
 

Seen this question in a real interview before?
1/6
Yes
No
Accepted
341,751/579.9K
Acceptance Rate
58.9%
Topics
Mid Level
Array
Hash Table
Two Pointers
Binary Search
Biweekly Contest 96


*/



class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {  //TC=O(m+n), sc=O(1)
        int i = 0, j = 0;

        //twoPointerApproach
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                return nums1[i];  // Found the smallest common value
            }
            else if (nums1[i] < nums2[j]) {
                i++;  // Move forward in nums1
            }
            else {
                j++;  // Move forward in nums2
            }
        }

        return -1;  // No common element found
    }
};



//Approach-1 (Using set)
//T.C : O(m+n)
//S.C : O(m)
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st(begin(nums1), end(nums1));
        
        for(int &num : nums2) {
            if(st.find(num) != st.end()) {
                return num;
            }
        }
        
        return -1;
    }
};


//Approach-2 (Using Binary Search)
//T.C : O(mlogn)
//S.C : O(1)
class Solution {
public:
    bool binarySearch(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        
        while(l <= r) {
            int mid = l + (r-l)/2;
            
            if(nums[mid] == target) {
                return true;
            } else if(nums[mid] < target) {
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        
        return false;
    }
    
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        
        for(int &num : nums1) {
            if(binarySearch(nums2, num))
                return num;
        }
        
        return -1;
    }
};


//Approach-3 (Using 2 Pointer)
//T.C : O(m+n)
//S.C : O(1)
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        
        int i = 0; //for nums1
        int j = 0; //for nums2
        
        while(i < m && j < n) {
            if(nums1[i] == nums2[j]) {
                return nums1[i];
            } else if(nums1[i] < nums2[j]) {
                i++;
            } else {
                j++;
            }
        }
        
        return -1;
    }
};