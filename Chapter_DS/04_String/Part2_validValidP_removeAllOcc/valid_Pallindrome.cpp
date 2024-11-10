

#include <iostream>
using namespace std;



// qno 125:   https://leetcode.com/problems/valid-palindrome/description/

/* check valid pallindrome (from starting and ending both char same) in string may contain alph, numeric, special char

step1:  first convert all char into small using c++ funct  tolower(char)
step2: initilize the st, end and compare its from both end
step3:  ignore karo specail character  ko

*/



class Solution {
public:


    // Function to check if a character is alphanumeric
    bool isAlphaNum(char ch) {  

        if ((ch >= '0' && ch <= '9') ||  // Check if the character is a digit
            (tolower(ch) >= 'a' && tolower(ch) <= 'z')) {  // Check if the character is a letter
            return true; 
        }
        return false;  
    }



    bool isPalindrome(string s) {
        int st = 0, end = s.length() - 1;

        while (st < end) {  // O(n) time complexity

            // Move the start pointer if it's not alphanumeric
            if (! isAlphaNum(s[st])) {
                st++; continue;  
              
            }

            // Move the end pointer if it's not alphanumeric
            if (! isAlphaNum(s[end])) {
                end--; continue;  
                 
            }

            // Compare characters (case-insensitive)
            if (tolower(s[st]) != tolower(s[end])) {
                return false; 
            }

            st++; end--; 
            
        }

        return true;  
    }
};


//two pointer approch -- TC = O(1) + O(n) = O(n) ,   SC = O(1)