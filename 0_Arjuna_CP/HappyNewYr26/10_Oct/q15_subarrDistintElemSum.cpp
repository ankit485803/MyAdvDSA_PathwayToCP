
/*

15th OCt 2026 (Thursday)

qno 2913  https://leetcode.com/problems/subarrays-distinct-element-sum-of-squares-i/description/?envType=daily-question&envId=2026-10-15


*/


class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        
        for (int i = 0; i < n; ++i) {
            unordered_set<int> s;
            for (int j = i; j < n; ++j) {
                s.insert(nums[j]);
                int d = s.size();
                res += d * d;
            }
        }
        return res;
    }
};