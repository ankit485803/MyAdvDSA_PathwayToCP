


/*



18th Jan 2026 (Sunday)


qno 2190   https://leetcode.com/problems/most-frequent-number-following-key-in-an-array/ 



2190. Most Frequent Number Following Key In an Array
Easy
Topics

Companies
Hint
You are given a 0-indexed integer array nums. You are also given an integer key, which is present in nums.

For every unique integer target in nums, count the number of times target immediately follows an occurrence of key in nums. In other words, count the number of indices i such that:

0 <= i <= nums.length - 2,
nums[i] == key and,
nums[i + 1] == target.
Return the target with the maximum count. The test cases will be generated such that the target with maximum count is unique.

 

Example 1:

Input: nums = [1,100,200,1,100], key = 1
Output: 100
Explanation: For target = 100, there are 2 occurrences at indices 1 and 4 which follow an occurrence of key.
No other integers follow an occurrence of key, so we return 100.
Example 2:

Input: nums = [2,2,2,2,3], key = 2
Output: 2
Explanation: For target = 2, there are 3 occurrences at indices 1, 2, and 3 which follow an occurrence of key.
For target = 3, there is only one occurrence at index 4 which follows an occurrence of key.
target = 2 has the maximum number of occurrences following an occurrence of key, so we return 2.
 

Constraints:

2 <= nums.length <= 1000
1 <= nums[i] <= 1000
The test cases will be generated such that the answer is unique.



*/



class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        unordered_map<int, int> freq;  //sc=O(n)
        int maxCount = 0;
        int ans = 0;

        for(int i=0; i<nums.size()-1; i++) {  //tc=O(n)
            if(nums[i] == key) {
                freq[nums[i+1]]++;

            }
            if(freq[nums[i+1]] > maxCount) {
                maxCount = freq[nums[i+1]];
                ans = nums[i+1];
            }
        }

        return ans;
    }
};




class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        vector<int> freq(1001, 0);
        int maxCount = 0;
        int result = 0;

        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == key) {
                freq[nums[i + 1]]++;
                if (freq[nums[i + 1]] > maxCount) {
                    maxCount = freq[nums[i + 1]];
                    result = nums[i + 1];
                }
            }
        }
        return result;
    }
};





/*

qno 2784    https://leetcode.com/problems/check-if-array-is-good/


2784. Check if Array is Good
Easy
Topics

Companies
Hint
You are given an integer array nums. We consider an array good if it is a permutation of an array base[n].

base[n] = [1, 2, ..., n - 1, n, n] (in other words, it is an array of length n + 1 which contains 1 to n - 1 exactly once, plus two occurrences of n). For example, base[1] = [1, 1] and base[3] = [1, 2, 3, 3].

Return true if the given array is good, otherwise return false.

Note: A permutation of integers represents an arrangement of these numbers.

 

Example 1:

Input: nums = [2, 1, 3]
Output: false
Explanation: Since the maximum element of the array is 3, the only candidate n for which this array could be a permutation of base[n], is n = 3. However, base[3] has four elements but array nums has three. Therefore, it can not be a permutation of base[3] = [1, 2, 3, 3]. So the answer is false.
Example 2:

Input: nums = [1, 3, 3, 2]
Output: true
Explanation: Since the maximum element of the array is 3, the only candidate n for which this array could be a permutation of base[n], is n = 3. It can be seen that nums is a permutation of base[3] = [1, 2, 3, 3] (by swapping the second and fourth elements in nums, we reach base[3]). Therefore, the answer is true.
Example 3:

Input: nums = [1, 1]
Output: true
Explanation: Since the maximum element of the array is 1, the only candidate n for which this array could be a permutation of base[n], is n = 1. It can be seen that nums is a permutation of base[1] = [1, 1]. Therefore, the answer is true.
Example 4:

Input: nums = [3, 4, 4, 1, 2, 1]
Output: false
Explanation: Since the maximum element of the array is 4, the only candidate n for which this array could be a permutation of base[n], is n = 4. However, base[4] has five elements but array nums has six. Therefore, it can not be a permutation of base[4] = [1, 2, 3, 4, 4]. So the answer is false.
 

Constraints:

1 <= nums.length <= 100
1 <= num[i] <= 200
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
63,220/129.9K
Acceptance Rate
48.7%
Topics
Array
Hash Table
Sorting
Biweekly Contest 109



*/



class Solution {
public:
    bool isGood(vector<int>& nums) {  //tc=O(n), sc=O(1)
        int maxElem = 0;
        for (int x : nums) {
            maxElem = max(maxElem, x);
        }

        // base[n] has length n + 1
        if (nums.size() != maxElem + 1)
            return false;

        vector<int> freq(201, 0);
        for (int x : nums) {
            freq[x]++;
        }

        // Check 1 to n-1 appear exactly once
        for (int i = 1; i < maxElem; i++) {
            if (freq[i] != 1)
                return false;
        }

        // Check n appears exactly twice
        if (freq[maxElem] != 2)
            return false;

        return true;
    }
};
