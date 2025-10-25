


/*

25th Oct 2025 (Satursday at Lucknow Samarth Home)


qno 3461  https://leetcode.com/problems/check-if-digits-are-equal-in-string-after-operations-i/description/

3461. Check If Digits Are Equal in String After Operations I
Easy
Topics

Companies
Hint
You are given a string s consisting of digits. Perform the following operation repeatedly until the string has exactly two digits:

For each pair of consecutive digits in s, starting from the first digit, calculate a new digit as the sum of the two digits modulo 10.
Replace s with the sequence of newly calculated digits, maintaining the order in which they are computed.
Return true if the final two digits in s are the same; otherwise, return false.

 

Example 1:

Input: s = "3902"

Output: true

Explanation:

Initially, s = "3902"
First operation:
(s[0] + s[1]) % 10 = (3 + 9) % 10 = 2
(s[1] + s[2]) % 10 = (9 + 0) % 10 = 9
(s[2] + s[3]) % 10 = (0 + 2) % 10 = 2
s becomes "292"
Second operation:
(s[0] + s[1]) % 10 = (2 + 9) % 10 = 1
(s[1] + s[2]) % 10 = (9 + 2) % 10 = 1
s becomes "11"
Since the digits in "11" are the same, the output is true.
Example 2:

Input: s = "34789"

Output: false

Explanation:

Initially, s = "34789".
After the first operation, s = "7157".
After the second operation, s = "862".
After the third operation, s = "48".
Since '4' != '8', the output is false.
 

Constraints:

3 <= s.length <= 100
s consists of only digits


*/

class Solution {
public:
    bool hasSameDigits(string s) { //TC=O(n^2), sc=(1)
        
        //Keep reducing the string until we have exactly twoDigits
        while(s.size() > 2) {
            string new_s = "";

            //performOperation onEachPair of consecutiveDigits
            for(int i=0; i<s.size()-1; i++){

                int sum = (s[i]-'0'  + s[i+1]-'0')  % 10;  //addConsecutiveDigits-Step 1: calculate (digit1 + digit2) % 10
                new_s += to_string(sum);  //Step2: append the new digit to new_s

            }

            s = new_s;  //Update s with the newStr
        }


        // After reducing to two digits, check if they are equal
        return s[0]  == s[1];
    }
};



/*

qno 628  https://leetcode.com/problems/maximum-product-of-three-numbers/description/




628. Maximum Product of Three Numbers
Attempted
Easy
Topics

Companies
Given an integer array nums, find three numbers whose product is maximum and return the maximum product.

 

Example 1:

Input: nums = [1,2,3]
Output: 6
Example 2:

Input: nums = [1,2,3,4]
Output: 24
Example 3:

Input: nums = [-1,-2,-3]
Output: -6
 

Constraints:

3 <= nums.length <= 104



ankit learn: Because that’s three smallest numbers, and their product will almost always be negative or smaller in magnitude.

*/

class Solution {
public:
    int maximumProduct(vector<int>& nums) {  //TC=O(nLogN), sc=O(1)
        int n = nums.size();

 
        sort(nums.begin(), nums.end());  // O(n log n)

        // Option 1: product of three largest numbers
        int option1 = nums[n - 1] * nums[n - 2] * nums[n - 3];

        // Option 2: product of two smallest (possibly negative) and largest number
        int option2 = nums[0] * nums[1] * nums[n - 1];

      
        return max(option1, option2);
    }
};


/*

qno 728  https://leetcode.com/problems/self-dividing-numbers/description/

728. Self Dividing Numbers
Attempted
Easy
Topics

Companies
Hint
A self-dividing number is a number that is divisible by every digit it contains.

For example, 128 is a self-dividing number because 128 % 1 == 0, 128 % 2 == 0, and 128 % 8 == 0.
A self-dividing number is not allowed to contain the digit zero.

Given two integers left and right, return a list of all the self-dividing numbers in the range [left, right] (both inclusive).

 

Example 1:

Input: left = 1, right = 22
Output: [1,2,3,4,5,6,7,8,9,11,12,15,22]
Example 2:

Input: left = 47, right = 85
Output: [48,55,66,77]
 

Constraints:

1 <= left <= right <= 104


*/


class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans; // store the valid self-dividing numbers

        for (int i = left; i <= right; i++) {
            int n = i;
            bool isSelfDividing = true;

            // check all digits
            while (n > 0) {
                int digit = n % 10; // extract last digit
                if (digit == 0 || i % digit != 0) {
                    isSelfDividing = false; // fails the condition
                    break;
                }
                n /= 10; // remove last digit
            }

            if (isSelfDividing)
                ans.push_back(i);
        }

        return ans;
    }
};



