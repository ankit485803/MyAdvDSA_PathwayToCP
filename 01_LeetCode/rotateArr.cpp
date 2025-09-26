


/*

24th Sep 2025 (Thursday - third day puja Maa Durja)

qno 189     https://leetcode.com/problems/rotate-array/



189. Rotate Array
Medium
Topics

Companies
Hint
Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

 

Example 1:
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]

Example 2:
Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
 

Constraints:
1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1
0 <= k <= 105
 

Follow up:
Try to come up with as many solutions as you can. There are at least three different ways to solve this problem.
Could you do it in-place with O(1) extra space?


*/




class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n; // handle k > n

        //this is ankit appracb simole  basic logic bachpan wala


        // Step 1: reverse entire array
        reverse(nums.begin(), nums.end());
        // Step 2: reverse first k elements
        reverse(nums.begin(), nums.begin() + k);
        // Step 3: reverse remaining elements
        reverse(nums.begin() + k, nums.end());
    }
};

//tc = O(N),  sc = O(1)



//approach2:  Extra Array (Simple but O(n) Space)




class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        vector<int> temp(n);

        for (int i = 0; i < n; i++) {
            temp[(i + k) % n] = nums[i];
        }

        nums = temp; // copy back
    }
};



//tc = O(N),  because one loop + copy back
// sc = O(N)  Extra Array (Simple but O(n) Space)



//approach3:  Cyclic Replacements (In-Place, O(1) Space)

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        int count = 0; // number of elements moved


        // Cyclic Redundancy Method - TC=O(n) (each element moved exactly once) and sc=O(1)

        for (int start = 0; count < n; start++) {
            int current = start;
            int prev = nums[start];

            do {
                int next = (current + k) % n;
                int temp = nums[next];
                nums[next] = prev;
                prev = temp;
                current = next;
                count++;
            } while (start != current);
        }
    }
};
