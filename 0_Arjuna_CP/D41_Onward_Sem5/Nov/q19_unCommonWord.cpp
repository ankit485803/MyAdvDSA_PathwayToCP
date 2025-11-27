


/*


27th Nov 2025  (Thursday)


qno  884  https://leetcode.com/problems/uncommon-words-from-two-sentences/


884. Uncommon Words from Two Sentences
Attempted
Easy
Topics

Companies
A sentence is a string of single-space separated words where each word consists only of lowercase letters.

A word is uncommon if it appears exactly once in one of the sentences, and does not appear in the other sentence.

Given two sentences s1 and s2, return a list of all the uncommon words. You may return the answer in any order.

 

Example 1:

Input: s1 = "this apple is sweet", s2 = "this apple is sour"

Output: ["sweet","sour"]

Explanation:

The word "sweet" appears only in s1, while the word "sour" appears only in s2.

Example 2:

Input: s1 = "apple apple", s2 = "banana"

Output: ["banana"]

 

Constraints:

1 <= s1.length, s2.length <= 200
s1 and s2 consist of lowercase English letters and spaces.
s1 and s2 do not have leading or trailing spaces.
All the words in s1 and s2 are separated by a single space.



*/



#include <unordered_map>
#include <sstream>
#include <string>

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) { //TC=O(n + m), sc=O(distinctWord)
        //wordCount
        unordered_map<string, int> wordC;


        // Function to count words and update their frequency
        auto countW = [&](const string& sentence) {
            istringstream stream(sentence);
            string word;
            while (stream >> word) {
                wordC[word]++;
            }
        };

        countW(s1);
        countW(s2);

        vector<string> result;

        //find uncommon words
        for (const auto& entry : wordC) {
            if (entry.second == 1) {  // Word appears exactly once
                result.push_back(entry.first);
            }
        }

        return result;
    }
};

