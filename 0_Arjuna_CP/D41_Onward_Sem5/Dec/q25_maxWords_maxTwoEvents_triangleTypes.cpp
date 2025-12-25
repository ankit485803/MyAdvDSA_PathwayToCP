



/*

25th Dec 2025 (Thursday - Merry Christmas)



qno 2114   https://leetcode.com/problems/maximum-number-of-words-found-in-sentences/




2114. Maximum Number of Words Found in Sentences
Easy
Topics

Companies
Hint
A sentence is a list of words that are separated by a single space with no leading or trailing spaces.

You are given an array of strings sentences, where each sentences[i] represents a single sentence.

Return the maximum number of words that appear in a single sentence.

 

Example 1:

Input: sentences = ["alice and bob love leetcode", "i think so too", "this is great thanks very much"]
Output: 6
Explanation: 
- The first sentence, "alice and bob love leetcode", has 5 words in total.
- The second sentence, "i think so too", has 4 words in total.
- The third sentence, "this is great thanks very much", has 6 words in total.
Thus, the maximum number of words in a single sentence comes from the third sentence, which has 6 words.
Example 2:

Input: sentences = ["please wait", "continue to fight", "continue to win"]
Output: 3
Explanation: It is possible that multiple sentences contain the same number of words. 
In this example, the second and third sentences (underlined) have the same number of words.
 

Constraints:

1 <= sentences.length <= 100
1 <= sentences[i].length <= 100
sentences[i] consists only of lowercase English letters and ' ' only.
sentences[i] does not have leading or trailing spaces.
All the words in sentences[i] are separated by a single space.




*/



#include <sstream>
class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {  //tc=O(no of char), sc=O(n*k)
        int maxWord = 0;
        
        for (int i = 0; i < sentences.size(); i++) {
            string curr = sentences[i];
            stringstream ss(curr);
            string word;
            int wordCount = 0;
            
            // Count words in the current sentence
            while (ss >> word) {
                wordCount++;
            }

            maxWord = max(maxWord, wordCount);
        }
        
        return maxWord;
    }
};





/*




qno 2652  https://leetcode.com/problems/sum-multiples/



2652. Sum Multiples
Solved
Easy
Topics

Companies
Hint
Given a positive integer n, find the sum of all integers in the range [1, n] inclusive that are divisible by 3, 5, or 7.

Return an integer denoting the sum of all numbers in the given range satisfying the constraint.

 

Example 1:

Input: n = 7
Output: 21
Explanation: Numbers in the range [1, 7] that are divisible by 3, 5, or 7 are 3, 5, 6, 7. The sum of these numbers is 21.
Example 2:

Input: n = 10
Output: 40
Explanation: Numbers in the range [1, 10] that are divisible by 3, 5, or 7 are 3, 5, 6, 7, 9, 10. The sum of these numbers is 40.
Example 3:

Input: n = 9
Output: 30
Explanation: Numbers in the range [1, 9] that are divisible by 3, 5, or 7 are 3, 5, 6, 7, 9. The sum of these numbers is 30.
 

Constraints:

1 <= n <= 103





*/


class Solution {
public:
    int sumOfMultiples(int n) {
        int sum = 0;
        for(int i=1; i<=n; i++) {
            if(i % 3 ==0 || i % 5==0 || i % 7==0) {
                sum += i;
            }
        }

        return sum;
    }
};



/*



qno 2054  https://leetcode.com/problems/two-best-non-overlapping-events/

DP approach used here



2054. Two Best Non-Overlapping Events
Medium
Topics

Companies
Hint
You are given a 0-indexed 2D integer array of events where events[i] = [startTimei, endTimei, valuei]. The ith event starts at startTimei and ends at endTimei, and if you attend this event, you will receive a value of valuei. You can choose at most two non-overlapping events to attend such that the sum of their values is maximized.

Return this maximum sum.

Note that the start time and end time is inclusive: that is, you cannot attend two events where one of them starts and the other ends at the same time. More specifically, if you attend an event with end time t, the next event must start at or after t + 1.

 

Example 1:


Input: events = [[1,3,2],[4,5,2],[2,4,3]]
Output: 4
Explanation: Choose the green events, 0 and 1 for a sum of 2 + 2 = 4.
Example 2:


Input: events = [[1,3,2],[4,5,2],[1,5,5]]
Output: 5
Explanation: Choose event 2 for a sum of 5.
Example 3:


Input: events = [[1,5,3],[1,5,1],[6,6,5]]
Output: 8
Explanation: Choose events 0 and 2 for a sum of 3 + 5 = 8.
 

Constraints:

2 <= events.length <= 105
events[i].length == 3
1 <= startTimei <= endTimei <= 109
1 <= valuei <= 106


*/



