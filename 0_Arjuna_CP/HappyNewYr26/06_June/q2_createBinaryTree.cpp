

/*

7th June 2026 (Sunday)


qno 2196  https://leetcode.com/problems/create-binary-tree-from-descriptions/?envType=daily-question&envId=2026-06-07

2196. Create Binary Tree From Descriptions
Solved
Medium
Topics

Companies
Hint
You are given a 2D integer array descriptions where descriptions[i] = [parenti, childi, isLefti] indicates that parenti is the parent of childi in a binary tree of unique values. Furthermore,

If isLefti == 1, then childi is the left child of parenti.
If isLefti == 0, then childi is the right child of parenti.
Construct the binary tree described by descriptions and return its root.

The test cases will be generated such that the binary tree is valid.

 

Example 1:


Input: descriptions = [[20,15,1],[20,17,0],[50,20,1],[50,80,0],[80,19,1]]
Output: [50,20,80,15,17,19]
Explanation: The root node is the node with value 50 since it has no parent.
The resulting binary tree is shown in the diagram.
Example 2:


Input: descriptions = [[1,2,1],[2,3,0],[3,4,1]]
Output: [1,2,null,null,3,4]
Explanation: The root node is the node with value 1 since it has no parent.
The resulting binary tree is shown in the diagram.
 

Constraints:

1 <= descriptions.length <= 104
descriptions[i].length == 3
1 <= parenti, childi <= 105
0 <= isLefti <= 1
The binary tree described by descriptions is valid.
 
Seen this question in a real interview before?
1/6
Yes
No
Accepted
209,957/253.3K
Acceptance Rate
82.9%
Topics
Senior
Array
Hash Table
Tree
Binary Tree
Weekly Contest 283


*/


//Simple Approach using map and set
//T.C : O(n), where n is the size of descriptions
//S.C : O(n), size of map and set
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;
        unordered_set<int> childSet; //they can never be root of the tree


        for(vector<int>& vec : descriptions) { //O(n)
            int parent = vec[0];
            int child  = vec[1];
            int isLeft = vec[2];

            if(mp.find(parent) == mp.end()) {
                mp[parent] = new TreeNode(parent);
            }

            if(mp.find(child) == mp.end()) {
                mp[child] = new TreeNode(child);
            }

            if(isLeft == 1) { //left child  
                mp[parent]->left = mp[child];
            } else {
                mp[parent]->right = mp[child];
            }

            childSet.insert(child);
        }


        //Find the root
        for(vector<int>& vec : descriptions) { //O(n)
            int parent = vec[0];
            if(childSet.find(parent) == childSet.end()) { //if(!mp.count(parent))
                return mp[parent];
            }
        }

        return NULL; //we will never reach here
    }
};