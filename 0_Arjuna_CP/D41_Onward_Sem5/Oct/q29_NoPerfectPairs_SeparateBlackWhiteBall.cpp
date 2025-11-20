



/*

8th Nov 2025 (Satursday)


qno 3649   https://leetcode.com/problems/number-of-perfect-pairs/description/

3649. Number of Perfect Pairs
Medium
Topics

Companies
Hint
You are given an integer array nums.

A pair of indices (i, j) is called perfect if the following conditions are satisfied:

i < j
Let a = nums[i], b = nums[j]. Then:
min(|a - b|, |a + b|) <= min(|a|, |b|)
max(|a - b|, |a + b|) >= max(|a|, |b|)
Return the number of distinct perfect pairs.

Note: The absolute value |x| refers to the non-negative value of x.

 

Example 1:

Input: nums = [0,1,2,3]

Output: 2

Explanation:

There are 2 perfect pairs:

(i, j)	(a, b)	min(|a − b|, |a + b|)	min(|a|, |b|)	max(|a − b|, |a + b|)	max(|a|, |b|)
(1, 2)	(1, 2)	min(|1 − 2|, |1 + 2|) = 1	1	max(|1 − 2|, |1 + 2|) = 3	2
(2, 3)	(2, 3)	min(|2 − 3|, |2 + 3|) = 1	2	max(|2 − 3|, |2 + 3|) = 5	3
Example 2:

Input: nums = [-3,2,-1,4]

Output: 4

Explanation:

There are 4 perfect pairs:

(i, j)	(a, b)	min(|a − b|, |a + b|)	min(|a|, |b|)	max(|a − b|, |a + b|)	max(|a|, |b|)
(0, 1)	(-3, 2)	min(|-3 - 2|, |-3 + 2|) = 1	2	max(|-3 - 2|, |-3 + 2|) = 5	3
(0, 3)	(-3, 4)	min(|-3 - 4|, |-3 + 4|) = 1	3	max(|-3 - 4|, |-3 + 4|) = 7	4
(1, 2)	(2, -1)	min(|2 - (-1)|, |2 + (-1)|) = 1	1	max(|2 - (-1)|, |2 + (-1)|) = 3	2
(1, 3)	(2, 4)	min(|2 - 4|, |2 + 4|) = 2	2	max(|2 - 4|, |2 + 4|) = 6	4
Example 3:

Input: nums = [1,10,100,1000]

Output: 0

Explanation:

There are no perfect pairs. Thus, the answer is 0.

 

Constraints:

2 <= nums.length <= 105
-109 <= nums[i] <= 109



*/

#include <list>

class Solution {
public:
    long long perfectPairs(vector<int>& nums) {

        sort(nums.begin(), nums.end());  //sorting O(log N)  myFirstApproach
        
        //takeTwoPointer
        int i = 0;
        int j = nuns.size() - 1;

        //take a list to store the distintPerfectPairs
        list<int> perfectPairs;

        while(i < j) {
            //define a and b
            int a = nums[i];
            int b = nums[j];

            //givePerfectPairsCondition for min and max also
            if(min((abs(a-b), abs(a+b)) <= min(abs(a), abs(b)) )    && max(abs(a-b), abs(a+b)) >= max(abs(a), abs(b))) {
                perfectPairs.push_back(i, j);

            } else {
                return 0;
            }
        }
 
    }
};


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long perfectPairs(vector<int>& nums) {  //TC=O(nLogN), sc=O(n)

        vector<long long> absVals;
        absVals.reserve(nums.size());


        for (int x : nums)
            absVals.push_back(abs((long long)x));

        sort(absVals.begin(), absVals.end());
        long long count = 0;


        for (int i = 0; i < absVals.size(); ++i) {
            long long lo = absVals[i];
            long long lowBound = (lo + 1) / 2;   // ceil(lo / 2)
            long long highBound = 2 * lo;

            // Find valid range [L, R) left right
            auto L = lower_bound(absVals.begin() + i + 1, absVals.end(), lowBound);
            auto R = upper_bound(absVals.begin() + i + 1, absVals.end(), highBound);

            count += (R - L);
        }

        return count;
    }
};


