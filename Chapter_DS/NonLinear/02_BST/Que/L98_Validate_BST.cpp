

/*

7th June 2025 (Saturday) Validate BST Lec No 98



qno 98  https://leetcode.com/problems/validate-binary-search-tree/description/ 


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