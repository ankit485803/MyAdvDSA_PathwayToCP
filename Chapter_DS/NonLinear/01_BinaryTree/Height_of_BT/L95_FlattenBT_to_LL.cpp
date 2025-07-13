

/*

1st June 2025 (Sunday)


qno 114  https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/

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