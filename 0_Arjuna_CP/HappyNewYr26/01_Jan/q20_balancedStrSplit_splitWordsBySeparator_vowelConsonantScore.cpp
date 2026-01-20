




/*


20th Jan 2026  (Tuesday)


qno 1221    https://leetcode.com/problems/split-a-string-in-balanced-strings/



1221. Split a String in Balanced Strings
Solved
Easy
Topics

Companies
Hint
Balanced strings are those that have an equal quantity of 'L' and 'R' characters.

Given a balanced string s, split it into some number of substrings such that:

Each substring is balanced.
Return the maximum number of balanced strings you can obtain.

 

Example 1:

Input: s = "RLRRLLRLRL"
Output: 4
Explanation: s can be split into "RL", "RRLL", "RL", "RL", each substring contains same number of 'L' and 'R'.
Example 2:

Input: s = "RLRRRLLRLL"
Output: 2
Explanation: s can be split into "RL", "RRRLLRLL", each substring contains same number of 'L' and 'R'.
Note that s cannot be split into "RL", "RR", "RL", "LR", "LL", because the 2nd and 5th substrings are not balanced.
Example 3:

Input: s = "LLLLRRRR"
Output: 1
Explanation: s can be split into "LLLLRRRR".
 

Constraints:

2 <= s.length <= 1000
s[i] is either 'L' or 'R'.
s is a balanced string.
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
375,594/430.7K
Acceptance Rate
87.2%
Topics
String
Greedy
Counting
Weekly Contest 158



*/



class Solution {
public:
    int balancedStringSplit(string s) {  //tc=O(n),sc=O(1)
        int ans = 0;

        int left = 0;
        int right = 0;
        for(int i=0; i<s.size(); i++) {
            if(s[i] == 'L') {
                left++;
            } else {
                right++;
            }

            if(left == right) {  //checkCondition: EQULITY
                ans++;
            }
        }

        return ans;
    }
};





/*

qno  2788  https://leetcode.com/problems/split-strings-by-separator/


2788. Split Strings by Separator
Easy
Topics

Companies
Hint
Given an array of strings words and a character separator, split each string in words by separator.

Return an array of strings containing the new strings formed after the splits, excluding empty strings.

Notes

separator is used to determine where the split should occur, but it is not included as part of the resulting strings.
A split may result in more than two strings.
The resulting strings must maintain the same order as they were initially given.
 

Example 1:

Input: words = ["one.two.three","four.five","six"], separator = "."
Output: ["one","two","three","four","five","six"]
Explanation: In this example we split as follows:

"one.two.three" splits into "one", "two", "three"
"four.five" splits into "four", "five"
"six" splits into "six" 

Hence, the resulting array is ["one","two","three","four","five","six"].
Example 2:

Input: words = ["$easy$","$problem$"], separator = "$"
Output: ["easy","problem"]
Explanation: In this example we split as follows: 

"$easy$" splits into "easy" (excluding empty strings)
"$problem$" splits into "problem" (excluding empty strings)

Hence, the resulting array is ["easy","problem"].
Example 3:

Input: words = ["|||"], separator = "|"
Output: []
Explanation: In this example the resulting split of "|||" will contain only empty strings, so we return an empty array []. 
 

Constraints:

1 <= words.length <= 100
1 <= words[i].length <= 20
characters in words[i] are either lowercase English letters or characters from the string ".,|$#@" (excluding the quotes)
separator is a character from the string ".,|$#@" (excluding the quotes)
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
76,624/101K
Acceptance Rate
75.9%
Topics
Array
String
Weekly Contest 355


*/




class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> result;

        for (int i = 0; i < words.size(); i++) {  //tc=sc=O(totalChar)
            string curr = "";

            for (char c : words[i]) {
                if (c == separator) {
                    if (!curr.empty()) {
                        result.push_back(curr);
                        curr.clear();
                    }
                } else {
                    curr.push_back(c);
                }
            }

            // add last part if non-empty
            if (!curr.empty()) {
                result.push_back(curr);
            }
        }

        return result;
    }
};





