





/*


24th Dec 2025 (Wednesday)


qno 3783  https://leetcode.com/problems/mirror-distance-of-an-integer/



3783. Mirror Distance of an Integer
Easy
Topics

Companies
Hint
You are given an integer n.

Define its mirror distance as: abs(n - reverse(n))​​​​​​​ where reverse(n) is the integer formed by reversing the digits of n.

Return an integer denoting the mirror distance of n​​​​​​​.

abs(x) denotes the absolute value of x.

 

Example 1:

Input: n = 25

Output: 27

Explanation:

reverse(25) = 52.
Thus, the answer is abs(25 - 52) = 27.
Example 2:

Input: n = 10

Output: 9

Explanation:

reverse(10) = 01 which is 1.
Thus, the answer is abs(10 - 1) = 9.
Example 3:

Input: n = 7

Output: 0

Explanation:

reverse(7) = 7.
Thus, the answer is abs(7 - 7) = 0.
 

Constraints:

1 <= n <= 109



*/


class Solution {
public:
    int mirrorDistance(int n) { //sc=O(1)
        //step1: Rev 
        int R = 0;
        int original = n;
        
        // ReverseNum - tc=O(n)
        while (n > 0) {
            R = R * 10 + (n % 10);  // Get the last digit and add it to R
            n /= 10;  // Remove the last digit from n
        }

        //step2: calculateDiff
        int diff = original - R;

        return abs(diff);
    }
};







/*

qno 3784  https://leetcode.com/problems/minimum-deletion-cost-to-make-all-characters-equal/description/



3784. Minimum Deletion Cost to Make All Characters Equal
Attempted
Medium
Topics

Companies
Hint
You are given a string s of length n and an integer array cost of the same length, where cost[i] is the cost to delete the ith character of s.

You may delete any number of characters from s (possibly none), such that the resulting string is non-empty and consists of equal characters.

Return an integer denoting the minimum total deletion cost required.

 

Example 1:

Input: s = "aabaac", cost = [1,2,3,4,1,10]

Output: 11

Explanation:

Deleting the characters at indices 0, 1, 2, 3, 4 results in the string "c", which consists of equal characters, and the total cost is cost[0] + cost[1] + cost[2] + cost[3] + cost[4] = 1 + 2 + 3 + 4 + 1 = 11.

Example 2:

Input: s = "abc", cost = [10,5,8]

Output: 13

Explanation:

Deleting the characters at indices 1 and 2 results in the string "a", which consists of equal characters, and the total cost is cost[1] + cost[2] = 5 + 8 = 13.

Example 3:

Input: s = "zzzzz", cost = [67,67,67,67,67]

Output: 0

Explanation:

All characters in s are equal, so the deletion cost is 0.

 

Constraints:

n == s.length == cost.length
1 <= n <= 105
1 <= cost[i] <= 109
s consists of lowercase English letters.




*/


class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        long long totalCost = 0;
        vector<long long> keepCost(26, 0);

        //step1: Compute total cost and cost per char
        for (int i = 0; i < s.size(); i++) {
            totalCost += cost[i];
            keepCost[s[i] - 'a'] += cost[i];
        }

        //step2: Find miniDeletion cost
        long long ans = LLONG_MAX;
        for (int i = 0; i < 26; i++) {
            if (keepCost[i] > 0) { // char exists in str
                ans = min(ans, totalCost - keepCost[i]);
            }
        }

        return ans;
    }
};




/*


qno 914  https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/


914. X of a Kind in a Deck of Cards
Solved
Easy
Topics

Companies
You are given an integer array deck where deck[i] represents the number written on the ith card.

Partition the cards into one or more groups such that:

Each group has exactly x cards where x > 1, and
All the cards in one group have the same integer written on them.
Return true if such partition is possible, or false otherwise.

 

Example 1:

Input: deck = [1,2,3,4,4,3,2,1]
Output: true
Explanation: Possible partition [1,1],[2,2],[3,3],[4,4].
Example 2:

Input: deck = [1,1,1,2,2,2,3,3]
Output: false
Explanation: No possible partition.
 

Constraints:

1 <= deck.length <= 104
0 <= deck[i] < 104


*/




class Solution {
public:
    int gcd(int a, int b) {  // helper function
        if (a == 0) {
            return b;
        }
        return gcd(b % a, a);
    }

    bool hasGroupsSizeX(vector<int>& deck) {
        sort(deck.begin(), deck.end());

        int count = 1;
        int g = 0;   // renamed variable

        for (int i = 0; i < deck.size() - 1; i++) {
            if (deck[i] == deck[i + 1]) {
                count++;
            } else {
                g = gcd(g, count);
                count = 1;
            }
        }

        // process last group
        g = gcd(g, count);
        return g >= 2;
    }
};




/*


qno 2520  https://leetcode.com/problems/count-the-digits-that-divide-a-number/


2520. Count the Digits That Divide a Number
Easy
Topics

Companies
Hint
Given an integer num, return the number of digits in num that divide num.

An integer val divides nums if nums % val == 0.

 

Example 1:

Input: num = 7
Output: 1
Explanation: 7 divides itself, hence the answer is 1.
Example 2:

Input: num = 121
Output: 2
Explanation: 121 is divisible by 1, but not 2. Since 1 occurs twice as a digit, we return 2.
Example 3:

Input: num = 1248
Output: 4
Explanation: 1248 is divisible by all of its digits, hence the answer is 4.
 

Constraints:

1 <= num <= 109
num does not contain 0 as one of its digits.



*/



class Solution {
public:
    int countDigits(int num) {  //tc=O(n), sc=O(1)
        int original = num;
        int count = 0;

        while (num > 0) {
            int digit = num % 10;

            if (original % digit == 0) {
                count++;
            }

            num /= 10;  // move to next digit
        }

        return count;
    }
};





/*


qno 2974   https://leetcode.com/problems/minimum-number-game/description/



2974. Minimum Number Game
Solved
Easy
Topics

Companies
Hint
You are given a 0-indexed integer array nums of even length and there is also an empty array arr. Alice and Bob decided to play a game where in every round Alice and Bob will do one move. The rules of the game are as follows:

Every round, first Alice will remove the minimum element from nums, and then Bob does the same.
Now, first Bob will append the removed element in the array arr, and then Alice does the same.
The game continues until nums becomes empty.
Return the resulting array arr.

 

Example 1:

Input: nums = [5,4,2,3]
Output: [3,2,5,4]
Explanation: In round one, first Alice removes 2 and then Bob removes 3. Then in arr firstly Bob appends 3 and then Alice appends 2. So arr = [3,2].
At the begining of round two, nums = [5,4]. Now, first Alice removes 4 and then Bob removes 5. Then both append in arr which becomes [3,2,5,4].
Example 2:

Input: nums = [2,5]
Output: [5,2]
Explanation: In round one, first Alice removes 2 and then Bob removes 5. Then in arr firstly Bob appends and then Alice appends. So arr = [5,2].
 

Constraints:

2 <= nums.length <= 100
1 <= nums[i] <= 100
nums.length % 2 == 0




*/



class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int i = 0;
        int j = 1;
        while(i<n  &&  j<n) {
            //swapping
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;

            i += 2;
            j += 2;
        }

        return nums;
    }
};