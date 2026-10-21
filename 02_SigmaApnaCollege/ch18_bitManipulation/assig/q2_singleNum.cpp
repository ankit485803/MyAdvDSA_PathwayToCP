

/*

21st Oct 2026 (Wednesday)


probNo 136  https://leetcode.com/problems/single-number/description/

Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.You must implement a solution with a linear runtime complexity and use only constant extra space.
*/


class Solution {
public:
    int singleNumber(vector<int>& nums) { //tc=O(n), sc=O(1)
        int ans = 0;

        //prop of bitwise XOR operator: A^A = 0, A^0=1

        for(int num : nums) {
            ans = ans ^ num;
            //ans ^= num;
        }

        return ans; 
    }
};