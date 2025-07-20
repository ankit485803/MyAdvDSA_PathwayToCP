





/*
20th July 2025 (Sunday) lecNo 104 Shardha Di - Recover BST

qno 104

You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake.
 Recover the tree without changing its structure.

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

    //initilization
    TreeNode* prev = NULL;
    TreeNode* first = NULL;
    TreeNode* sec = NULL;

    void inorder(TreeNode* root) {
        if(root == NULL) {
            return;
        }
        inorder(root->left);
        
        if(prev != NULL && prev->val > root->val) {
            if(first == NULL) {
                first = prev;
            }
            sec = root;
        }

        prev = root;
        inorder(root->right);
    }


    void recoverTree(TreeNode* root) {
        
        //step hoga Ankit
        //step1: inoder => first, sec
        //step2: first, sec => SWAP

        inorder(root);

        //SWAPPING
        int temp = first->val;
        first->val = sec->val;
        sec->val = temp;


    }
};



/*
TC = O(n) , SC = O(n)  Can we do this in Constant SC; yes hm kar sakte hai using Recursion ko replace karke inorder funct
 mai ITERATIVE method apply karke -- MORRIS inoder traversal jo covered hai LecNo 94 mai

C:\Users\sanja\Desktop\GitHub_ankit485803\MyAdvDSA_PathwayToCP\Chapter_DS\NonLinear\01_BinaryTree\Height_of_BT\L94_Morris_InorderTraversal.cpp
 

*/


