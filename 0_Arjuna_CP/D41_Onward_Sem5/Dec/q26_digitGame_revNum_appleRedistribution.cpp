





/*


26th Dec 2025 (Thursday)


qno 3232  https://leetcode.com/problems/find-if-digit-game-can-be-won/description/



3232. Find if Digit Game Can Be Won
Attempted
Easy
Topics

Companies
Hint
You are given an array of positive integers nums.

Alice and Bob are playing a game. In the game, Alice can choose either all single-digit numbers or all double-digit numbers from nums, and the rest of the numbers are given to Bob. Alice wins if the sum of her numbers is strictly greater than the sum of Bob's numbers.

Return true if Alice can win this game, otherwise, return false.

 

Example 1:

Input: nums = [1,2,3,4,10]

Output: false

Explanation:

Alice cannot win by choosing either single-digit or double-digit numbers.

Example 2:

Input: nums = [1,2,3,4,5,14]

Output: true

Explanation:

Alice can win by choosing single-digit numbers which have a sum equal to 15.

Example 3:

Input: nums = [5,5,5,25]

Output: true

Explanation:

Alice can win by choosing double-digit numbers which have a sum equal to 25.

 

Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 99




*/



class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int singleSum = 0;
        int doubleSum = 0;

        for (int num : nums) {
            if (num < 10) {
                singleSum += num;
            } else {
                doubleSum += num;
            }
        }

        // Alice can choose either group
        return (singleSum > doubleSum) || (doubleSum > singleSum);
    }
};






class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int singleD = 0;  //digit single
        int doubleD = 0;
        
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] < 10) {
                singleD += nums[i];
            } else {
                doubleD += nums[i];
            }
        }
        if(singleD == doubleD) {
            return false;   //aliceShikha wins
        }
        return true;  //bobBanti 
    }
};






/*


qno 2789  https://leetcode.com/problems/find-the-maximum-achievable-number/description/

2769. Find the Maximum Achievable Number
Solved
Easy
Topics

Companies
Hint
Given two integers, num and t. A number x is achievable if it can become equal to num after applying the following operation at most t times:

Increase or decrease x by 1, and simultaneously increase or decrease num by 1.
Return the maximum possible value of x.

 

Example 1:

Input: num = 4, t = 1

Output: 6

Explanation:

Apply the following operation once to make the maximum achievable number equal to num:

Decrease the maximum achievable number by 1, and increase num by 1.
Example 2:

Input: num = 3, t = 2

Output: 7

Explanation:

Apply the following operation twice to make the maximum achievable number equal to num:

Decrease the maximum achievable number by 1, and increase num by 1.
 

Constraints:

1 <= num, t <= 50



*/



class Solution {
public:
    int theMaximumAchievableX(int num, int t) {  //tc=O(1)=sc
        //increase or decrease by 1 netGain = 2 so for t time: 2*t
        int ans = num + 2*t;
        return ans;
    }
};




/*


qno 2443  https://leetcode.com/problems/sum-of-number-and-its-reverse/description/



2443. Sum of Number and Its Reverse
Medium
Topics

Companies
Hint
Given a non-negative integer num, return true if num can be expressed as the sum of any non-negative integer and its reverse, or false otherwise.

 

Example 1:

Input: num = 443
Output: true
Explanation: 172 + 271 = 443 so we return true.
Example 2:

Input: num = 63
Output: false
Explanation: 63 cannot be expressed as the sum of a non-negative integer and its reverse so we return false.
Example 3:

Input: num = 181
Output: true
Explanation: 140 + 041 = 181 so we return true. Note that when a number is reversed, there may be leading zeros.
 

Constraints:

0 <= num <= 105





*/



class Solution {
public:
    int reverseNum(int x) {   //helperFunct
        int rev = 0;
        while (x > 0) {
            rev = rev * 10 + (x % 10);
            x /= 10;  //revLastDigit
        }
        return rev;
    }

    bool sumOfNumberAndReverse(int num) {
        for (int x = 0; x <= num; x++) {
            if (x + reverseNum(x) == num) {
                return true;
            }
        }
        return false;
    }
};





/*




qno 3074  https://leetcode.com/problems/apple-redistribution-into-boxes/


3074. Apple Redistribution into Boxes
Easy
Topics

Companies
Hint
You are given an array apple of size n and an array capacity of size m.

There are n packs where the ith pack contains apple[i] apples. There are m boxes as well, and the ith box has a capacity of capacity[i] apples.

Return the minimum number of boxes you need to select to redistribute these n packs of apples into boxes.

Note that, apples from the same pack can be distributed into different boxes.

 

Example 1:

Input: apple = [1,3,2], capacity = [4,3,1,5,2]
Output: 2
Explanation: We will use boxes with capacities 4 and 5.
It is possible to distribute the apples as the total capacity is greater than or equal to the total number of apples.
Example 2:

Input: apple = [5,5,5], capacity = [2,4,2,7]
Output: 4
Explanation: We will need to use all the boxes.
 

Constraints:

1 <= n == apple.length <= 50
1 <= m == capacity.length <= 50
1 <= apple[i], capacity[i] <= 50
The input is generated such that it's possible to redistribute packs of apples into boxes.




*/


