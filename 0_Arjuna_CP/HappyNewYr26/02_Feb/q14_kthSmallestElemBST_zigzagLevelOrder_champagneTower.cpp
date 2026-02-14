


/*

14th Feb 2026 (Satursday)


qno 230 https://leetcode.com/problems/kth-smallest-element-in-a-bst/


230. Kth Smallest Element in a BST
Solved
Medium
Topics

Companies
Hint
Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

 

Example 1:


Input: root = [3,1,4,null,2], k = 1
Output: 1
Example 2:


Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3
 

Constraints:

The number of nodes in the tree is n.
1 <= k <= n <= 104
0 <= Node.val <= 104
 

Follow up: If the BST is modified often (i.e., we can do insert and delete operations) and you need to find the kth smallest frequently, how would you optimize?

 
Discover more
Software Development Tools
Seen this question in a real interview before?
1/5
Yes
No
Accepted
2,163,510/2.8M
Acceptance Rate
76.4%
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
    int preOrder = 0;  // Actually behaves like in-order counter

    int kthSmallest(TreeNode* root, int k) {
        
        if(root == NULL) {
            return -1;
        }

        // LEFT subtree
        if(root->left != NULL) {
            int leftAns = kthSmallest(root->left, k);
            if(leftAns != -1) {
                return leftAns;
            }
        }

        // ROOT node
        preOrder = preOrder + 1;
        if(preOrder == k) {
            return root->val;
        }

        // RIGHT subtree
        if(root->right != NULL) {
            int rightAns = kthSmallest(root->right, k);
            if(rightAns != -1) {
                return rightAns;
            }
        }

        return -1;
    }
};


// TC = O(n) = SC





/*


qno 106  https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/


103. Binary Tree Zigzag Level Order Traversal
Medium
Topics

Companies
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100
 
Discover more
Developer Community Forum
Seen this question in a real interview before?
1/5
Yes
No
Accepted
1,708,661/2.7M
Acceptance Rate
63.1%
Topics
Tree
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;
        
        queue<TreeNode*> q;  //tc=O(n)=sc
        q.push(root);
        bool leftToRight = true;
        
        while (!q.empty()) {
            int size = q.size();
            vector<int> level(size);
            
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                // Determine position based on direction
                int index = leftToRight ? i : (size - 1 - i);
                level[index] = node->val;
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            
            result.push_back(level);
            leftToRight = !leftToRight;  // flip direction
        }
        
        return result;
    }
};




/*

qno 114  https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/


114. Flatten Binary Tree to Linked List
Solved
Medium
Topics

Companies
Hint
Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.
 

Example 1:


Input: root = [1,2,5,3,4,null,6]
Output: [1,null,2,null,3,null,4,null,5,null,6]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [0]
Output: [0]
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100
 

Follow up: Can you flatten the tree in-place (with O(1) extra space)?
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
1,349,127/1.9M
Acceptance Rate
70.1%
Topics
Linked List
Stack
Tree
Depth-First Search
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
    TreeNode* nextRight = nullptr;  //Maintain a pointer to the next node in the flattened list

    void flatten(TreeNode* root) {
        if (root == NULL) {
            return;
        }

        flatten(root->right);  // Traverse right subtree
        flatten(root->left);    

        root->right = nextRight;  // Rewire the right child
        root->left = NULL;        // Set left child to NULL
        nextRight = root;         // Move nextRight to current node
    }
};


/*
Time Complexity: O(n) – Each node is visited once.

Space Complexity: O(h) – Due to recursive call stack, where h is the height of the tree (worst case O(n) for skewed tree, best case O(log n) for balanced tree).


*/



/*


qno 799   https://leetcode.com/problems/champagne-tower/?envType=daily-question&envId=2026-02-14


799. Champagne Tower
Medium
Topics

Companies
We stack glasses in a pyramid, where the first row has 1 glass, the second row has 2 glasses, and so on until the 100th row.  Each glass holds one cup of champagne.

Then, some champagne is poured into the first glass at the top.  When the topmost glass is full, any excess liquid poured will fall equally to the glass immediately to the left and right of it.  When those glasses become full, any excess champagne will fall equally to the left and right of those glasses, and so on.  (A glass at the bottom row has its excess champagne fall on the floor.)

For example, after one cup of champagne is poured, the top most glass is full.  After two cups of champagne are poured, the two glasses on the second row are half full.  After three cups of champagne are poured, those two cups become full - there are 3 full glasses total now.  After four cups of champagne are poured, the third row has the middle glass half full, and the two outside glasses are a quarter full, as pictured below.



Now after pouring some non-negative integer cups of champagne, return how full the jth glass in the ith row is (both i and j are 0-indexed.)

 

Example 1:

Input: poured = 1, query_row = 1, query_glass = 1
Output: 0.00000
Explanation: We poured 1 cup of champange to the top glass of the tower (which is indexed as (0, 0)). There will be no excess liquid so all the glasses under the top glass will remain empty.
Example 2:

Input: poured = 2, query_row = 1, query_glass = 1
Output: 0.50000
Explanation: We poured 2 cups of champange to the top glass of the tower (which is indexed as (0, 0)). There is one cup of excess liquid. The glass indexed as (1, 0) and the glass indexed as (1, 1) will share the excess liquid equally, and each will get half cup of champange.
Example 3:

Input: poured = 100000009, query_row = 33, query_glass = 17
Output: 1.00000
 

Constraints:

0 <= poured <= 109
0 <= query_glass <= query_row < 100
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
197,445/323.6K
Acceptance Rate
61.0%
Topics
Principal
Dynamic Programming
Weekly Contest 75


*/



class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {  //2d DP approach
        // Max 100 rows
        vector<vector<double>> dp(101, vector<double>(101, 0.0));
        
        dp[0][0] = poured;
        
        for (int row = 0; row < query_row; row++) {
            for (int col = 0; col <= row; col++) {
                if (dp[row][col] > 1.0) {
                    double overflow = (dp[row][col] - 1.0) / 2.0;
                    dp[row + 1][col] += overflow;
                    dp[row + 1][col + 1] += overflow;
                    dp[row][col] = 1.0;  // cap at 1
                }
            }
        }
        
        return min(1.0, dp[query_row][query_glass]);
    }
};




class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {  //1d DP approach
        vector<double> dp(101, 0.0);
        dp[0] = poured;
        
        for (int row = 0; row <= query_row; row++) {
            for (int col = row; col >= 0; col--) {
                if (dp[col] > 1.0) {
                    double overflow = (dp[col] - 1.0) / 2.0;
                    dp[col] = overflow;
                    dp[col + 1] += overflow;
                } else {
                    dp[col] = 0.0;
                }
            }
        }
        
        return min(1.0, dp[query_glass]);
    }
};
