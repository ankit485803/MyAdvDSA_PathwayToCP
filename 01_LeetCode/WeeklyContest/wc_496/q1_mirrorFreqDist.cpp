


/* qno 3889 https://leetcode.com/problems/mirror-frequency-distance/description/

https://leetcode.com/discuss/post/951105/new-contest-rule-updated-in-sep-2024-by-zowhy/



5th April 2026 (Sunday- sem6 3rd Year IITP) weeklyContest LeetCode 496

https://leetcode.com/contest/weekly-contest-496/


q1  https://leetcode.com/contest/weekly-contest-496/problems/mirror-frequency-distance/

Q1. Mirror Frequency Distance
Medium
4 pt.
You are given a string s consisting of lowercase English letters and digits.

For each character, its mirror character is defined by reversing the order of its character set:

For letters, the mirror of a character is the letter at the same position from the end of the alphabet.
For example, the mirror of 'a' is 'z', and the mirror of 'b' is 'y', and so on.
For digits, the mirror of a character is the digit at the same position from the end of the range '0' to '9'.
For example, the mirror of '0' is '9', and the mirror of '1' is '8', and so on.
For each unique character c in the string:

Let m be its mirror character.
Let freq(x) denote the number of times character x appears in the string.
Compute the absolute difference between their frequencies, defined as: |freq(c) - freq(m)|
The mirror pairs (c, m) and (m, c) are the same and must be counted only once.

Return an integer denoting the total sum of these values over all such distinct mirror pairs.

 

Example 1:

Input: s = "ab1z9"

Output: 3

Explanation:

For every mirror pair:

c	m	freq(c)	freq(m)	|freq(c) - freq(m)|
a	z	1	1	0
b	y	1	0	1
1	8	1	0	1
9	0	1	0	1
Thus, the answer is 0 + 1 + 1 + 1 = 3.

Example 2:

Input: s = "4m7n"

Output: 2

Explanation:

c	m	freq(c)	freq(m)	|freq(c) - freq(m)|
4	5	1	0	1
m	n	1	1	0
7	2	1	0	1
Thus, the answer is 1 + 0 + 1 = 2.​​​​​​​

Example 3:

Input: s = "byby"

Output: 0

Explanation:

c	m	freq(c)	freq(m)	|freq(c) - freq(m)|
b	y	2	2	0
Thus, the answer is 0.

 

Constraints:

1 <= s.length <= 5 * 105
s consists only of lowercase English letters and digits.
 
Copyright © 2026 LeetCode. All rights reserved.



baseCase: if s is symmetry return ans = 0; step1: iterate each Unique char and take mirror step2:
 calcuate freq(c), freq(m) step3: find absDiff freqC - freqM , return sum of all


*/

class Solution {
public:
    int mirrorFrequency(string s) {  //tc=O(n), sc=O(1)
        vector<int> freq(128, 0);
        
        // Step 1: Count frequency
        for (char c : s) {
            freq[c]++;
        }
        
        int ans = 0;
        
        // Step 2: Iterate over all possible charsa
        for (char c = 'a'; c <= 'z'; c++) {
            char m = 'z' - (c - 'a');
            
            if (c > m) continue; // avoid double counting
            
            ans += abs(freq[c] - freq[m]);
        }
        
        for (char c = '0'; c <= '9'; c++) {
            char m = '9' - (c - '0');
            
            if (c > m) continue; // avoid double counting
            
            ans += abs(freq[c] - freq[m]);
        }
        
        return ans;
    }
};





class Solution {
public:
    int mirrorFrequency(string s) {
        
        vector<int> f(128);
        for(char c : s) f[c]++;
        int ans = 0;
        vector<bool> vis(128);
        for(char c : s){
            if(vis[c]) continue;
            char m;
            if(isalpha(c)) m = 'z' - (c - 'a');
            else m = '9' - (c - '0');
            ans += abs(f[c] - f[m]);
            vis[c] = vis[m] = 1;
        }
        return ans;
    }
};