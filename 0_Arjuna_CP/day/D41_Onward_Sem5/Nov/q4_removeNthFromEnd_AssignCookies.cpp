


/*

12th Nov 2025 (Wednesday)

qno 19  https://leetcode.com/problems/remove-nth-node-from-end-of-list/


19. Remove Nth Node From End of List
Medium
Topics

Companies
Hint
Given the head of a linked list, remove the nth node from the end of the list and return its head.

 

Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]
 

Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
 

Follow up: Could you do this in one pass?






*/


class Solution {
public:
    int iterativeSizeLL(ListNode* head) {
        int sizeLL = 0;
        ListNode* curr = head;
        while (curr != nullptr) {
            sizeLL++;
            curr = curr->next;
        }
        return sizeLL;
    }


    ListNode* removeNthFromEnd(ListNode* head, int n) {   //TC=O(n), SC=O(1)
        //Case1: Empty list
        if (head == nullptr) return nullptr;

        int sizeLL = iterativeSizeLL(head);

        //Case2: Remove the first node (also covers single-node list)
        if (n == sizeLL) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }


        //Case3: General case
        ListNode* curr = head;
        for (int i = 1; i < sizeLL - n; ++i) {
            curr = curr->next;
        }

        ListNode* nodeToDelete = curr->next;
        curr->next = curr->next->next;
        delete nodeToDelete;

        return head;
    }
};




/*

qno 455 https://leetcode.com/problems/assign-cookies/



455. Assign Cookies
Easy
Topics

Companies
Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie.

Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with; and each cookie j has a size s[j]. If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content. Your goal is to maximize the number of your content children and output the maximum number.

 

Example 1:

Input: g = [1,2,3], s = [1,1]
Output: 1
Explanation: You have 3 children and 2 cookies. The greed factors of 3 children are 1, 2, 3. 
And even though you have 2 cookies, since their size is both 1, you could only make the child whose greed factor is 1 content.
You need to output 1.
Example 2:

Input: g = [1,2], s = [1,2,3]
Output: 2
Explanation: You have 2 children and 3 cookies. The greed factors of 2 children are 1, 2. 
You have 3 cookies and their sizes are big enough to gratify all of the children, 
You need to output 2.
 

Constraints:

1 <= g.length <= 3 * 104
0 <= s.length <= 3 * 104
1 <= g[i], s[j] <= 231 - 1
 

Note: This question is the same as 2410: Maximum Matching of Players With Trainers.


*/


class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {

        sort(g.begin(), g.end());  // Sort greed factors O(nLogN)
        sort(s.begin(), s.end());  // Sort cookie sizes  O(m log m)

        int i = 0;  // childPointer
        int j = 0;  // cookie pointer



        // Traverse both lists  O(n + m) scanTwoPointer
        while (i < g.size() && j < s.size()) {
            if (s[j] >= g[i]) {
                // cookie j can satisfy child i
                i++;  // move to next child
                j++;  // move to next cookie

            } else {
                // cookie too small, try next cookie
                j++;
            }
        }

        // i is the number of satisfied children
        return i;
    }
};


//TC=O(n log n + m log m),  where n = g.size() and m = s.size().  SC+O(1)



/*

qno  2410   https://leetcode.com/problems/maximum-matching-of-players-with-trainers/description/


2410. Maximum Matching of Players With Trainers
Medium
Topics

Companies
Hint
You are given a 0-indexed integer array players, where players[i] represents the ability of the ith player. You are also given a 0-indexed integer array trainers, where trainers[j] represents the training capacity of the jth trainer.

The ith player can match with the jth trainer if the player's ability is less than or equal to the trainer's training capacity. Additionally, the ith player can be matched with at most one trainer, and the jth trainer can be matched with at most one player.

Return the maximum number of matchings between players and trainers that satisfy these conditions.

 

Example 1:

Input: players = [4,7,9], trainers = [8,2,5,8]
Output: 2
Explanation:
One of the ways we can form two matchings is as follows:
- players[0] can be matched with trainers[0] since 4 <= 8.
- players[1] can be matched with trainers[3] since 7 <= 8.
It can be proven that 2 is the maximum number of matchings that can be formed.
Example 2:

Input: players = [1,1,1], trainers = [10]
Output: 1
Explanation:
The trainer can be matched with any of the 3 players.
Each player can only be matched with one trainer, so the maximum answer is 1.
 

Constraints:

1 <= players.length, trainers.length <= 105
1 <= players[i], trainers[j] <= 109
 

Note: This question is the same as 445: Assign Cookies.


*/

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int i = 0; // pointer for players
        int j = 0; // pointer for trainers

        while (i < players.size() && j < trainers.size()) {
            if (players[i] <= trainers[j]) {
                // match player i with trainer j
                i++;
                j++;
            } else {
                // trainer too weak, try next trainer
                j++;
            }
        }

        return i; // number of matched players
    }
};
