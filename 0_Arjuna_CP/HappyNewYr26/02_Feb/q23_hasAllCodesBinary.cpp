


/*


23rd Feb 2026 (Monday)


qno 1461    https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/?envType=daily-question&envId=2026-02-23


1461. Check If a String Contains All Binary Codes of Size K
Medium
Topics

Companies
Hint
Given a binary string s and an integer k, return true if every binary code of length k is a substring of s. Otherwise, return false.

 

Example 1:

Input: s = "00110110", k = 2
Output: true
Explanation: The binary codes of length 2 are "00", "01", "10" and "11". They can be all found as substrings at indices 0, 1, 3 and 2 respectively.
Example 2:

Input: s = "0110", k = 1
Output: true
Explanation: The binary codes of length 1 are "0" and "1", it is clear that both exist as a substring. 
Example 3:

Input: s = "0110", k = 2
Output: false
Explanation: The binary code "00" is of length 2 and does not exist in the array.
 

Constraints:

1 <= s.length <= 5 * 105
s[i] is either '0' or '1'.
1 <= k <= 20
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
148,444/258.3K
Acceptance Rate
57.5%
Topics
Senior
Hash Table
String
Bit Manipulation
Rolling Hash
Hash Function
Biweekly Contest 27



*/



class Solution {
public:
    bool hasAllCodes(string s, int k) {  //tc=O(n), sc=O(n^2) using sliddingWindows approach
        int n = s.size();
        
        // If total possible substrings is greater than available windows
        if (n < k) return false;
        
        int total = 1 << k;  // 2^k possible binary codes
        vector<bool> seen(total, false);
        
        int count = 0;
        int mask = 0;
        
        for (int i = 0; i < n; i++) {
            // Shift left and add current bit
            mask = ((mask << 1) & (total - 1)) | (s[i] - '0');
            
            // Start checking once window size reaches k
            if (i >= k - 1) {
                if (!seen[mask]) {
                    seen[mask] = true;
                    count++;
                    
                    if (count == total) 
                        return true;
                }
            }
        }
        
        return false;
    }
};



class Solution {
public:
    bool hasAllCodes(string s, int k) {  //tc=O(n * k), sc=O(n)
        unordered_set<string> st;

        for(int i=0; i+k <= s.size(); i++) {
            st.insert(s.substr(i, k));
        }

        //onlyNeed to check size of EachSubstr
        return st.size() == (1 << k);
    }
};