class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        
        // 1. Sort events by start time
        sort(events.begin(), events.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        });

        // 2. Build suffix maximum array of values
        vector<int> suffixMax(n);
        suffixMax[n - 1] = events[n - 1][2];
        for (int i = n - 2; i >= 0; i--) {
            suffixMax[i] = max(suffixMax[i + 1], events[i][2]);
        }

        int ans = 0;

        // 3. Try each event as the first event
        for (int i = 0; i < n; i++) {
            ans = max(ans, events[i][2]); // single event case

            // Binary search for first event with start > end[i]
            int lo = i + 1, hi = n - 1, idx = -1;
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                if (events[mid][0] > events[i][1]) {
                    idx = mid;
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }

            // Combine with best possible future event
            if (idx != -1) {
                ans = max(ans, events[i][2] + suffixMax[idx]);
            }
        }

        return ans;
    }
};





/*



qno 2894  https://leetcode.com/problems/divisible-and-non-divisible-sums-difference/



2894. Divisible and Non-divisible Sums Difference
Easy
Topics

Companies
Hint
You are given positive integers n and m.

Define two integers as follows:

num1: The sum of all integers in the range [1, n] (both inclusive) that are not divisible by m.
num2: The sum of all integers in the range [1, n] (both inclusive) that are divisible by m.
Return the integer num1 - num2.

 

Example 1:

Input: n = 10, m = 3
Output: 19
Explanation: In the given example:
- Integers in the range [1, 10] that are not divisible by 3 are [1,2,4,5,7,8,10], num1 is the sum of those integers = 37.
- Integers in the range [1, 10] that are divisible by 3 are [3,6,9], num2 is the sum of those integers = 18.
We return 37 - 18 = 19 as the answer.
Example 2:

Input: n = 5, m = 6
Output: 15
Explanation: In the given example:
- Integers in the range [1, 5] that are not divisible by 6 are [1,2,3,4,5], num1 is the sum of those integers = 15.
- Integers in the range [1, 5] that are divisible by 6 are [], num2 is the sum of those integers = 0.
We return 15 - 0 = 15 as the answer.
Example 3:

Input: n = 5, m = 1
Output: -15
Explanation: In the given example:
- Integers in the range [1, 5] that are not divisible by 1 are [], num1 is the sum of those integers = 0.
- Integers in the range [1, 5] that are divisible by 1 are [1,2,3,4,5], num2 is the sum of those integers = 15.
We return 0 - 15 = -15 as the answer.
 

Constraints:

1 <= n, m <= 1000


*/


class Solution {
public:
    int differenceOfSums(int n, int m) {  //wrong
        int num1, num2;
        for(int i=1; i<=n; i++) {
            if(i % m != 0) {
                num1 += i;
            } else {
                num2 += i;
            }
        }

        return num1-num2;
    }
};


class Solution {
public:
    int differenceOfSums(int n, int m) {
        int num1 = 0;  //not divisible
        int num2 = 0;  //divisible by m

        for(int i=1; i<=n; i++) {
            if(i % m == 0) {
                num2 += i;
            }
        }
        int totalSum = n * (n+1) / 2;
        num1 = totalSum - num2;

        return num1-num2;
    }

};




/*


qno 3019  https://leetcode.com/problems/number-of-changing-keys/description/



3019. Number of Changing Keys
Easy
Topics

Companies
Hint
You are given a 0-indexed string s typed by a user. Changing a key is defined as using a key different from the last used key. For example, s = "ab" has a change of a key while s = "bBBb" does not have any.

Return the number of times the user had to change the key.

Note: Modifiers like shift or caps lock won't be counted in changing the key that is if a user typed the letter 'a' and then the letter 'A' then it will not be considered as a changing of key.

 

Example 1:

Input: s = "aAbBcC"
Output: 2
Explanation: 
From s[0] = 'a' to s[1] = 'A', there is no change of key as caps lock or shift is not counted.
From s[1] = 'A' to s[2] = 'b', there is a change of key.
From s[2] = 'b' to s[3] = 'B', there is no change of key as caps lock or shift is not counted.
From s[3] = 'B' to s[4] = 'c', there is a change of key.
From s[4] = 'c' to s[5] = 'C', there is no change of key as caps lock or shift is not counted.

Example 2:

Input: s = "AaAaAaaA"
Output: 0
Explanation: There is no change of key since only the letters 'a' and 'A' are pressed which does not require change of key.
 

Constraints:

1 <= s.length <= 100
s consists of only upper case and lower case English letters.




*/


#include <cctype> // for isupper and tolower
class Solution {
public:
    int countKeyChanges(string s) {
        int count = 0;
        for (int i = 0; i < s.size() - 1; i++) {
            char ch1 = s[i];
            char ch2 = s[i + 1];

            // Check if the current characters are of different cases
            if (tolower(ch1) != tolower(ch2)) {
                count++;
            }
        }
        return count;
    }
};





