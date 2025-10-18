



/*

18th Oct 2025 (Saturday)


qno  832  https://leetcode.com/problems/flipping-an-image/

Ankit Learn:
in c++ 11 Range based for loop  





832. Flipping an Image
Easy
Topics

Companies
Given an n x n binary matrix image, flip the image horizontally, then invert it, and return the resulting image.

To flip an image horizontally means that each row of the image is reversed.

For example, flipping [1,1,0] horizontally results in [0,1,1].
To invert an image means that each 0 is replaced by 1, and each 1 is replaced by 0.

For example, inverting [0,1,1] results in [1,0,0].
 

Example 1:

Input: image = [[1,1,0],[1,0,1],[0,0,0]]
Output: [[1,0,0],[0,1,0],[1,1,1]]
Explanation: First reverse each row: [[0,1,1],[1,0,1],[0,0,0]].
Then, invert the image: [[1,0,0],[0,1,0],[1,1,1]]
Example 2:

Input: image = [[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]
Output: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
Explanation: First reverse each row: [[0,0,1,1],[1,0,0,1],[1,1,1,0],[0,1,0,1]].
Then invert the image: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
 

Constraints:

n == image.length
n == image[i].length
1 <= n <= 20
images[i][j] is either 0 or 1.


| Loop Syntax               | What it does                         | Why use reference `&`?              |
| ------------------------- | ------------------------------------ | ----------------------------------- |
| `for (auto& row : image)` | Loops through each row in the matrix | So you can modify the rows directly |
| `for (int& pixel : row)`  | Loops through each element in a row  | So you can modify the pixel values  |




*/


class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) { //tc=o(n), sc=O(1)
        
        //first revEachRow
        for(auto& row : image) {
            reverse(row.begin(), row.end());  // Flip row horizontally - reverse it


            //invert value 0->1 and 1->0
            for(int& pixel : row) {
                pixel = 1 - pixel;   // invert the pixel
            }
        }

        return image;




    }
};



/*

qno 2000  https://leetcode.com/problems/reverse-prefix-of-word/


2000. Reverse Prefix of Word
Easy
Topics

Companies
Hint
Given a 0-indexed string word and a character ch, reverse the segment of word that starts at index 0 and ends at the index of the first occurrence of ch (inclusive). If the character ch does not exist in word, do nothing.

For example, if word = "abcdefd" and ch = "d", then you should reverse the segment that starts at 0 and ends at 3 (inclusive). The resulting string will be "dcbaefd".
Return the resulting string.

 

Example 1:

Input: word = "abcdefd", ch = "d"
Output: "dcbaefd"
Explanation: The first occurrence of "d" is at index 3. 
Reverse the part of word from 0 to 3 (inclusive), the resulting string is "dcbaefd".
Example 2:

Input: word = "xyxzxe", ch = "z"
Output: "zxyxxe"
Explanation: The first and only occurrence of "z" is at index 3.
Reverse the part of word from 0 to 3 (inclusive), the resulting string is "zxyxxe".
Example 3:

Input: word = "abcd", ch = "z"
Output: "abcd"
Explanation: "z" does not exist in word.
You should not do any reverse operation, the resulting string is "abcd".
 

Constraints:

1 <= word.length <= 250
word consists of lowercase English letters.
ch is a lowercase English letter.




*/


class Solution {
public:
    string reversePrefix(string word, char ch) {  //TC=O(n), sc=O(1)
        
        //iterate each index till ch found
        for(int i=0; i<word.size(); i++) {
            if(word[i] == ch) {
                //Reverse the prefix from 0 to i (inclusive)
                reverse(word.begin(), word.begin() + i + 1);
                return  word;
            } 
        }

        return word;  //If 'ch' is not found, return the original word
    }
};