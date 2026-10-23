

/*

23rd OCt 2026 (Friday)

qno 3644  https://leetcode.com/problems/maximum-k-to-sort-a-permutation/?envType=daily-question&envId=2026-10-23


*/

//Approach (Bits Observation )
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();

        int K = -1; //"1111111" (all bits set)

        for(int i = 0; i < n; i++) {
            if(nums[i] != i) {
                K = (K & nums[i]);
            }
        }

        return K == -1 ? 0 : K;
    }
};


class Solution {
    public int sortPermutation(int[] nums) {
        int n = nums.length;

        int K = -1; // all bits set (0xFFFFFFFF)

        for (int i = 0; i < n; i++) {
            if (nums[i] != i) {
                K &= nums[i];
            }
        }

        return K == -1 ? 0 : K;
    }
}