/*


qno 3810   https://leetcode.com/problems/minimum-operations-to-reach-target-array/

3810. Minimum Operations to Reach Target Array
Medium

Companies
Hint
You are given two integer arrays nums and target, each of length n, where nums[i] is the current value at index i and target[i] is the desired value at index i.

You may perform the following operation any number of times (including zero):

Choose an integer value x
Find all maximal contiguous segments where nums[i] == x (a segment is maximal if it cannot be extended to the left or right while keeping all values equal to x)
For each such segment [l, r], update simultaneously:
nums[l] = target[l], nums[l + 1] = target[l + 1], ..., nums[r] = target[r]
Return the minimum number of operations required to make nums equal to target.

 

Example 1:

Input: nums = [1,2,3], target = [2,1,3]

Output: 2

Explanation:​​​​​​​

Choose x = 1: maximal segment [0, 0] updated -> nums becomes [2, 2, 3]
Choose x = 2: maximal segment [0, 1] updated (nums[0] stays 2, nums[1] becomes 1) -> nums becomes [2, 1, 3]
Thus, 2 operations are required to convert nums to target.​​​​​​​​​​​​​​
Example 2:

Input: nums = [4,1,4], target = [5,1,4]

Output: 1

Explanation:

Choose x = 4: maximal segments [0, 0] and [2, 2] updated (nums[2] stays 4) -> nums becomes [5, 1, 4]
Thus, 1 operation is required to convert nums to target.
Example 3:

Input: nums = [7,3,7], target = [5,5,9]

Output: 2

Explanation:

Choose x = 7: maximal segments [0, 0] and [2, 2] updated -> nums becomes [5, 3, 9]
Choose x = 3: maximal segment [1, 1] updated -> nums becomes [5, 5, 9]
Thus, 2 operations are required to convert nums to target.
 

Constraints:

1 <= n == nums.length == target.length <= 105
1 <= nums[i], target[i] <= 105



*/



class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& target) {
        int ops = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] != target[i]) {
                if (i == 0 || nums[i] != nums[i - 1]) {
                    ops++;
                }
            }
        }

        return ops;
    }
};



class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& target) {  //tc=O(n)=sc
        unordered_set<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != target[i]) {
                ans.insert(nums[i]);
            }
        }

        return ans.size();
    }
};




/*



qno 3047   https://leetcode.com/problems/find-the-largest-area-of-square-inside-two-rectangles/



3047. Find the Largest Area of Square Inside Two Rectangles
Medium
Topics

Companies
Hint
There exist n rectangles in a 2D plane with edges parallel to the x and y axis. You are given two 2D integer arrays bottomLeft and topRight where bottomLeft[i] = [a_i, b_i] and topRight[i] = [c_i, d_i] represent the bottom-left and top-right coordinates of the ith rectangle, respectively.

You need to find the maximum area of a square that can fit inside the intersecting region of at least two rectangles. Return 0 if such a square does not exist.

 

Example 1:


Input: bottomLeft = [[1,1],[2,2],[3,1]], topRight = [[3,3],[4,4],[6,6]]

Output: 1

Explanation:

A square with side length 1 can fit inside either the intersecting region of rectangles 0 and 1 or the intersecting region of rectangles 1 and 2. Hence the maximum area is 1. It can be shown that a square with a greater side length can not fit inside any intersecting region of two rectangles.

Example 2:


Input: bottomLeft = [[1,1],[1,3],[1,5]], topRight = [[5,5],[5,7],[5,9]]

Output: 4

Explanation:

A square with side length 2 can fit inside either the intersecting region of rectangles 0 and 1 or the intersecting region of rectangles 1 and 2. Hence the maximum area is 2 * 2 = 4. It can be shown that a square with a greater side length can not fit inside any intersecting region of two rectangles.

Example 3:

  
Input: bottomLeft = [[1,1],[2,2],[1,2]], topRight = [[3,3],[4,4],[3,4]]

Output: 1

Explanation:

A square with side length 1 can fit inside the intersecting region of any two rectangles. Also, no larger square can, so the maximum area is 1. Note that the region can be formed by the intersection of more than 2 rectangles.

Example 4:

  
Input: bottomLeft = [[1,1],[3,3],[3,1]], topRight = [[2,2],[4,4],[4,2]]

Output: 0

Explanation:

No pair of rectangles intersect, hence, the answer is 0.

 

Constraints:

n == bottomLeft.length == topRight.length
2 <= n <= 103
bottomLeft[i].length == topRight[i].length == 2
1 <= bottomLeft[i][0], bottomLeft[i][1] <= 107
1 <= topRight[i][0], topRight[i][1] <= 107
bottomLeft[i][0] < topRight[i][0]
bottomLeft[i][1] < topRight[i][1]
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
96,244/144.3K
Acceptance Rate
66.7%
Topics
Array
Math
Geometry
Weekly Contest 386



*/



