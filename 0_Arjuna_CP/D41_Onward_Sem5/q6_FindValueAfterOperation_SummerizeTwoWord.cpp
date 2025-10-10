


/*


10th Oct 2025 (Friday)


qno 2011   https://leetcode.com/problems/final-value-of-variable-after-performing-operations/


concepts:
& is for passing by reference (works for all types like int, string, etc.).
* is for working with pointers (which is how arrays are passed to functions in C++).








2011. Final Value of Variable After Performing Operations
Easy
Topics
premium lock icon
Companies
Hint
There is a programming language with only four operations and one variable X:

++X and X++ increments the value of the variable X by 1.
--X and X-- decrements the value of the variable X by 1.
Initially, the value of X is 0.

Given an array of strings operations containing a list of operations, return the final value of X after performing all the operations.

 

Example 1:

Input: operations = ["--X","X++","X++"]
Output: 1
Explanation: The operations are performed as follows:
Initially, X = 0.
--X: X is decremented by 1, X =  0 - 1 = -1.
X++: X is incremented by 1, X = -1 + 1 =  0.
X++: X is incremented by 1, X =  0 + 1 =  1.
Example 2:

Input: operations = ["++X","++X","X++"]
Output: 3
Explanation: The operations are performed as follows:
Initially, X = 0.
++X: X is incremented by 1, X = 0 + 1 = 1.
++X: X is incremented by 1, X = 1 + 1 = 2.
X++: X is incremented by 1, X = 2 + 1 = 3.
Example 3:

Input: operations = ["X++","++X","--X","X--"]
Output: 0
Explanation: The operations are performed as follows:
Initially, X = 0.
X++: X is incremented by 1, X = 0 + 1 = 1.
++X: X is incremented by 1, X = 1 + 1 = 2.
--X: X is decremented by 1, X = 2 - 1 = 1.
X--: X is decremented by 1, X = 1 - 1 = 0.
 

Constraints:
1 <= operations.length <= 100
operations[i] will be either "++X", "X++", "--X", or "X--".



*/


class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) { //TC=O(n), sc=O(1)
        
        //initilize
        int X = 0;

        for(const string& op : operations) {
            //increments
            if(op == "++X"  ||  op == "X++") {
                X++;  //inc by 1
            } else if(op == "--X" ||  op == "X--") {
                X--;   //dec by 1
            }
        }

        return X;
    }
};



/*

qno 1880  https://leetcode.com/problems/check-if-word-equals-summation-of-two-words/description/

1880. Check if Word Equals Summation of Two Words
Easy
Topics

Companies
Hint
The letter value of a letter is its position in the alphabet starting from 0 (i.e. 'a' -> 0, 'b' -> 1, 'c' -> 2, etc.).
The numerical value of some string of lowercase English letters s is the concatenation of the letter values of each letter in s, which is then converted into an integer.

For example, if s = "acb", we concatenate each letter's letter value, resulting in "021". After converting it, we get 21.
You are given three strings firstWord, secondWord, and targetWord, each consisting of lowercase English letters 'a' through 'j' inclusive.

Return true if the summation of the numerical values of firstWord and secondWord equals the numerical value of targetWord, or false otherwise.

 

Example 1:

Input: firstWord = "acb", secondWord = "cba", targetWord = "cdb"
Output: true
Explanation:
The numerical value of firstWord is "acb" -> "021" -> 21.
The numerical value of secondWord is "cba" -> "210" -> 210.
The numerical value of targetWord is "cdb" -> "231" -> 231.
We return true because 21 + 210 == 231.
Example 2:

Input: firstWord = "aaa", secondWord = "a", targetWord = "aab"
Output: false
Explanation: 
The numerical value of firstWord is "aaa" -> "000" -> 0.
The numerical value of secondWord is "a" -> "0" -> 0.
The numerical value of targetWord is "aab" -> "001" -> 1.
We return false because 0 + 0 != 1.
Example 3:

Input: firstWord = "aaa", secondWord = "a", targetWord = "aaaa"
Output: true
Explanation: 
The numerical value of firstWord is "aaa" -> "000" -> 0.
The numerical value of secondWord is "a" -> "0" -> 0.
The numerical value of targetWord is "aaaa" -> "0000" -> 0.
We return true because 0 + 0 == 0.
 

Constraints:

1 <= firstWord.length, secondWord.length, targetWord.length <= 8
firstWord, secondWord, and targetWord consist of lowercase English letters from 'a' to 'j' inclusive.


*/


class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        // Helper function to calculate the numerical value of a word
        auto wordToNumber = [](const string& word) {
            int num = 0;
            for (char c : word) {
                num = num * 10 + (c - 'a');  // Convert each character to its number and build the number
            }
            return num;
        };
        
        // Calculate the numerical values of the words
        int firstNum = wordToNumber(firstWord);
        int secondNum = wordToNumber(secondWord);
        int targetNum = wordToNumber(targetWord);
        
        // Check if the sum of firstNum and secondNum equals targetNum
        return (firstNum + secondNum == targetNum);
    }
};

//TC=O(n), sc=O(1)