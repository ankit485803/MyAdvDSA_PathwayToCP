
/*

Conclusion:
To convert a single digit character to an integer in C++, you subtract the character '0' from the character.
This works because the characters '0' through '9' are sequential in the ASCII table, making the conversion straightforward and efficient.


*/


#include <iostream>
#include <string>
using namespace std;

int main() {
    string num = "35427";
    for (int i = 0; i < num.size(); i++) {
        int digit = num[i] - '0';  // Convert character to integer
        cout << "Character: " << num[i] << " -> Integer: " << digit << endl;
    }
    return 0;
}



/*


9th Oct 2025 (Thursday) 

qno 1903    https://leetcode.com/problems/largest-odd-number-in-string/description/

Ankit learn
Converting a String Character to an Integer:
To convert a character representing a digit (e.g., '0', '1', '2') into its corresponding integer value (e.g., 0, 1, 2), you subtract the ASCII value of the character '0' from the ASCII value of the character you're interested in.
'0' has an ASCII value of 48.
'1' has an ASCII value of 49.
'2' has an ASCII value of 50

Why '0'?

The subtraction of '0' works because the characters '0' to '9' in ASCII are sequential. The ASCII values of '0' to '9' are continuous (48 to 57), so subtracting '0' from any digit gives you the correct integer representation of the digit.





1903. Largest Odd Number in String
Easy
Topics

Companies
Hint
You are given a string num, representing a large integer. Return the largest-valued odd integer (as a string) that is a non-empty substring of num, or an empty string "" if no odd integer exists.

A substring is a contiguous sequence of characters within a string.

 

Example 1:
Input: num = "52"
Output: "5"
Explanation: The only non-empty substrings are "5", "2", and "52". "5" is the only odd number.


Example 2:
Input: num = "4206"
Output: ""
Explanation: There are no odd numbers in "4206".



Example 3:
Input: num = "35427"
Output: "35427"
Explanation: "35427" is already an odd number.
 

Constraints:
1 <= num.length <= 105
num only consists of digits and does not contain any leading zeros.




Approach:
1. Start from the end of the string, since the largest odd number will likely be at the end of the string (and if it exists, it will be the longest substring).
2. Check for the first odd digit from the end of the string.
3. If an odd number is found, return the substring from the beginning up to that point.



check ODD
We convert each character (num[i]) to its integer value using num[i] - '0' and check if it is odd by checking if ((num[i] - '0') % 2 != 0).



*/


class Solution {
public:
    string largestOddNumber(string num) {
        
        //traverse all Elem from end 
        for(int i=num.size()-1; i>=0; i--) {

            //check ODD as the string, so first convert to string into integer
            if((num[i] - '0')% 2 !=  0) {
                return num.substr(0, i+1); // Return the substring from the start to the current index
            }
        }

        return "";  //if no ODD, then return empty string
    }
};

// TC=O(n)
// SC=O(n) due to the space required to store the substring that is returned



/*

qno 1832  https://leetcode.com/problems/check-if-the-sentence-is-pangram/description/



1832. Check if the Sentence Is Pangram

A pangram is a sentence where every letter of the English alphabet appears at least once.
Given a string sentence containing only lowercase English letters, return true if sentence is a pangram, or false otherwise.




*/

class Solution {
public:
    bool checkIfPangram(string sentence) { //TC=O(n), SC=(1)
        // Create a boolean array of size 26 initialized to false
        vector<bool> letterExists(26, false);

        // Traverse the string and mark the corresponding position in the array
        for (char ch : sentence) {
            letterExists[ch - 'a'] = true;
        }

        // Check if all letters from 'a' to 'z' are present
        for (bool exists : letterExists) {
            if (!exists) {
                return false;  // If any letter is missing, return false
            }
        }

        return true;  // All letters are present
    }
};



class Solution {
public:
    bool checkIfPangram(string sentence) { //TC=O(n), SC=(1)
        // Create a set to store unique characters
        unordered_set<char> uniqueChars;
        
        // Traverse the string and add each character to the set
        for (char ch : sentence) {
            uniqueChars.insert(ch);
        }
        
        // If the size of the set is 26, then it's a pangram
        return uniqueChars.size() == 26;
    }
};