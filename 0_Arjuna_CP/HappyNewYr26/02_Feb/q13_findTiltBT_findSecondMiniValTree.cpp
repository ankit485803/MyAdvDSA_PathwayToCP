



/*

13th Feb 2026 (Friday)

qno 563 https://leetcode.com/problems/binary-tree-tilt/

563. Binary Tree Tilt
Easy
Topics

Companies
Hint
Given the root of a binary tree, return the sum of every tree node's tilt.

The tilt of a tree node is the absolute difference between the sum of all left subtree node values and all right subtree node values. If a node does not have a left child, then the sum of the left subtree node values is treated as 0. The rule is similar if the node does not have a right child.

 

Example 1:


Input: root = [1,2,3]
Output: 1
Explanation: 
Tilt of node 2 : |0-0| = 0 (no children)
Tilt of node 3 : |0-0| = 0 (no children)
Tilt of node 1 : |2-3| = 1 (left subtree is just left child, so sum is 2; right subtree is just right child, so sum is 3)
Sum of every tilt : 0 + 0 + 1 = 1
Example 2:


Input: root = [4,2,9,3,5,null,7]
Output: 15
Explanation: 
Tilt of node 3 : |0-0| = 0 (no children)
Tilt of node 5 : |0-0| = 0 (no children)
Tilt of node 7 : |0-0| = 0 (no children)
Tilt of node 2 : |3-5| = 2 (left subtree is just left child, so sum is 3; right subtree is just right child, so sum is 5)
Tilt of node 9 : |0-7| = 7 (no left child, so sum is 0; right subtree is just right child, so sum is 7)
Tilt of node 4 : |(3+5+2)-(9+7)| = |10-16| = 6 (left subtree values are 3, 5, and 2, which sums to 10; right subtree values are 9 and 7, which sums to 16)
Sum of every tilt : 0 + 0 + 0 + 2 + 7 + 6 = 15
Example 3:


Input: root = [21,7,14,1,1,2,2,3,3]
Output: 9
 

Constraints:

The number of nodes in the tree is in the range [0, 104].
-1000 <= Node.val <= 1000
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
262,334/401.8K
Acceptance Rate
65.3%
Topics
Mid Level
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
    int findTilt(TreeNode* root) {
        //step1: takeAnsVariable
        int ans = 0;

        //step2: forEachNode find leafSubtree & rightSubtree nodeSum

        //step3: int tilt = abs(leftSubtree - rightSubtree)
        int tilt = abs(left - right)
        ans += tilt;

        return ans;
    }
};


leftSum  = sum of left subtree
rightSum = sum of right subtree
tilt     = abs(leftSum - rightSum)



class Solution {
public:
    int findTilt(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);  //makePrivateFun
        return ans;
        
    }

private:
    int dfs(TreeNode* node, int &ans) {
        if(!node) return 0;

        int leftSum = dfs(node->left, ans);  //recusivelyCall - sc=O(heightBT), tc=O(n)
        int rightSum = dfs(node->right, ans);
        ans += abs(leftSum - rightSum);

        return leftSum + rightSum + node->val;
    }
};




/*


qno 671  https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/

671. Second Minimum Node In a Binary Tree
Easy
Topics

Companies
Given a non-empty special binary tree consisting of nodes with the non-negative value, where each node in this tree has exactly two or zero sub-node. If the node has two sub-nodes, then this node's value is the smaller value among its two sub-nodes. More formally, the property root.val = min(root.left.val, root.right.val) always holds.

Given such a binary tree, you need to output the second minimum value in the set made of all the nodes' value in the whole tree.

If no such second minimum value exists, output -1 instead.

 

 

Example 1:


Input: root = [2,2,5,null,null,5,7]
Output: 5
Explanation: The smallest value is 2, the second smallest value is 5.
Example 2:


Input: root = [2,2,2]
Output: -1
Explanation: The smallest value is 2, but there isn't any second smallest value.
 

Constraints:

The number of nodes in the tree is in the range [1, 25].
1 <= Node.val <= 231 - 1
root.val == min(root.left.val, root.right.val) for each internal node of the tree.
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
239,380/521.4K
Acceptance Rate
45.9%
Topics
Mid Level
Tree
Depth-First Search
Binary Tree

*/



return (secondMin == LONG_MAX) ? -1 : secondMin;
// written in normal if-else format instead of the ternary operator.
if (secondMin == LONG_MAX) {
    return -1;
} else {
    return secondMin;
}



class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        if(!root) return -1;
        
        int minVal = root->val;
        long secondMin = LONG_MAX;
        dfs(root, minVal, secondMin);

        return (secondMin == LONG_MAX) ? -1 : secondMin;
    }

private:
    void dfs(TreeNode* node, int minVal, long &secondMin) {  //tc=O(n),sc=O(height)
        if(!node) return;  //justPass

        if(node->val > minVal && node->val < secondMin) {
            secondMin = node->val;
        }

        dfs(node->left, minVal, secondMin);
        dfs(node->right, minVal, secondMin);
    }

};




/*

qno 3714  https://leetcode.com/problems/longest-balanced-substring-ii/description/?envType=daily-question&envId=2026-02-13

3714. Longest Balanced Substring II
Medium
Topics

Companies
Hint
You are given a string s consisting only of the characters 'a', 'b', and 'c'.

A substring of s is called balanced if all distinct characters in the substring appear the same number of times.

Return the length of the longest balanced substring of s.

 

Example 1:

Input: s = "abbac"

Output: 4

Explanation:

The longest balanced substring is "abba" because both distinct characters 'a' and 'b' each appear exactly 2 times.

Example 2:

Input: s = "aabcc"

Output: 3

Explanation:

The longest balanced substring is "abc" because all distinct characters 'a', 'b' and 'c' each appear exactly 1 time.

Example 3:

Input: s = "aba"

Output: 2

Explanation:

One of the longest balanced substrings is "ab" because both distinct characters 'a' and 'b' each appear exactly 1 time. Another longest balanced substring is "ba".

 

Constraints:

1 <= s.length <= 105
s contains only the characters 'a', 'b', and 'c'.
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
13,132/52.5K
Acceptance Rate
25.0%
Topics
Staff
Hash Table
String
Prefix Sum
Weekly Contest 471


*/



class Solution {
public:
    int longestBalanced(string s) {  //but not pass on each testcase
        unordered_map<long long, int> mp;
        
        int countA = 0, countB = 0, countC = 0;
        int ans = 0;
        
        // Base case: before string starts
        mp[0] = -1; 
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a') countA++;
            else if (s[i] == 'b') countB++;
            else countC++;
            
            int d1 = countA - countB;
            int d2 = countA - countC;
            
            // Combine two ints into one key
            long long key = ((long long)d1 << 32) | (unsigned int)d2;
            
            if (mp.count(key)) {
                ans = max(ans, i - mp[key]);
            } else {
                mp[key] = i;
            }
        }
        
        return ans;
    }
};
