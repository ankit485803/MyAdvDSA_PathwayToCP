




/*


4th Jan 2026 (Sunday)


qno 1390  https://leetcode.com/problems/four-divisors/?envType=daily-question&envId=2026-01-04



1390. Four Divisors
Medium
Topics

Companies
Hint
Given an integer array nums, return the sum of divisors of the integers in that array that have exactly four divisors. If there is no such integer in the array, return 0.

 

Example 1:

Input: nums = [21,4,7]
Output: 32
Explanation: 
21 has 4 divisors: 1, 3, 7, 21
4 has 3 divisors: 1, 2, 4
7 has 2 divisors: 1, 7
The answer is the sum of divisors of 21 only.
Example 2:

Input: nums = [21,21]
Output: 64
Example 3:

Input: nums = [1,2,3,4,5]
Output: 0
 

Constraints:

1 <= nums.length <= 104
1 <= nums[i] <= 105




*/




class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {  //tc=O(n √m) where m = max(nums[i]), sc=O(1)
        int totalSum = 0;

        for (int n : nums) {
            int sum = 0;
            int count = 0;

            for (int d = 1; d * d <= n; d++) {
                if (n % d == 0) {
                    int d1 = d;
                    int d2 = n / d;

                    if (d1 == d2) {
                        count++;
                        sum += d1;
                    } else {
                        count += 2;
                        sum += d1 + d2;
                    }

                    if (count > 4) break;
                }
            }

            if (count == 4) {
                totalSum += sum;
            }
        }

        return totalSum;
    }
};
