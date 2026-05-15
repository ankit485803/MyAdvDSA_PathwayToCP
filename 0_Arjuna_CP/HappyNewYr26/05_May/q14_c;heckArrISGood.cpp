

/*

14th May 2026 (Thursday)


qno 2784  https://leetcode.com/problems/check-if-array-is-good/description/?envType=daily-question&envId=2026-05-14
alreadySolved on 18th Jan 2026

2784. Check if Array is Good
Solved
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
 
Discover more
LeetCode Premium Access
Seen this question in a real interview before?
1/6
Yes
No
Accepted
113,540/210.1K
Acceptance Rate
54.0%
Topics
Mid Level
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



//Approach-1 (Using frequency count)
//T.C : O(n) 
//S.C : O(n)
class Solution {
public:
    bool isGood(vector<int>& nums) {
        int maxEl = *max_element(begin(nums), end(nums));

        if(nums.size() != maxEl+1)
            return false;

        vector<int> count(maxEl+1, 0);

        for(int i = 0; i < nums.size(); i++) {
            count[nums[i]]++;

            if(nums[i] != maxEl && count[nums[i]] > 1)
                return false;
            else if(nums[i] == maxEl && count[nums[i]] > 2)
                return false;
        }

        return true;
    }
};

//Approach-2 (Sorting)
//T.C : O(n*logn) 
//S.C : O(1)
class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums), end(nums));

        for(int i = 0; i <= n-2; i++) {
            if(nums[i] != i+1)
                return false;
        }

        return nums[n-1] == n-1;
    }
};

//Approach-3 (Marking visited indices - O(1) space)
//T.C : O(n) 
//S.C : O(1)
class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();

        int maxEl = n-1;

        int maxElCount = 0;

        for(int num : nums) {
            int val = abs(num);

            if(val > maxEl) {
                return false;
            } else if(val == maxEl) {
                maxElCount++;
            }

            if(nums[val] < 0) {
                if(val != maxEl) {
                    return false;
                } else if(maxElCount > 2) {
                    return false;
                }
            } else {
                nums[val] *= -1;
            }
        }

        return true;
    }
};