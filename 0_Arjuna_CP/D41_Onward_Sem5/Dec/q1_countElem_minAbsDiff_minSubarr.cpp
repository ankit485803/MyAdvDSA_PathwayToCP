


/*


1st Dec 2025 (Monday - firstDay of month and week) 


qno 3759  https://leetcode.com/problems/count-elements-with-at-least-k-greater-values/


3759. Count Elements With at Least K Greater Values
Medium

Companies
Hint
You are given an integer array nums of length n and an integer k.

An element in nums is said to be qualified if there exist at least k elements in the array that are strictly greater than it.

Return an integer denoting the total number of qualified elements in nums.

 

Example 1:

Input: nums = [3,1,2], k = 1

Output: 2

Explanation:

The elements 1 and 2 each have at least k = 1 element greater than themselves.
​​​​​​​No element is greater than 3. Therefore, the answer is 2.

Example 2:

Input: nums = [5,5,5], k = 2

Output: 0

Explanation:

Since all elements are equal to 5, no element is greater than the other. Therefore, the answer is 0.

 

Constraints:

1 <= n == nums.length <= 105
1 <= nums[i] <= 109
0 <= k < n


*/



class Solution {
public:
    int countElements(vector<int>& nums, int k) {  //myFirstApproach
        int n = nums.size();
        
        // Edge case: if all elements are the same
        if (nums[0] == nums[n-1]) {
            return 0;
        }

        sort(nums.begin(), nums.end());
        
        // Initialize a counter for qualified elements
        int count = 0;

        for (int i = 0; i < n; ++i) {
            // The number of elements greater than nums[i] is (n - i - 1)
            if (n - i - 1 >= k) {
                count++;
            }
        }
        
        return count;
    }
};






#include <algorithm>

class Solution {
public:
    int countElements(vector<int>& nums, int k) {  //tc=O(n logN), sc=O(1)
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int qualified = 0;
        for (int i = 0; i < n; i++) {
            int count = 0;
            int j = binarySearch(nums, nums[i]);

            // The number of elements strictly greater than nums[i] is (n - j)
            count = n - j;

            if (count >= k) {
                qualified++;
            }
        }

        return qualified;
    }

private:
    // Binary search to find the first index where elements are strictly greater than target
    int binarySearch(const vector<int>& arr, int target) {
        int left = 0, right = arr.size();

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left; 
    }
};






/*

qno  1200  https://leetcode.com/problems/minimum-absolute-difference/description/


1200. Minimum Absolute Difference
Easy
Topics

Companies
Hint
Given an array of distinct integers arr, find all pairs of elements with the minimum absolute difference of any two elements.

Return a list of pairs in ascending order(with respect to pairs), each pair [a, b] follows

a, b are from arr
a < b
b - a equals to the minimum absolute difference of any two elements in arr
 

Example 1:

Input: arr = [4,2,1,3]
Output: [[1,2],[2,3],[3,4]]
Explanation: The minimum absolute difference is 1. List all pairs with difference equal to 1 in ascending order.
Example 2:

Input: arr = [1,3,6,10,15]
Output: [[1,3]]
Example 3:

Input: arr = [3,8,-10,23,19,-4,-14,27]
Output: [[-14,-10],[19,23],[23,27]]
 

Constraints:

2 <= arr.length <= 105
-106 <= arr[i] <= 106


*/


class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {  //tc=O(n logN), sc=O(n) due ans vector
        sort(arr.begin(), arr.end()); 

        int minDiff = INT_MAX;
        vector<vector<int>> ans;

        for (int i = 1; i < arr.size(); ++i) {
            int diff = arr[i] - arr[i - 1];
            if (diff < minDiff) {
                // Found a new minimum difference
                minDiff = diff;
                ans.clear();  
                ans.push_back({arr[i - 1], arr[i]});
            } else if (diff == minDiff) {
                // Same as the current minimum, so add this pair
                ans.push_back({arr[i - 1], arr[i]});
            }
        }

        return ans;
    }
};






