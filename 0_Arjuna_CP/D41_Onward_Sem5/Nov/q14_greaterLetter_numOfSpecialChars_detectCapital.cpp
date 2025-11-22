#include <iostream>  // Include the header for input/output streams
using namespace std;

int main() {
    // Declare a variable to store the character 'A'
    char myCharA = 'A';
    char myCharZ = 'Z';
    
    char myChar_a = 'a';
    char myChar_z = 'z';


    cout << "The ASCII value of capital A = " << int(myCharA) << endl;
    cout << "The ASCII value of capital Z = " << int(myCharZ) << endl;
    
    cout << "The ASCII value of small a = " << int(myChar_a) << endl;
    cout << "The ASCII value of small z = " << int(myChar_z) << endl;

    return 0;
}





/*


22nd Nov 2025 (Satursday)


qno 2309  https://leetcode.com/problems/greatest-english-letter-in-upper-and-lower-case/

Concepts used in this probL: ASCII valueTable:   0_Arjuna_CP\D41_Onward_Sem5\Nov\ASCII_ValueTable_src ResearchGate.png
https://www.geeksforgeeks.org/dsa/ascii-table/

https://www.researchgate.net/publication/342461031_Improvement_of_Menezes-Vanstone_Elliptic_Curve_Cryptosystem_Based_on_Quadratic_Bezier_Curve_Technique/figures?lo=1



2309. Greatest English Letter in Upper and Lower Case
Easy
Topics

Companies
Hint
Given a string of English letters s, return the greatest English letter which occurs as both a lowercase and uppercase letter in s. The returned letter should be in uppercase. If no such letter exists, return an empty string.

An English letter b is greater than another letter a if b appears after a in the English alphabet.

 

Example 1:

Input: s = "lEeTcOdE"
Output: "E"
Explanation:
The letter 'E' is the only letter to appear in both lower and upper case.
Example 2:

Input: s = "arRAzFif"
Output: "R"
Explanation:
The letter 'R' is the greatest letter to appear in both lower and upper case.
Note that 'A' and 'F' also appear in both lower and upper case, but 'R' is greater than 'F' or 'A'.
Example 3:

Input: s = "AbCdEfGhIjK"
Output: ""
Explanation:
There is no letter that appears in both lower and upper case.
 

Constraints:

1 <= s.length <= 1000
s consists of lowercase and uppercase English letters.





*/



#include <unordered_set>
#include <algorithm>

class Solution {
public:
    string greatestLetter(string s) {  //TC=O(n), SC=O(1) only 26 alphabet
        // Create two sets to store lowercase and uppercase char
        unordered_set<char> lower, upper;
        
        // Fill the sets with the characters from the string
        for (char c : s) {
            if (isupper(c)) {
                upper.insert(c);
            } else {
                lower.insert(c);
            }
        }
        
        // Variable to keep track of the greatest letter found
        char greatest = ' ';
        
 
        for (char c : upper) {
            if (lower.count(tolower(c))) {
                // Update greatest if the current letter is greater than the previous one
                greatest = max(greatest, c);
            }
        }
        
        
        return greatest == ' ' ? "" : string(1, greatest);
    }
};




class Solution {
public:
    string greatestLetter(string s) {

        //ASCII value approach TC=o(n), SC=O(1)

        bool lower[26] = {false}; // To track lowercase letters
        bool upper[26] = {false}; 
        

        // Iterate through the string and fill the arrays
        for (char c : s) {
            if (islower(c)) {
                lower[c - 'a'] = true; // Mark the lowercase letter
            } else if (isupper(c)) {
                upper[c - 'A'] = true; // Mark the uppercase letter
            }
        }


        for (int i = 25; i >= 0; --i) {
            if (lower[i] && upper[i]) {
                return string(1, 'A' + i); // Return the letter as an uppercase
            }
        }

        return "";
    }
};




/*

qno 3120  https://leetcode.com/problems/count-the-number-of-special-characters-i/


3120. Count the Number of Special Characters I
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





note: 
islower(c): Returns true if the character c is lowercase (i.e., between 'a' and 'z').

isupper(c): Returns true if the character c is uppercase (i.e., between 'A' and 'Z').

You don’t need to define islower and isupper yourself — they are built-in functions provided by the C++ Standard Library in <cctype>. 
You just need to include this header (#include <cctype>) to use them.



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




/*

qno 520  https://leetcode.com/problems/detect-capital/description/


520. Detect Capital
Easy
Topics

Companies
We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital, like "Google".
Given a string word, return true if the usage of capitals in it is right.

 

Example 1:

Input: word = "USA"
Output: true
Example 2:

Input: word = "FlaG"
Output: false
 

Constraints:

1 <= word.length <= 100
word consists of lowercase and uppercase English letters.


*/



class Solution {
public:
    bool detectCapitalUse(string word) { //TC=O(n), SC=O(1)
        // Case1: All letters are capital letters
        if (all_of(word.begin(), word.end(), [](char c) { return isupper(c); })) {
            return true;
        }
        
        // Case2: All letters are lowercase
        if (all_of(word.begin(), word.end(), [](char c) { return islower(c); })) {
            return true;
        }
        
        // Case3: Only the first letter is capital, the rest are lowercase
        if (isupper(word[0]) && all_of(word.begin() + 1, word.end(), [](char c) { return islower(c); })) {
            return true;
        }
        
        return false;
    }
};