/*

qno 2938  https://leetcode.com/problems/separate-black-and-white-balls/description/

Every time we see a '1' (black ball) before a '0' (white ball),
that '1' will eventually have to move to the right of that zero.
That means the total number of swaps = number of inversions where '1' appears before '0'.




2938. Separate Black and White Balls
Medium
Topics

Companies
Hint
There are n balls on a table, each ball has a color black or white.

You are given a 0-indexed binary string s of length n, where 1 and 0 represent black and white balls, respectively.

In each step, you can choose two adjacent balls and swap them.

Return the minimum number of steps to group all the black balls to the right and all the white balls to the left.

 

Example 1:

Input: s = "101"
Output: 1
Explanation: We can group all the black balls to the right in the following way:
- Swap s[0] and s[1], s = "011".
Initially, 1s are not grouped together, requiring at least 1 step to group them to the right.
Example 2:

Input: s = "100"
Output: 2
Explanation: We can group all the black balls to the right in the following way:
- Swap s[0] and s[1], s = "010".
- Swap s[1] and s[2], s = "001".
It can be proven that the minimum number of steps needed is 2.
Example 3:

Input: s = "0111"
Output: 0
Explanation: All the black balls are already grouped to the right.
 

Constraints:

1 <= n == s.length <= 105
s[i] is either '0' or '1'.



*/

class Solution {
public:
    long long minimumSteps(string s) {  //TC=O(n), sc=O(1)

        //akho ka kaamal
//      //EYE observation: total number of swaps = number of inversions where '1' appears before '0'
        long long ones = 0;   // count of '1's seen so far
        long long steps = 0;  // total swaps needed



        for (char c : s) {
            if (c == '1') {
                ones++; // every '1' may need to move right
            } else {
                steps += ones; // each '0' must move past all previous '1's
            }
        }

        return steps;
    }
};




/*

qno  1455   https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/description/ 


1455. Check If a Word Occurs As a Prefix of Any Word in a Sentence
Easy
Topics

Companies
Hint
Given a sentence that consists of some words separated by a single space, and a searchWord, check if searchWord is a prefix of any word in sentence.

Return the index of the word in sentence (1-indexed) where searchWord is a prefix of this word. If searchWord is a prefix of more than one word, return the index of the first word (minimum index). If there is no such word return -1.

A prefix of a string s is any leading contiguous substring of s.

 

Example 1:

Input: sentence = "i love eating burger", searchWord = "burg"
Output: 4
Explanation: "burg" is prefix of "burger" which is the 4th word in the sentence.
Example 2:

Input: sentence = "this problem is an easy problem", searchWord = "pro"
Output: 2
Explanation: "pro" is prefix of "problem" which is the 2nd and the 6th word in the sentence, but we return 2 as it's the minimal index.
Example 3:

Input: sentence = "i am tired", searchWord = "you"
Output: -1
Explanation: "you" is not a prefix of any word in the sentence.
 

Constraints:

1 <= sentence.length <= 100
1 <= searchWord.length <= 10
sentence consists of lowercase English letters and spaces.
searchWord consists of lowercase English letters.



*/

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {  //TC=O(n), SC=O(1)

        stringstream ss(sentence);
        string word;
        int index = 1;  // words are 1-indexed

        while (ss >> word) {
            if (word.rfind(searchWord, 0) == 0) { 
                // rfind(searchWord, 0) == 0 means searchWord is prefix of word
                return index;
            }

            index++;
        }

        return -1;

    }
};



