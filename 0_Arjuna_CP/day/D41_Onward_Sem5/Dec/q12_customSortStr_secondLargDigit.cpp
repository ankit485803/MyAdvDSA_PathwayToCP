



/*


12th Dec 2025 (Friday - at room)


qno  791  https://leetcode.com/problems/custom-sort-string/


791. Custom Sort String
Medium
Topics

Companies
You are given two strings order and s. All the characters of order are unique and were sorted in some custom order previously.

Permute the characters of s so that they match the order that order was sorted. More specifically, if a character x occurs before a character y in order, then x should occur before y in the permuted string.

Return any permutation of s that satisfies this property.

 

Example 1:

Input: order = "cba", s = "abcd"

Output: "cbad"

Explanation: "a", "b", "c" appear in order, so the order of "a", "b", "c" should be "c", "b", and "a".

Since "d" does not appear in order, it can be at any position in the returned string. "dcba", "cdba", "cbda" are also valid outputs.

Example 2:

Input: order = "bcafg", s = "abcd"

Output: "bcad"

Explanation: The characters "b", "c", and "a" from order dictate the order for the characters in s. The character "d" in s does not appear in order, so its position is flexible.

Following the order of appearance in order, "b", "c", and "a" from s should be arranged as "b", "c", "a". "d" can be placed at any position since it's not in order. The output "bcad" correctly follows this rule. Other arrangements like "dbca" or "bcda" would also be valid, as long as "b", "c", "a" maintain their order.

 

Constraints:

1 <= order.length <= 26
1 <= s.length <= 200
order and s consist of lowercase English letters.
All the characters of order are unique.


*/



#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string customSortString(string order, string s) {
        // Step 1: Create a map to store the priority of each character in the order string
        unordered_map<char, int> charPriority;
        for (int i = 0; i < order.size(); ++i) {
            charPriority[order[i]] = i;
        }
        
        // Step 2: Create a lambda function to sort characters based on their order priority
        auto customComparator = [&charPriority](char a, char b) {
            // If both characters are in the order, compare their priorities
            if (charPriority.count(a) && charPriority.count(b)) {
                return charPriority[a] < charPriority[b];
            }
            // If only one of them is in the order, that one should come first
            if (charPriority.count(a)) return true;
            if (charPriority.count(b)) return false;
            // If neither is in the order, keep the original order
            return a < b;
        };
        
        // Step 3: Sort the string 's' based on the custom order
        sort(s.begin(), s.end(), customComparator);
        
        return s;
    }
};


// Test the function
int main() {
    Solution solution;
    string order = "cba";
    string s = "abcd";
    cout << solution.customSortString(order, s) << endl;  // Output can be "cbad"
    return 0;
}




#include <unordered_map>
#include <algorithm>


class Solution {
public:
    string customSortString(string order, string s) { //tc=O(n logN), sc=(m + n)
        // Step 1: Create map to store the priority of eachChar
        unordered_map<char, int> charPriority;
        for (int i = 0; i < order.size(); ++i) {
            charPriority[order[i]] = i;
        }
        
        // Step 2: Create a lambdaFunct to sort characters based on their order priority
        auto customComparator = [&charPriority](char a, char b) {
            // If both characters are in the order, compare their priorities
            if (charPriority.count(a) && charPriority.count(b)) {
                return charPriority[a] < charPriority[b];
            }
            // If only one of them is in the order, that one should come first
            if (charPriority.count(a)) return true;
            if (charPriority.count(b)) return false;
            // If neither is in the order, keep the original order
            return a < b;
        };
        
        // Step3: Sort
        sort(s.begin(), s.end(), customComparator);
        
        return s;
    }
};





/*



qno 1796  https://leetcode.com/problems/second-largest-digit-in-a-string/description/




1796. Second Largest Digit in a String
Easy
Topics

Companies
Hint
Given an alphanumeric string s, return the second largest numerical digit that appears in s, or -1 if it does not exist.

An alphanumeric string is a string consisting of lowercase English letters and digits.

 

Example 1:

Input: s = "dfa12321afd"
Output: 2
Explanation: The digits that appear in s are [1, 2, 3]. The second largest digit is 2.
Example 2:

Input: s = "abc1111"
Output: -1
Explanation: The digits that appear in s are [1]. There is no second largest digit. 
 

Constraints:

1 <= s.length <= 500
s consists of only lowercase English letters and digits.





*/



class Solution {
public:
    int secondHighest(string s) {  //tc=o(n logN), sc=O(n) due to digits
        vector<int> digits;
 
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                digits.push_back(s[i] - '0');  // Store the actual digit, not the index
            }
        }

        // If there are fewer than two digits
        if (digits.size() < 2) {
            return -1;
        }

        // Sort descending order to find the secondLarg
        sort(digits.begin(), digits.end(), greater<int>());
        
        // Find the second largest unique digit
        for (int i = 1; i < digits.size(); i++) {
            if (digits[i] != digits[0]) {
                return digits[i];
            }
        }
        
        return -1;  
    }
};






class Solution {
public:
    int secondHighest(string s) {
        int first = -1, second = -1; 

        for (char c : s) {
            if (isdigit(c)) {
                int digit = c - '0';  // Convert the character to its integer value

       
                if (digit > first) {
                    second = first;  
                    first = digit; 
                } else if (digit > second && digit < first) {
                    second = digit;  
                }
            }
        }

        return second;  // If no second largest found, it will remain -1
    }
};