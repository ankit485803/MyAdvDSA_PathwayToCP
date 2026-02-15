#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "12345";
    vector<int> v;

    // Convert each character in the string to an integer
    for (char c : s)
        v.push_back(c - '0');

    for (int i : v) cout << i << " ";
    return 0;
}







/*

15th Feb 2026 (Sunday - mahaShivRatri)


qno 199  https://leetcode.com/problems/binary-tree-right-side-view/


199. Binary Tree Right Side View
Medium
Topics

Companies
Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

 

Example 1:

Input: root = [1,2,3,null,5,null,4]

Output: [1,3,4]

Explanation:



Example 2:

Input: root = [1,2,3,4,null,null,null,5]

Output: [1,3,4,5]

Explanation:



Example 3:

Input: root = [1,null,3]

Output: [1,3]

Example 4:

Input: root = []

Output: []

 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
2,137,171/3.1M
Acceptance Rate
69.4%
Topics
Tree
Depth-First Search
Breadth-First Search
Binary Tree


*/



class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {  //tc=O(n)=sc using BFS approach
        vector<int> result;
        if (!root) return result;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();

            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();

                // If it's the last node of this level
                if (i == levelSize - 1) {
                    result.push_back(node->val);
                }

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }

        return result;
    }
};




class Solution {
public:
    void dfs(TreeNode* node, int depth, vector<int>& result) {  //tc=O(n), sc=O(height) stack
        if (!node) return;

        // If first time visiting this depth
        if (depth == result.size()) {
            result.push_back(node->val);
        }

        dfs(node->right, depth + 1, result);
        dfs(node->left, depth + 1, result);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        dfs(root, 0, result);
        return result;
    }
};




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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if(!root) return result;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int levelSize = q.size();   //BFS tc=O(n)=sc
            for(int i=0; i<levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();

                //if it is lastNode of thisLevel
                if(i == levelSize - 1) {
                    result.push_back(node->val);
                }

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);

            }
        }

        return result;
    }
};





/*

qn0 67  https://leetcode.com/problems/add-binary/?envType=daily-question&envId=2026-02-15


Code
Testcase
Testcase
Test Result
67. Add Binary
Easy
Topics

Companies
Given two binary strings a and b, return their sum as a binary string.

 

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
 

Constraints:

1 <= a.length, b.length <= 104
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself.
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
2,157,906/3.8M
Acceptance Rate
56.9%
Topics
Math
String
Bit Manipulation
Simulation

*/



class Solution {
public:
    string addBinary(string a, string b) {  //myWrongApproach
        vector<int> ans;
        //conceptUsed: As we know int store in pc in already binaryForm, so we can dirctly add

        //step1: convert str a, b into intForm
        vector<int> A, B;
        for(char c : a) {
            A.push_back(c - '0');
        }

        for(char c : b) {
            B.push_back(c - '0');
        }

        //step2: add both
        int ans = A + B;

        return ans.to_string;  //in stringForm

    }
};



class Solution {
public:
    string addBinary(string a, string b) {  //tc=O(max(m, n)) = sc
        string result = "";
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;

            if (i >= 0) {
                sum += a[i] - '0';
                i--;
            }

            if (j >= 0) {
                sum += b[j] - '0';
                j--;
            }

            result += (sum % 2) + '0';
            carry = sum / 2;
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
