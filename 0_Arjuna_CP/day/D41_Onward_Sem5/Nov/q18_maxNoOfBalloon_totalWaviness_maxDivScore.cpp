


/*

26th Nov 2025 (Wednesday)

qno 1189   https://leetcode.com/problems/maximum-number-of-balloons/



1189. Maximum Number of Balloons
Easy
Topics
premium lock icon
Companies
Hint
Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.

You can use each character in text at most once. Return the maximum number of instances that can be formed.

 

Example 1:



Input: text = "nlaebolko"
Output: 1
Example 2:



Input: text = "loonbalxballpoon"
Output: 2
Example 3:

Input: text = "leetcode"
Output: 0
 

Constraints:

1 <= text.length <= 104
text consists of lower case English letters only.
 

Note: This question is the same as 2287: Rearrange Characters to Make Target String.



*/


 #include <unordered_map>

class Solution {
public:
    int maxNumberOfBalloons(string text) {  //TC=O(n), SC=O(1) to at most 26 englishChar

        unordered_map<char, int> freq;
        for (char c : text) {
            freq[c]++;
        }
        
        // "balloon" requires 1 b, 1 a, 2 l's, 2 o's, and 1 n
        int bCount = freq['b'];
        int aCount = freq['a'];
        int lCount = freq['l'] / 2;  
        int oCount = freq['o'] / 2;  // Because we need 2 'o's for each "balloon"
        int nCount = freq['n'];
        

        return min({bCount, aCount, lCount, oCount, nCount});
    }
};




/*


qno 2287 https://leetcode.com/problems/rearrange-characters-to-make-target-string/


2287. Rearrange Characters to Make Target String
Attempted
Easy
Topics

Companies
Hint
You are given two 0-indexed strings s and target. You can take some letters from s and rearrange them to form new strings.

Return the maximum number of copies of target that can be formed by taking letters from s and rearranging them.

 

Example 1:

Input: s = "ilovecodingonleetcode", target = "code"
Output: 2
Explanation:
For the first copy of "code", take the letters at indices 4, 5, 6, and 7.
For the second copy of "code", take the letters at indices 17, 18, 19, and 20.
The strings that are formed are "ecod" and "code" which can both be rearranged into "code".
We can make at most two copies of "code", so we return 2.
Example 2:

Input: s = "abcba", target = "abc"
Output: 1
Explanation:
We can make one copy of "abc" by taking the letters at indices 0, 1, and 2.
We can make at most one copy of "abc", so we return 1.
Note that while there is an extra 'a' and 'b' at indices 3 and 4, we cannot reuse the letter 'c' at index 2, so we cannot make a second copy of "abc".
Example 3:

Input: s = "abbaccaddaeea", target = "aaaaa"
Output: 1
Explanation:
We can make one copy of "aaaaa" by taking the letters at indices 0, 3, 6, 9, and 12.
We can make at most one copy of "aaaaa", so we return 1.
 

Constraints:

1 <= s.length <= 100
1 <= target.length <= 10
s and target consist of lowercase English letters.
 

Note: This question is the same as 1189: Maximum Number of Balloons.



*/



#include <unordered_map>

class Solution {
public:
    int rearrangeCharacters(string s, string target) { //TC=O(n + m), SC=O(no of distint in s, targ)
        // Frequency map for characters in string s
        unordered_map<char, int> sFreq;
        for (char c : s) {
            sFreq[c]++;
        }


        unordered_map<char, int> targetFreq;
        for (char c : target) {
            targetFreq[c]++;
        }

        int minCopies = INT_MAX; 

        // For each character in target, calculate how many times we can use it
        for (const auto& pair : targetFreq) {
            char c = pair.first;
            int targetCount = pair.second;

            if (sFreq.find(c) == sFreq.end()) {
                return 0;
            }

            // Calculate how many times we can use this character from s
            int maxPossible = sFreq[c] / targetCount;
            minCopies = min(minCopies, maxPossible);
        }

        return minCopies;
    }
};




