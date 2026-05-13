

/*

13th May 2026 (Wednesday)


qno 1674  https://leetcode.com/problems/minimum-moves-to-make-array-complementary/?envType=daily-question&envId=2026-05-13

1674. Minimum Moves to Make Array Complementary
Attempted
Medium
Topics

Companies
Hint
You are given an integer array nums of even length n and an integer limit. In one move, you can replace any integer from nums with another integer between 1 and limit, inclusive.

The array nums is complementary if for all indices i (0-indexed), nums[i] + nums[n - 1 - i] equals the same number. For example, the array [1,2,3,4] is complementary because for all indices i, nums[i] + nums[n - 1 - i] = 5.

Return the minimum number of moves required to make nums complementary.

 

Example 1:

Input: nums = [1,2,4,3], limit = 4
Output: 1
Explanation: In 1 move, you can change nums to [1,2,2,3] (underlined elements are changed).
nums[0] + nums[3] = 1 + 3 = 4.
nums[1] + nums[2] = 2 + 2 = 4.
nums[2] + nums[1] = 2 + 2 = 4.
nums[3] + nums[0] = 3 + 1 = 4.
Therefore, nums[i] + nums[n-1-i] = 4 for every i, so nums is complementary.
Example 2:

Input: nums = [1,2,2,1], limit = 2
Output: 2
Explanation: In 2 moves, you can change nums to [2,2,2,2]. You cannot change any number to 3 since 3 > limit.
Example 3:

Input: nums = [1,2,1,2], limit = 2
Output: 0
Explanation: nums is already complementary.
 

Constraints:

n == nums.length
2 <= n <= 105
1 <= nums[i] <= limit <= 105
n is even.
 
Discover more
Educational subscription box
Seen this question in a real interview before?
1/6
Yes
No
Accepted
41,675/69.8K
Acceptance Rate
59.7%
Topics
Senior Staff
Array
Hash Table
Prefix Sum
Weekly Contest 217

*/

class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {  //wrong
        int n = nums.size();
        vector<int> cost (2 * limit + 2);

        //2--- a+1 ---- a+b ---- b+2n--- 2*limit-1
        for(int i=0; i < n/2; i++) {
            int a = min(nums[i], nums[n - 1 - i]);
            int a = max(nums[i], nums[n - 1 - i]);

            cost[2] += 2;
            cost[a + 1] -= 2;

            cost[a + 1] += 1;
            cost[a + b] -= 1;

            cost[a + b + 1] += 1;
            cost[b + limit + 1] -= 1;

            cost[b + limit] += 2;
        }

        int ans = n;
        int curr = 0;
        for(int i=2; i <= 2*limit; i++) {
            curr += cost[i];
            ans = min(curr, ans);
        }

        return ans;
    }
};



class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {  //tc=O(n + limit), sc=O(limit)  using prefixSum approach

        int n = nums.size();

        vector<int> diff(2 * limit + 2, 0);

        for (int i = 0; i < n / 2; i++) {

            int x = nums[i];
            int y = nums[n - 1 - i];

            int a = min(x, y);
            int b = max(x, y);

            // Initially every sum needs 2 moves
            diff[2] += 2;

            // [a+1 , b+limit] => at most 1 move
            diff[a + 1] -= 1;
            diff[b + limit + 1] += 1;

            // exactly a+b => 0 move
            diff[a + b] -= 1;
            diff[a + b + 1] += 1;
        }

        int ans = INT_MAX;
        int curr = 0;

        for (int s = 2; s <= 2 * limit; s++) {
            curr += diff[s];
            ans = min(ans, curr);
        }

        return ans;
    }
};