class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n = apple.size();
        int m = capacity.size();

        sort(capacity.begin(), capacity.end());
        int totalApple = 0;
        for(int i=0; i<n; i++) {
            totalApple += apple[i];
        }

        int ans = 0;
        int totalCapacity = 0;
        for(int i=m-1; i>=0; i--) {
            totalCapacity += capacity[i];

            if(totalCapacity >= totalApple) {
                ans = m-i;
                break;
            }
        }

        return ans;
    }
};




class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int totalApple = 0;
        for (int a : apple) {
            totalApple += a;
        }

        sort(capacity.begin(), capacity.end(), greater<int>());

        int totalCapacity = 0;
        int boxes = 0;

        for (int c : capacity) {
            totalCapacity += c;
            boxes++;
            if (totalCapacity >= totalApple) {
                return boxes;
            }
        }

        return boxes; // guaranteed to be possible
    }
};





/*




qno 2  https://leetcode.com/problems/add-two-numbers/


2. Add Two Numbers
Solved
Medium
Topics

Companies
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:


Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
 

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
6,539,442/13.8M
Acceptance Rate
47.5%
Topics
Linked List
Math
Recursion



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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);  // dummy node to simplify code
        ListNode* current = dummy;          // pointer to construct the result list
        int carry = 0;                      // to keep track of carry-over
        

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;  // start with carry from previous operation
            

            // If l1 is not null, add its value to sum
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;  // move to the next node in l1
            }
            
            // If l2 is not null, add its value to sum
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;  // move to the next node in l2
            }
            
            // Update carry for the next addition (sum / 10 gives the carry)
            carry = sum / 10;
            
            // Create a new node with the digit (sum % 10)
            current->next = new ListNode(sum % 10);
            current = current->next;  // move to the new node
        }
        
        return dummy->next;  // the result starts from dummy->next
    }
};


//TC=(max(n, m)) = sc




/*




qno 445  https://leetcode.com/problems/add-two-numbers-ii/description/


445. Add Two Numbers II
Medium
Topics

Companies
You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:


Input: l1 = [7,2,4,3], l2 = [5,6,4]
Output: [7,8,0,7]
Example 2:

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [8,0,7]
Example 3:

Input: l1 = [0], l2 = [0]
Output: [0]
 

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
 

Follow up: Could you solve it without reversing the input lists?




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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) { //tc=O(n+m) = sc 
        stack<int> s1, s2;

        // Push values of l1 into stack
        while (l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }

        // Push values of l2 into stack
        while (l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }

        int carry = 0;
        ListNode* head = nullptr;

        while (!s1.empty() || !s2.empty() || carry) {
            int sum = carry;

            if (!s1.empty()) {
                sum += s1.top();
                s1.pop();
            }

            if (!s2.empty()) {
                sum += s2.top();
                s2.pop();
            }

            carry = sum / 10;

            // Insert at front
            ListNode* node = new ListNode(sum % 10);
            node->next = head;
            head = node;
        }

        return head;
    }
};




/*



qno 3075   https://leetcode.com/problems/maximize-happiness-of-selected-children/description/


3075. Maximize Happiness of Selected Children
Solved
Medium
Topics

Companies
Hint
You are given an array happiness of length n, and a positive integer k.

There are n children standing in a queue, where the ith child has happiness value happiness[i]. You want to select k children from these n children in k turns.

In each turn, when you select a child, the happiness value of all the children that have not been selected till now decreases by 1. Note that the happiness value cannot become negative and gets decremented only if it is positive.

Return the maximum sum of the happiness values of the selected children you can achieve by selecting k children.

 

Example 1:

Input: happiness = [1,2,3], k = 2
Output: 4
Explanation: We can pick 2 children in the following way:
- Pick the child with the happiness value == 3. The happiness value of the remaining children becomes [0,1].
- Pick the child with the happiness value == 1. The happiness value of the remaining child becomes [0]. Note that the happiness value cannot become less than 0.
The sum of the happiness values of the selected children is 3 + 1 = 4.
Example 2:

Input: happiness = [1,1,1,1], k = 2
Output: 1
Explanation: We can pick 2 children in the following way:
- Pick any child with the happiness value == 1. The happiness value of the remaining children becomes [0,0,0].
- Pick the child with the happiness value == 0. The happiness value of the remaining child becomes [0,0].
The sum of the happiness values of the selected children is 1 + 0 = 1.
Example 3:

Input: happiness = [2,3,4,5], k = 1
Output: 5
Explanation: We can pick 1 child in the following way:
- Pick the child with the happiness value == 5. The happiness value of the remaining children becomes [1,2,3].
The sum of the happiness values of the selected children is 5.
 

Constraints:

1 <= n == happiness.length <= 2 * 105
1 <= happiness[i] <= 108
1 <= k <= n



*/


class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {  //tc=O(nLogN), sc=O(1)
        int n = happiness.size();
        sort(happiness.begin(), happiness.end());

        long long maxHapp = 0;
        int dec = 0;
        for(int i=n-1; i>=n-k; i--) {
            int reduced = happiness[i] - dec;
            dec++;

            if(reduced > 0) {
                maxHapp += reduced;
            } else {
                break;
            }
        }

        return maxHapp;
    }
};