/*


qno 3751  https://leetcode.com/problems/total-waviness-of-numbers-in-range-i/description/


3751. Total Waviness of Numbers in Range I
Medium
Topics
premium lock icon
Companies
Hint
You are given two integers num1 and num2 representing an inclusive range [num1, num2].

The waviness of a number is defined as the total count of its peaks and valleys:

A digit is a peak if it is strictly greater than both of its immediate neighbors.
A digit is a valley if it is strictly less than both of its immediate neighbors.
The first and last digits of a number cannot be peaks or valleys.
Any number with fewer than 3 digits has a waviness of 0.
Return the total sum of waviness for all numbers in the range [num1, num2].
 

Example 1:

Input: num1 = 120, num2 = 130

Output: 3

Explanation:

In the range [120, 130]:
120: middle digit 2 is a peak, waviness = 1.
121: middle digit 2 is a peak, waviness = 1.
130: middle digit 3 is a peak, waviness = 1.
All other numbers in the range have a waviness of 0.
Thus, total waviness is 1 + 1 + 1 = 3.

Example 2:

Input: num1 = 198, num2 = 202

Output: 3

Explanation:

In the range [198, 202]:
198: middle digit 9 is a peak, waviness = 1.
201: middle digit 0 is a valley, waviness = 1.
202: middle digit 0 is a valley, waviness = 1.
All other numbers in the range have a waviness of 0.
Thus, total waviness is 1 + 1 + 1 = 3.

Example 3:

Input: num1 = 4848, num2 = 4848

Output: 2

Explanation:

Number 4848: the second digit 8 is a peak, and the third digit 4 is a valley, giving a waviness of 2.

 

Constraints:

1 <= num1 <= num2 <= 105


*/


class Solution {
public:
    int totalWaviness(int num1, int num2) {  //TC=O(n*d), SC=O(d)
        int total = 0;

        for (int num = num1; num <= num2; ++num) {
            string strNum = to_string(num);
            int waviness = 0;
            
            // Skip numbers with fewer than 3 digits
            if (strNum.size() < 3) continue;
            
            // Loop through digits (excluding first and last)
            for (int i = 1; i < strNum.size() - 1; ++i) {
                char prev = strNum[i - 1];
                char curr = strNum[i];
                char next = strNum[i + 1];
                
                // Check for peak
                if (curr > prev && curr > next) {
                    waviness++;
                }
                // Check for valley
                if (curr < prev && curr < next) {
                    waviness++;
                }
            }
            
            total += waviness;
        }
        
        return total;
    }
};




/*

qno  26444  https://leetcode.com/problems/find-the-maximum-divisibility-score/description/

2644. Find the Maximum Divisibility Score
Easy
Topics

Companies
Hint
You are given two integer arrays nums and divisors.

The divisibility score of divisors[i] is the number of indices j such that nums[j] is divisible by divisors[i].

Return the integer divisors[i] with the maximum divisibility score. If multiple integers have the maximum score, return the smallest one.

 

Example 1:

Input: nums = [2,9,15,50], divisors = [5,3,7,2]

Output: 2

Explanation:

The divisibility score of divisors[0] is 2 since nums[2] and nums[3] are divisible by 5.

The divisibility score of divisors[1] is 2 since nums[1] and nums[2] are divisible by 3.

The divisibility score of divisors[2] is 0 since none of the numbers in nums is divisible by 7.

The divisibility score of divisors[3] is 2 since nums[0] and nums[3] are divisible by 2.

As divisors[0], divisors[1], and divisors[3] have the same divisibility score, we return the smaller one which is divisors[3].

Example 2:

Input: nums = [4,7,9,3,9], divisors = [5,2,3]

Output: 3

Explanation:

The divisibility score of divisors[0] is 0 since none of numbers in nums is divisible by 5.

The divisibility score of divisors[1] is 1 since only nums[0] is divisible by 2.

The divisibility score of divisors[2] is 3 since nums[2], nums[3] and nums[4] are divisible by 3.

Example 3:

Input: nums = [20,14,21,10], divisors = [10,16,20]

Output: 10

Explanation:

The divisibility score of divisors[0] is 2 since nums[0] and nums[3] are divisible by 10.

The divisibility score of divisors[1] is 0 since none of the numbers in nums is divisible by 16.

The divisibility score of divisors[2] is 1 since nums[0] is divisible by 20.

 

Constraints:

1 <= nums.length, divisors.length <= 1000
1 <= nums[i], divisors[i] <= 109


*/


class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) { //TC=O(n*d), SC=O(1)

        int maxScore = -1;  // Track the maximum divisibility score
        int result = INT_MAX; 

        for (int div : divisors) {
            int score = 0;  
            

            for (int num : nums) {
                if (num % div == 0) {
                    score++;
                }
            }
            
            
            if (score > maxScore || (score == maxScore && div < result)) {
                maxScore = score;
                result = div;
            }
        }
        
        return result;
    }
};
