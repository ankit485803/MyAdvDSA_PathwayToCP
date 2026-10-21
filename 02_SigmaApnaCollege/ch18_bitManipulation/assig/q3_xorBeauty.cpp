

/*

leetcode probNo 2527  https://leetcode.com/problems/find-xor-beauty-of-array/description/

You are given a 0-indexed integer array nums.
The effective value of three indices i, j, and k is defined as ((nums[i] | nums[j]) & nums[k]).

The xor-beauty of the array is the XORing of the effective values of all the possible triplets of indices (i, j, k) where 0 <= i, j, k < n.

Return the xor-beauty of nums.





The important result is that the XOR of all triplets simplifies to the XOR of every element in nums:
xorBeauty = num[0] ^ num[1] ^ num[2] ..... num[n-1]


*/

class Solution {
public:
    int xorBeauty(vector<int>& nums) {
        //after maths calculation: xorBeauty = num[0] ^ num[1] ^ num[2] ..... num[n-1]

        int ans = 0;
        for(int num : nums) {  //tc=O(n), sc=O(1)
            ans = ans ^ num;
        }
        return ans;
    }
};