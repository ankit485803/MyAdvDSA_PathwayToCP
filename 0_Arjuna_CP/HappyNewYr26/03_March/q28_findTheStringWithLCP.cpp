

/*


28th March 2026 (Satursday)

learn: how to make LCP 2D grid using String


qno 2573  https://leetcode.com/problems/find-the-string-with-lcp/?envType=daily-question&envId=2026-03-28



In the context of an n x n matrix called `lcp`, the goal is to find the alphabetically smallest string (`word`) that matches this 
`lcp` matrix. If no such string exists, the function should return an empty string. The `lcp` matrix likely represents the longest common prefix lengths between suffixes of the string.




2573. Find the String with LCP
Hard
Topics

Companies
Hint
We define the lcp matrix of any 0-indexed string word of n lowercase English letters as an n x n grid such that:

lcp[i][j] is equal to the length of the longest common prefix between the substrings word[i,n-1] and word[j,n-1].
Given an n x n matrix lcp, return the alphabetically smallest string word that corresponds to lcp. If there is no such string, return an empty string.

A string a is lexicographically smaller than a string b (of the same length) if in the first position where a and b differ, string a has a letter that appears earlier in the alphabet than the corresponding letter in b. For example, "aabd" is lexicographically smaller than "aaca" because the first position they differ is at the third letter, and 'b' comes before 'c'.

 

Example 1:

Input: lcp = [[4,0,2,0],[0,3,0,1],[2,0,2,0],[0,1,0,1]]
Output: "abab"
Explanation: lcp corresponds to any 4 letter string with two alternating letters. The lexicographically smallest of them is "abab".
Example 2:

Input: lcp = [[4,3,2,1],[3,3,2,1],[2,2,2,1],[1,1,1,1]]
Output: "aaaa"
Explanation: lcp corresponds to any 4 letter string with a single distinct letter. The lexicographically smallest of them is "aaaa". 
Example 3:

Input: lcp = [[4,3,2,1],[3,3,2,1],[2,2,2,1],[1,1,1,3]]
Output: ""
Explanation: lcp[3][3] cannot be equal to 3 since word[3,...,3] consists of only a single letter; Thus, no answer exists.
 

Constraints:

1 <= n == lcp.length == lcp[i].length <= 1000
0 <= lcp[i][j] <= n
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
24,226/46.1K
Acceptance Rate
52.5%
Topics
Senior Staff
Array
String
Dynamic Programming
Greedy
Union-Find
Matrix
Weekly Contest 333

Companies

*/


class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        
    }
};


//Approach-1 (Using Greedy Allocation + Finding LCP and comparing)
//T.C : O(n^2)
//S.C : O(n^2)
class Solution {
    vector<vector<int>> LongestCommonPrefixMatrix (string s) {
        int n = s.length();
        vector<vector<int>> result(n, vector<int>(n, 0));
        
        for (int j = 0; j < n; j ++) {
            result[n-1][j] = result[j][n-1] = (s[j] == s[n-1])? 1 : 0; 
        }
        for (int i = n-2; i >= 0; i --) {
            for (int j = n-2; j >= 0; j --) {
                result[i][j] = (s[i] == s[j])? 1 + result[i+1][j+1] : 0;
            }
        }
        
        return result;
    }
    
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        
        string result (n, 'a');
        
        for (int i = 1; i < n; i ++) {
            vector<bool> not_equal(26, false);
            bool matched = false;
            
            for (int j = 0; j < i; j ++) {
                if (lcp[j][i] == 0) {
                    not_equal[result[j] - 'a'] = true;
                    continue;
                }
                
                matched = true;
                result[i] = result[j];
                break;
            }
        
            if (matched) continue;
            for (int j = 0; j < 26; j ++) {
                if (not_equal[j]) continue;
                
                result[i] = (char)('a' + j);
                break;
            }
        }
        
        if (LongestCommonPrefixMatrix(result) == lcp) return result;
        return "";
    }
};



//Approach-2 (Using Greedy Allocation + Without finding LCP)
//T.C : O(n^2)
//S.C : O(n) for word
class Solution {
public:
    bool checkLCP(string &word, vector<vector<int>>& lcp) {
        int n = word.length();

        for(int i = 0; i < n; i++) {
            //lcp[i][n-1] = (word[i] == word[n-1]) ? 1 : 0;
            if(word[i] != word[n-1]) {
                if(lcp[i][n-1] != 0) return false;
            } else {
                if(lcp[i][n-1] != 1) return false;
            }
        }

        for(int j = 0; j < n; j++) {
            //lcp[n-1][j] = (word[n-1] == word[j]) ? 1 : 0;
            if(word[n-1] != word[j]) {
                if(lcp[n-1][j] != 0) return false;
            } else {
                if(lcp[n-1][j] != 1) return false;
            }
        }

        for(int i = n-2; i >= 0; i--) {
            for(int j = n-2; j >= 0; j--) {
                if(word[i] == word[j]) {
                    if(lcp[i][j] != 1 + lcp[i+1][j+1]) return false;
                } else {
                    if(lcp[i][j] != 0) return false;
                }
            }
        }

        return true;
    }

    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();

        string word(n, '$');

        for(int i = 0; i < n; i++) {

            //word[i] = ?
            for(int j = 0; j < i; j++) {
                if(lcp[j][i] != 0) {
                    word[i] = word[j];
                    break;
                }
            }


            if(word[i] == '$') {
                vector<bool> forbidden(26, false);

                for(int j = 0; j < i; j++) {
                    if(lcp[j][i] == 0) {
                        forbidden[word[j] - 'a'] = true;
                    }
                }

                //a, b, c ..., z
                for(int idx = 0; idx < 26; idx++) {
                    if(forbidden[idx] == false) {
                        word[i] = idx + 'a';
                        break;
                    }
                }

                if(word[i] == '$')
                    return ""; //we could never fill word[i]
            }
        }

        return checkLCP(word, lcp) == true ? word : "";
    }
};