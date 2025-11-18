


/*

18th Nov 2025 (Tuesday)

qno 2274   https://leetcode.com/problems/maximum-consecutive-floors-without-special-floors/description/


2274. Maximum Consecutive Floors Without Special Floors
Medium
Topics

Companies
Hint
Alice manages a company and has rented some floors of a building as office space. Alice has decided some of these floors should be special floors, used for relaxation only.

You are given two integers bottom and top, which denote that Alice has rented all the floors from bottom to top (inclusive). You are also given the integer array special, where special[i] denotes a special floor that Alice has designated for relaxation.

Return the maximum number of consecutive floors without a special floor.

 

Example 1:

Input: bottom = 2, top = 9, special = [4,6]
Output: 3
Explanation: The following are the ranges (inclusive) of consecutive floors without a special floor:
- (2, 3) with a total amount of 2 floors.
- (5, 5) with a total amount of 1 floor.
- (7, 9) with a total amount of 3 floors.
Therefore, we return the maximum number which is 3 floors.
Example 2:

Input: bottom = 6, top = 8, special = [7,6,8]
Output: 0
Explanation: Every floor rented is a special floor, so we return 0.
 

Constraints:

1 <= special.length <= 105
1 <= bottom <= special[i] <= top <= 109
All the values of special are unique.



*/




class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) { //tc=O(n), SC=O(1)
        int n = special.size();

        sort(special.begin(), special.end());
 
        int maxGap = 0;

        // First, consider the gap before the first special floor
        maxGap = max(maxGap, special[0] - bottom);

        // Then, consider the gaps between consecutive special floors
        for (int i=1; i<n; i++) {
            maxGap = max(maxGap, special[i] - special[i - 1] - 1);
        }

        // Finally, consider the gap after the last special floor
        maxGap = max(maxGap, top - special[n - 1]);

        return maxGap;
    }
};



/*

qno 3234  https://leetcode.com/problems/count-the-number-of-substrings-with-dominant-ones/description/



3234. Count the Number of Substrings With Dominant Ones
Medium
Topics

Companies
Hint
You are given a binary string s.

Return the number of substrings with dominant ones.

A string has dominant ones if the number of ones in the string is greater than or equal to the square of the number of zeros in the string.

 

Example 1:

Input: s = "00011"

Output: 5

Explanation:

The substrings with dominant ones are shown in the table below.

i	j	s[i..j]	Number of Zeros	Number of Ones
3	3	1	0	1
4	4	1	0	1
2	3	01	1	1
3	4	11	0	2
2	4	011	1	2
Example 2:

Input: s = "101101"

Output: 16

Explanation:

The substrings with non-dominant ones are shown in the table below.

Since there are 21 substrings total and 5 of them have non-dominant ones, it follows that there are 16 substrings with dominant ones.

i	j	s[i..j]	Number of Zeros	Number of Ones
1	1	0	1	0
4	4	0	1	0
1	4	0110	2	2
0	4	10110	2	3
1	5	01101	2	3
 

Constraints:

1 <= s.length <= 4 * 104
s consists only of characters '0' and '1'.



*/


class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> zeroPos;
        
        // Store positions of zeros
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') zeroPos.push_back(i);
        }
        
        long long ans = 0;
        
        // Case 1: Substrings with no zeros
        long long countOnes = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                countOnes++;
            } else {
                ans += countOnes * (countOnes + 1) / 2;
                countOnes = 0;
            }
        }
        ans += countOnes * (countOnes + 1) / 2;
        

        // Case 2: Substrings with >=1 zero but limited to 200 zeros
        int Z = zeroPos.size();
        
        for (int i = 0; i < Z; i++) {
            for (int j = i; j < Z && j < i + 200; j++) {
                int leftZero = zeroPos[i];
                int rightZero = zeroPos[j];

                int zeros = j - i + 1;
                int requiredOnes = zeros * zeros;

                // ones in substring [leftZero..rightLimit]
                int left = leftZero;
                int rightLimit = (j + 1 < Z ? zeroPos[j + 1] - 1 : n - 1);

                int totalLen = rightLimit - left + 1;
                int ones = totalLen - zeros;

                if (ones >= requiredOnes)
                    ans += (rightLimit - rightZero + 1);
            }
        }

        return ans;
    }
};



class Solution {
public:
    int numberOfSubstrings(string s) { //TC=O(n)=SC
        int n = s.size();
        vector<int> zeroPos;
        
        // Store positions of zeros
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') zeroPos.push_back(i);
        }
        
        long long ans = 0;
        
        // Case 1: Substrings with no zeros
        long long countOnes = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                countOnes++;
            } else {
                ans += countOnes * (countOnes + 1) / 2;
                countOnes = 0;
            }
        }
        ans += countOnes * (countOnes + 1) / 2;


        // Case 2: Substrings with >=1 zero but limited to 200 zeros
        int Z = zeroPos.size();
        
        for (int i = 0; i < Z; i++) {
            for (int j = i; j < Z && j < i + 200; j++) {
                int leftZero = zeroPos[i];
                int rightZero = zeroPos[j];

                int zeros = j - i + 1;
                int requiredOnes = zeros * zeros;

                // ones in substring [leftZero..rightLimit]
                int left = leftZero;
                int rightLimit = (j + 1 < Z ? zeroPos[j + 1] - 1 : n - 1);

                int totalLen = rightLimit - left + 1;
                int ones = totalLen - zeros;

                if (ones >= requiredOnes)
                    ans += (rightLimit - rightZero + 1);
            }
        }

        return ans;
    }
};
