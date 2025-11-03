



/*

3rd Nov 2025 (Monday)


qno 319  https://leetcode.com/problems/bulb-switcher/description/


319. Bulb Switcher
Medium
Topics

Companies
There are n bulbs that are initially off. You first turn on all the bulbs, then you turn off every second bulb.

On the third round, you toggle every third bulb (turning on if it's off or turning off if it's on). For the ith round, you toggle every i bulb. For the nth round, you only toggle the last bulb.

Return the number of bulbs that are on after n rounds.

 

Example 1:
Input: n = 3
Output: 1
Explanation: At first, the three bulbs are [off, off, off].
After the first round, the three bulbs are [on, on, on].
After the second round, the three bulbs are [on, off, on].
After the third round, the three bulbs are [on, off, off]. 
So you should return 1 because there is only one bulb is on.


Example 2:

Input: n = 0
Output: 0
Example 3:

Input: n = 1
Output: 1
 

Constraints:

0 <= n <= 109


💡 Observations
Each bulb is toggled once for every divisor it has.

For example:
Bulb 1 is toggled on Round 1 → 1 divisor → toggled once → ON
Bulb 2 is toggled on Rounds 1 and 2 → 2 divisors → toggled twice → OFF
Bulb 3 is toggled on Rounds 1 and 3 → 2 divisors → OFF
Bulb 4 is toggled on Rounds 1, 2, and 4 → 3 divisors → ON
So, a bulb ends up ON if it is toggled an odd number of times.

🧮 When does a bulb have an odd number of divisors?
A number has an odd number of divisors only if it’s a perfect square.
That’s because divisors usually come in pairs:
e.g., for 12: (1,12), (2,6), (3,4)
but for perfect squares (like 9): (1,9), (3,3) — 3 is counted once


✅ Conclusion
Only bulbs at perfect square positions will remain ON.
So:
For n = 3 → perfect squares ≤ 3: [1] → 1 bulb ON
For n = 10 → perfect squares ≤ 10: [1, 4, 9] → 3 bulbs ON


🧠 Formula: Number of bulbs ON = ⌊√n⌋

*/


class Solution {
public:
    int bulbSwitch(int n) {
        
        /*

        obsevation: Each bulb is toggled once for every divisor it has.
        So, a bulb ends up ON if it is toggled an odd number of times
        A number has an odd number of divisors only if it’s a perfect square.
        
        ans: Only bulbs at perfect square positions will remain ON.
        
        
        */

        return sqrt(n);
    }
};



/*

qno 2108  https://leetcode.com/problems/find-first-palindromic-string-in-the-array/


2108. Find First Palindromic String in the Array
Easy
Topics

Companies
Hint
Given an array of strings words, return the first palindromic string in the array. If there is no such string, return an empty string "".

A string is palindromic if it reads the same forward and backward.

 

Example 1:

Input: words = ["abc","car","ada","racecar","cool"]
Output: "ada"
Explanation: The first string that is palindromic is "ada".
Note that "racecar" is also palindromic, but it is not the first.
Example 2:

Input: words = ["notapalindrome","racecar"]
Output: "racecar"
Explanation: The first and only string that is palindromic is "racecar".
Example 3:

Input: words = ["def","ghi"]
Output: ""
Explanation: There are no palindromic strings, so the empty string is returned.
 

Constraints:

1 <= words.length <= 100
1 <= words[i].length <= 100
words[i] consists only of lowercase English letters.


*/


#include <bits/stdc++.h>   // (LeetCode allows this, but not always best practice)
// or better to include only what we need:
#include <vector>
#include <string>
#include <algorithm>  // for std::equal

using namespace std;

class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (string &w : words)
            if (equal(w.begin(), w.end(), w.rbegin()))  // check palindrome
                return w;
        return "";
    }
};




#include <vector>
#include <string>
#include <algorithm>  // for std::reverse

using namespace std;

class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (string &w : words) {
            string rev = w;
            reverse(rev.begin(), rev.end());  // reverse copy
            if (w == rev) return w;
        }
        return "";
    }
};




class Solution {
public:
    string firstPalindrome(vector<string>& words) {  //TC=O(n), sc=O(1)
        for (string &word : words) {
            if (isPalindrome(word)) {
                return word;  // return the first palindrome found
            }
        }
        return "";  // if no palindrome found
    }


private:
    bool isPalindrome(string &s) {
        //twoPointerApproach
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};
