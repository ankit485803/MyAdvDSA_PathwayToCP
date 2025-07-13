

/*

24th June 2025 (Tuesday) Kth smallest in BST Lec 100 Shardha didi


qno 230   https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/

similar prob- kth largest

hmko harek node ki ORDER hi find out karna h
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
