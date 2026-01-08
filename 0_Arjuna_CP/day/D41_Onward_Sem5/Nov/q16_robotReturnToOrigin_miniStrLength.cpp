



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

qno 2491  https://leetcode.com/problems/divide-players-into-teams-of-equal-skill/description/


2491. Divide Players Into Teams of Equal Skill
Solved
Medium
Topics

Companies
Hint
You are given a positive integer array skill of even length n where skill[i] denotes the skill of the ith player. Divide the players into n / 2 teams of size 2 such that the total skill of each team is equal.

The chemistry of a team is equal to the product of the skills of the players on that team.

Return the sum of the chemistry of all the teams, or return -1 if there is no way to divide the players into teams such that the total skill of each team is equal.

 

Example 1:

Input: skill = [3,2,5,1,3,4]
Output: 22
Explanation: 
Divide the players into the following teams: (1, 5), (2, 4), (3, 3), where each team has a total skill of 6.
The sum of the chemistry of all the teams is: 1 * 5 + 2 * 4 + 3 * 3 = 5 + 8 + 9 = 22.
Example 2:

Input: skill = [3,4]
Output: 12
Explanation: 
The two players form a team with a total skill of 7.
The chemistry of the team is 3 * 4 = 12.
Example 3:

Input: skill = [1,1,2,3]
Output: -1
Explanation: 
There is no way to divide the players into teams such that the total skill of each team is equal.
 

Constraints:

2 <= skill.length <= 105
skill.length is even.
1 <= skill[i] <= 1000
 
Discover more
Programming language textbooks
coding
Seen this question in a real interview before?
1/5
Yes
No
Accepted
196,329/284.9K
Acceptance Rate
68.9%
Topics
Array
Hash Table
Two Pointers
Sorting
Weekly Contest 322

*/


class Solution {
public:
    long long dividePlayers(vector<int>& skill) { //TC=O(n logN), SC=O(1)
        int n = skill.size();
        sort(skill.begin(), skill.end());

        int pairSum = skill[0] + skill[n-1];
        //possiblePair using twoPointer
        int i=0, j=n-1;
        long chem = 0;

        while(i < j) {
            if(skill[i] + skill[j] != pairSum) {
                return -1;
            }
            chem += (long)skill[i] * skill[j];
            i++;
            j--;
        }
        return chem;
    }
};



/*

qno 1047  https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/description/

1047. Remove All Adjacent Duplicates In String
Easy
Topics

Companies
Hint
You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.

We repeatedly make duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.

 

Example 1:

Input: s = "abbaca"
Output: "ca"
Explanation: 
For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".
Example 2:

Input: s = "azxxzy"
Output: "ay"
 

Constraints:

1 <= s.length <= 105
s consists of lowercase English letters.
 
Discover more
LeetCode Premium subscription
Seen this question in a real interview before?
1/5
Yes
No
Accepted
799,929/1.1M
Acceptance Rate
72.3%
Topics
String
Stack
Weekly Contest 137

*/


class Solution {
public:
    string removeDuplicates(string s) {  //TC=O(n)
        stack<char> stk;  //sc = O(n)

        for(char c : s) {
            if(!stk.empty() && stk.top() == c) {
                stk.pop();  //remove topElem (duplicate pair)
            } else {
                stk.push(c); //add currChar
            }
        }

        //build result from stack
        string result = "";
        while(!stk.empty()) {
            result = stk.top() + result;
            stk.pop();
        }
        return result;
    }
};




/*

qno  2716  https://leetcode.com/problems/minimize-string-length/description/



2716. Minimize String Length
Easy
Topics

Companies
Hint
Given a string s, you have two types of operation:

Choose an index i in the string, and let c be the character in position i. Delete the closest occurrence of c to the left of i (if exists).
Choose an index i in the string, and let c be the character in position i. Delete the closest occurrence of c to the right of i (if exists).
Your task is to minimize the length of s by performing the above operations zero or more times.

Return an integer denoting the length of the minimized string.

 

Example 1:

Input: s = "aaabc"

Output: 3

Explanation:

Operation 2: we choose i = 1 so c is 'a', then we remove s[2] as it is closest 'a' character to the right of s[1].
s becomes "aabc" after this.
Operation 1: we choose i = 1 so c is 'a', then we remove s[0] as it is closest 'a' character to the left of s[1].
s becomes "abc" after this.
Example 2:

Input: s = "cbbd"

Output: 3

Explanation:

Operation 1: we choose i = 2 so c is 'b', then we remove s[1] as it is closest 'b' character to the left of s[1].
s becomes "cbd" after this.
Example 3:

Input: s = "baadccab"

Output: 4

Explanation:

Operation 1: we choose i = 6 so c is 'a', then we remove s[2] as it is closest 'a' character to the left of s[6].
s becomes "badccab" after this.
Operation 2: we choose i = 0 so c is 'b', then we remove s[6] as it is closest 'b' character to the right of s[0].
s becomes "badcca" fter this.
Operation 2: we choose i = 3 so c is 'c', then we remove s[4] as it is closest 'c' character to the right of s[3].
s becomes "badca" after this.
Operation 1: we choose i = 4 so c is 'a', then we remove s[1] as it is closest 'a' character to the left of s[4].
s becomes "bdca" after this.
 

Constraints:

1 <= s.length <= 100
s contains only lowercase English letters



*/


class Solution {
public:
    int minimizedStringLength(string s) {  //TC=O(size of str), SC=O(no of uniqChar)
        unordered_set<char> uniqChar;

        for(char c : s) {
            uniqChar.insert(c);
        }

        return uniqChar.size();
    }
};


class Solution {
public:
    int minimizedStringLength(string s) {
        int n = s.length();   
        
        // Create a boolean array to track the presence of each character (for 'a' to 'z')
        bool count[26] = {false};  // Array to track if a character has been seen
        int len = 0;  // Variable to store the number of unique characters



        for (int i = 0; i < n; i++) {
            char c = s[i];  
            // If the character has not been seen before, mark it and increment the unique count
            if (!count[c - 'a']) {
                count[c - 'a'] = true;
                len++;
            }
        }

        return len;   
    }
};