class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft,
                                vector<vector<int>>& topRight) {

        int n = bottomLeft.size();
        long long maxArea = 0;

        for (int i = 0; i < n; i++) {  //tc=O(n^2),  sc=O(1)
            for (int j = i + 1; j < n; j++) {
                long long xLeft   = max(bottomLeft[i][0], bottomLeft[j][0]);
                long long yBottom = max(bottomLeft[i][1], bottomLeft[j][1]);
                long long xRight  = min(topRight[i][0],   topRight[j][0]);
                long long yTop    = min(topRight[i][1],   topRight[j][1]);

                long long width  = xRight - xLeft;
                long long height = yTop - yBottom;

                if (width > 0 && height > 0) {
                    long long side = min(width, height);
                    maxArea = max(maxArea, side * side);
                }
            }
        }

        return maxArea;
    }
};





/*


qno 3813   https://leetcode.com/problems/vowel-consonant-score/



3813. Vowel-Consonant Score
Easy

Companies
Hint
You are given a string s consisting of lowercase English letters, spaces, and digits.

Let v be the number of vowels in s and c be the number of consonants in s.

A vowel is one of the letters 'a', 'e', 'i', 'o', or 'u', while any other letter in the English alphabet is considered a consonant.

The score of the string s is defined as follows:

If c > 0, the score = floor(v / c) where floor denotes rounding down to the nearest integer.
Otherwise, the score = 0.
Return an integer denoting the score of the string.

 

Example 1:

Input: s = "cooear"

Output: 2

Explanation:

The string s = "cooear" contains v = 4 vowels ('o', 'o', 'e', 'a') and c = 2 consonants ('c', 'r').

The score is floor(v / c) = floor(4 / 2) = 2.

Example 2:

Input: s = "axeyizou"

Output: 1

Explanation:

The string s = "axeyizou" contains v = 5 vowels ('a', 'e', 'i', 'o', 'u') and c = 3 consonants ('x', 'y', 'z').

The score is floor(v / c) = floor(5 / 3) = 1.

Example 3:

Input: s = "au 123"

Output: 0

Explanation:

The string s = "au 123" contains no consonants (c = 0), so the score is 0.

 

Constraints:

1 <= s.length <= 100
s consists of lowercase English letters, spaces and digits.


*/



class Solution {
public:
    int vowelConsonantScore(string s) {
        int v = 0; // number of vowels
        int c = 0; // number of consonants

        for (char ch : s) {
            if (ch >= 'a' && ch <= 'z') {   // only letters
                if (ch == 'a' || ch == 'e' || ch == 'i' ||
                    ch == 'o' || ch == 'u') {
                    v++;
                } else {
                    c++;
                }
            }
        }

        if (c == 0) return 0;
        return v / c;   // integer division = floor
    }
};





/*


qno 2027  https://leetcode.com/problems/minimum-moves-to-convert-string/


2027. Minimum Moves to Convert String
Solved
Easy
Topics

Companies
Hint
You are given a string s consisting of n characters which are either 'X' or 'O'.

A move is defined as selecting three consecutive characters of s and converting them to 'O'. Note that if a move is applied to the character 'O', it will stay the same.

Return the minimum number of moves required so that all the characters of s are converted to 'O'.

 

Example 1:

Input: s = "XXX"
Output: 1
Explanation: XXX -> OOO
We select all the 3 characters and convert them in one move.
Example 2:

Input: s = "XXOX"
Output: 2
Explanation: XXOX -> OOOX -> OOOO
We select the first 3 characters in the first move, and convert them to 'O'.
Then we select the last 3 characters and convert them so that the final string contains all 'O's.
Example 3:

Input: s = "OOOO"
Output: 0
Explanation: There are no 'X's in s to convert.
 

Constraints:

3 <= s.length <= 1000
s[i] is either 'X' or 'O'.



*/


