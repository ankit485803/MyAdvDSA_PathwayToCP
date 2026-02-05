

/*

5th Feb 2026 (Thursday)


qno 938  https://leetcode.com/problems/range-sum-of-bst/

938. Range Sum of BST
Easy
Topics

Companies
Given the root node of a binary search tree and two integers low and high, return the sum of values of all nodes with a value in the inclusive range [low, high].

 

Example 1:


Input: root = [10,5,15,3,7,null,18], low = 7, high = 15
Output: 32
Explanation: Nodes 7, 10, and 15 are in the range [7, 15]. 7 + 10 + 15 = 32.
Example 2:


Input: root = [10,5,15,3,7,13,18,1,null,6], low = 6, high = 10
Output: 23
Explanation: Nodes 6, 7, and 10 are in the range [6, 10]. 6 + 7 + 10 = 23.
 

Constraints:

The number of nodes in the tree is in the range [1, 2 * 104].
1 <= Node.val <= 105
1 <= low <= high <= 105
All Node.val are unique.
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
1,327,116/1.5M
Acceptance Rate
87.6%
Topics
Senior
Tree
Depth-First Search
Binary Search Tree
Binary Tree
Weekly Contest 110



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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root == NULL) return 0;

        //ignore left and goToRight
        if(root->val < low) {
            return rangeSumBST(root->right, low, high);
        }
        //left
        if(root->val > high) {
            return rangeSumBST(root->left, low, high);
        }

        //withinRange
        return root->val 
                        + rangeSumBST(root->left, low, high)
                        + rangeSumBST(root->right, low, high);


    }
};



/*

qno 98  https://leetcode.com/problems/validate-binary-search-tree/

8. Validate Binary Search Tree
Solved
Medium
Topics

Companies
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys strictly less than the node's key.
The right subtree of a node contains only nodes with keys strictly greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:


Input: root = [2,1,3]
Output: true
Example 2:


Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-231 <= Node.val <= 231 - 1
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
3,207,271/9.1M
Acceptance Rate
35.3%
Topics
Tree
Depth-First Search
Binary Search Tree
Binary Tree




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

    bool helper(TreeNode* root, TreeNode* min, TreeNode* max) {
        if(root == NULL) {
            return true;
        }

        if(min != NULL  && root->val  <=  min-> val) {
            return false;
        }

        if(max != NULL && root->val >= max->val) {
            return false;
        }

        return helper(root->left, min, root) 
            && helper(root->right, root, max);
    }
    bool isValidBST(TreeNode* root) {
        
        return helper(root, NULL, NULL);

    }
};


//  TC = O(N) = SC




/*


qno 226  https://leetcode.com/problems/invert-binary-tree/


226. Invert Binary Tree
Solved
Easy
Topics

Companies
Given the root of a binary tree, invert the tree, and return its root.

 

Example 1:


Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]
Example 2:


Input: root = [2,1,3]
Output: [2,3,1]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
2,922,769/3.7M
Acceptance Rate
79.8%
Topics
Tree
Depth-First Search
Breadth-First Search
Binary Tree


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
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return NULL;

        TreeNode* leftMirror = invertTree(root->left);   //recuusssivelyCalcualte
        TreeNode* rightMirror = invertTree(root->right);   

        //exchange
        root->left = rightMirror;
        root->right = leftMirror;

        return root;
    }
};






/*

qno 108  https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/


108. Convert Sorted Array to Binary Search Tree
Solved
Easy
Topics

Companies
Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

 

Example 1:


Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted:

Example 2:


Input: nums = [1,3]
Output: [3,1]
Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.
 

Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums is sorted in a strictly increasing order.
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
1,662,619/2.2M
Acceptance Rate
75.1%
Topics
Array
Divide and Conquer
Tree
Binary Search Tree
Binary Tree


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

    //helper funct banawo
    TreeNode* helper(vector<int>& nums, int st, int end) {
        if(st > end) {
            return NULL;
        }

        int mid = st + (end-st)/2;
        TreeNode* root = new TreeNode(nums[mid]);

        root->left = helper(nums, st, mid-1);
        root->right = helper(nums, mid+1, end);

        return root;
    }



    TreeNode* sortedArrayToBST(vector<int>& nums) {

        return helper(nums, 0, nums.size()-1);
        
    }
};


/*

Time Complexity:
O(n) — Every node is visited once and added to the tree.

Space Complexity:
O(log n) — Due to recursion stack space for a balanced BST (height ≈ log n)



*/




