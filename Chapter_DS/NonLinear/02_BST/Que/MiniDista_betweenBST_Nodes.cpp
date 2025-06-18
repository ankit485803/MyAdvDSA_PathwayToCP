


/*

18th June 2025 (Wednesday) Lec-99 Apna College


qno 783   https://leetcode.com/problems/minimum-distance-between-bst-nodes/description/

same que with no qno 530 https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/

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

    TreeNode* prev = NULL;

    int minDiffInBST(TreeNode* root) {

        if(root == NULL) {
            return INT_MAX;
        }

        int ans = INT_MAX;
        if(root->left  !=  NULL) {
            int leftMin = minDiffInBST(root->left);
            ans = min(ans, leftMin); 
        }

        //calculate currMin
        if(prev != NULL) {
            ans = min(ans, root->val - prev->val);
        }
        prev = root;

        //same thing for right wale ke liye
        if(root->right  !=  NULL) {
            int rightMin = minDiffInBST(root->right);
            ans = min(ans, rightMin); 
        }

        return ans;
    }
};


// TC = O(n)= SC