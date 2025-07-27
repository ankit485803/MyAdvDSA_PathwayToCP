

/*

27th July 2025 (Sunday) LecNo 107 Shardha Di 


qno 173   https://leetcode.com/problems/binary-search-tree-iterator/description/


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

class BSTIterator {
public:
    stack<TreeNode *> s;

    // Helper function to push all left nodes
    void storeLeftNodes(TreeNode* root) {
        while (root != nullptr) {
            s.push(root);
            root = root->left;
        }
    }

    BSTIterator(TreeNode* root) {
        storeLeftNodes(root);
    }
    
    int next() {
        TreeNode* ans = s.top();
        s.pop();

        // Push all left nodes of the right subtree
        storeLeftNodes(ans->right);
        return ans->val;
    }
    
    bool hasNext() {
        return !s.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */



//avg TC=O(1), SC=O(height)