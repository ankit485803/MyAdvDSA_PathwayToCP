





/* qno 543    https://leetcode.com/problems/diameter-of-binary-tree/


Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or 
may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.



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
    
        int height(TreeNode* root) {  //TC=O(n)
            if(root == NULL) {
                return 0;
            }
    
            int leftHt = height(root->left);  //height using recurssion
            int rightHt = height(root->right);
    
            return max(leftHt, rightHt) + 1;
        }
    
    
    
    
    
        int diameterOfBinaryTree(TreeNode* root) {  //O(n * n) because hm again height calculate kar rahe hai
        
            if(root == NULL) {
                return 0;
            }
    
            int leftDiam = diameterOfBinaryTree(root->left);
            int rightDiam =diameterOfBinaryTree(root->right);
            int currDiam = height(root->left) + height(root->right);
    
            return max(currDiam, max(leftDiam, rightDiam));
        }
    };



//method2: TC=O(n) using parallel approach


// diameter = left subtree height + right subtree height
//          = leftHt + rightHt


class Solution {
    public:
    
        int ans = 0;
        int height(TreeNode* root) {  //TC=O(n)
            if(root == NULL) {
                return 0;
            }
    
            int leftHt = height(root->left);  //height using recurssion
            int rightHt = height(root->right);
            
            ans = max(ans, leftHt + rightHt); //currDiam of root node
            return max(leftHt, rightHt) + 1;
        }
    
    
    
    
    
        int diameterOfBinaryTree(TreeNode* root) {  //O(n * n) because hm again height calculate kar rahe hai
    
            height(root);
            return ans;
        }
    };
    
    
    /*
    Time Complexity: O(n) → Every node visited once.
    Space Complexity: O(h) → Height of recursion stack (in worst-case O(n) for skewed tree).
    */