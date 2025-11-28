



/*

28th Nov 2025 (Friday)


qno 1417  https://leetcode.com/problems/reformat-the-string/


1417. Reformat The String
Easy
Topics

Companies
Hint
You are given an alphanumeric string s. (Alphanumeric string is a string consisting of lowercase English letters and digits).

You have to find a permutation of the string where no letter is followed by another letter and no digit is followed by another digit. That is, no two adjacent characters have the same type.

Return the reformatted string or return an empty string if it is impossible to reformat the string.

 

Example 1:

Input: s = "a0b1c2"
Output: "0a1b2c"
Explanation: No two adjacent characters have the same type in "0a1b2c". "a0b1c2", "0a1b2c", "0c2a1b" are also valid permutations.
Example 2:

Input: s = "leetcode"
Output: ""
Explanation: "leetcode" has only characters so we cannot separate them by digits.
Example 3:

Input: s = "1229857369"
Output: ""
Explanation: "1229857369" has only digits so we cannot separate them by characters.
 

Constraints:

1 <= s.length <= 500
s consists of only lowercase English letters and/or digits.


*/


class Solution {
public:
    string reformat(string s) {   //tc=O(n), sc=o(n)
        string letters = "", digits = "";

        //separate Letters and digits
        for(char c : s) {
            if(isalpha(c)) letters += c;
            else digits += c;
        }

        //if diff > 1, impossible
        if(abs( (int)letters.size()  - (int)digits.size()) > 1) 
        return "";

        string result = "";
        //Decide which type to place first
        bool letterTurn = letters.size() > digits.size();

        int i=0, j=0;
        while(i<letters.size() || j<digits.size()) {
            if(letterTurn) {
                result += letters[i++]; 
            } else {
                result += digits[j++];
            }

            letterTurn = !letterTurn;  //alternate
        }

        return result;
    }
};




/*

qno 1078 https://leetcode.com/problems/occurrences-after-bigram/description/


1078. Occurrences After Bigram
Easy
Topics

Companies
Hint
Given two strings first and second, consider occurrences in some text of the form "first second third", where second comes immediately after first, and third comes immediately after second.

Return an array of all the words third for each occurrence of "first second third".

 

Example 1:

Input: text = "alice is a good girl she is a good student", first = "a", second = "good"
Output: ["girl","student"]
Example 2:

Input: text = "we will we will rock you", first = "we", second = "will"
Output: ["we","rock"]
 

Constraints:

1 <= text.length <= 1000
text consists of lowercase English letters and spaces.
All the words in text are separated by a single space.
1 <= first.length, second.length <= 10
first and second consist of lowercase English letters.
text will not have any leading or trailing spaces.


*/



class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> words;
        string word = "";

        // Split text into words
        for (char c : text) {
            if (c == ' ') {
                words.push_back(word);
                word = "";
            } else {
                word += c;
            }
        }
        words.push_back(word); // push last word

        vector<string> result;

        // Check consecutive triplets
        for (int i = 0; i + 2 < words.size(); i++) {
            if (words[i] == first && words[i + 1] == second) {
                result.push_back(words[i + 2]);
            }
        }

        return result;
    }
};


// Time: O(n) — scanning text and checking words
// Space: O(n) — storing words



/*





*/