#include <list>
#include <algorithm>
#include <climits>
class Solution {  //using list same tc, sc
public:
    list<list<int>> minimumAbsDifference(list<int>& arr) {
        // Convert list to vector to use sort (since list does not support random access)
        list<int> sortedArr(arr);
        sortedArr.sort();

        int minDiff = INT_MAX;
        list<list<int>> result;

        // Find the minimum absolute difference by checking adjacent elements
        auto it = sortedArr.begin();
        auto nextIt = ++sortedArr.begin();

        for (; nextIt != sortedArr.end(); ++it, ++nextIt) {
            int diff = *nextIt - *it;
            if (diff < minDiff) {
                // Found a new minimum difference
                minDiff = diff;
                result.clear();  // Clear the previous pairs
                result.push_back({*it, *nextIt});
            } else if (diff == minDiff) {
                // Same as the current minimum, so add this pair
                result.push_back({*it, *nextIt});
            }
        }

        return result;
    }
};



/*


qno 1608  https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/


Code
Testcase
Testcase
Test Result
1608. Special Array With X Elements Greater Than or Equal X
Attempted
Easy
Topics

Companies
Hint
You are given an array nums of non-negative integers. nums is considered special if there exists a number x such that there are exactly x numbers in nums that are greater than or equal to x.

Notice that x does not have to be an element in nums.

Return x if the array is special, otherwise, return -1. It can be proven that if nums is special, the value for x is unique.

 

Example 1:

Input: nums = [3,5]
Output: 2
Explanation: There are 2 values (3 and 5) that are greater than or equal to 2.
Example 2:

Input: nums = [0,0]
Output: -1
Explanation: No numbers fit the criteria for x.
If x = 0, there should be 0 numbers >= x, but there are 2.
If x = 1, there should be 1 number >= x, but there are 0.
If x = 2, there should be 2 numbers >= x, but there are 0.
x cannot be greater since there are only 2 numbers in nums.
Example 3:

Input: nums = [0,4,3,0,4]
Output: 3
Explanation: There are 3 values that are greater than or equal to 3.
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 1000



*/



class Solution {
public:
    int specialArray(vector<int>& nums) { //tc=O(n logN), sc=O(1)
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int x = 1; x <= n; ++x) {
            // Count how many elements are >= x
            int count = 0;
            for (int num : nums) {
                if (num >= x) {
                    count++;
                }
            }
            // If count is exactly x, return x
            if (count == x) {
                return x;
            }
        }
        
        return -1;
    }
};





/*


qno  1590  https://leetcode.com/problems/make-sum-divisible-by-p/description/


1590. Make Sum Divisible by P
Medium
Topics

Companies
Hint
Given an array of positive integers nums, remove the smallest subarray (possibly empty) such that the sum of the remaining elements is divisible by p. It is not allowed to remove the whole array.

Return the length of the smallest subarray that you need to remove, or -1 if it's impossible.

A subarray is defined as a contiguous block of elements in the array.

 

Example 1:

Input: nums = [3,1,4,2], p = 6
Output: 1
Explanation: The sum of the elements in nums is 10, which is not divisible by 6. We can remove the subarray [4], and the sum of the remaining elements is 6, which is divisible by 6.
Example 2:

Input: nums = [6,3,5,2], p = 9
Output: 2
Explanation: We cannot remove a single element to get a sum divisible by 9. The best way is to remove the subarray [5,2], leaving us with [6,3] with sum 9.
Example 3:

Input: nums = [1,2,3], p = 3
Output: 0
Explanation: Here the sum is 6. which is already divisible by 3. Thus we do not need to remove anything.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109
1 <= p <= 109


*/



class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {  //tc=O(n)=sc
        int n = nums.size();
        long long sum = 0;

        // Calculate the sum of all elements and take % p
        for (int num : nums) {
            sum = (sum + num) % p;
        }

        int target = sum % p;
        if (target == 0) {
            return 0;
        }

        unordered_map<int, int> map;
        map[0] = -1; 
        
        long long curr = 0;
        int result = n;
        for (int j = 0; j < n; ++j) {
            curr = (curr + nums[j]) % p;

            // Calculate the remainder needed to achieve the target
            int remain = (curr - target + p) % p;
            
            // If the required remainder exists in the map, update the result
            if (map.count(remain)) {
                result = min(result, j - map[remain]);
            }
            
            // Store the current remainder with its index
            map[curr] = j;
        }

        return result == n ? -1 : result;
    }
};
