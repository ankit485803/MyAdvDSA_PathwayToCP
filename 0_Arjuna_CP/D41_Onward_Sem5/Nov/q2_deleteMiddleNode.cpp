
#include <iostream>
using namespace std;


/*

10th Nov 2025 (Monday) revise concepts LL and solve min 5q easyLevel


LL is Linear DS, dynamiceNature, non-contigious memoryAllocation, vairableSize
we need two class for constructe lL: Node class and List class and linked both them

inserate and search for tomarrow



*/



class Node {
public:

    //everyNode have two thing data and next pointer location
    int data;
    Node* next;

    //initlize this
    Node(int val) {
        data = val;
        next = NULL; //nextPointer ko hmesa NULL se intilize karte hai

    }
};




//secondClass private rakhte jo List ka hoga fir connect both
class List {
private:
    Node* head;
    Node* tail;

public:
    List() {
        head = tail = NULL;
    }



    //basicStructure is ready hm four operations perform karte hai aab
    void push_front(int val) {
        //take newNode jispe sara kam karenge hm directly head mai nai karte h because Backtravse node ko LL mai nahi kar sakte

        Node* newNode = new Node(val);  //DYNAMIC
        //Node* newNode(val);  //STATIC

        if(head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }      
    }

    void pop_front() {
        if(head == NULL) {
            cout << "LL is empty";
        } else {
            Node* temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
        }
    }


    void printLL() {
        Node* temp = head;

        while(temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }



};








int main() {

    //create one list
    List l1;

    l1.push_front(1);
    l1.push_front(2);
    l1.push_front(3);

    l1.printLL();

    l1.


    return 0;
}




/*


qno 2095   



2095. Delete the Middle Node of a Linked List
Medium
Topics

Companies
Hint
You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.

The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start using 0-based indexing, where ⌊x⌋ denotes the largest integer less than or equal to x.

For n = 1, 2, 3, 4, and 5, the middle nodes are 0, 1, 1, 2, and 2, respectively.
 

Example 1:


Input: head = [1,3,4,7,1,2,6]
Output: [1,3,4,1,2,6]
Explanation:
The above figure represents the given linked list. The indices of the nodes are written below.
Since n = 7, node 3 with value 7 is the middle node, which is marked in red.
We return the new list after removing this node. 
Example 2:


Input: head = [1,2,3,4]
Output: [1,2,4]
Explanation:
The above figure represents the given linked list.
For n = 4, node 2 with value 3 is the middle node, which is marked in red.
Example 3:


Input: head = [2,1]
Output: [2]
Explanation:
The above figure represents the given linked list.
For n = 2, node 1 with value 1 is the middle node, which is marked in red.
Node 0 with value 2 is the only node remaining after removing node 1.
 

Constraints:

The number of nodes in the list is in the range [1, 105].
1 <= Node.val <= 105


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
    ListNode* deleteMiddle(ListNode* head) {   //TC=O(n) sigleTranverseEachNode, SC=O(1)
        
        //case1: onlyOneNode
        if(!head || !head->next) return nullptr;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        //moveFaset twice as slow
        while(fast  &&  fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;

        }
        //deleteMiddleNode
        prev->next = slow->next;

        return head;
    }
};





/*

qno 3542  https://leetcode.com/problems/minimum-operations-to-convert-all-elements-to-zero/description/?envType=daily-question&envId=2025-11-10


3542. Minimum Operations to Convert All Elements to Zero
Attempted
Medium
Topics

Companies
Hint
You are given an array nums of size n, consisting of non-negative integers. Your task is to apply some (possibly zero) operations on the array so that all elements become 0.

In one operation, you can select a subarray [i, j] (where 0 <= i <= j < n) and set all occurrences of the minimum non-negative integer in that subarray to 0.

Return the minimum number of operations required to make all elements in the array 0.

 

Example 1:

Input: nums = [0,2]

Output: 1

Explanation:

Select the subarray [1,1] (which is [2]), where the minimum non-negative integer is 2. Setting all occurrences of 2 to 0 results in [0,0].
Thus, the minimum number of operations required is 1.
Example 2:

Input: nums = [3,1,2,1]

Output: 3

Explanation:

Select subarray [1,3] (which is [1,2,1]), where the minimum non-negative integer is 1. Setting all occurrences of 1 to 0 results in [3,0,2,0].
Select subarray [2,2] (which is [2]), where the minimum non-negative integer is 2. Setting all occurrences of 2 to 0 results in [3,0,0,0].
Select subarray [0,0] (which is [3]), where the minimum non-negative integer is 3. Setting all occurrences of 3 to 0 results in [0,0,0,0].
Thus, the minimum number of operations required is 3.
Example 3:

Input: nums = [1,2,1,2,1,2]

Output: 4

Explanation:

Select subarray [0,5] (which is [1,2,1,2,1,2]), where the minimum non-negative integer is 1. Setting all occurrences of 1 to 0 results in [0,2,0,2,0,2].
Select subarray [1,1] (which is [2]), where the minimum non-negative integer is 2. Setting all occurrences of 2 to 0 results in [0,0,0,2,0,2].
Select subarray [3,3] (which is [2]), where the minimum non-negative integer is 2. Setting all occurrences of 2 to 0 results in [0,0,0,0,0,2].
Select subarray [5,5] (which is [2]), where the minimum non-negative integer is 2. Setting all occurrences of 2 to 0 results in [0,0,0,0,0,0].
Thus, the minimum number of operations required is 4.
 

Constraints:

1 <= n == nums.length <= 105
0 <= nums[i] <= 105



*/


class Solution {
public:
    int minOperations(vector<int>& nums) {  //TC=O(n), sc=O(k) where k = number of distinctElem
    
        int n = nums.size();
        int ans = 0;
        int i = 0;

        while (i < n) {
            // skip zeros
            if (nums[i] == 0) {
                i++;
                continue;
            }

            // find end of nonzero segment
            int j = i;
            unordered_set<int> distinct;
            while (j < n && nums[j] != 0) {
                distinct.insert(nums[j]);
                j++;
            }

            ans += distinct.size(); // operations for this segment
            i = j; // move to next segment
        }

        return ans;
        //answer = sum of counts of distinct nonzero numbers in each contiguous nonzero segment of nums

    }    
};