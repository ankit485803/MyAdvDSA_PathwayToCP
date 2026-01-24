



/*


24th Jan 2026 (Satursday - JaiMaaSarde Puja)


qno 543  https://leetcode.com/problems/diameter-of-binary-tree/


543. Diameter of Binary Tree
Solved
Easy
Topics

Companies
Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.

 

Example 1:


Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].
Example 2:

Input: root = [1,2]
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-100 <= Node.val <= 100
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
2,362,608/3.6M
Acceptance Rate
64.9%
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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
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




/*


qno 572   https://leetcode.com/problems/subtree-of-another-tree/description/


572. Subtree of Another Tree
Solved
Easy
Topics

Companies
Hint
Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.

A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.

 

Example 1:


Input: root = [3,4,5,1,2], subRoot = [4,1,2]
Output: true
Example 2:


Input: root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
Output: false
 

Constraints:

The number of nodes in the root tree is in the range [1, 2000].
The number of nodes in the subRoot tree is in the range [1, 1000].
-104 <= root.val <= 104
-104 <= subRoot.val <= 104
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
1,205,495/2.4M
Acceptance Rate
51.1%
Topics
Tree
Depth-First Search
String Matching
Binary Tree
Hash Function




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

    bool isIdentical(TreeNode* p, TreeNode* q) {
        if(p == NULL || q == NULL) {
            return p == q;
        }

        return p->val == q->val 
                && isIdentical(p->left, q->left) 
                && isIdentical(p->right, q->right);
    }


    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        //BASE-CASE
        if(root == NULL || subRoot == NULL) {
            return root == subRoot;
        }

        if(root->val == subRoot-> val && isIdentical(root, subRoot)) {
            return true;
        }

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};




/*


qno 101   https://leetcode.com/problems/symmetric-tree/


101. Symmetric Tree
Easy
Topics

Companies
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

 

Example 1:


Input: root = [1,2,2,3,4,4,3]
Output: true
Example 2:


Input: root = [1,2,2,null,3,null,3]
Output: false
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
-100 <= Node.val <= 100
 

Follow up: Could you solve it both recursively and iteratively?


*/



class Solution {
public:

    bool isMirror(TreeNode* t1, TreeNode* t2) {  //tc=O(n), sc=O(height)  usingRecurssive
        if (t1 == NULL || t2 == NULL) {
            return t1 == t2;
        }

        return (t1->val == t2->val)
            && isMirror(t1->left, t2->right)
            && isMirror(t1->right, t2->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        return isMirror(root->left, root->right);
    }
};





class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;

        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);

        while (!q.empty()) {
            TreeNode* t1 = q.front(); q.pop();
            TreeNode* t2 = q.front(); q.pop();

            if (t1 == NULL && t2 == NULL) continue;
            if (t1 == NULL || t2 == NULL) return false;
            if (t1->val != t2->val) return false;

            // push mirrored children
            q.push(t1->left);
            q.push(t2->right);

            q.push(t1->right);
            q.push(t2->left);
        }

        return true;
    }
};




/*


qno 100 https://leetcode.com/problems/same-tree/ 



100. Same Tree
Solved
Easy
Topics

Companies
Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

 

Example 1:


Input: p = [1,2,3], q = [1,2,3]
Output: true
Example 2:


Input: p = [1,2], q = [1,null,2]
Output: false
Example 3:


Input: p = [1,2,1], q = [1,1,2]
Output: false
 

Constraints:

The number of nodes in both trees is in the range [0, 100].
-104 <= Node.val <= 104
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
3,229,905/4.9M
Acceptance Rate
66.4%
Topics
Tree
Depth-First Search
Breadth-First Search
Binary Tree




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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        if(p == NULL  ||  q == NULL) {
            return p == q;
        }

        bool isLeftSame = isSameTree(p->left,  q->left);
        bool isRightSame = isSameTree(p->right, q->right);

        return isLeftSame && isRightSame && p->val == q->val;

    }
};

// TC = O(n) = SC





/*


qno  1877  https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/?envType=daily-question&envId=2026-01-24


1877. Minimize Maximum Pair Sum in Array
Medium
Topics

Companies
Hint
The pair sum of a pair (a,b) is equal to a + b. The maximum pair sum is the largest pair sum in a list of pairs.

For example, if we have pairs (1,5), (2,3), and (4,4), the maximum pair sum would be max(1+5, 2+3, 4+4) = max(6, 5, 8) = 8.
Given an array nums of even length n, pair up the elements of nums into n / 2 pairs such that:

Each element of nums is in exactly one pair, and
The maximum pair sum is minimized.
Return the minimized maximum pair sum after optimally pairing up the elements.

 

Example 1:

Input: nums = [3,5,2,3]
Output: 7
Explanation: The elements can be paired up into pairs (3,3) and (5,2).
The maximum pair sum is max(3+3, 5+2) = max(6, 7) = 7.
Example 2:

Input: nums = [3,5,4,2,4,6]
Output: 8
Explanation: The elements can be paired up into pairs (3,5), (4,4), and (6,2).
The maximum pair sum is max(3+5, 4+4, 6+2) = max(8, 8, 8) = 8.
 

Constraints:

n == nums.length
2 <= n <= 105
n is even.
1 <= nums[i] <= 105
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
264,075/319.8K
Acceptance Rate
82.6%
Topics
Array
Two Pointers
Greedy
Sorting
Biweekly Contest 53



*/



class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int i = 0;   //smaller
        int j = nums.size() - 1;  //larger
        int ans = 0;

        while (i < j) {
            ans = max(ans, nums[i] + nums[j]);
            i++;
            j--;
        }

        return ans;
    }
};
