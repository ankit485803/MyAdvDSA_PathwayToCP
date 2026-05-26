

/*


26th May 2026 (Tuesday)

qno 3120  https://leetcode.com/problems/count-the-number-of-special-characters-i/description/?envType=daily-question&envId=2026-05-26
already solved on 22nd Nov 2025


3120. Count the Number of Special Characters I
Solved
Easy
Topics

Companies
Hint
You are given a string word. A letter is called special if it appears both in lowercase and uppercase in word.

Return the number of special letters in word.

 

Example 1:

Input: word = "aaAbcBC"

Output: 3

Explanation:

The special characters in word are 'a', 'b', and 'c'.

Example 2:

Input: word = "abc"

Output: 0

Explanation:

No character in word appears in uppercase.

Example 3:

Input: word = "abBCab"

Output: 1

Explanation:

The only special character in word is 'b'.

 

Constraints:

1 <= word.length <= 50
word consists of only lowercase and uppercase English letters.
 

Seen this question in a real interview before?
1/6
Yes
No
Accepted
142,635/189.6K
Acceptance Rate
75.2%
Topics
Mid Level
Hash Table
String
Weekly Contest 394




*/



#include <cctype>  //for islower, isupper function

class Solution {
public:
    int numberOfSpecialChars(string word) {
        
        bool lower[26] = {false};
        bool upper[26] = {false};

        for(char c : word) {
            if(islower(c)) {  //using C++ STL funct islower
                lower[c - 'a'] = true;  //markLower
            } else if(isupper(c)) {
                upper[c - 'A'] = true;
            }
        }


        //nowCountSpecialChar
        int count = 0;
        for(int i=0; i<26; ++i) {
            if(lower[i] && upper[i]) {
                count++;
            }
        }

        return count;
    }
};



//today submitted
#include <cctype> //for islower, isupper funct STL  c++

class Solution {
public:
    int numberOfSpecialChars(string word) {  //tc=O(n), sc=O(1)
        //step1: take two variable 
        bool lower[26] = {false};
        bool upper[26] = {false};

        //step2: assig lower, upper char
        for(char c : word) {
            if(islower(c)) {   //using STL
                lower[c - 'a'] = true;  
            } else {
                upper[c - 'A'] = true;
            }
        }

        //step3: count specialChar
        int count = 0;

        for(int i=0; i < 26; i++) {
            if(lower[i] && upper[i]) {   //bothCharPresent
                count++;
            }
        }

        return count;
    }
};



class Solution {
public:
    int numberOfSpecialChars(string word) {  //without STL tc=O(26 * n), sc=O(1)
        int count = 0;

        // Check every lowercase alphabet
        for (char ch = 'a'; ch <= 'z'; ch++) {

            bool lowerFound = false;
            bool upperFound = false;

            // Traverse the string
            for (int i = 0; i < word.length(); i++) {

                // lowercase check
                if (word[i] == ch)
                    lowerFound = true;

                // corresponding uppercase check
                if (word[i] == (ch - 'a' + 'A'))
                    upperFound = true;
            }

            // both present
            if (lowerFound && upperFound)
                count++;
        }

        return count;
    }
};