


/*


12th Feb 2026 (Thursday)


qno 404   https://leetcode.com/problems/sum-of-left-leaves/


404. Sum of Left Leaves
Easy
Topics

Companies
Given the root of a binary tree, return the sum of all left leaves.

A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: 24
Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.
Example 2:

Input: root = [1]
Output: 0
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
-1000 <= Node.val <= 1000
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
774,454/1.2M
Acceptance Rate
62.3%
Topics
Junior
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
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == NULL) return 0;

        int sum = 0;

        // Check if left child exists and is a leaf
        if (root->left != NULL) {
            if (root->left->left == NULL && root->left->right == NULL) {
                sum += root->left->val;
            } else {
                sum += sumOfLeftLeaves(root->left);
            }
        }

        // Always check right subtree
        sum += sumOfLeftLeaves(root->right);

        return sum;  //tc=O(n), sc=O(heightTree)
    }
};





/*


qno 965  https://leetcode.com/problems/univalued-binary-tree/


965. Univalued Binary Tree
Easy
Topics

Companies
A binary tree is uni-valued if every node in the tree has the same value.

Given the root of a binary tree, return true if the given tree is uni-valued, or false otherwise.

 

Example 1:


Input: root = [1,1,1,1,1,null,1]
Output: true
Example 2:


Input: root = [2,2,2,5,2]
Output: false
 

Constraints:

The number of nodes in the tree is in the range [1, 100].
0 <= Node.val < 100
 
Seen this question in a real interview before?
1/5
Yes
No
Accepted
269,203/369.9K
Acceptance Rate
72.8%
Topics
Mid Level
Tree
Depth-First Search
Breadth-First Search
Binary Tree
Weekly Contest 117


*/




class Solution {
public:
    bool dfs(TreeNode* node, int value) {
        if (node == NULL) return true;

        if (node->val != value) return false;

        return dfs(node->left, value) && dfs(node->right, value);
    }

    bool isUnivalTree(TreeNode* root) {
        return dfs(root, root->val);
    }
};




/*


qno 3713  https://leetcode.com/problems/longest-balanced-substring-i/description/?envType=daily-question&envId=2026-02-12


3713. Longest Balanced Substring I
Solved
Medium
Topics

Companies
Hint
You are given a string s consisting of lowercase English letters.

A substring of s is called balanced if all distinct characters in the substring appear the same number of times.

Return the length of the longest balanced substring of s.

 

Example 1:

Input: s = "abbac"

Output: 4

Explanation:

The longest balanced substring is "abba" because both distinct characters 'a' and 'b' each appear exactly 2 times.

Example 2:

Input: s = "zzabccy"

Output: 4

Explanation:

The longest balanced substring is "zabc" because the distinct characters 'z', 'a', 'b', and 'c' each appear exactly 1 time.​​​​​​​

Example 3:

Input: s = "aba"

Output: 2

Explanation:

​​​​​​​One of the longest balanced substrings is "ab" because both distinct characters 'a' and 'b' each appear exactly 1 time. Another longest balanced substring is "ba".

 

Constraints:

1 <= s.length <= 1000
s consists of lowercase English letters.
 
Discover more
LeetCode certified developer program
Seen this question in a real interview before?
1/5
Yes
No
Accepted
73,110/112.9K
Acceptance Rate
64.7%
Topics
Senior
Hash Table
String
Counting
Enumeration
Weekly Contest 471


*/



#include <unordered_map>

class Solution {
public:
    int longestBalanced(string s) {  //TC=(n * n) due to nestedLoop, SC=O(1)map will store at most 26 key-value pairs.

        
        int n = s.size();
        int max_len = 0;
        
        // Step1: Iterate over all possible substr
        for (int i = 0; i < n; ++i) {
            unordered_map<char, int> freq;  // To store Freq of char in curr window
            
            // Step2: Iterate over the subStr starting from i
            for (int j = i; j < n; ++j) {
                freq[s[j]]++;  // Increment

                // Step3: Check if the curr subStr is balanced
                if (isBalanced(freq)) {
                    max_len = max(max_len, j - i + 1);  // Update max_len if the curr subStr is balanced
                }
            }
        }

        return max_len;  
    }



    
private:
    // Helper function to check if the curr Freq map represents a balanced subStr
    bool isBalanced(const unordered_map<char, int>& freq) {   //TC=(n)
        int count = -1;
        
        // Check if all characters have the same Freq
        for (const auto& entry : freq) {
            if (count == -1) {
                count = entry.second;  // Initialize with the first character's Freq
            } else if (entry.second != count) {
                return false;  // If any character has a different Freq, it's not balanced
            }
        }
        
        return true;
    }
};
