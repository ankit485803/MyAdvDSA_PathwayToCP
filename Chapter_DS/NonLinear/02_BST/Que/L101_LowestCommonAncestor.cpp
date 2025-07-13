

/*

26th June 2025 (Thursday) DSA series Lec 101 Apna College 

qno 235  https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/



*/ 






// same ques no 236  https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if(root == NULL) {
            return NULL;
        }

        if(root->val == p->val  ||  root->val  == q->val) {
            return root;
        }

        TreeNode* leftLCA = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightLCA = lowestCommonAncestor(root->right, p, q);

        if(leftLCA  &&  rightLCA) {
            return root;

        } else if(leftLCA !=  NULL) {
            return leftLCA;

        } else {
            return rightLCA;

        }
        
    }
};

// TC = O(n) = SC












/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        // baseCase
        if(root == NULL) {
            return NULL;
        }

        if(root->val > p->val  && root->val  >  q->val) {  //leftSubtree
            return lowestCommonAncestor(root->left, p, q);

        } else if(root->val < p->val  && root->val <  q->val)  {  //right subTree
            return lowestCommonAncestor(root->right, p, q);

        } else {
            return root;  //LCA hoga root 
        }
    }
};


// TC = O(height of BST) = SC 