

/*

11th July 2025 (Friday = after came from IIRS to Room Temple ) Apna college DSA series Lec No 102

qno 1008 Leetcode   https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/


method1: Brute force - TC = O(n * n) esmai hm directly add karte h node mai
method2: Linear TC - O(n)


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

    TreeNode* helper(vector<int>& preorder, int &i, int bound) {  // TC=O(n)
        if(i >= preorder.size() || preorder[i] > bound) {
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[i++]);
        root->left = helper(preorder, i, root->val);
        root->right = helper(preorder, i, bound);

        return root;
    }


    TreeNode* bstFromPreorder(vector<int>& preorder) {  //TC=O(1)
        int i = 0;
        return helper(preorder, i, INT_MAX);
    }
};

// TC = O(n) =  SC 