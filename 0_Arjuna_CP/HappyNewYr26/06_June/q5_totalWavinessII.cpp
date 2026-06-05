

/*

5th June 2026 (Friday)

qno 3753  https://leetcode.com/problems/total-waviness-of-numbers-in-range-ii/?envType=daily-question&envId=2026-06-05

3753. Total Waviness of Numbers in Range II
Hard
Topics

Companies
Hint
You are given two integers num1 and num2 representing an inclusive range [num1, num2].

The waviness of a number is defined as the total count of its peaks and valleys:

A digit is a peak if it is strictly greater than both of its immediate neighbors.
A digit is a valley if it is strictly less than both of its immediate neighbors.
The first and last digits of a number cannot be peaks or valleys.
Any number with fewer than 3 digits has a waviness of 0.
Return the total sum of waviness for all numbers in the range [num1, num2].
 

Example 1:

Input: num1 = 120, num2 = 130

Output: 3

Explanation:

In the range [120, 130]:

120: middle digit 2 is a peak, waviness = 1.
121: middle digit 2 is a peak, waviness = 1.
130: middle digit 3 is a peak, waviness = 1.
All other numbers in the range have a waviness of 0.
Thus, total waviness is 1 + 1 + 1 = 3.

Example 2:

Input: num1 = 198, num2 = 202

Output: 3

Explanation:

In the range [198, 202]:

198: middle digit 9 is a peak, waviness = 1.
201: middle digit 0 is a valley, waviness = 1.
202: middle digit 0 is a valley, waviness = 1.
All other numbers in the range have a waviness of 0.
Thus, total waviness is 1 + 1 + 1 = 3.

Example 3:

Input: num1 = 4848, num2 = 4848

Output: 2

Explanation:

Number 4848: the second digit 8 is a peak, and the third digit 4 is a valley, giving a waviness of 2.

 

Constraints:

1 <= num1 <= num2 <= 1015​​​​​​​
 
Seen this question in a real interview before?
1/6
Yes
No
Accepted
19,659/43.6K
Acceptance Rate
45.0%
Topics
Senior Staff
Math
Dynamic Programming
Biweekly Contest 170

*/



#include <bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<string, pair<long long, long long>> mp;

public:
    // Time: O(D * 11 * 11 * 2 * 2) = O(D), Space: O(D)
    // where D = number of digits in num2

    long long totalWaviness(long long num1, long long num2) {
        // Count waviness in [num1, num2] using prefix subtraction
        return getWaves(num2) - getWaves(num1 - 1);
    }

    // Returns total waviness for all numbers in [0, num]
    long long getWaves(long long num) {
        if (num < 0) return 0;

        mp.clear();
        string s = to_string(num);

        // Numbers with fewer than 3 digits can't have a wave peak/valley
        if ((int)s.size() < 3) return 0;

        auto ans = helper(s, 0, true, -1, -1, true);
        return ans.second; // ans.first = count, ans.second = total waviness
    }

    // Returns {count of valid numbers, total waviness}
    pair<long long, long long> helper(
        string &s,
        int idx,
        bool isBound,
        int twobefore,
        int onebefore,
        bool leadingZero
    ) {
        // Base case: full number formed
        if (idx == (int)s.size()) {
            // Leading zero means the number was effectively empty/zero — not valid
            return leadingZero ? make_pair(0LL, 0LL)
                               : make_pair(1LL, 0LL);
        }

        string key = to_string(idx) + "#" +
                     to_string(isBound) + "#" +
                     to_string(twobefore) + "#" +
                     to_string(onebefore) + "#" +
                     to_string(leadingZero);

        if (mp.count(key))
            return mp[key];

        int upper = isBound ? (s[idx] - '0') : 9;

        long long totalCount = 0;
        long long totalWaves = 0;

        for (int i = 0; i <= upper; i++) {
            long long wave = 0;
            int nextTwoBefore, nextOneBefore;

            if (leadingZero) {
                // Still in leading zero phase
                nextTwoBefore = -1;
                nextOneBefore = (i == 0) ? -1 : i;
            } else {
                nextTwoBefore = onebefore;
                nextOneBefore = i;

                // Check if onebefore forms a wave peak or valley
                if (twobefore >= 0 && onebefore >= 0) {
                    if ((onebefore > twobefore && onebefore > i) || // peak
                        (onebefore < twobefore && onebefore < i)) { // valley
                        wave = 1;
                    }
                }
            }

            bool nextBound = isBound && (i == upper);
            bool nextLeadingZero = leadingZero && (i == 0);

            auto sub = helper(
                s,
                idx + 1,
                nextBound,
                nextTwoBefore,
                nextOneBefore,
                nextLeadingZero
            );

            totalCount += sub.first;

            // Each of the sub.first numbers contributes current wave
            // plus their own internal waves
            totalWaves += sub.second + sub.first * wave;
        }

        return mp[key] = {totalCount, totalWaves};
    }
};