/*

qno 2255  https://leetcode.com/problems/count-prefixes-of-a-given-string/

Ankit learn
rfind() is a member function of the std::string class (from <string>).
It is used to search for the last occurrence of a substring (or character) inside a string, searching backward from a given position.

| Parameter | Meaning                                                                                                       |
| --------- | ------------------------------------------------------------------------------------------------------------- |
| `str`     | The substring or character to find                                                                            |
| `pos`     | The **starting position** for the search (counted from the left, but search happens backward from there)      |
| `npos`    | A special constant (`string::npos`) that represents “not found” or “search until the beginning of the string” |



SUMMARY:

| Expression                       | Meaning                                    |
| -------------------------------- | ------------------------------------------ |
| `s.rfind("abc")`                 | Find last `"abc"` anywhere in `s`          |
| `s.rfind("abc", 10)`             | Search backward from index 10              |
| `s.rfind("abc", 0)`              | Only match if `"abc"` starts at position 0 |
| `s.rfind('x')`                   | Find last occurrence of `'x'`              |
| `s.rfind("xyz") == string::npos` | `"xyz"` not found                          |




DIFFERENCE: 

| Function  | Search Direction | Finds                |
| --------- | ---------------- | -------------------- |
| `find()`  | Left → Right     | **First** occurrence |
| `rfind()` | Right → Left     | **Last** occurrence  |


🧠 In Short
rfind(sub, 0) == 0 → means “does this string start with sub?”
rfind() by itself → “find me the last occurrence of sub.”







2255. Count Prefixes of a Given String
Attempted
Easy
Topics

Companies
Hint
You are given a string array words and a string s, where words[i] and s comprise only of lowercase English letters.

Return the number of strings in words that are a prefix of s.

A prefix of a string is a substring that occurs at the beginning of the string. A substring is a contiguous sequence of characters within a string.

 

Example 1:

Input: words = ["a","b","c","ab","bc","abc"], s = "abc"
Output: 3
Explanation:
The strings in words which are a prefix of s = "abc" are:
"a", "ab", and "abc".
Thus the number of strings in words which are a prefix of s is 3.
Example 2:

Input: words = ["a","a"], s = "aa"
Output: 2
Explanation:
Both of the strings are a prefix of s. 
Note that the same string can occur multiple times in words, and it should be counted each time.
 

Constraints:

1 <= words.length <= 1000
1 <= words[i].length, s.length <= 10
words[i] and s consist of lowercase English letters only.


*/



class Solution {
public:
    int countPrefixes(vector<string>& words, string s) { //TC=O(N * L), no of word and woedLength SC=O(1)
        int count = 0;

        for (auto &word : words) {
            // Check if s starts with word
            if (s.rfind(word, 0) == 0) {
                count++;
            }
        }

        return count;
    }
};


class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int count = 0;

        for (auto &word : words) {
            bool isPrefix = true;

            // if word is longer than s, it can't be a prefix
            if (word.size() > s.size()) continue;

            // compare character by character
            for (int i = 0; i < word.size(); i++) {
                if (word[i] != s[i]) {
                    isPrefix = false;
                    break;
                }
            }

            if (isPrefix)
                count++;
        }

        return count;
    }
};


class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int count = 0;
        for (auto &word : words) {
            if (s.substr(0, word.size()) == word)
                count++;
        }
        return count;
    }
};





/*

qno 541  https://leetcode.com/problems/reverse-string-ii/description/

541. Reverse String II
Solved
Easy
Topics

Companies
Given a string s and an integer k, reverse the first k characters for every 2k characters counting from the start of the string.

If there are fewer than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and leave the other as original.

 

Example 1:

Input: s = "abcdefg", k = 2
Output: "bacdfeg"
Example 2:

Input: s = "abcd", k = 2
Output: "bacd"
 

Constraints:

1 <= s.length <= 104
s consists of only lowercase English letters.
1 <= k <= 104


*/

class Solution {
public:
    string reverseStr(string s, int k) {
        
        for(int i=0; i<s.length(); i += 2*k) {
            int end = min(i+k, (int)s.length());  //to select min

            reverse(s.begin()+i, s.begin()+end);
        }

        return s;
    }
};


// TC=O(n), SC=O(1)