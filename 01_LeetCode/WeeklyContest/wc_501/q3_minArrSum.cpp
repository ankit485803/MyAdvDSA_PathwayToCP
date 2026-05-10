

/* probNo 3927  https://leetcode.com/problems/minimize-array-sum-using-divisible-replacements/description/

https://leetcode.com/contest/weekly-contest-501/problems/minimize-array-sum-using-divisible-replacements/


3927. Minimize Array Sum Using Divisible Replacements
Medium
premium lock icon
Companies
You are given an integer array nums.

You can perform the following operation any number of times:

Choose two indices a and b such that nums[a] % nums[b] == 0.
Replace nums[a] with nums[b].
Return the minimum possible sum of the array after performing any number of operations.

 

Example 1:

Input: nums = [3,6,2]

Output: 7

Explanation:

Choose a = 1, b = 2, where nums[a] = 6 and nums[b] = 2. Since 6 % 2 == 0, replace nums[1] with nums[2].
The array becomes [3, 2, 2].
No further operation reduces the sum. Thus, the final sum is 3 + 2 + 2 = 7.
Example 2:

Input: nums = [4,2,8,3]

Output: 9

Explanation:

Choose a = 0, b = 1, where nums[a] = 4 and nums[b] = 2. Since 4 % 2 == 0, replace nums[0] with nums[1].
Choose a = 2, b = 1, where nums[a] = 8 and nums[b] = 2. Since 8 % 2 == 0, replace nums[2] with nums[1].
The array becomes [2, 2, 2, 3].
No further operation reduces the sum. Thus, the final sum is 2 + 2 + 2 + 3 = 9.
Example 3:

Input: nums = [7,5,9]

Output: 21

Explanation:

There is no pair (a, b) such that nums[a] % nums[b] == 0.
Hence, no operation can be performed. The sum remains 7 + 5 + 9 = 21.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 10​​​​​​​5

*/


class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());

        int mn = *min_element(nums.begin(), nums.end());

        // If the minimum element exists,
        // every number divisible by it can become mn.
        long long ans = 0;

        for (int x : nums) {
            if (x % mn == 0)
                ans += mn;
            else
                ans += x;
        }

        return ans;
    }
};