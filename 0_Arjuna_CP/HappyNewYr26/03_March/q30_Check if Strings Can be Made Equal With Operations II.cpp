



/*

30th March 2026 (Monday) yesterday alreadySolved


qno 2840  https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-ii/description/?envType=daily-question&envId=2026-03-30


2840. Check if Strings Can be Made Equal With Operations II
Solved
Medium
Topics

Companies
Hint
You are given two strings s1 and s2, both of length n, consisting of lowercase English letters.

You can apply the following operation on any of the two strings any number of times:

Choose any two indices i and j such that i < j and the difference j - i is even, then swap the two characters at those indices in the string.
Return true if you can make the strings s1 and s2 equal, and false otherwise.

 

Example 1:

Input: s1 = "abcdba", s2 = "cabdab"
Output: true
Explanation: We can apply the following operations on s1:
- Choose the indices i = 0, j = 2. The resulting string is s1 = "cbadba".
- Choose the indices i = 2, j = 4. The resulting string is s1 = "cbbdaa".
- Choose the indices i = 1, j = 5. The resulting string is s1 = "cabdab" = s2.
Example 2:

Input: s1 = "abe", s2 = "bea"
Output: false
Explanation: It is not possible to make the two strings equal.
 

Constraints:

n == s1.length == s2.length
1 <= n <= 105
s1 and s2 consist only of lowercase English letters.
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
45,939/73.2K
Acceptance Rate
62.8%
Topics
Senior
Hash Table
String
Sorting
Biweekly Contest 112


*/


//Approach - Using map for grouping even and odd indices
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int even[26] = {0};a
        int odd[26] = {0};

        int n = s1.length();

        for(int i = 0; i < n; i++) {
            if(i%2 == 0) { //even indices
                even[s1[i] - 'a']++;
                even[s2[i] - 'a']--;
            } else { //odd indices
                odd[s1[i] - 'a']++;
                odd[s2[i] - 'a']--;
            }
        }

        for(int i = 0; i < 26; i++) {
            if(even[i] != 0 || odd[i] != 0)
                return false;
        }

        return true;
    }
};