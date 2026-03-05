
/*

5th March 2026 (Thursday)


qno 1758     https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/?envType=daily-question&envId=2026-03-05


1758. Minimum Changes To Make Alternating Binary String
Solved
Easy
Topics

Companies
Hint
You are given a string s consisting only of the characters '0' and '1'. In one operation, you can change any '0' to '1' or vice versa.

The string is called alternating if no two adjacent characters are equal. For example, the string "010" is alternating, while the string "0100" is not.

Return the minimum number of operations needed to make s alternating.

 

Example 1:

Input: s = "0100"
Output: 1
Explanation: If you change the last character to '1', s will be "0101", which is alternating.
Example 2:

Input: s = "10"
Output: 0
Explanation: s is already alternating.
Example 3:

Input: s = "1111"
Output: 2
Explanation: You need two operations to reach "0101" or "1010".
 

Constraints:

1 <= s.length <= 104
s[i] is either '0' or '1'.
 
Discover more
Online Assessment Services
Seen this question in a real interview before?
1/5
Yes
No
Accepted
171,015/266.5K
Acceptance Rate
64.2%
Topics
Mid Level
String
Weekly Contest 228


*/



class Solution {
public:
    int minOperations(string s) {  //TC=O(n),SC=O(1)
 
        int countZ = 0; //zeros
        int countO = 0;  //ones counting

        for (int i = 0; i < s.size(); i++) {

            // Case1: evenIndex (i = 0, 2, 4, ...)
            if (i % 2 == 0) {
                // For pattern "0101...", even positions should be '0'
                if (s[i] != '0') countZ++;

                // For pattern "1010...", even positions should be '1'
                if (s[i] != '1') countO++;
               } 



            // Case2: oddIndex (i = 1, 3, 5, ...)
            else {
                // For pattern "0101...", odd positions should be '1'
                if (s[i] != '1') countZ++;

                // For pattern "1010...", odd positions should be '0'
                if (s[i] != '0') countO++;
               }
        }


        return min(countZ, countO);
      }
};





class Solution {
public:
    int minOperations(string s) {
        int pattern1 = 0, pattern2 = 0;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] != (i % 2 ? '1' : '0')) pattern1++; // 0101
            if(s[i] != (i % 2 ? '0' : '1')) pattern2++; // 1010
        }

        return min(pattern1, pattern2);
    }
};




/*

qno 3856   https://leetcode.com/problems/trim-trailing-vowels/


3856. Trim Trailing Vowels
Easy

Companies
Hint
You are given a string s that consists of lowercase English letters.

Return the string obtained by removing all trailing vowels from s.

The vowels consist of the characters 'a', 'e', 'i', 'o', and 'u'.

 

Example 1:

Input: s = "idea"

Output: "id"

Explanation:

Removing "idea", we obtain the string "id".

Example 2:

Input: s = "day"

Output: "day"

Explanation:

There are no trailing vowels in the string "day".

Example 3:

Input: s = "aeiou"

Output: ""

Explanation:

Removing "aeiou", we obtain the string "".

 

Constraints:

1 <= s.length <= 100
s consists of only lowercase English letters.
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
45,436/58.9K
Acceptance Rate
77.2%
Topics
Mid Level
Weekly Contest 491


*/




class Solution {
private:
    bool isVowel(char ch) {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||) {
            return true;
        } else {
            false;
        }
    }    

public:
    string trimTrailingVowels(string s) {
        //vowels that are at the end of str: Trailing
        //trim: cut into pieces
        vector<char> st;
        
    }
};




class Solution {
private:
    bool isVowel(char ch) {  //tc=O(n), sc=O(1)
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            return true;
        } else {
            return false;
        }
    }    

public:
    string trimTrailingVowels(string s) {
        //vowels that are at the end of str: Trailing
        //trim: cut into pieces
        int i = s.size() - 1;

        while(i >= 0 && isVowel(s[i])) {  //loop strats from endStr
            i--;
        }
        return s.substr(0, i+1);

    }
};


