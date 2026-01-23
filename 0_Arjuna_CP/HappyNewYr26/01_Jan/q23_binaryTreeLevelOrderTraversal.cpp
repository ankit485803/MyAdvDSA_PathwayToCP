


/*


23rd Jan 2026 (Friday - JaiMaaSarsati Puja)


qno 102  https://leetcode.com/problems/binary-tree-level-order-traversal/description/


102. Binary Tree Level Order Traversal
Medium
Topics

Companies
Hint
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000


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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root) return result;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int levelSize = q.size();
            vector<int> level;
            for(int i=0; i<levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();

                level.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

            result.push_back(level);
        }

        return result;    //tc=O(n)=sc
    }
};




/*


qno 222  https://leetcode.com/problems/count-complete-tree-nodes/description/


222. Count Complete Tree Nodes
Solved
Easy
Topics

Companies
Given the root of a complete binary tree, return the number of the nodes in the tree.

According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Design an algorithm that runs in less than O(n) time complexity.

 

Example 1:


Input: root = [1,2,3,4,5,6]
Output: 6
Example 2:

Input: root = []
Output: 0
Example 3:

Input: root = [1]
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [0, 5 * 104].
0 <= Node.val <= 5 * 104
The tree is guaranteed to be complete.





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
    int countNodes(TreeNode* root) {  //tc=O(n), sc=O(logN)

        if(root == NULL) return 0;

        int left = countNodes(root->left);   //no of nodes in leftSize
        int right = countNodes(root->right);

        return left + right + 1;
    }
};





class Solution {
public:
    int leftHeight(TreeNode* node) {
        int h = 0;
        while (node) {
            h++;
            node = node->left;
        }
        return h;
    }

    int rightHeight(TreeNode* node) {
        int h = 0;
        while (node) {
            h++;
            node = node->right;
        }
        return h;
    }

    int countNodes(TreeNode* root) {
        if (!root) return 0;

        int lh = leftHeight(root);
        int rh = rightHeight(root);

        // Perfect binary tree
        if (lh == rh) {
            return (1 << lh) - 1;
        }

        // Otherwise recurse
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};


// sc=O(log n) (recursion stack), tc=O(log² n)




/*


qno 107  https://leetcode.com/problems/binary-tree-level-order-traversal-ii/


107. Binary Tree Level Order Traversal II
Medium
Topics

Companies
Given the root of a binary tree, return the bottom-up level order traversal of its nodes' values. (i.e., from left to right, level by level from leaf to root).

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[15,7],[9,20],[3]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000



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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> level;

            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();

                level.push_back(node->val);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            result.push_back(level);
        }

        reverse(result.begin(), result.end());   //sameProb sirf rev
        return result;
    }
};





/*


qno 3510  https://leetcode.com/problems/minimum-pair-removal-to-sort-array-ii/?envType=daily-question&envId=2026-01-23


Code
Testcase
Testcase
Test Result
3510. Minimum Pair Removal to Sort Array II
Attempted
Hard
Topics

Companies
Hint
Given an array nums, you can perform the following operation any number of times:

Select the adjacent pair with the minimum sum in nums. If multiple such pairs exist, choose the leftmost one.
Replace the pair with their sum.
Return the minimum number of operations needed to make the array non-decreasing.

An array is said to be non-decreasing if each element is greater than or equal to its previous element (if it exists).

 

Example 1:

Input: nums = [5,2,3,1]

Output: 2

Explanation:

The pair (3,1) has the minimum sum of 4. After replacement, nums = [5,2,4].
The pair (2,4) has the minimum sum of 6. After replacement, nums = [5,6].
The array nums became non-decreasing in two operations.

Example 2:

Input: nums = [1,2,2]

Output: 0

Explanation:

The array nums is already sorted.

 

Constraints:

1 <= nums.length <= 105
-109 <= nums[i] <= 109
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
9,124/38.7K
Acceptance Rate
23.6%
Topics
Array
Hash Table
Linked List
Heap (Priority



*/



//Approach (Using hashset and prevIndex and nextIndex to avoid rase time complexity)
//T.C : O(n * logn)
//S.C : O(n)
class Solution {
public:
    typedef long long ll;

    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();

        //{a, b, c, d} --> {a, b+c, d}
        vector<ll> temp(n);
        for(int i = 0; i < n; i++)
            temp[i] = nums[i];

        set<pair<ll, int>> minPairSet;

        vector<int> nextIndex(n);
        vector<int> prevIndex(n);

        for(int i = 0; i < n; i++) {
            nextIndex[i] = i+1;
            prevIndex[i] = i-1;
        }

        int badPairs = 0;
        for(int i = 0; i < n-1; i++) {
            if(temp[i] > temp[i+1]) {
                badPairs++;
            }
            minPairSet.insert({temp[i] + temp[i+1], i});
        }

        int operations = 0;

        while(badPairs > 0) {
            int first  = minPairSet.begin()->second;
            int second = nextIndex[first];

            int first_left   = prevIndex[first];
            int second_right = nextIndex[second];


            minPairSet.erase(begin(minPairSet));

            if(temp[first] > temp[second]) {
                badPairs--;
            }

            //{d, (a, b)}
            if(first_left >= 0) {
                if(temp[first_left] > temp[first] &&
                temp[first_left] <= temp[first] + temp[second]) {
                    badPairs--;
                } 
                else if(temp[first_left] <= temp[first] &&
                temp[first_left] > temp[first] + temp[second]) {
                    badPairs++;
                }
            }

            //{(a, b), d}
            if (second_right < n) {
                if (temp[second_right] >= temp[second] &&
                    temp[second_right] < temp[first] + temp[second]) {
                    badPairs++;
                }
                else if (temp[second_right] < temp[second] &&
                         temp[second_right] >= temp[first] + temp[second]) {
                    badPairs--;
                }
            }

            if(first_left >= 0) {
                minPairSet.erase({temp[first_left] + temp[first], first_left});
                minPairSet.insert({temp[first_left] + temp[first] + temp[second], first_left});
            }

            if(second_right < n) {
                minPairSet.erase({temp[second] + temp[second_right], second});
                minPairSet.insert({temp[first] + temp[second] + temp[second_right], first});
                prevIndex[second_right] = first;
            }

            nextIndex[first] = second_right;
            temp[first] += temp[second];

            operations++;
        }

        return operations;
    }
};
