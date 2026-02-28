


/*

28th Feb 2026 (Satursday - lastDayOfFebmonth)


qno 1680  https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/?envType=daily-question&envId=2026-02-28


1680. Concatenation of Consecutive Binary Numbers
Medium
Topics

Companies
Hint
Given an integer n, return the decimal value of the binary string formed by concatenating the binary representations of 1 to n in order, modulo 109 + 7.

 

Example 1:

Input: n = 1
Output: 1
Explanation: "1" in binary corresponds to the decimal value 1. 
Example 2:

Input: n = 3
Output: 27
Explanation: In binary, 1, 2, and 3 corresponds to "1", "10", and "11".
After concatenating them, we have "11011", which corresponds to the decimal value 27.
Example 3:

Input: n = 12
Output: 505379714
Explanation: The concatenation results in "1101110010111011110001001101010111100".
The decimal value of that is 118505380540.
After modulo 109 + 7, the result is 505379714.
 

Constraints:

1 <= n <= 105
 
Discover more
LeetCode Premium Subscription
Seen this question in a real interview before?
1/5
Yes
No
Accepted
104,657/179K
Acceptance Rate
58.5%
Topics
Staff
Math
Bit Manipulation
Simulation
Weekly Contest 218



*/



class Solution {
public:
    int concatenatedBinary(int n) {  //bruteForce
        //step1: write num 1 to n

        //step2: convert into binaryRepresentation

        //step3: concate and convert into decial then return ans
    }
};



class Solution {
public:
    int concatenatedBinary(int n) {  //tc=O(n^2), sc=O(nlogN)
        const int MOD = 1e9 + 7;
        string s = "";
        
        // Step 1 & 2: build binary string
        for (int i = 1; i <= n; i++) {
            s += bitset<32>(i).to_string();
            
            // remove leading zeros
            while (s.back() == '0' && s.size() > 1 && s[s.size()-2] == '0') break;
        }

        // Better way to build binary properly:
        s = "";
        for (int i = 1; i <= n; i++) {
            int num = i;
            string temp = "";
            while (num > 0) {
                temp = char('0' + num % 2) + temp;
                num /= 2;
            }
            s += temp;
        }

        // Step 3: convert binary string to decimal
        long long ans = 0;
        for (char c : s) {
            ans = (ans * 2 + (c - '0')) % MOD;
        }

        return ans;
    }
};




class Solution {
public:
    int concatenatedBinary(int n) {  //tc=O(n), sc=O(1) using bitManipulaton approach
        const int MOD = 1e9 + 7;
        long long ans = 0;
        int bitLeng = 0;

        for(int i=1; i<=n; i++) {
            //if i is power of 2, increase bitLength
            if((i & (i - 1)) == 0) {
                bitLeng++;
            }
            ans = ((ans << bitLeng) % MOD + i) % MOD;
        }

        return ans;
    }
};




/*


qno 3842  https://leetcode.com/problems/toggle-light-bulbs/

3842. Toggle Light Bulbs
Easy
Topics

Companies
Hint
You are given an array bulbs of integers between 1 and 100.

There are 100 light bulbs numbered from 1 to 100. All of them are switched off initially.

For each element bulbs[i] in the array bulbs:

If the bulbs[i]th light bulb is currently off, switch it on.
Otherwise, switch it off.
Return the list of integers denoting the light bulbs that are on in the end, sorted in ascending order. If no bulb is on, return an empty list.

 

Example 1:

Input: bulbs = [10,30,20,10]

Output: [20,30]

Explanation:

The bulbs[0] = 10th light bulb is currently off. We switch it on.
The bulbs[1] = 30th light bulb is currently off. We switch it on.
The bulbs[2] = 20th light bulb is currently off. We switch it on.
The bulbs[3] = 10th light bulb is currently on. We switch it off.
In the end, the 20th and the 30th light bulbs are on.
Example 2:

Input: bulbs = [100,100]

Output: []

Explanation:

The bulbs[0] = 100th light bulb is currently off. We switch it on.
The bulbs[1] = 100th light bulb is currently on. We switch it off.
In the end, no light bulb is on.
 

Constraints:

1 <= bulbs.length <= 100
1 <= bulbs[i] <= 100
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
53,955/75.2K
Acceptance Rate
71.8%
Topics
Mid Level
Array
Hash Table
Sorting
Simulation
Weekly Contest 489


*/


class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        vector<int> freq(101, 0);   // bulbs numbered 1 to 100
        
        // Count frequency
        for (int b : bulbs) {
            freq[b]++;
        }
        
        vector<int> ans;
        
        // Check which bulbs are ON (odd count)
        for (int i = 1; i <= 100; i++) {
            if (freq[i] % 2 == 1) {
                ans.push_back(i);
            }
        }
        
        return ans;   // already sorted because we go from 1 to 100
    }
};


class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        vector<bool> state(101, false);  // all OFF initially
        
        // Toggle directly
        for (int b : bulbs) {
            state[b] = !state[b];
        }
        
        vector<int> ans;
        
        for (int i = 1; i <= 100; i++) {
            if (state[i]) {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};