/*

qno  37  https://leetcode.com/problems/sudoku-solver/description/



*/

class Solution {
public:
    // Check if placing digit 'dig' is safe in row, col
    bool isSafe(vector<vector<char>>& board, int row, int col, char dig) {
        // Check row
        for(int j = 0; j < 9; j++) {
            if(board[row][j] == dig) {
                return false;
            }
        }

        // Check column
        for(int i = 0; i < 9; i++) {
            if(board[i][col] == dig) {
                return false;
            }
        }

        // Check 3x3 subgrid
        int srow = (row / 3) * 3;
        int scol = (col / 3) * 3;
        for(int i = srow; i < srow + 3; i++) {
            for(int j = scol; j < scol + 3; j++) {
                if(board[i][j] == dig) {
                    return false;
                }
            }
        }

        return true;
    }

    // Helper function to solve Sudoku using backtracking
    bool helper(vector<vector<char>>& board, int row, int col) {
        // Base case: if we've reached the 9th row, return true (solved)
        if(row == 9) {
            return true;
        }

        // Move to the next column
        int nextRow = row, nextCol = col + 1;
        if(nextCol == 9) {
            nextRow = row + 1;
            nextCol = 0;
        }

        // Skip cells that are already filled
        if(board[row][col] != '.') {
            return helper(board, nextRow, nextCol);
        }

        // Try digits '1' to '9'
        for(char dig = '1'; dig <= '9'; dig++) {
            if(isSafe(board, row, col, dig)) {
                board[row][col] = dig; // Place the digit

                // Recursively solve the next cell
                if(helper(board, nextRow, nextCol)) {
                    return true;
                }

                board[row][col] = '.'; // Backtrack if the solution is not found
            }
        }

        return false;
    }

    // Main function to solve the Sudoku
    void solveSudoku(vector<vector<char>>& board) {
        helper(board, 0, 0); // Start solving from the top-left corner
    }
};


// TC = O(9 ** no of empty cell)



/*

qno  2490  https://leetcode.com/problems/circular-sentence/description/

2490. Circular Sentence
Easy
Topics

Companies
Hint
A sentence is a list of words that are separated by a single space with no leading or trailing spaces.

For example, "Hello World", "HELLO", "hello world hello world" are all sentences.
Words consist of only uppercase and lowercase English letters. Uppercase and lowercase English letters are considered different.

A sentence is circular if:

The last character of each word in the sentence is equal to the first character of its next word.
The last character of the last word is equal to the first character of the first word.
For example, "leetcode exercises sound delightful", "eetcode", "leetcode eats soul" are all circular sentences. However, "Leetcode is cool", "happy Leetcode", "Leetcode" and "I like Leetcode" are not circular sentences.

Given a string sentence, return true if it is circular. Otherwise, return false.

 

Example 1:

Input: sentence = "leetcode exercises sound delightful"
Output: true
Explanation: The words in sentence are ["leetcode", "exercises", "sound", "delightful"].
- leetcode's last character is equal to exercises's first character.
- exercises's last character is equal to sound's first character.
- sound's last character is equal to delightful's first character.
- delightful's last character is equal to leetcode's first character.
The sentence is circular.
Example 2:

Input: sentence = "eetcode"
Output: true
Explanation: The words in sentence are ["eetcode"].
- eetcode's last character is equal to eetcode's first character.
The sentence is circular.
Example 3:

Input: sentence = "Leetcode is cool"
Output: false
Explanation: The words in sentence are ["Leetcode", "is", "cool"].
- Leetcode's last character is not equal to is's first character.
The sentence is not circular.
 

Constraints:

1 <= sentence.length <= 500
sentence consist of only lowercase and uppercase English letters and spaces.
The words in sentence are separated by a single space.
There are no leading or trailing spaces

*/


class Solution {
public:
    bool isCircularSentence(string sentence) {  //TC=O(n), sc=O(1)
        int n = sentence.size();

        // Check each space to ensure the chain property holds
        for (int i = 0; i < n; i++) {
            if (sentence[i] == ' ') {

                // Condition1: last char of each word == first char of next
                if (sentence[i - 1] != sentence[i + 1])                 // previous word's last char != next word's first char
                    return false;
            }
        }

        // Condition 2: last char of last word == first char of first
        // Finally, check if first and last character match
        return sentence[0] == sentence[n - 1];
    }
};
