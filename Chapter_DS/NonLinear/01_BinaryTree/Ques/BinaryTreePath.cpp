


/*
4th May 2025 (Sunday) Lec 92 of Shardha Kharapara YouTube Channel

tranversal like DFS

hmara recursion will stop at the leaf node, es liye wah BaseCase banata h

qno 257  https://leetcode.com/problems/binary-tree-paths/description/

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
        
        void allPaths(TreeNode* root, string path, vector<string>& ans) {
            if(root->left == NULL && root->right == NULL) {
                ans.push_back(path);
                return;
            }
    
            if(root->left) {
                allPaths(root->left, path + "->" + to_string(root->left->val), ans);
            }
    
            if(root->right) {
                allPaths(root->right, path + "->" + to_string(root->right->val), ans);
            }
        }
    
        vector<string> binaryTreePaths(TreeNode* root) {
            vector<string> ans;
            if(!root) return ans;  // handle NULL root case
    
            string path = to_string(root->val);
            allPaths(root, path, ans);
            return ans;
        }
    };
    
    
    /*
     TC = O(n^2)  
    Reason: You visit every node once ⇒ O(N)
    But at each leaf, you build a string of path length ≈ height ⇒ in skewed trees this could be O(N)
    And there can be O(N) such leaf nodes in the worst case.
    So total string-building across all paths = O(N²)
    
    
    SC = O(n^2) Recursive stack: O(H), where H is the height of the tree (worst case O(N) for skewed trees)
    
    
    */
    
    