/*

qno 3024   https://leetcode.com/problems/type-of-triangle/


3024. Type of Triangle
Easy
Topics

Companies
Hint
You are given a 0-indexed integer array nums of size 3 which can form the sides of a triangle.

A triangle is called equilateral if it has all sides of equal length.
A triangle is called isosceles if it has exactly two sides of equal length.
A triangle is called scalene if all its sides are of different lengths.
Return a string representing the type of triangle that can be formed or "none" if it cannot form a triangle.

 

Example 1:

Input: nums = [3,3,3]
Output: "equilateral"
Explanation: Since all the sides are of equal length, therefore, it will form an equilateral triangle.
Example 2:

Input: nums = [3,4,5]
Output: "scalene"
Explanation: 
nums[0] + nums[1] = 3 + 4 = 7, which is greater than nums[2] = 5.
nums[0] + nums[2] = 3 + 5 = 8, which is greater than nums[1] = 4.
nums[1] + nums[2] = 4 + 5 = 9, which is greater than nums[0] = 3. 
Since the sum of the two sides is greater than the third side for all three cases, therefore, it can form a triangle.
As all the sides are of different lengths, it will form a scalene triangle.
 

Constraints:

nums.length == 3
1 <= nums[i] <= 100



*/




class Solution {
public:
    string triangleType(vector<int>& nums) {  //tc=O(1)=sc
        
        //equi
        if(nums[0] == nums[1] && nums[1] == nums[2]) {
            return "equilateral";
        }
        if(nums[0] == nums[1] || nums[1] == nums[2] || nums[2] == nums[0]) {  //anyTwoSides
            return "isosceles";
        } 
        if(nums[0] != nums[1] != nums[2]) { //allDiff
            return "scalene";
        } else {
           return  "none";
        }

    }
};




class Solution {
public:
    string triangleType(vector<int>& nums) {
        // Check if the sides form a valid triangle using the triangle inequality theorem
        if (nums[0] + nums[1] <= nums[2] || nums[0] + nums[2] <= nums[1] || nums[1] + nums[2] <= nums[0]) {
            return "none"; // Not a valid triangle
        }
        
        // Check for equilateral triangle
        if (nums[0] == nums[1] && nums[1] == nums[2]) {
            return "equilateral";
        }
        
        // Check for isosceles triangle (exactly two sides equal)
        if (nums[0] == nums[1] || nums[1] == nums[2] || nums[2] == nums[0]) {
            return "isosceles";
        }
        
        // If no two sides are equal, it's scalene
        return "scalene";
    }
};





class Solution {
public:
    string triangleType(vector<int>& nums) {
        // Assign sides to variables a, b, and c
        int a = nums[0];
        int b = nums[1];
        int c = nums[2];
        
        // Check if the sides form a valid triangle using the triangle inequality theorem
        if (a + b <= c || a + c <= b || b + c <= a) {
            return "none"; // Not a valid triangle
        }
        
        // Check for equilateral triangle (all sides equal)
        if (a == b && b == c) {
            return "equilateral";
        }
        
        // Check for isosceles triangle (exactly two sides equal)
        if (a == b || b == c || c == a) {
            return "isosceles";
        }
        
        // If no two sides are equal, it's scalene
        return "scalene";
    }
};




class Solution {
public:
    string triangleType(vector<int>& nums) {   //tc=O(1)=SC
        // Assign sides to variables a, b, and c
        int a = nums[0];
        int b = nums[1];
        int c = nums[2];
        
        // Check if the sides form a valid triangle using the triangle inequality theorem
        if (a + b <= c || a + c <= b || b + c <= a) {
            return "none"; // Not a valid triangle
        }
        
        if (a == b && b == c) {
            return "equilateral";
        }
        
        if (a == b || b == c || c == a) {
            return "isosceles";
        }
        
        // If no two sides are equal, it's scalene
        return "scalene";
    }
};





/*



qno  155o   https://leetcode.com/problems/three-consecutive-odds/description/



1550. Three Consecutive Odds
Attempted
Easy
Topics

Companies
Hint
Given an integer array arr, return true if there are three consecutive odd numbers in the array. Otherwise, return false.
 

Example 1:

Input: arr = [2,6,4,1]
Output: false
Explanation: There are no three consecutive odds.
Example 2:

Input: arr = [1,2,34,3,4,5,7,23,12]
Output: true
Explanation: [5,7,23] are three consecutive odds.
 

Constraints:

1 <= arr.length <= 1000
1 <= arr[i] <= 1000




*/



class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int count = 0; // Count of consecutive odd numbers
        
        for (int num : arr) {
            if (num % 2 != 0) {  //odd
                count++;
                if (count == 3) {  // If we have found 3 consecutive odd numbers
                    return true;
                }
            } else {
                count = 0;  // Reset the count if the number is even
            }
        }
        
        return false;   
    }
};
