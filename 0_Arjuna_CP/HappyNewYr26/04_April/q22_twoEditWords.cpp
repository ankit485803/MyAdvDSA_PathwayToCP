

/*

22nd April 2026 (Wednesday)


qno 2452  https://leetcode.com/problems/words-within-two-edits-of-dictionary/?envType=daily-question&envId=2026-04-22

2452. Words Within Two Edits of Dictionary
Solved
Medium
Topics

Companies
Hint
You are given two string arrays, queries and dictionary. All words in each array comprise of lowercase English letters and have the same length.

In one edit you can take a word from queries, and change any letter in it to any other letter. Find all words from queries that, after a maximum of two edits, equal some word from dictionary.

Return a list of all words from queries, that match with some word from dictionary after a maximum of two edits. Return the words in the same order they appear in queries.

 

Example 1:

Input: queries = ["word","note","ants","wood"], dictionary = ["wood","joke","moat"]
Output: ["word","note","wood"]
Explanation:
- Changing the 'r' in "word" to 'o' allows it to equal the dictionary word "wood".
- Changing the 'n' to 'j' and the 't' to 'k' in "note" changes it to "joke".
- It would take more than 2 edits for "ants" to equal a dictionary word.
- "wood" can remain unchanged (0 edits) and match the corresponding dictionary word.
Thus, we return ["word","note","wood"].
Example 2:

Input: queries = ["yes"], dictionary = ["not"]
Output: []
Explanation:
Applying any two edits to "yes" cannot make it equal to "not". Thus, we return an empty array.
 

Constraints:

1 <= queries.length, dictionary.length <= 100
n == queries[i].length == dictionary[j].length
1 <= n <= 100
All queries[i] and dictionary[j] are composed of lowercase English letters.
 
Discover more
Resume writing services
Seen this question in a real interview before?
1/6
Yes
No
Accepted
68,439/98K
Acceptance Rate
69.9%
Topics
Senior
Array
String
Trie
Biweekly Contest 90


*/


class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> result;  //tc=O(query * d * n), sc=O(1)

        for(string& query : queries) {
            for(string& s : dictionary) {
                int diff = 0;
                //check
                for(int i=0; i < query.size(); i++) {
                    if(query[i] != s[i]) {
                        ++diff;
                    }
                    if(diff > 2) 
                        break;
                }

                if(diff <= 2) {
                    result.push_back(query);
                    break;
                }
            }
        }

        return result; 
    }
};