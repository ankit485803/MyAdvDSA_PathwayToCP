



/*


7th Jan 2026 (Wednesday - resultOutSem5 spi=9.29)



qno 13339  https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/?envType=daily-question&envId=2026-01-07



1339. Maximum Product of Splitted Binary Tree
Medium
Topics

Companies
Hint
Given the root of a binary tree, split the binary tree into two subtrees by removing one edge such that the product of the sums of the subtrees is maximized.

Return the maximum product of the sums of the two subtrees. Since the answer may be too large, return it modulo 109 + 7.

Note that you need to maximize the answer before taking the mod and not after taking it.

 

Example 1:


Input: root = [1,2,3,4,5,6]
Output: 110
Explanation: Remove the red edge and get 2 binary trees with sum 11 and 10. Their product is 110 (11*10)
Example 2:


Input: root = [1,null,2,3,4,null,null,5,6]
Output: 90
Explanation: Remove the red edge and get 2 binary trees with sum 15 and 6.Their product is 90 (15*6)
 

Constraints:

The number of nodes in the tree is in the range [2, 5 * 104].
1 <= Node.val <= 104
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
170,186/334.3K
Acceptance Rate
50.9%
Topics
Tree
Depth-First Search
Binary Tree
Weekly Contest 174



apporach: subtreeSum * (totalSum - subtreeSum)
Algorithm (DFS, 2 passes)
    First DFS → compute totalSum
    Second DFS → compute each subtree sum and update max product


ok 


*/




/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */



 class Solution {
public:
    static constexpr int MOD = 1e9 + 7;
    long long totalSum = 0;
    long long maxProd = 0;

    long long dfsSum(TreeNode* root) {
        if (!root) return 0;
        return root->val + dfsSum(root->left) + dfsSum(root->right);
    }

    long long dfsProduct(TreeNode* root) {  //tc=O(n) visitedEachNode, sc=O(h) height of tee
        if (!root) return 0;

        long long leftSum = dfsProduct(root->left);
        long long rightSum = dfsProduct(root->right);
        long long currSum = root->val + leftSum + rightSum;

        long long product = currSum * (totalSum - currSum);
        maxProd = max(maxProd, product);

        return currSum;
    }


    int maxProduct(TreeNode* root) { 
        totalSum = dfsSum(root);     // First pass
        dfsProduct(root);            // Second pass
        return maxProd % MOD;
    }
};





/*


qno 705  https://leetcode.com/problems/design-hashset/description/


705. Design HashSet
Easy
Topics

Companies
Design a HashSet without using any built-in hash table libraries.

Implement MyHashSet class:

void add(key) Inserts the value key into the HashSet.
bool contains(key) Returns whether the value key exists in the HashSet or not.
void remove(key) Removes the value key in the HashSet. If key does not exist in the HashSet, do nothing.
 

Example 1:

Input
["MyHashSet", "add", "add", "contains", "contains", "add", "contains", "remove", "contains"]
[[], [1], [2], [1], [3], [2], [2], [2], [2]]
Output
[null, null, null, true, false, null, true, null, false]

Explanation
MyHashSet myHashSet = new MyHashSet();
myHashSet.add(1);      // set = [1]
myHashSet.add(2);      // set = [1, 2]
myHashSet.contains(1); // return True
myHashSet.contains(3); // return False, (not found)
myHashSet.add(2);      // set = [1, 2]
myHashSet.contains(2); // return True
myHashSet.remove(2);   // set = [1]
myHashSet.contains(2); // return False, (already removed)
 

Constraints:

0 <= key <= 106
At most 104 calls will be made to add, remove, and contains.
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
545,910/807.5K
Acceptance Rate
67.6%
Topics
Array
Hash Table
Linked List
Design
Hash Function



*/




class MyHashSet {
private:
    vector<bool> hash;   //booleanArr approach

public:
    MyHashSet() {
        hash.resize(1000001, false);
    }
    
    void add(int key) {  //O(1) tc
        hash[key] = true;
    }
    
    void remove(int key) {  //O(1)
        hash[key] = false;
    }
    
    bool contains(int key) {  //O(1)
        return hash[key];
    }
};





/*


qno 160  https://leetcode.com/problems/intersection-of-two-linked-lists/description/


160. Intersection of Two Linked Lists
Easy
Topics

Companies
Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.

For example, the following two linked lists begin to intersect at node c1:


The test cases are generated such that there are no cycles anywhere in the entire linked structure.

Note that the linked lists must retain their original structure after the function returns.

Custom Judge:

The inputs to the judge are given as follows (your program is not given these inputs):

intersectVal - The value of the node where the intersection occurs. This is 0 if there is no intersected node.
listA - The first linked list.
listB - The second linked list.
skipA - The number of nodes to skip ahead in listA (starting from the head) to get to the intersected node.
skipB - The number of nodes to skip ahead in listB (starting from the head) to get to the intersected node.
The judge will then create the linked structure based on these inputs and pass the two heads, headA and headB to your program. If you correctly return the intersected node, then your solution will be accepted.

 

Example 1:


Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
Output: Intersected at '8'
Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists intersect).
From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,6,1,8,4,5]. There are 2 nodes before the intersected node in A; There are 3 nodes before the intersected node in B.
- Note that the intersected node's value is not 1 because the nodes with value 1 in A and B (2nd node in A and 3rd node in B) are different node references. In other words, they point to two different locations in memory, while the nodes with value 8 in A and B (3rd node in A and 4th node in B) point to the same location in memory.
Example 2:


Input: intersectVal = 2, listA = [1,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
Output: Intersected at '2'
Explanation: The intersected node's value is 2 (note that this must not be 0 if the two lists intersect).
From the head of A, it reads as [1,9,1,2,4]. From the head of B, it reads as [3,2,4]. There are 3 nodes before the intersected node in A; There are 1 node before the intersected node in B.
Example 3:


Input: intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
Output: No intersection
Explanation: From the head of A, it reads as [2,6,4]. From the head of B, it reads as [1,5]. Since the two lists do not intersect, intersectVal must be 0, while skipA and skipB can be arbitrary values.
Explanation: The two lists do not intersect, so return null.
 

Constraints:

The number of nodes of listA is in the m.
The number of nodes of listB is in the n.
1 <= m, n <= 3 * 104
1 <= Node.val <= 105
0 <= skipA <= m
0 <= skipB <= n
intersectVal is 0 if listA and listB do not intersect.
intersectVal == listA[skipA] == listB[skipB] if listA and listB intersect.
 

Follow up: Could you write a solution that runs in O(m + n) time and use only O(1) memory?


“Both pointers traverse the same total length by switching heads, so they meet at the intersection if it exists.

*/



class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0, lenB = 0;
        ListNode *a = headA, *b = headB;

        // calculate lengths
        while (a) {
            lenA++;
            a = a->next;
        }
        while (b) {
            lenB++;
            b = b->next;
        }

        a = headA;
        b = headB;

        // move longer list ahead
        if (lenA > lenB) {
            int diff = lenA - lenB;
            while (diff--) a = a->next;
        } else {
            int diff = lenB - lenA;
            while (diff--) b = b->next;
        }

        // move both together
        while (a && b) {
            if (a == b) return a;
            a = a->next;
            b = b->next;
        }

        return NULL;
    }
};




class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr)
            return nullptr;

        ListNode* h1 = headA;
        ListNode* h2 = headB;

        while (h1 != h2) {
            h1 = (h1 == nullptr) ? headB : h1->next;
            h2 = (h2 == nullptr) ? headA : h2->next;
        }

        return h1;  // intersection node or nullptr
    }
};

