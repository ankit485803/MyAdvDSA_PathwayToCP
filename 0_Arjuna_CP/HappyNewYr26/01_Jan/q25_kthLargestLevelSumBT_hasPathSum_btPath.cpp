


/*


25th Jan 2026 (Sunday)



qno  2583  https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/


2583. Kth Largest Sum in a Binary Tree
Medium
Topics

Companies
Hint
You are given the root of a binary tree and a positive integer k.

The level sum in the tree is the sum of the values of the nodes that are on the same level.

Return the kth largest level sum in the tree (not necessarily distinct). If there are fewer than k levels in the tree, return -1.

Note that two nodes are on the same level if they have the same distance from the root.

 

Example 1:


Input: root = [5,8,9,2,1,3,7,4,6], k = 2
Output: 13
Explanation: The level sums are the following:
- Level 1: 5.
- Level 2: 8 + 9 = 17.
- Level 3: 2 + 1 + 3 + 7 = 13.
- Level 4: 4 + 6 = 10.
The 2nd largest level sum is 13.
Example 2:


Input: root = [1,2,null,3], k = 1
Output: 3
Explanation: The largest level sum is 3.
 

Constraints:

The number of nodes in the tree is n.
2 <= n <= 105
1 <= Node.val <= 106
1 <= k <= n
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
178,199/302.1K
Acceptance Rate
59.0%
Topics
Tree
Breadth-First Search
Sorting
Binary Tree
Weekly Contest 335


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
    long long kthLargestLevelSum(TreeNode* root, int k) { //tc=O(logN),sc=O(k)
        if (!root) return -1;

        queue<TreeNode*> q;
        q.push(root);

        // min-heap to keep k largest level sums
        priority_queue<long long, vector<long long>, greater<long long>> pq;

        while (!q.empty()) {
            int sz = q.size();
            long long levelSum = 0;

            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front();
                q.pop();

                levelSum += node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            pq.push(levelSum);
            if ((int)pq.size() > k) {
                pq.pop();
            }
        }

        if ((int)pq.size() < k) return -1;
        return pq.top();
    }
};



/*

qno 112   https://leetcode.com/problems/path-sum/description/


112. Path Sum
Easy
Topics

Companies
Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

A leaf is a node with no children.

 

Example 1:


Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
Output: true
Explanation: The root-to-leaf path with the target sum is shown.
Example 2:


Input: root = [1,2,3], targetSum = 5
Output: false
Explanation: There are two root-to-leaf paths in the tree:
(1 --> 2): The sum is 3.
(1 --> 3): The sum is 4.
There is no root-to-leaf path with sum = 5.
Example 3:

Input: root = [], targetSum = 0
Output: false
Explanation: Since the tree is empty, there are no root-to-leaf paths.
 

Constraints:

The number of nodes in the tree is in the range [0, 5000].
-1000 <= Node.val <= 1000
-1000 <= targetSum <= 1000
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
2,041,464/3.8M
Acceptance Rate
54.2%
Topics
Tree
Depth-First Search
Breadth-First Search
Binary Tree



*/


class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) false;
        //dfs recsively

        //step1: If it's a leaf, check if path sum matches
        if(!root->left && !root->right) {
            return targetSum == root->val;
        }

        //step2: Recur on left or right subtree
        return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    }
};



class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;

        // If it's a leaf, check if path sum matches
        if (!root->left && !root->right) {
            return targetSum == root->val;
        }

        // Recur on left or right subtree
        return hasPathSum(root->left, targetSum - root->val) ||
               hasPathSum(root->right, targetSum - root->val);
    }
};




/*


qno 113  https://leetcode.com/problems/path-sum-ii/description/


257. Binary Tree Paths
Solved
Easy
Topics

Companies
Given the root of a binary tree, return all root-to-leaf paths in any order.

A leaf is a node with no children.

 

Example 1:


Input: root = [1,2,3,null,5]
Output: ["1->2->5","1->3"]
Example 2:

Input: root = [1]
Output: ["1"]
 

Constraints:

The number of nodes in the tree is in the range [1, 100].
-100 <= Node.val <= 100


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






/*


1984  https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/description/?envType=daily-question&envId=2026-01-25



1984. Minimum Difference Between Highest and Lowest of K Scores
Easy
Topics

Companies
Hint
You are given a 0-indexed integer array nums, where nums[i] represents the score of the ith student. You are also given an integer k.

Pick the scores of any k students from the array so that the difference between the highest and the lowest of the k scores is minimized.

Return the minimum possible difference.

 

Example 1:

Input: nums = [90], k = 1
Output: 0
Explanation: There is one way to pick score(s) of one student:
- [90]. The difference between the highest and lowest score is 90 - 90 = 0.
The minimum possible difference is 0.
Example 2:

Input: nums = [9,4,1,7], k = 2
Output: 2
Explanation: There are six ways to pick score(s) of two students:
- [9,4,1,7]. The difference between the highest and lowest score is 9 - 4 = 5.
- [9,4,1,7]. The difference between the highest and lowest score is 9 - 1 = 8.
- [9,4,1,7]. The difference between the highest and lowest score is 9 - 7 = 2.
- [9,4,1,7]. The difference between the highest and lowest score is 4 - 1 = 3.
- [9,4,1,7]. The difference between the highest and lowest score is 7 - 4 = 3.
- [9,4,1,7]. The difference between the highest and lowest score is 7 - 1 = 6.
The minimum possible difference is 2.
 

Constraints:

1 <= k <= nums.length <= 1000
0 <= nums[i] <= 105
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
132,196/220.4K
Acceptance Rate
60.0%
Topics
Array
Sliding Window
Sorting
Weekly Contest 256


*/



class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) { //tc=O(nlogN), sc=O(1)
        if(k == 1) return 0;

        sort(nums.begin(), nums.end());
        int ans = INT_MAX;

        for(int i=0; i+k-1 < nums.size(); i++) {   //sliddingWindow approach
            ans = min(ans, nums[i+k-1] - nums[i]);
        }

        return ans;
    }
};
