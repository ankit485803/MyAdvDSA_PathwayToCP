

/*
identical tree or same tree

qno 100  https://leetcode.com/problems/same-tree/

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
        bool isSameTree(TreeNode* p, TreeNode* q) {

            //BASE-CASE
            if(p == NULL  ||  q == NULL) {
                return p == q;
            }
    
            bool isLeftSame = isSameTree(p->left,  q->left);
            bool isRightSame = isSameTree(p->right, q->right);
    
            return isLeftSame && isRightSame && p->val == q->val;
    
        }
    };
    
    // TC = O(n) = SC





// qno 572  https://leetcode.com/problems/subtree-of-another-tree/




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

    bool isIdentical(TreeNode* p, TreeNode* q) {
        if(p == NULL || q == NULL) {
            return p == q;
        }

        return p->val == q->val 
                && isIdentical(p->left, q->left) 
                && isIdentical(p->right, q->right);
    }


    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        //BASE-CASE
        if(root == NULL || subRoot == NULL) {
            return root == subRoot;
        }

        if(root->val == subRoot-> val && isIdentical(root, subRoot)) {
            return true;
        }

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};