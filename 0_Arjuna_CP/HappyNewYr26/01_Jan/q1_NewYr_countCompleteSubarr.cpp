




/*

1st Jan 2026 (Thursday - HappyNewYear 2026)



qno 3095  https://leetcode.com/problems/shortest-subarray-with-or-at-least-k-i/ 



3095. Shortest Subarray With OR at Least K I
Easy
Topics

Companies
Hint
You are given an array nums of non-negative integers and an integer k.

An array is called special if the bitwise OR of all of its elements is at least k.

Return the length of the shortest special non-empty subarray of nums, or return -1 if no special subarray exists.

 

Example 1:

Input: nums = [1,2,3], k = 2

Output: 1

Explanation:

The subarray [3] has OR value of 3. Hence, we return 1.

Note that [2] is also a special subarray.

Example 2:

Input: nums = [2,1,8], k = 10

Output: 3

Explanation:

The subarray [2,1,8] has OR value of 11. Hence, we return 3.

Example 3:

Input: nums = [1,2], k = 0

Output: 1

Explanation:

The subarray [1] has OR value of 1. Hence, we return 1.

 

Constraints:

1 <= nums.length <= 50
0 <= nums[i] <= 50
0 <= k < 64 



*/


class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {  
        int n = nums.size();
        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {
            int currOR = 0;
            for (int j = i; j < n; j++) {
                currOR |= nums[j];
                if (currOR >= k) {
                    ans = min(ans, j - i + 1);
                    break; // no need to extend further
                }
            }
        }

        //return (ans == INT_MAX) ? -1 : ans;
        if(ans == INT_MAX) {
            return -1;
        } else {
            return ans;
        }
    }
};




/*


qno 2799  https://leetcode.com/problems/count-complete-subarrays-in-an-array/



2799. Count Complete Subarrays in an Array
Solved
Medium
Topics

Companies
Hint
You are given an array nums consisting of positive integers.

We call a subarray of an array complete if the following condition is satisfied:

The number of distinct elements in the subarray is equal to the number of distinct elements in the whole array.
Return the number of complete subarrays.

A subarray is a contiguous non-empty part of an array.

 

Example 1:

Input: nums = [1,3,1,2,2]
Output: 4
Explanation: The complete subarrays are the following: [1,3,1,2], [1,3,1,2,2], [3,1,2] and [3,1,2,2].
Example 2:

Input: nums = [5,5,5,5]
Output: 10
Explanation: The array consists only of the integer 5, so any subarray is complete. The number of subarrays that we can choose is 10.
 

Constraints:

1 <= nums.length <= 1000
1 <= nums[i] <= 2000


*/




class Solution {
public:
    
    // Step 1: Helper function to count distinct elements in a subarray
    int countDistinct(int start, int end, vector<int>& nums) {
        unordered_set<int> st;
        for (int i = start; i <= end; i++) {
            st.insert(nums[i]);
        }
        return st.size();
    }
    
    int countCompleteSubarrays(vector<int>& nums) {   //tc=O(n^3)
        int n = nums.size();
        
        // Count distinct elements in the whole array
        unordered_set<int> totalSet(nums.begin(), nums.end());
        int totalDistinct = totalSet.size();
        
        int count = 0;
        
        // Step 2: Generate all possible subarrays
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                
                // Step 3: Check if subarray is complete
                if (countDistinct(i, j, nums) == totalDistinct) {
                    count++;
                }
            }
        }
        
        return count;
    }
};




/*


qno 1985  https://leetcode.com/problems/find-the-kth-largest-integer-in-the-array/description/


1985. Find the Kth Largest Integer in the Array
Medium
Topics

Companies
Hint
You are given an array of strings nums and an integer k. Each string in nums represents an integer without leading zeros.

Return the string that represents the kth largest integer in nums.

Note: Duplicate numbers should be counted distinctly. For example, if nums is ["1","2","2"], "2" is the first largest integer, "2" is the second-largest integer, and "1" is the third-largest integer.

 

Example 1:

Input: nums = ["3","6","7","10"], k = 4
Output: "3"
Explanation:
The numbers in nums sorted in non-decreasing order are ["3","6","7","10"].
The 4th largest integer in nums is "3".
Example 2:

Input: nums = ["2","21","12","1"], k = 3
Output: "2"
Explanation:
The numbers in nums sorted in non-decreasing order are ["1","2","12","21"].
The 3rd largest integer in nums is "2".
Example 3:

Input: nums = ["0","0"], k = 2
Output: "0"
Explanation:
The numbers in nums sorted in non-decreasing order are ["0","0"].
The 2nd largest integer in nums is "0".
 

Constraints:

1 <= k <= nums.length <= 104
1 <= nums[i].length <= 100
nums[i] consists of only digits.
nums[i] will not have any leading zeros


*/


class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        
        sort(nums.begin(), nums.end(), [](const string &a, const string &b) {
            if (a.length() != b.length())
                return a.length() > b.length(); // longer = larger
            return a > b; // lexicographically larger
        });
        
        return nums[k - 1];
    }
};
