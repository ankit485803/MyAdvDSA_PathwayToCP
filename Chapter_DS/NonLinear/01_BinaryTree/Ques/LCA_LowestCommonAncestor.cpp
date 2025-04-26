

/*

26th April 2025 (Satursday) LCA - Lowest Common Ancestor


qno 236     https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/


According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as 
the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”



*/







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


/*


Time Complexity: O(n) — each node is visited once.
Space Complexity: O(h) — due to recursion stack (height of tree).

*/

