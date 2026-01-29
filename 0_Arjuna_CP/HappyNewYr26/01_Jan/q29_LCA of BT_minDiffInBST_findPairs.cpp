



/*


29th Jan 2026 (Thursday)


qno 236  https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/


236. Lowest Common Ancestor of a Binary Tree
Solved
Medium
Topics

Companies
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

 

Example 1:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.
Example 2:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
Example 3:

Input: root = [1,2], p = 1, q = 2
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [2, 105].
-109 <= Node.val <= 109
All Node.val are unique.
p != q
p and q will exist in the tree.
 
Discover more
LeetCode Premium Subscription
Seen this question in a real interview before?
1/5
Yes
No
Accepted
2,470,675/3.6M
Acceptance Rate
68.5%
Topics
Tree
Depth-First Search
Binary Tree


*/



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if(root == NULL) {
            return NULL;
        }

        if(root->val == p->val  ||  root->val  == q->val) {
            return root;
        }

        TreeNode* leftLCA = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightLCA = lowestCommonAncestor(root->right, p, q);

        if(leftLCA  &&  rightLCA) {
            return root;

        } else if(leftLCA !=  NULL) {
            return leftLCA;

        } else {
            return rightLCA;

        }
        
    }
};

// TC = O(n) = SC




/*

qno 783  https://leetcode.com/problems/minimum-distance-between-bst-nodes/description/


783. Minimum Distance Between BST Nodes
Solved
Easy
Topics

Companies
Given the root of a Binary Search Tree (BST), return the minimum difference between the values of any two different nodes in the tree.

 

Example 1:


Input: root = [4,2,6,1,3]
Output: 1
Example 2:


Input: root = [1,0,48,null,null,12,49]
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [2, 100].
0 <= Node.val <= 105
 

Note: This question is the same as 530: https://leetcode.com/problems/minimum-absolute-difference-in-bst/



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



/*


qno 530  https://leetcode.com/problems/minimum-absolute-difference-in-bst/



530. Minimum Absolute Difference in BST
Easy
Topics

Companies
Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.

 

Example 1:


Input: root = [4,2,6,1,3]
Output: 1
Example 2:


Input: root = [1,0,48,null,null,12,49]
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [2, 104].
0 <= Node.val <= 105
 

Note: This question is the same as 783: https://leetcode.com/problems/minimum-distance-between-bst-nodes/


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

    int getMinimumDifference(TreeNode* root) {

        if(root == NULL) {
            return INT_MAX;
        }

        int ans = INT_MAX;
        if(root->left  !=  NULL) {
            int leftMin = getMinimumDifference(root->left);
            ans = min(ans, leftMin); 
        }

        //calculate currMin
        if(prev != NULL) {
            ans = min(ans, root->val - prev->val);
        }
        prev = root;

        //same thing for right wale ke liye
        if(root->right  !=  NULL) {
            int rightMin = getMinimumDifference(root->right);
            ans = min(ans, rightMin); 
        }

        return ans;
    }
};


// TC = O(n)= SC




/*

qno 532  https://leetcode.com/problems/k-diff-pairs-in-an-array/


532. K-diff Pairs in an Array
Medium
Topics

Companies
Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array.

A k-diff pair is an integer pair (nums[i], nums[j]), where the following are true:

0 <= i, j < nums.length
i != j
|nums[i] - nums[j]| == k
Notice that |val| denotes the absolute value of val.

 

Example 1:

Input: nums = [3,1,4,1,5], k = 2
Output: 2
Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
Although we have two 1s in the input, we should only return the number of unique pairs.
Example 2:

Input: nums = [1,2,3,4,5], k = 1
Output: 4
Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3, 4) and (4, 5).
Example 3:

Input: nums = [1,3,1,5,4], k = 0
Output: 1
Explanation: There is one 0-diff pair in the array, (1, 1).
 

Constraints:

1 <= nums.length <= 104
-107 <= nums[i] <= 107
0 <= k <= 107
 
Seen this question in a real interview before?
1/5
Yes
No
Accepted
417,818/917.9K
Acceptance Rate
45.5%
Topics
Array
Hash Table
Two Pointers
Binary Search
Sorting



*/


class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) return 0;

        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0, j = 1;
        int count = 0;

        while (i < n && j < n) {
            if (i == j) {
                j++;
                continue;
            }

            long diff = (long)nums[j] - nums[i];

            if (diff < k) {
                j++;
            } 
            else if (diff > k) {
                i++;
            } 
            else { // diff == k
                count++;

                int leftVal = nums[i];
                int rightVal = nums[j];

                // skip duplicates
                while (i < n && nums[i] == leftVal) i++;
                while (j < n && nums[j] == rightVal) j++;
            }
        }

        return count;
    }
};




/*






*/