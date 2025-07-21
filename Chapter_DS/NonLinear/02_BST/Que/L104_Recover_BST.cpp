





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


class Solution {
public:
    void recoverTree(TreeNode* root) {
        // Pointers to track the misplaced nodes and the previous visited node in inorder traversal
        TreeNode* first = nullptr;
        TreeNode* second = nullptr;
        TreeNode* prev = nullptr;

        // Start Morris Inorder Traversal
        while (root != nullptr) {
            // Case 1: If there is no left child, process current node and move to right
            if (root->left == nullptr) {
                
                // Detect swapped nodes by checking if the previous node is greater than the current
                if (prev && prev->val > root->val) {
                    if (!first) {
                        first = prev;      // First anomaly
                    }
                    second = root;         // Second anomaly
                }

                prev = root;               // Update previous node
                root = root->right;        // Move to right subtree

            } else {
                // Case 2: If left child exists, find the rightmost node in left subtree (inorder predecessor)
                TreeNode* pred = root->left;
                while (pred->right && pred->right != root) {
                    pred = pred->right;
                }

                // Threading: Create a temporary link from predecessor to current node
                if (pred->right == nullptr) {
                    pred->right = root;     // Establish the thread
                    root = root->left;      // Move to left child
                } else {
                    // If thread already exists, it's time to remove it and process the current node
                    pred->right = nullptr;  // Remove the thread

                    // Again, check for anomalies
                    if (prev && prev->val > root->val) {
                        if (!first) {
                            first = prev;
                        }
                        second = root;
                    }

                    prev = root;            // Update previous node
                    root = root->right;     // Move to right subtree
                }
            }
        }

        // Swap the values of the two misplaced nodes to fix the tree
        if (first && second) {
            std::swap(first->val, second->val);
        }
    }
};
