



/*


4th Dec 2025 (Thursday - day3 Campus, OS 303)


qno 1365  https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/description/


1365. How Many Numbers Are Smaller Than the Current Number
Easy
Topics

Companies
Hint
Given the array nums, for each nums[i] find out how many numbers in the array are smaller than it. That is, for each nums[i] you have to count the number of valid j's such that j != i and nums[j] < nums[i].

Return the answer in an array.

 

Example 1:

Input: nums = [8,1,2,2,3]
Output: [4,0,1,1,3]
Explanation: 
For nums[0]=8 there exist four smaller numbers than it (1, 2, 2 and 3). 
For nums[1]=1 does not exist any smaller number than it.
For nums[2]=2 there exist one smaller number than it (1). 
For nums[3]=2 there exist one smaller number than it (1). 
For nums[4]=3 there exist three smaller numbers than it (1, 2 and 2).
Example 2:

Input: nums = [6,5,4,8]
Output: [2,1,0,3]
Example 3:

Input: nums = [7,7,7,7]
Output: [0,0,0,0]
 

Constraints:

2 <= nums.length <= 500
0 <= nums[i] <= 100



*/



class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {  //tc=O(n*n), sc=O(1)
        int n = nums.size();
        vector<int> ans(n);  // allocate size n

        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (nums[j] < nums[i]) {
                    count++;
                }
            }
            ans[i] = count;  // assign after finishing count
        }

        return ans;
    }
};




class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {  //optimized using countingSort, tc=O(n), sc=O(1)
        vector<int> freq(101, 0);

        // count frequency
        for (int x : nums) {
            freq[x]++;
        }

        // prefix sum: freq[i] = count of numbers < i
        for (int i = 1; i < 101; i++) {
            freq[i] += freq[i - 1];
        }

        // build answer
        vector<int> ans(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) ans[i] = 0;
            else ans[i] = freq[nums[i] - 1];
        }

        return ans;
    }
};




/*

qno 2554  https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-i/description/


2554. Maximum Number of Integers to Choose From a Range I
Medium
Topics

Companies
Hint
You are given an integer array banned and two integers n and maxSum. You are choosing some number of integers following the below rules:

The chosen integers have to be in the range [1, n].
Each integer can be chosen at most once.
The chosen integers should not be in the array banned.
The sum of the chosen integers should not exceed maxSum.
Return the maximum number of integers you can choose following the mentioned rules.

 

Example 1:

Input: banned = [1,6,5], n = 5, maxSum = 6
Output: 2
Explanation: You can choose the integers 2 and 4.
2 and 4 are from the range [1, 5], both did not appear in banned, and their sum is 6, which did not exceed maxSum.
Example 2:

Input: banned = [1,2,3,4,5,6,7], n = 8, maxSum = 1
Output: 0
Explanation: You cannot choose any integer while following the mentioned conditions.
Example 3:

Input: banned = [11], n = 7, maxSum = 50
Output: 7
Explanation: You can choose the integers 1, 2, 3, 4, 5, 6, and 7.
They are from the range [1, 7], all did not appear in banned, and their sum is 28, which did not exceed maxSum.
 

Constraints:

1 <= banned.length <= 104
1 <= banned[i], n <= 104
1 <= maxSum <= 109


*/




class Solution {
public:
    int maxCount(vector<int>& banned, int n, long long maxSum) {  //tc=O(n logN), sc=O(1) using GREEDY approach

        unordered_set<int> ban(banned.begin(), banned.end());
        long long sum = 0;
        int count = 0;

        for (int i = 1; i <= n; i++) {
            if (ban.count(i)) continue;   // skip banned numbers

            if (sum + i > maxSum) break;  // stop if sum exceeds maxSum

            sum += i;
            count++;
        }
        
        return count;
    }
};







/*


qno 2578   https://leetcode.com/problems/split-with-minimum-sum/




2578. Split With Minimum Sum
Easy
Topics
premium lock icon
Companies
Hint
Given a positive integer num, split it into two non-negative integers num1 and num2 such that:

The concatenation of num1 and num2 is a permutation of num.
In other words, the sum of the number of occurrences of each digit in num1 and num2 is equal to the number of occurrences of that digit in num.
num1 and num2 can contain leading zeros.
Return the minimum possible sum of num1 and num2.

Notes:

It is guaranteed that num does not contain any leading zeros.
The order of occurrence of the digits in num1 and num2 may differ from the order of occurrence of num.
 

Example 1:

Input: num = 4325
Output: 59
Explanation: We can split 4325 so that num1 is 24 and num2 is 35, giving a sum of 59. We can prove that 59 is indeed the minimal possible sum.
Example 2:

Input: num = 687
Output: 75
Explanation: We can split 687 so that num1 is 68 and num2 is 7, which would give an optimal sum of 75.
 

Constraints:

10 <= num <= 109




*/



class Solution {
public:
    int splitNum(int num) {  //tc=O(10 log10), sc=O(1)
        vector<int> digits;
        
        // Extract digits
        while (num > 0) {
            digits.push_back(num % 10);
            num /= 10;
        }
        
        // Sort digits ascending
        sort(digits.begin(), digits.end());
        
        long long num1 = 0, num2 = 0;
        
        // Distribute digits alternately
        for (int i = 0; i < digits.size(); i++) {
            if (i % 2 == 0) {
                num1 = num1 * 10 + digits[i];
            } else {
                num2 = num2 * 10 + digits[i];
            }
        }
        
        return num1 + num2;
    }
};
