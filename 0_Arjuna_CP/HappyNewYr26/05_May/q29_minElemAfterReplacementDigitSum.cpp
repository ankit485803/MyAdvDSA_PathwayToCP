

/*

29th May 2026 (Friday)

qno 3300  https://leetcode.com/problems/minimum-element-after-replacement-with-digit-sum/description/?envType=daily-question&envId=2026-05-29

3300. Minimum Element After Replacement With Digit Sum
Easy
Topics

Companies
Hint
You are given an integer array nums.

You replace each element in nums with the sum of its digits.

Return the minimum element in nums after all replacements.

 

Example 1:

Input: nums = [10,12,13,14]

Output: 1

Explanation:

nums becomes [1, 3, 4, 5] after all replacements, with minimum element 1.

Example 2:

Input: nums = [1,2,3,4]

Output: 1

Explanation:

nums becomes [1, 2, 3, 4] after all replacements, with minimum element 1.

Example 3:

Input: nums = [999,19,199]

Output: 10

Explanation:

nums becomes [27, 10, 19] after all replacements, with minimum element 10.

 

Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 104
 
Discover more
Mathematics
Math
Seen this question in a real interview before?
1/6
Yes
No
Accepted
172,637/193.2K
Acceptance Rate
89.4%
Topics
Mid Level
Array
Math
Biweekly Contest 140

*/



class Solution {
public:
    int digitSeparator(int num) {  //helperFun
        while(num > 0) {
            int digits = num % 10;  //lastParts
            num /= 10;   //remove
        }

        return digits;
    }

    int minElement(vector<int>& nums) {
        //bruteForce appraoch -- iterate eachElem tc=O(n), sc=O(1)
        vector<int> ans;
        int sum = 0;

        for(int i=0; i<nums.size(); i++) {
            int digits = digitSeparator(nums[i]);
            sum += digits;

            ans.push_back(sum);
        }

        return min_element(ans);
    }
};



class Solution {
public:
    int digitSum(int num) {
        int sum = 0;

        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }

        return sum;
    }

    int minElement(vector<int>& nums) {   //tc=O(no of digits), sc=O(1)
        int mini = INT_MAX;

        for (int num : nums) {
            mini = min(mini, digitSum(num));
        }

        return mini;
    }
};


//Approach-1
//T.C : O(n * log10(m)), where n = nums.size(), m = max element in nums
//S.C : O(1)
class Solution {
public:
    int digitSum(int n) {
        int sum = 0;

        while(n > 0) {
            sum += n % 10;
            n /= 10;
        }

        return sum;
    }

    int minElement(vector<int>& nums) {
        int result = 37; //Note that 1 <= nums[i] <= 10^4 and biggest sum can be obtained by 9999 (whose digit sum = 36)

        for(int num : nums) {
            int s = digitSum(num); //O(log10(num))

            result = min(result, s);
        }

        return result;
    }
};


//Approach-2
//T.C : O(n), where n = nums.size()
//S.C : O(1)
class Solution {
public:
    int digitSum(int n) {
        return
            (n / 10000) +           // ten-thousands digit
            (n % 10000 / 1000) +    // thousands digit
            (n % 1000 / 100) +      // hundreds digit
            (n % 100 / 10) +        // tens digit
            (n % 10);               // units digit
    }

    int minElement(vector<int>& nums) {
        int result = 37; //Note that 1 <= nums[i] <= 10^4 and biggest sum can be obtained by 9999 (whose digit sum = 36)

        for(int num : nums) {
            int s = digitSum(num); //O(1)

            result = min(result, s);
        }

        return result;
    }
};