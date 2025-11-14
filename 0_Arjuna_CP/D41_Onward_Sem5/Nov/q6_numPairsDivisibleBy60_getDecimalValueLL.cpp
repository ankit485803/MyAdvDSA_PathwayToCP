

/*

14th Nov 2025 (Friday)

qno 1010   https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/


1010. Pairs of Songs With Total Durations Divisible by 60
Medium
Topics

Companies
Hint
You are given a list of songs where the ith song has a duration of time[i] seconds.

Return the number of pairs of songs for which their total duration in seconds is divisible by 60. Formally, we want the number of indices i, j such that i < j with (time[i] + time[j]) % 60 == 0.

 

Example 1:

Input: time = [30,20,150,100,40]
Output: 3
Explanation: Three pairs have a total duration divisible by 60:
(time[0] = 30, time[2] = 150): total duration 180
(time[1] = 20, time[3] = 100): total duration 120
(time[1] = 20, time[4] = 40): total duration 60
Example 2:

Input: time = [60,60,60]
Output: 3
Explanation: All three pairs have a total duration of 120, which is divisible by 60.
 

Constraints:

1 <= time.length <= 6 * 104
1 <= time[i] <= 500



*/


class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {  //TC=O(n), SC=O(1)
        
        vector<int> freq(60, 0);
        int ans = 0;

        for (int t : time) {
            int remainder = t % 60;

            if (remainder == 0) {
                ans += freq[0];  //find how many songs have remainder 0 

            } else {
                ans += freq[60 - remainder];  //find how many songs have remainder (60 - r)
            }

            freq[remainder]++;
        }

        return ans;
    }
};



/*

qno 1290   https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/


1290. Convert Binary Number in a Linked List to Integer
Easy
Topics

Companies
Hint
Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number.

Return the decimal value of the number in the linked list.

The most significant bit is at the head of the linked list.

 

Example 1:


Input: head = [1,0,1]
Output: 5
Explanation: (101) in base 2 = (5) in base 10
Example 2:

Input: head = [0]
Output: 0
 

Constraints:

The Linked List is not empty.
Number of nodes will not exceed 30.
Each node's value is either 0 or 1.


*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {  //TC=O(n), TC=O(1)
        
        int ans = 0;

        while(head != nullptr) {
            ans = ans * 2 + head->val;  //Shift left (multiply by 2) and add the current bit
            head = head->next;  //moveToNextNode

        }

        return ans;
    }
};



/*

qno 2231  https://leetcode.com/problems/largest-number-after-digit-swaps-by-parity/

2231. Largest Number After Digit Swaps by Parity
Easy
Topics

Companies
Hint
You are given a positive integer num. You may swap any two digits of num that have the same parity (i.e. both odd digits or both even digits).

Return the largest possible value of num after any number of swaps.

 

Example 1:

Input: num = 1234
Output: 3412
Explanation: Swap the digit 3 with the digit 1, this results in the number 3214.
Swap the digit 2 with the digit 4, this results in the number 3412.
Note that there may be other sequences of swaps but it can be shown that 3412 is the largest possible number.
Also note that we may not swap the digit 4 with the digit 1 since they are of different parities.
Example 2:

Input: num = 65875
Output: 87655
Explanation: Swap the digit 8 with the digit 6, this results in the number 85675.
Swap the first digit 5 with the digit 7, this results in the number 87655.
Note that there may be other sequences of swaps but it can be shown that 87655 is the largest possible number.
 

Constraints:

1 <= num <= 109

*/

class Solution {
public:
    int largestInteger(int num) {  //TC=o(n logN), SC=O(n)
        string s = to_string(num);
        
        vector<int> even, odd;
        
        // Separate digits by parity
        for (char c : s) {
            int d = c - '0';
            if (d % 2 == 0) even.push_back(d);
            else odd.push_back(d);
        }
        
        // Sort both groups in descending order
        sort(even.begin(), even.end(), greater<int>());
        sort(odd.begin(), odd.end(), greater<int>());
        
        // Rebuild largest possible number
        string res = "";
        int even_idx = 0, odd_idx = 0;
        
        for (char c : s) {
            int d = c - '0';
            if (d % 2 == 0) {
                res += char(even[even_idx++] + '0');
            } else {
                res += char(odd[odd_idx++] + '0');
            }
        }
        
        return stoi(res);
    }
};