class Solution {
public:
    int minimumMoves(string s) {
        int moves = 0;
        int i=0;
        while(i < s.size()) {
            if(s[i] == 'X') {
                moves++;
                i +=3;  //given oneMove takes threePosition
            } else {
                i++;
            }
        }
        return moves;
    }
};




/*


qno 1217   https://leetcode.com/problems/minimum-cost-to-move-chips-to-the-same-position/


1217. Minimum Cost to Move Chips to The Same Position
Solved
Easy
Topics

Companies
Hint
We have n chips, where the position of the ith chip is position[i].

We need to move all the chips to the same position. In one step, we can change the position of the ith chip from position[i] to:

position[i] + 2 or position[i] - 2 with cost = 0.
position[i] + 1 or position[i] - 1 with cost = 1.
Return the minimum cost needed to move all the chips to the same position.

 

Example 1:


Input: position = [1,2,3]
Output: 1
Explanation: First step: Move the chip at position 3 to position 1 with cost = 0.
Second step: Move the chip at position 2 to position 1 with cost = 1.
Total cost is 1.
Example 2:


Input: position = [2,2,2,3,3]
Output: 2
Explanation: We can move the two chips at position  3 to position 2. Each move has cost = 1. The total cost = 2.
Example 3:

Input: position = [1,1000000000]
Output: 1
 

Constraints:

1 <= position.length <= 100
1 <= position[i] <= 10^9
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
164,906/226.8K
Acceptance Rate
72.7%
Topics
Array
Math
Greedy
Weekly Contest 157


*/



class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int evenChips = 0;
        int oddChips = 0;

        for(int i=0; i<position.size(); i++) {
            if(position[i] % 2 == 0) {
                evenChips++;
            } else {
                
                oddChips++;
            }
        }
        int minCost = min(evenChips, oddChips);
        return minCost;
    }
};



/*


qno 3314  https://leetcode.com/problems/construct-the-minimum-bitwise-array-i/description/?envType=daily-question&envId=2026-01-20


3314. Construct the Minimum Bitwise Array I
Easy
Topics

Companies
Hint
You are given an array nums consisting of n prime integers.

You need to construct an array ans of length n, such that, for each index i, the bitwise OR of ans[i] and ans[i] + 1 is equal to nums[i], i.e. ans[i] OR (ans[i] + 1) == nums[i].

Additionally, you must minimize each value of ans[i] in the resulting array.

If it is not possible to find such a value for ans[i] that satisfies the condition, then set ans[i] = -1.

 

Example 1:

Input: nums = [2,3,5,7]

Output: [-1,1,4,3]

Explanation:

For i = 0, as there is no value for ans[0] that satisfies ans[0] OR (ans[0] + 1) = 2, so ans[0] = -1.
For i = 1, the smallest ans[1] that satisfies ans[1] OR (ans[1] + 1) = 3 is 1, because 1 OR (1 + 1) = 3.
For i = 2, the smallest ans[2] that satisfies ans[2] OR (ans[2] + 1) = 5 is 4, because 4 OR (4 + 1) = 5.
For i = 3, the smallest ans[3] that satisfies ans[3] OR (ans[3] + 1) = 7 is 3, because 3 OR (3 + 1) = 7.
Example 2:

Input: nums = [11,13,31]

Output: [9,12,15]

Explanation:

For i = 0, the smallest ans[0] that satisfies ans[0] OR (ans[0] + 1) = 11 is 9, because 9 OR (9 + 1) = 11.
For i = 1, the smallest ans[1] that satisfies ans[1] OR (ans[1] + 1) = 13 is 12, because 12 OR (12 + 1) = 13.
For i = 2, the smallest ans[2] that satisfies ans[2] OR (ans[2] + 1) = 31 is 15, because 15 OR (15 + 1) = 31.
 

Constraints:

1 <= nums.length <= 100
2 <= nums[i] <= 1000
nums[i] is a prime number.
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
41,908/53.6K
Acceptance Rate
78.3%
Topics
Array
Bit Manipulation
Biweekly Contest 141


*/



class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;

        for(int num : nums) {
            int found = -1;

            for(int x = 0; x < num; x++) {
                if ((x | (x + 1)) == num) {
                    found = x;
                    break;  // minimum x
                }
            }

            ans.push_back(found);
        }

        return ans;
    }
};
