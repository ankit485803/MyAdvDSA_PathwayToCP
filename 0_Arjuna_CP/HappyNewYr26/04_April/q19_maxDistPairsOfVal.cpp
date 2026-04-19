

/*

19th April 2026 (Sunday)


qno 1855  https://leetcode.com/problems/maximum-distance-between-a-pair-of-values/?envType=daily-question&envId=2026-04-19

1855. Maximum Distance Between a Pair of Values
Solved
Medium
Topics

Companies
Hint
You are given two non-increasing 0-indexed integer arrays nums1​​​​​​ and nums2​​​​​​.

A pair of indices (i, j), where 0 <= i < nums1.length and 0 <= j < nums2.length, is valid if both i <= j and nums1[i] <= nums2[j]. The distance of the pair is j - i​​​​.

Return the maximum distance of any valid pair (i, j). If there are no valid pairs, return 0.

An array arr is non-increasing if arr[i-1] >= arr[i] for every 1 <= i < arr.length.

 

Example 1:

Input: nums1 = [55,30,5,4,2], nums2 = [100,20,10,10,5]
Output: 2
Explanation: The valid pairs are (0,0), (2,2), (2,3), (2,4), (3,3), (3,4), and (4,4).
The maximum distance is 2 with pair (2,4).
Example 2:

Input: nums1 = [2,2,2], nums2 = [10,10,1]
Output: 1
Explanation: The valid pairs are (0,0), (0,1), and (1,1).
The maximum distance is 1 with pair (0,1).
Example 3:

Input: nums1 = [30,29,19,5], nums2 = [25,25,25,25,25]
Output: 2
Explanation: The valid pairs are (2,2), (2,3), (2,4), (3,3), and (3,4).
The maximum distance is 2 with pair (2,4).
 

Constraints:

1 <= nums1.length, nums2.length <= 105
1 <= nums1[i], nums2[j] <= 105
Both nums1 and nums2 are non-increasing.
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
108,892/185.6K
Acceptance Rate
58.7%
Topics
Senior
Array
Two Pointers
Binary Search
Weekly Contest 240


*/



class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {   //oldSubmission 20th, 19th Dec 2025
        int maxDist = 0; 

        //twoPointer
        int i = 0;
        int j = 0;
        while(i < nums1.size() &&  j < nums2.size()) {
            if(nums1[i] <= nums2[j]) {
                int dist = j-i;
                maxDist = max(dist, maxDist);
                j++;
            } else {
                i++;
            }
        }

        return maxDist;
    }
};





class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {  //today submitted 19th April 2026
        int ans = 0;
        //takePointerApproach tc=O(n + m), sc=O(1)

        int i = 0, j = 0;

        while(i < nums1.size() && j < nums2.size()) {
            if(nums1[i] <= nums2[j] ) {  //validPair condition
                ans = max(ans, j - i);
                j++;  //try to maximize dist
            } else {
                i++;  //needSmaller nums1[i]
            }
        }

        return ans;
    }
};



class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {  //using BS tc=O(n logN) not faster then O(n + m)
        int ans = 0;

        for (int i = 0; i < nums1.size(); i++) {
            int left = i, right = nums2.size() - 1;
            int best = i - 1;

            while (left <= right) {
                int mid = left + (right - left) / 2;

                if (nums2[mid] >= nums1[i]) {
                    best = mid;
                    left = mid + 1;  // try farther
                } else {
                    right = mid - 1;
                }
            }

            ans = max(ans, best - i);
        }

        return ans;
    }
};