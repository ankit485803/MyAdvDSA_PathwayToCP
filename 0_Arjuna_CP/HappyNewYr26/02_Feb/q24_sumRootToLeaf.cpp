


/*


24th Feb 2026 (Tuesday)


qno 1022   https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/?envType=daily-question&envId=2026-02-24


1022. Sum of Root To Leaf Binary Numbers
Easy
Topics

Companies
Hint
You are given the root of a binary tree where each node has a value 0 or 1. Each root-to-leaf path represents a binary number starting with the most significant bit.

For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in binary, which is 13.
For all leaves in the tree, consider the numbers represented by the path from the root to that leaf. Return the sum of these numbers.

The test cases are generated so that the answer fits in a 32-bits integer.

 

Example 1:


Input: root = [1,0,1,0,1,0,1]
Output: 22
Explanation: (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22
Example 2:

Input: root = [0]
Output: 0
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
Node.val is 0 or 1.
 
Discover more
Practice coding interview platforms
Seen this question in a real interview before?
1/5
Yes
No
Accepted
303,358/402.8K
Acceptance Rate
75.3%
Topics
Staff
Tree
Depth-First Search
Binary Tree
Weekly Contest 131


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
    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0);
    }
    
private:
    int dfs(TreeNode* node, int curr) { //tc=O(n), sc=O(heightTree)
        if (!node) return 0;
        
        // Shift left and add current node value
        curr = (curr << 1) | node->val;
        
        // If leaf node, return the binary number
        if (!node->left && !node->right) {
            return curr;
        }
        
        // Recurse left and right
        return dfs(node->left, curr) + 
               dfs(node->right, curr);
    }
};