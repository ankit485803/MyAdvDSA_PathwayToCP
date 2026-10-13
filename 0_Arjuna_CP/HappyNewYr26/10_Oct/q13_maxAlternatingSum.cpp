

/*

13th Oct 2026 (Tuesday)

qno 3727  https://leetcode.com/problems/maximum-alternating-sum-of-squares/?envType=daily-question&envId=2026-10-13

*/

//Approach-1 (Square and sort and pick larger and smaller)
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i < n; i++ ){
            nums[i] = nums[i]*nums[i];
        }

        sort(begin(nums), end(nums));

        long long largeHalf = accumulate(begin(nums)+n/2, end(nums), 0LL);
        long long smallHalf = accumulate(begin(nums), begin(nums)+n/2, 0LL);

        return largeHalf - smallHalf;
    }
};
