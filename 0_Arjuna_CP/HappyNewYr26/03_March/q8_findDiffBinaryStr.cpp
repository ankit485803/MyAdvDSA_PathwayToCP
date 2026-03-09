#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to flip a binary character
char flip(char c) {
    return (c == '0' ? '1' : '0');
}

int main() {
    vector<string> nums = {"01", "10"};
    string res = "";

    // Diagonalization trick
    for (int i = 0; i < nums.size(); ++i) {
        res += flip(nums[i][i]);
    }

    cout << "After diagonalization: " << res << endl; // Output: 11

    return 0;
}


/*


8th March 2026 (Sunday)


qno 1980   https://leetcode.com/problems/find-unique-binary-string/?envType=daily-question&envId=2026-03-08
clever trick called “diagonalization”, inspired by Cantor’s diagonal argument.
Why the Diagonalization Trick Works

The idea comes from Cantor’s diagonal argument, which is a famous method in mathematics to construct an element not in a list.


1980. Find Unique Binary String
Medium
Topics

Companies
Hint
Given an array of strings nums containing n unique binary strings each of length n, return a binary string of length n that does not appear in nums. If there are multiple answers, you may return any of them.

 

Example 1:

Input: nums = ["01","10"]
Output: "11"
Explanation: "11" does not appear in nums. "00" would also be correct.
Example 2:

Input: nums = ["00","01"]
Output: "11"
Explanation: "11" does not appear in nums. "10" would also be correct.
Example 3:

Input: nums = ["111","011","001"]
Output: "101"
Explanation: "101" does not appear in nums. "000", "010", "100", and "110" would also be correct.
 

Constraints:

n == nums.length
1 <= n <= 16
nums[i].length == n
nums[i] is either '0' or '1'.
All the strings of nums are unique.
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
351,819/438.1K
Acceptance Rate
80.3%
Topics
Senior
Array
Hash Table
String
Backtracking
Weekly Contest 255


*/



class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {  //tc=O(n)=sc
        int n = nums.size();
        string res = "";

        //approach: clever trick called “diagonalization”, inspired by Cantor’s diagonal argument.

        for (int i = 0; i < n; ++i) {
            res += (nums[i][i] == '0' ? '1' : '0');
        }
        return res;
    }
};


class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();      
        string res = "";          

        // approach: diagonalization (flip the diagonal bits)
        int i = 0;
        while (i < n) {
            char currentChar = nums[i][i]; // get the character at position (i, i)
            char flippedChar;

            // flip '0' to '1' and '1' to '0'
            if (currentChar == '0') {
                flippedChar = '1';
            } else {
                flippedChar = '0';
            }

            res += flippedChar; // append flipped character to result
            i++;               
        }

        return res;
    }
};



class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string result;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i][i] == '0') {
                result += '1';
            } else {
                result += '0';
            }
        }
        return result;
    }
};