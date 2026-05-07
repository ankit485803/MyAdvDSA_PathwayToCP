

/*

7th May 2026 (Thursday)

qno 3660  https://leetcode.com/problems/jump-game-ix/?envType=daily-question&envId=2026-05-07

3660. Jump Game IX
Attempted
Medium
Topics

Companies
Hint
You are given an integer array nums.

From any index i, you can jump to another index j under the following rules:

Jump to index j where j > i is allowed only if nums[j] < nums[i].
Jump to index j where j < i is allowed only if nums[j] > nums[i].
For each index i, find the maximum value in nums that can be reached by following any sequence of valid jumps starting at i.

Return an array ans where ans[i] is the maximum value reachable starting from index i.

 

Example 1:

Input: nums = [2,1,3]

Output: [2,2,3]

Explanation:

For i = 0: No jump increases the value.
For i = 1: Jump to j = 0 as nums[j] = 2 is greater than nums[i].
For i = 2: Since nums[2] = 3 is the maximum value in nums, no jump increases the value.
Thus, ans = [2, 2, 3].

Example 2:

Input: nums = [2,3,1]

Output: [3,3,3]

Explanation:

For i = 0: Jump forward to j = 2 as nums[j] = 1 is less than nums[i] = 2, then from i = 2 jump to j = 1 as nums[j] = 3 is greater than nums[2].
For i = 1: Since nums[1] = 3 is the maximum value in nums, no jump increases the value.
For i = 2: Jump to j = 1 as nums[j] = 3 is greater than nums[2] = 1.
Thus, ans = [3, 3, 3].

 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109​​​​​​​
 
Discover more
Games
Programming
Seen this question in a real interview before?
1/6
Yes
No
Accepted
47,542/122.4K
Acceptance Rate
38.9%
Topics
Staff
Array
Dynamic Programming
Weekly Contest 464

*/


class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {  //tc=O(n)=sc  wrongAns
        int n = nums.size();

        vector<int> prefixMax(n);
        vector<int> suffixMin(n);
        vector<int> ans(n);

        // prefix maximum
        prefixMax[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefixMax[i] = max(prefixMax[i - 1], nums[i]);
        }

        // suffix minimum
        suffixMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffixMin[i] = min(suffixMin[i + 1], nums[i]);
        }

        ans[n - 1] = prefixMax[n - 1];

        // fill answers
        for (int i = n - 2; i >= 0; i--) {

            // If there exists a smaller value on the right,
            // then connectivity propagates.
            if (nums[i] > suffixMin[i + 1]) {
                ans[i] = ans[i + 1];
            } else {
                ans[i] = prefixMax[i];
            }
        }

        return ans;
    }
};




class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {  //tc=O(n)=sc  corrected
        int n = nums.size();

        vector<int> maxLeft(n); //maxLeft[i] = max element from index 0 to i
        vector<int> minRight(n); //minRight[i] = min element from i+1 to n

        maxLeft[0] = nums[0];
        minRight[n-1] = nums[n-1];

        for(int i = 1; i < n; i++) {
            maxLeft[i] = max(nums[i], maxLeft[i-1]);
        }

        for(int i = n-2; i >= 0; i--) {
            minRight[i] = min(nums[i], minRight[i+1]);
        }

        vector<int> ans(n);

        ans[n-1] = maxLeft[n-1];

        for(int i = n-2; i >= 0; i--) {
            if(maxLeft[i] <= minRight[i+1]) { //can't go to right at all
                ans[i] = maxLeft[i];
            } else {
                ans[i] = ans[i+1];
            }
        }

        return ans;
    }
};