/*


qno 109  https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/


109. Convert Sorted List to Binary Search Tree
Medium
Topics

Companies
Given the head of a singly linked list where elements are sorted in ascending order, convert it to a height-balanced binary search tree.

 

Example 1:


Input: head = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: One possible answer is [0,-3,9,-10,null,5], which represents the shown height balanced BST.
Example 2:

Input: head = []
Output: []
 

Constraints:

The number of nodes in head is in the range [0, 2 * 104].
-105 <= Node.val <= 105
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
662,471/1M
Acceptance Rate
65.8%
Topics
Linked List
Divide and Conquer
Tree
Binary Search Tree
Binary Tree


*/



class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return nullptr;
        if (!head->next) return new TreeNode(head->val);

        // find middle (prev -> slow -> fast)
        ListNode* prev = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // cut left half
        if (prev) prev->next = nullptr;

        // slow is middle
        TreeNode* root = new TreeNode(slow->val);

        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);

        return root;
    }
};




/*


qno 3379   https://leetcode.com/problems/transformed-array/description/?envType=daily-question&envId=2026-02-05


3379. Transformed Array
Easy
Topics

Companies
Hint
You are given an integer array nums that represents a circular array. Your task is to create a new array result of the same size, following these rules:

For each index i (where 0 <= i < nums.length), perform the following independent actions:
If nums[i] > 0: Start at index i and move nums[i] steps to the right in the circular array. Set result[i] to the value of the index where you land.
If nums[i] < 0: Start at index i and move abs(nums[i]) steps to the left in the circular array. Set result[i] to the value of the index where you land.
If nums[i] == 0: Set result[i] to nums[i].
Return the new array result.

Note: Since nums is circular, moving past the last element wraps around to the beginning, and moving before the first element wraps back to the end.

 

Example 1:

Input: nums = [3,-2,1,1]

Output: [1,1,1,3]

Explanation:

For nums[0] that is equal to 3, If we move 3 steps to right, we reach nums[3]. So result[0] should be 1.
For nums[1] that is equal to -2, If we move 2 steps to left, we reach nums[3]. So result[1] should be 1.
For nums[2] that is equal to 1, If we move 1 step to right, we reach nums[3]. So result[2] should be 1.
For nums[3] that is equal to 1, If we move 1 step to right, we reach nums[0]. So result[3] should be 3.
Example 2:

Input: nums = [-1,4,-1]

Output: [-1,-1,4]

Explanation:

For nums[0] that is equal to -1, If we move 1 step to left, we reach nums[2]. So result[0] should be -1.
For nums[1] that is equal to 4, If we move 4 steps to right, we reach nums[2]. So result[1] should be -1.
For nums[2] that is equal to -1, If we move 1 step to left, we reach nums[1]. So result[2] should be 4.
 

Constraints:

1 <= nums.length <= 100
-100 <= nums[i] <= 100
 
Discover more
LeetCode Premium subscription
Seen this question in a real interview before?
1/5
Yes
No
Accepted
51,061/81.9K
Acceptance Rate
62.3%
Topics
Mid Level
Array
Simulation
Weekly Contest 427


*/



class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {  //tc=O(n)=sc
        int n = nums.size();
        vector<int> result(n);

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                result[i] = 0;
            } else {
                int idx = ((i + nums[i]) % n + n) % n;
                result[i] = nums[idx];
            }
        }

        return result;
    }
};
