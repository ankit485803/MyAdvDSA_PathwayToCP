

/*

1st June 2025 (Sunday - after EndSem4 paper IITP) DSA Series: Lec 94



🌿 Morris Inorder Traversal (O(1) Space Inorder Traversal)
Morris Inorder Traversal is an efficient method to traverse a binary tree in-order (Left → Root → Right) 
without using a stack or recursion — i.e., with O(1) auxiliary space.



Inorder Predecessor : IP

qno 94 https://leetcode.com/problems/binary-tree-inorder-traversal/description/

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;

        while (curr != NULL) {
            if (curr->left == NULL) {
                // Visit current node
                ans.push_back(curr->val);  // ✅ Fixed: used push_back instead of push
                curr = curr->right;
            } else {
                // Find the inorder predecessor (IP)
                TreeNode* IP = curr->left;
                while (IP->right != NULL && IP->right != curr) {
                    IP = IP->right;
                }

                if (IP->right == NULL) {
                    // Create thread
                    IP->right = curr;
                    curr = curr->left;

                } else {
                    // Thread already exists, destroy it and visit node
                    IP->right = NULL;
                    ans.push_back(curr->val);  
                    curr = curr->right;
                }
            }
        }

        return ans;  
    }
};


/*
Time and Space Complexity:

Time: O(n) — each node is visited at most twice.
Space: O(1) — no recursion or extra stack (in-place traversal).

*/