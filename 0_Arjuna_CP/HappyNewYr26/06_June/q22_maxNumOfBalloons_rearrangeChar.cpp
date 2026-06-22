

/*

22nd June 2026 (Monday)

qno 1189  https://leetcode.com/problems/maximum-number-of-balloons/description/?envType=daily-question&envId=2026-06-22

1189. Maximum Number of Balloons
Solved
Easy
Topics

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

 
Discover more
Electronic Components
Power Supplies
Seen this question in a real interview before?
1/6
Yes
No
Accepted
427,120/681.1K
Acceptance Rate
62.7%
Topics
Mid Level
Hash Table
String
Counting
Weekly Contest 154


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



class Solution {
public:
    int maxNumberOfBalloons(string text) {  //tc=O(n), sc=O(1)  not passed all the testcases
        //step1: iterate each char in str to count freq
        int b=0, a = 0, l=0, o = 0, n=0;

        for(char ch : text) {
            if(ch == 'b') b++;
            else if(ch == 'a') a++;
            else if(ch == 'l') l++;
            else if(ch == 'o') o++;
            else {
                n++;
            }
        }

        //step2: instance BALLON condition 
        int count = 0;  //no of ballon

        if(b >= 1 && a >= 1 && l >= 2 && o >= 1 && n >= 1) {
            count++;
        }
        return count;
    }
};


/* The answer is the minimum among these available counts:

b,
a,
l / 2,
o / 2,
n

Your approach only checks whether one "balloon" can be formed. The problem asks for the maximum number of "balloon" instances.

*/

class Solution {
public:
    int maxNumberOfBalloons(string text) {  //tc=O(n), sc=O(1)
        //step1: iterate each char in str to count freq
        int b=0, a = 0, l=0, o = 0, n=0;

        for(char ch : text) {
            if(ch == 'b') b++;
            else if(ch == 'a') a++;
            else if(ch == 'l') l++;
            else if(ch == 'o') o++;
            else if(ch == 'n') n++;
        }

        //step2: instance BALLON condition 
        int ans = min({b, a, l / 2, o / 2, n});
        return ans;
    }
};


//Alternative (using frequency array)
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> freq(26, 0);

        for (char ch : text)
            freq[ch - 'a']++;

        return min({
            freq['b' - 'a'],
            freq['a' - 'a'],
            freq['l' - 'a'] / 2,
            freq['o' - 'a'] / 2,
            freq['n' - 'a']
        });
    }
};



/*

qno 2287 https://leetcode.com/problems/rearrange-characters-to-make-target-string/

2287. Rearrange Characters to Make Target String
Solved
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

 
Discover more
Technical interview resources
Seen this question in a real interview before?
1/6
Yes
No
Accepted
61,371/98.3K
Acceptance Rate
62.4%
Topics
Mid Level
Hash Table
String
Counting
Weekly Contest 295

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



class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        vector<int> sFreq(26, 0);
        vector<int> targetFreq(26, 0);

        for(char c : s)
            sFreq[c - 'a']++;

        for(char c : target)
            targetFreq[c - 'a']++;

        int ans = INT_MAX;

        for(int i = 0; i < 26; i++) {
            if(targetFreq[i] > 0) {
                ans = min(ans, sFreq[i] / targetFreq[i]);
            }
        }

        return ans;
    }
};



class Solution {
public:
    int rearrangeCharacters(string s, string target) {  //tc=O(n), sc=O(1)
        vector<int> sFreq(26, 0);
        vector<int> targetFreq(26, 0);

        //freq
        for(char c : s) 
            sFreq[c - 'a']++;

        for(char c : target) 
            targetFreq[c - 'a']++;

        //mainLogic
        int ans = INT_MAX;

        for(int i=0; i<26; i++) {
            if(targetFreq[i] > 0) {
                ans = min(ans, sFreq[i] / targetFreq[i]); 
            }
        }

        return ans;
    }   
};


git commit -m "maxNumberOfBalloons probNo 1189 and rearrangeChar probNo 2287 LeetCode ques solved"