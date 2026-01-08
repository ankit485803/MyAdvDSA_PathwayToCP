



/*


18th Dec 2025 (Thursday)


qno 2869   https://leetcode.com/problems/minimum-operations-to-collect-elements/description/



2869. Minimum Operations to Collect Elements
Easy
Topics

Companies
Hint
You are given an array nums of positive integers and an integer k.

In one operation, you can remove the last element of the array and add it to your collection.

Return the minimum number of operations needed to collect elements 1, 2, ..., k.

 

Example 1:

Input: nums = [3,1,5,4,2], k = 2
Output: 4
Explanation: After 4 operations, we collect elements 2, 4, 5, and 1, in this order. Our collection contains elements 1 and 2. Hence, the answer is 4.
Example 2:

Input: nums = [3,1,5,4,2], k = 5
Output: 5
Explanation: After 5 operations, we collect elements 2, 4, 5, 1, and 3, in this order. Our collection contains elements 1 through 5. Hence, the answer is 5.
Example 3:

Input: nums = [3,2,5,3,1], k = 3
Output: 4
Explanation: After 4 operations, we collect elements 1, 3, 5, and 2, in this order. Our collection contains elements 1 through 3. Hence, the answer is 4.
 

Constraints:

1 <= nums.length <= 50
1 <= nums[i] <= nums.length
1 <= k <= nums.length
The input is generated such that you can collect elements 1, 2, ..., k.



*/



class Solution {  //myFirstApproach
public:
    int minOperations(vector<int>& nums, int k) {
        int n = sizeof(nums) / sizeof(nums[0]);  // Calculate no of elem

        //step1: makeReq range
        vector<int> reqRange;
        for(int i=0; i<=k; i++) {
            reqRange.push_back(i);
        }

        //step2: form collection 
        vector<int> collection;
        int countOp = 0;  //no of operation
        while(! nums.empty()) {
            int lastElem = nums[n - 1];
            collection.push_back(lastElem);
            countOp++; 
        }

        if(collection == reqRange) {
            return countOp;  
        }
    }
};






#include <unordered_set>
class Solution {
public:
    int minOperations(std::vector<int>& nums, int k) {
        int n = nums.size();   

        unordered_set<int> reqElem;
        for (int i=1; i<=k; i++) {
            reqElem.insert(i);
        }

        unordered_set<int> collection;
        int countOp = 0;  
        
        // Iterate over the nums array in reverse (from last to first)
        for (int i=n-1; i >= 0; i--) {
            collection.insert(nums[i]);
            countOp++;
            
            // If collection contains allElem from 1 to k
            if (collection.size() == k) {
                return countOp;
            }
        }

        return countOp;   
    }
};




class Solution {
public:
    int minOperations(std::vector<int>& nums, int k) {  //tc=O(n), sc=O(k)
        int n = nums.size(); 

        vector<bool> seen(k, false);  // Boolean array to track collected elements
        int collected = 0;  
        int ops = 0;  

    
        for (int i=n-1; i>=0; i--) {
            ops++;
            
            int val = nums[i];
            
            // If the element is in the range [1, k] and hasn't been collected yet
            if (val <= k && !seen[val - 1]) {
                seen[val - 1] = true;  
                collected++;  
            }

            if (collected == k) {
                return ops;
            }
        }

        return ops;  
    }
};






/*


qno  1763  https://leetcode.com/problems/longest-nice-substring/description/


1763. Longest Nice Substring
Easy
Topics

Companies
Hint
A string s is nice if, for every letter of the alphabet that s contains, it appears both in uppercase and lowercase. For example, "abABB" is nice because 'A' and 'a' appear, and 'B' and 'b' appear. However, "abA" is not because 'b' appears, but 'B' does not.

Given a string s, return the longest substring of s that is nice. If there are multiple, return the substring of the earliest occurrence. If there are none, return an empty string.

 

Example 1:

Input: s = "YazaAay"
Output: "aAa"
Explanation: "aAa" is a nice string because 'A/a' is the only letter of the alphabet in s, and both 'A' and 'a' appear.
"aAa" is the longest nice substring.
Example 2:

Input: s = "Bb"
Output: "Bb"
Explanation: "Bb" is a nice string because both 'B' and 'b' appear. The whole string is a substring.
Example 3:

Input: s = "c"
Output: ""
Explanation: There are no nice substrings.
 

Constraints:

1 <= s.length <= 100
s consists of uppercase and lowercase English letters.
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
87,033/137.7K
Acceptance Rate
63.2%
Topics
Hash Table
String
Divide and Conquer
Bit Manipulation
Sliding Window
Biweekly Contest 46



*/




class Solution {
public:
    string longestNiceSubstring(string s) {  //tc=O(n ^3), sc=O(n)
        int n = s.size();
        
        if(n < 2) return "";  //edgeCase

        // Helper function to check if a substring is "nice"
        auto isNice = [](const string& substr) {
            unordered_set<char> lowercase, uppercase;
            for (char c : substr) {
                if (islower(c)) lowercase.insert(c);
                if (isupper(c)) uppercase.insert(c);
            }

         // Check if for every lowercase letter, the uppercase counterpart is present and vice versa
            for (char c : lowercase) {
                if (uppercase.find(toupper(c)) == uppercase.end()) return false;
            }
            for (char c : uppercase) {
                if (lowercase.find(tolower(c)) == lowercase.end()) return false;
            }
            return true;
        };

         // Recursively check all possible substrings
        string longest = "";
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                string substr = s.substr(i, j - i);
                if (isNice(substr) && substr.size() > longest.size()) {
                    longest = substr;
                }
            }
        }

        return longest;    
    }
};



/*


qno 1876  https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters/description/


1876. Substrings of Size Three with Distinct Characters
Easy
Topics

Companies
Hint
A string is good if there are no repeated characters.

Given a string s​​​​​, return the number of good substrings of length three in s​​​​​​.

Note that if there are multiple occurrences of the same substring, every occurrence should be counted.

A substring is a contiguous sequence of characters in a string.

 

Example 1:

Input: s = "xyzzaz"
Output: 1
Explanation: There are 4 substrings of size 3: "xyz", "yzz", "zza", and "zaz". 
The only good substring of length 3 is "xyz".
Example 2:

Input: s = "aababcabc"
Output: 4
Explanation: There are 7 substrings of size 3: "aab", "aba", "bab", "abc", "bca", "cab", and "abc".
The good substrings are "abc", "bca", "cab", and "abc".
 

Constraints:

1 <= s.length <= 100
s​​​​​​ consists of lowercase English letters.


*/



class Solution {
public:
    int countGoodSubstrings(string s) {
        int count = 0;
        int n = s.length();
        
        // Loop through the string to check substrings of size 3
        for (int i = 0; i <= n - 3; i++) {
            string sub = s.substr(i, 3);  // Get the substring of length 3
            if (sub[0] != sub[1] && sub[1] != sub[2] && sub[0] != sub[2]) {
                count++;  // If all characters are distinct, increment the count
            }
        }
        
        return count;
    }
};
