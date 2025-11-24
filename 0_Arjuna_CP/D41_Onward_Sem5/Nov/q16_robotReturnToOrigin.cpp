



/*

24th Nov 2025 (Monday)


qno  657  https://leetcode.com/problems/robot-return-to-origin/


657. Robot Return to Origin
Easy
Topics

Companies
There is a robot starting at the position (0, 0), the origin, on a 2D plane. Given a sequence of its moves, judge if this robot ends up at (0, 0) after it completes its moves.

You are given a string moves that represents the move sequence of the robot where moves[i] represents its ith move. Valid moves are 'R' (right), 'L' (left), 'U' (up), and 'D' (down).

Return true if the robot returns to the origin after it finishes all of its moves, or false otherwise.

Note: The way that the robot is "facing" is irrelevant. 'R' will always make the robot move to the right once, 'L' will always make it move left, etc. Also, assume that the magnitude of the robot's movement is the same for each move.

 

Example 1:

Input: moves = "UD"
Output: true
Explanation: The robot moves up once, and then down once. All moves have the same magnitude, so it ended up at the origin where it started. Therefore, we return true.
Example 2:

Input: moves = "LL"
Output: false
Explanation: The robot moves left twice. It ends up two "moves" to the left of the origin. We return false because it is not at the origin at the end of its moves.
 

Constraints:

1 <= moves.length <= 2 * 104
moves only contains the characters 'U', 'D', 'L' and 'R'.



*/


class Solution {
public:
    bool judgeCircle(string moves) {  //TC=O(n), SC=O(1)
        //startWithOrigin
        int x=0, y=0;

        for(char mov : moves) {
            if(mov == 'U') {
                y++;
            } else if(mov == 'D') {
                y--; //move down decrease y coord

            } else if(mov == 'L') {
                x--;  
            } else if(mov == 'R') {
                x++;
            }
        }

        return (x == 0 && y == 0);
    }
};




/*

qno 1930   https://leetcode.com/problems/unique-length-3-palindromic-subsequences/


1930. Unique Length-3 Palindromic Subsequences
Medium
Topics

Companies
Hint
Given a string s, return the number of unique palindromes of length three that are a subsequence of s.

Note that even if there are multiple ways to obtain the same subsequence, it is still only counted once.

A palindrome is a string that reads the same forwards and backwards.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
 

Example 1:

Input: s = "aabca"
Output: 3
Explanation: The 3 palindromic subsequences of length 3 are:
- "aba" (subsequence of "aabca")
- "aaa" (subsequence of "aabca")
- "aca" (subsequence of "aabca")
Example 2:

Input: s = "adc"
Output: 0
Explanation: There are no palindromic subsequences of length 3 in "adc".
Example 3:

Input: s = "bbcbaba"
Output: 4
Explanation: The 4 palindromic subsequences of length 3 are:
- "bbb" (subsequence of "bbcbaba")
- "bcb" (subsequence of "bbcbaba")
- "bab" (subsequence of "bbcbaba")
- "aba" (subsequence of "bbcbaba")
 

Constraints:

3 <= s.length <= 105
s consists of only lowercase English letters.

Accepted
360,054/487.9K
Acceptance Rate
73.8%
Topics
Hash Table
String
Bit Manipulation
Prefix Sum
Weekly Contest 249


*/





class Solution {
public:
    int countPalindromicSubsequence(string s) {  //TC=O(n), sc=O(1)
        int n = s.length();
        
        // Step1: Track first and last  
        vector<int> first(26, -1);   
        vector<int> last(26, -1);   
        

        // Step2: Iterate through the string to fill the first and last  
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (first[c - 'a'] == -1) {
                first[c - 'a'] = i;
            }
            last[c - 'a'] = i;
        }
        
        // Step3: Count no of palindromic subseq
        int ans = 0;
        
        for (int i = 0; i < 26; i++) {
            if (first[i] == -1) {
                continue;   
            }
            
            int st = first[i];  
            int end = last[i];    
            
            unordered_set<char> unique;   
            
            // Step4: Collect unique 
            for (int j = st + 1; j < end; j++) {
                unique.insert(s[j]);
            }
            
            ans += unique.size();
        }
        
        return ans;
    }
};



/*

qno 3190  https://leetcode.com/problems/find-minimum-operations-to-make-all-elements-divisible-by-three/description/


3190. Find Minimum Operations to Make All Elements Divisible by Three
Attempted
Easy
Topics

Companies
Hint
You are given an integer array nums. In one operation, you can add or subtract 1 from any element of nums.

Return the minimum number of operations to make all elements of nums divisible by 3.

 

Example 1:

Input: nums = [1,2,3,4]

Output: 3

Explanation:

All array elements can be made divisible by 3 using 3 operations:

Subtract 1 from 1.
Add 1 to 2.
Subtract 1 from 4.
Example 2:

Input: nums = [3,6,9]

Output: 0

 

Constraints:

1 <= nums.length <= 50
1 <= nums[i] <= 50


*/


class Solution {
public:
    int minimumOperations(vector<int>& nums) {  //myfirstWrongApproach
        int sum = 0;
        
        for(int i=0; i<nums.size(); i++) {
            sum += nums[i];  //calculate sum of elem in arr

            if((sum % 3) == 0) {
                return 0;  //no need of operatation 
            } else {
                return (sum % 3);  //remainder subtract from num will ans
            }
        }
    }
};




class Solution {
public:
    int minimumOperations(vector<int>& nums) {  //TC=O(n), SC=O(1)
        int op = 0;  //operation

        for(int num : nums) {
            int rem = num % 3;
            if(rem == 1) {
                op += 1;  //1 op needed to sub 1

            } else if(rem == 2) {
                op += 1;  //2 op needed to add 1
            }
        }

        return op;
    }
};


class Solution {
public:
    int minimumOperations(vector<int>& nums) {  //method2 - same tc, sc
        int ans = 0;
        for(int i=0; i<nums.size(); i++) {
            int rem = nums[i] % 3;
            ans += min(rem, 3-rem);
        }
        return ans;
    }
};



/*




*/