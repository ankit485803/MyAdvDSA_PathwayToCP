



/*


29th Dec 2025 (Monday)


qno 3788  https://leetcode.com/problems/maximum-score-of-a-split/
weekly contest sunday 482



3788. Maximum Score of a Split
Medium

Companies
Hint
You are given an integer array nums of length n.

Choose an index i such that 0 <= i < n - 1.

For a chosen split index i:

Let prefixSum(i) be the sum of nums[0] + nums[1] + ... + nums[i].
Let suffixMin(i) be the minimum value among nums[i + 1], nums[i + 2], ..., nums[n - 1].
The score of a split at index i is defined as:

score(i) = prefixSum(i) - suffixMin(i)

Return an integer denoting the maximum score over all valid split indices.

 

Example 1:

Input: nums = [10,-1,3,-4,-5]

Output: 17

Explanation:

The optimal split is at i = 2, score(2) = prefixSum(2) - suffixMin(2) = (10 + (-1) + 3) - (-5) = 17.

Example 2:

Input: nums = [-7,-5,3]

Output: -2

Explanation:

The optimal split is at i = 0, score(0) = prefixSum(0) - suffixMin(0) = (-7) - (-5) = -2.

Example 3:

Input: nums = [1,1]

Output: 0

Explanation:

The only valid split is at i = 0, score(0) = prefixSum(0) - suffixMin(0) = 1 - 1 = 0.

 

Constraints:

2 <= nums.length <= 105
-109​​​​​​​ <= nums[i] <= 109



*/


class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        int n = nums.size();
        
        //Step1: Calculate suffixMin arr
        vector<long long> suffixMin(n);
        suffixMin[n-1] = (long long)INT_MAX;  // Use max int value to represent "out of bound" value

        // Fill the suffixMin array (min from the right)
        for (int i = n - 2; i >= 0; i--) {
            suffixMin[i] = min((long long)nums[i + 1], suffixMin[i + 1]);
        }

        //Step2: Calculate the maxScore
        long long prefixSum = 0;
        long long maxScore = (long long)INT_MIN;

        for (int i = 0; i < n - 1; i++) {
            prefixSum += nums[i];
            long long score = prefixSum - suffixMin[i];
            maxScore = max(maxScore, score);
        }

        return maxScore;
    }
};




/*


qno 3789  https://leetcode.com/problems/smallest-all-ones-multiple/description/


3790. Smallest All-Ones Multiple
Medium

Companies
Hint
You are given a positive integer k.

Find the smallest integer n divisible by k that consists of only the digit 1 in its decimal representation (e.g., 1, 11, 111, ...).

Return an integer denoting the number of digits in the decimal representation of n. If no such n exists, return -1.

 

Example 1:

Input: k = 3

Output: 3

Explanation:

n = 111 because 111 is divisible by 3, but 1 and 11 are not. The length of n = 111 is 3.

Example 2:

Input: k = 7

Output: 6

Explanation:

n = 111111. The length of n = 111111 is 6.

Example 3:

Input: k = 2

Output: -1

Explanation:

There does not exist a valid n that is a multiple of 2.

 

Constraints:

2 <= k <= 105

*/


class Solution {
public:
    int minAllOneMultiple(int k) {
        int num = 0;
        for(int leng=1; leng<=k; leng++) {
            num = (num * 10 + 1) % k;

            if(num == 0) {
                return leng;
            }
        }

        return -1;
    }
};






