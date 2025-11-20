

/*

7th Oct 2025 (Tuesday) 

qno 709  https://leetcode.com/problems/to-lower-case/description/


Ankit Learn
A - 65,  a-97
Z - 90,  z-122
the difference between an uppercase letter and its lowercase equivalent is always 32 in the ASCII table. This is true for all alphabetic letters.





Given a string s, return the string after replacing every uppercase letter with the same lowercase letter.

 

Example 1:
Input: s = "Hello"
Output: "hello"


Example 2:
Input: s = "here"
Output: "here"



Example 3:
Input: s = "LOVELY"
Output: "lovely"




*/



        //first change char  -- logic
        char toLowerCase(char ch) {
            if(ch >= 'A'  &&  ch <= 'Z') {
                return ch + ('a' - 'A');
            } else {
                return ch;   //if not uppercase
            }
        }


        void stringToLower(char* str) {
            int i=0;
            while(str[i]  !=  0) {
                str[i] = toLowerCase(str[i]);
                i++;
            }
        }


        
//for lower to uppercase 
for (int i = 0; i < s.size(); i++) {
    if (s[i] >= 'a' && s[i] <= 'z') { 
        s[i] = s[i] - ('a' - 'A');  // Convert lowercase to uppercase
    }
}
return s;




//final solution of this problem
class Solution {
public:
    string toLowerCase(string s) {
        
        for(int i=0; i<s.size(); i++) {

             //ASCII value a =  97, z = 122   
            if(s[i] >= 'A'  &&  s[i] <= 'Z') {    //A -> 65 and Z -> 70,

                s[i] = s[i] + ('a' - 'A'); // LC = LC + diff between ASCII value of small and big 
            }
        }

        return s;
    }
};

//TC=O(n), sc=O(1)




/*

qno 1816   https://leetcode.com/problems/truncate-sentence/description/





1816. Truncate Sentence
Easy
Topics

Companies
Hint
A sentence is a list of words that are separated by a single space with no leading or trailing spaces. Each of the words consists of only uppercase and lowercase English letters (no punctuation).

For example, "Hello World", "HELLO", and "hello world hello world" are all sentences.
You are given a sentence s​​​​​​ and an integer k​​​​​​. You want to truncate s​​​​​​ such that it contains only the first k​​​​​​ words. Return s​​​​​​ after truncating it.

 

Example 1:

Input: s = "Hello how are you Contestant", k = 4
Output: "Hello how are you"
Explanation:
The words in s are ["Hello", "how" "are", "you", "Contestant"].
The first 4 words are ["Hello", "how", "are", "you"].
Hence, you should return "Hello how are you".






our approach
step1. Iterate each character of the string.
2. Count how many spaces you see (each space = one word ended).
3. Stop when you've reached k words.
4.  Return the substring from the start up to that point.



*/





class Solution {
public:
    string truncateSentence(string s, int k) {
        
        //ourApproach:  Count how many spaces you see (each space = one word ended)
        int spaceCount = 0;
        
        for(int i=0; i<s.size(); i++) {
            if(s[i] == ' ') {   //jab space ho word ke before
                spaceCount ++;

                if(spaceCount == k) {
                    return s.substr(0, i);   //Return up to the k-th word (before this space)
                }
            }
        }

        // If k is equal to the number of words in s, return whole string
        return s;
    }
};


//TC+O(n), sc=O(1)