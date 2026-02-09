



/*


9th Feb 2026 (Monday)


qno 2042  https://leetcode.com/problems/check-if-numbers-are-ascending-in-a-sentence/


2042. Check if Numbers Are Ascending in a Sentence
Easy
Topics

Companies
Hint
A sentence is a list of tokens separated by a single space with no leading or trailing spaces. Every token is either a positive number consisting of digits 0-9 with no leading zeros, or a word consisting of lowercase English letters.

For example, "a puppy has 2 eyes 4 legs" is a sentence with seven tokens: "2" and "4" are numbers and the other tokens such as "puppy" are words.
Given a string s representing a sentence, you need to check if all the numbers in s are strictly increasing from left to right (i.e., other than the last number, each number is strictly smaller than the number on its right in s).

Return true if so, or false otherwise.

 

Example 1:


Input: s = "1 box has 3 blue 4 red 6 green and 12 yellow marbles"
Output: true
Explanation: The numbers in s are: 1, 3, 4, 6, 12.
They are strictly increasing from left to right: 1 < 3 < 4 < 6 < 12.
Example 2:

Input: s = "hello world 5 x 5"
Output: false
Explanation: The numbers in s are: 5, 5. They are not strictly increasing.
Example 3:


Input: s = "sunset is at 7 51 pm overnight lows will be in the low 50 and 60 s"
Output: false
Explanation: The numbers in s are: 7, 51, 50, 60. They are not strictly increasing.
 

Constraints:

3 <= s.length <= 200
s consists of lowercase English letters, spaces, and digits from 0 to 9, inclusive.
The number of tokens in s is between 2 and 100, inclusive.
The tokens in s are separated by a single space.
There are at least two numbers in s.
Each number in s is a positive number less than 100, with no leading zeros.
s contains no leading or trailing spaces.
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
83,757/115K
Acceptance Rate
72.8%
Topics
Mid Level
String
Weekly Contest 263


*/



class Solution {
public:
    bool areNumbersAscending(string s) {   //tc=O(n), sc=O(1)
        int prev = -1;
        int n = s.size();

        for(int i=0; i<n; i++) {
            if(isdigit(s[i])) {
                int curr = 0;

                //extract all the numb from s
                while(i<n && isdigit(s[i])) {
                    curr = curr * 10 + (s[i] - '0');
                    i++;
                }

                //check stricklyInc
                if(curr <= prev) {
                    return false;
                }

                prev = curr;
            }
        }

        return true;
    }
};






/*


qno 1752  https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/


1752. Check if Array Is Sorted and Rotated
Solved
Easy
Topics

Companies
Hint
Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.

There may be duplicates in the original array.

Note: An array A rotated by x positions results in an array B of the same length such that B[i] == A[(i+x) % A.length] for every valid index i.

 

Example 1:

Input: nums = [3,4,5,1,2]
Output: true
Explanation: [1,2,3,4,5] is the original sorted array.
You can rotate the array by x = 2 positions to begin on the element of value 3: [3,4,5,1,2].
Example 2:

Input: nums = [2,1,3,4]
Output: false
Explanation: There is no sorted array once rotated that can make nums.
Example 3:

Input: nums = [1,2,3]
Output: true
Explanation: [1,2,3] is the original sorted array.
You can rotate the array by x = 0 positions (i.e. no rotation) to make nums.
 

Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 100


*/



class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int count = 0;  // to count the number of "drops" (nums[i] > nums[i+1])
        
        // Traverse the entire array
        for (int i = 0; i < n; i++) {
            // Compare current element with the next one (circular using % n)
            if (nums[i] > nums[(i + 1) % n]) {
                count++;  // found a "drop" in order
            }
        }
        
        // If there is more than 1 drop, it's not a sorted-then-rotated array
        return count <= 1;
    }
};


//tc=O(n), sc=O(1)
// This is a   VALIDATION  problem, not a SEARCH problem. so not pefer BinarySearch here


class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int count = 0;  // number of drops
        
        for (int i = 0; i < n; i++) {
            if (nums[i] > nums[(i + 1) % n]) {
                count++;
            }
        }
        
        return count <= 1;
    }
};



/*


qno  1382  https://leetcode.com/problems/balance-a-binary-search-tree/?envType=daily-question&envId=2026-02-09


1382. Balance a Binary Search Tree
Solved
Medium
Topics

Companies
Hint
Given the root of a binary search tree, return a balanced binary search tree with the same node values. If there is more than one answer, return any of them.

A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.

 

Example 1:


Input: root = [1,null,2,null,3,null,4,null,null]
Output: [2,1,3,null,null,null,4]
Explanation: This is not the only correct answer, [3,1,4,null,2] is also correct.
Example 2:


Input: root = [2,1,3]
Output: [2,1,3]
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
1 <= Node.val <= 105


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
    vector<TreeNode*> nodes;

    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        nodes.push_back(root);
        inorder(root->right);
    }

    TreeNode* build(int left, int right) {
        if (left > right) return nullptr;

        int mid = left + (right - left) / 2;
        TreeNode* root = nodes[mid];

        root->left = build(left, mid - 1);
        root->right = build(mid + 1, right);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        return build(0, nodes.size() - 1);
    }
};
