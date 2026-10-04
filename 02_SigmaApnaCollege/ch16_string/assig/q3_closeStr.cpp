

/*


probNo 1657  https://leetcode.com/problems/determine-if-two-strings-are-close/description/

1657. Determine if Two Strings Are CloseMediumTopicsCompaniesHintTwo strings are considered close if you can attain one from 
the other using the following operations:Operation 1: Swap any two existing characters.
For example, abcde -> aecdbOperation 2: Transform every occurrence of one existing character into another existing character, and do the same with the other character.For example, aacabb -> bbcbaa (all a's turn into b's, and all b's turn into a's)You can use the operations on either string as many times as necessary.Given two strings, word1 and word2, return true if word1 and word2 are close, and false otherwise. Example 1:Input: word1 = "abc", word2 = "bca"Output: trueExplanation: You can attain word2 from word1 in 2 operations.Apply Operation 1: "abc" -> "acb"Apply Operation 1: "acb" -> "bca"Example 2:Input: word1 = "a", word2 = "aa"Output: falseExplanation: It is impossible to attain word2 from word1, or vice versa, in any number of operations.Example 3:Input: word1 = "cabbba", word2 = "abbccc"Output: trueExplanation: You can attain word2 from word1 in 3 operations.Apply Operation 1: "cabbba" -> "caabbb"Apply Operation 2: "caabbb" -> "baaccc"Apply Operation 2: "baaccc" -> "abbccc" Constraints:1 <= word1.length, word2.length <= 105word1 and word2 contain only lowercase English letters. Seen this question in a real interview before?1/6YesNoAccepted606,054/1.1MAcceptance Rate54.4%TopicsSeniorHash TableStringSortingCountingWeekly Contest 215

*/

class Solution {
public:
    bool closeStrings(string word1, string word2) {  //tc=O(n), sc=O(1)

        if(word1.length() != word2.length()) {  //condition1: same strLength
            return false;
        }

        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        for(char ch : word1) {
            freq1[ch - 'a']++;
        }

        for(char ch : word2) {
            freq2[ch - 'a']++;
        }

        //condition12: Both strings must contain the same characters
        for(int i = 0; i < 26; i++) {
            if((freq1[i] == 0) != (freq2[i] == 0)) {
                return false;
            }
        }

        //condition2: Their frequency values must be the same
        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());

        return freq1 == freq2;
    }
};
