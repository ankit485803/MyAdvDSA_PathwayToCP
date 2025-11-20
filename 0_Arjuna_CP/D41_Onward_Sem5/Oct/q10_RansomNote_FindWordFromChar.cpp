



/*

17th Oct 2025 (Friday)

qno 383  https://leetcode.com/problems/ransom-note/description/




383. Ransom Note
Easy
Topics

Companies
Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.

 

Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false
Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false
Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true
 

Constraints:

1 <= ransomNote.length, magazine.length <= 105
ransomNote and magazine consist of lowercase English letters.





*/


class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) { //SC=O(1)
        
        //sort - time O(log N)
        sort(ransomNote.begin(), ransomNote.end());
        sort(magazine.begin(), magazine.end());


        //twoPointerAppraoch - using Arr not HASH
        int i=0, j=0;

        while(i<ransomNote.size()  && j<magazine.size()) {
            // If the current character in magazine matches the one in ransomNote
            if(ransomNote[i]  ==  magazine[j]) {
                i++;
            } else {
                j++;  // Always move pointer in magazine
            }

        }

        // If all characters in ransomNote have been matched
        return i == ransomNote.size();

    }
};



class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // Arr to store freqCount of letters in magazine
        vector<int> freq(26, 0);

        // Fill freqArr with char from magazine
        for (char c : magazine) {
            freq[c - 'a']++;
        }

        // Check if ransomNote can be constructed
        for (char c : ransomNote) {
            if (freq[c - 'a'] == 0) {
                return false;  
            }
            freq[c - 'a']--;  // Decrease the frequency of the character
        }

        return true;  
    }
};

// TC - O(m + n), where m is the length of magazine and n for ransomeNote
//sc=O(1)





/*

qno  1160  https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/

1160. Find Words That Can Be Formed by Characters
Easy
Topics

Companies
Hint
You are given an array of strings words and a string chars.
A string is good if it can be formed by characters from chars (each character can only be used once for each word in words).
Return the sum of lengths of all good strings in words.

 

Example 1:

Input: words = ["cat","bt","hat","tree"], chars = "atach"
Output: 6
Explanation: The strings that can be formed are "cat" and "hat" so the answer is 3 + 3 = 6.
Example 2:

Input: words = ["hello","world","leetcode"], chars = "welldonehoneyr"
Output: 10
Explanation: The strings that can be formed are "hello" and "world" so the answer is 5 + 5 = 10.
 

Constraints:

1 <= words.length <= 1000
1 <= words[i].length, chars.length <= 100
words[i] and chars consist of lowercase English letters.


*/



class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        // Frequency map of characters in chars
        unordered_map<char, int> charCount;
        for (char c : chars) {
            charCount[c]++;
        }

        int result = 0;

        // Iterate over each word in words
        for (const string& word : words) {
            unordered_map<char, int> wordCount;
            bool canForm = true;

            // Count the frequency of characters in the word
            for (char c : word) {
                wordCount[c]++;
            }

            // Check if word can be formed using chars
            for (const auto& pair : wordCount) {
                if (charCount[pair.first] < pair.second) {
                    canForm = false; // Not enough characters in chars
                    break;
                }
            }

            // If the word can be formed, add its length to result
            if (canForm) {
                result += word.length();
            }
        }

        return result;
    }
};

//TC=O(n), sc=O(1)
