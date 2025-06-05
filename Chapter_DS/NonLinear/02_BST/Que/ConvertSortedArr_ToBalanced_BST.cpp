

/*

5th June 2025 (Thursday) lec no 97 Apna College

qno 108  https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/

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

    //helper funct banawo
    TreeNode* helper(vector<int>& nums, int st, int end) {
        if(st > end) {
            return NULL;
        }

        int mid = st + (end-st)/2;
        TreeNode* root = new TreeNode(nums[mid]);

        root->left = helper(nums, st, mid-1);
        root->right = helper(nums, mid+1, end);

        return root;
    }



    TreeNode* sortedArrayToBST(vector<int>& nums) {

        return helper(nums, 0, nums.size()-1);
        
    }
};


/*

Time Complexity:
O(n) — Every node is visited once and added to the tree.

Space Complexity:
O(log n) — Due to recursion stack space for a balanced BST (height ≈ log n)



*/