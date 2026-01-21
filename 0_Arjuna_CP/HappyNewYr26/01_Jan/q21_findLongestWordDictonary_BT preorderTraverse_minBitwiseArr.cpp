




/*


21st Jan 2026 (Wednesday - Sem6 class starts)


qno 524   https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/


524. Longest Word in Dictionary through Deleting
Medium
Topics

Companies
Given a string s and a string array dictionary, return the longest string in the dictionary that can be formed by deleting some of the given string characters. If there is more than one possible result, return the longest word with the smallest lexicographical order. If there is no possible result, return the empty string.

 

Example 1:

Input: s = "abpcplea", dictionary = ["ale","apple","monkey","plea"]
Output: "apple"
Example 2:

Input: s = "abpcplea", dictionary = ["a","b","c"]
Output: "a"
 

Constraints:

1 <= s.length <= 1000
1 <= dictionary.length <= 1000
1 <= dictionary[i].length <= 1000
s and dictionary[i] consist of lowercase English letters.
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
179,967/343.2K
Acceptance Rate
52.4%
Topics
Array
Two Pointers
String
Sorting



*/



class Solution {
public:
    bool isSubsequence(const string& s, const string& word) {  //tc=O(m*n), sc=O(1)
        int i = 0, j = 0;
        while (i < s.size() && j < word.size()) {
            if (s[i] == word[j]) {
                j++;
            }
            i++;
        }
        return j == word.size();
    }

    string findLongestWord(string s, vector<string>& dictionary) {
        string result = "";

        for (const string& word : dictionary) {
            if (isSubsequence(s, word)) {
                if (word.size() > result.size() ||
                   (word.size() == result.size() && word < result)) {
                    result = word;
                }
            }
        }

        return result;
    }
};






/*



qno 2037  https://leetcode.com/problems/minimum-number-of-moves-to-seat-everyone/



2037. Minimum Number of Moves to Seat Everyone
Solved
Easy
Topics

Companies
Hint
There are n availabe seats and n students standing in a room. You are given an array seats of length n, where seats[i] is the position of the ith seat. You are also given the array students of length n, where students[j] is the position of the jth student.

You may perform the following move any number of times:

Increase or decrease the position of the ith student by 1 (i.e., moving the ith student from position x to x + 1 or x - 1)
Return the minimum number of moves required to move each student to a seat such that no two students are in the same seat.

Note that there may be multiple seats or students in the same position at the beginning.

 

Example 1:

Input: seats = [3,1,5], students = [2,7,4]
Output: 4
Explanation: The students are moved as follows:
- The first student is moved from position 2 to position 1 using 1 move.
- The second student is moved from position 7 to position 5 using 2 moves.
- The third student is moved from position 4 to position 3 using 1 move.
In total, 1 + 2 + 1 = 4 moves were used.
Example 2:

Input: seats = [4,1,5,9], students = [1,3,2,6]
Output: 7
Explanation: The students are moved as follows:
- The first student is not moved.
- The second student is moved from position 3 to position 4 using 1 move.
- The third student is moved from position 2 to position 5 using 3 moves.
- The fourth student is moved from position 6 to position 9 using 3 moves.
In total, 0 + 1 + 3 + 3 = 7 moves were used.
Example 3:

Input: seats = [2,2,6,6], students = [1,3,2,6]
Output: 4
Explanation: Note that there are two seats at position 2 and two seats at position 6.
The students are moved as follows:
- The first student is moved from position 1 to position 2 using 1 move.
- The second student is moved from position 3 to position 6 using 3 moves.
- The third student is not moved.
- The fourth student is not moved.
In total, 1 + 3 + 0 + 0 = 4 moves were used.
 

Constraints:

n == seats.length == students.length
1 <= n <= 100
1 <= seats[i], students[j] <= 100
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
278,220/319K
Acceptance Rate
87.2%
Topics
Array
Greedy
Sorting
Counting Sort
Biweekly Contest 63





*/



class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());

        int moves = 0;
        for(int i=0; i<seats.size(); i++) {
            moves += abs(students[i] - seats[i]);
        }
        return moves;
    }
};




/*


qno 144  https://leetcode.com/problems/binary-tree-preorder-traversal/description/


144. Binary Tree Preorder Traversal
Easy
Topics

Companies
Given the root of a binary tree, return the preorder traversal of its nodes' values.

 

Example 1:

Input: root = [1,null,2,3]

Output: [1,2,3]

Explanation:



Example 2:

Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]

Output: [1,2,4,5,6,7,3,8,9]

Explanation:



Example 3:

Input: root = []

Output: []

Example 4:

Input: root = [1]

Output: [1]

 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
 

Follow up: Recursive solution is trivial, could you do it iteratively?

 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
2,313,226/3.1M
Acceptance Rate
74.9%
Topics
Stack
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
    void dfs(TreeNode* root, vector<int>& result) {
        if(!root) return;

        result.push_back(root->val);
        dfs(root->left, result);
        dfs(root->right, result);
    }

    vector<int> preorderTraversal(TreeNode* root) {  //tc=O(n)=sc
        vector<int> result;
        dfs(root, result);
        return result;
    }
};




/*


qno 94  https://leetcode.com/problems/binary-tree-inorder-traversal/description/

94. Binary Tree Inorder Traversal
Solved
Easy
Topics

Companies
Given the root of a binary tree, return the inorder traversal of its nodes' values.

 

Example 1:

Input: root = [1,null,2,3]

Output: [1,3,2]

Explanation:



Example 2:

Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]

Output: [4,2,6,5,7,1,3,9,8]

Explanation:



Example 3:

Input: root = []

Output: []

Example 4:

Input: root = [1]

Output: [1]

 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
 

Follow up: Recursive solution is trivial, could you do it iteratively?
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
3,521,184/4.4M
Acceptance Rate
79.6%
Topics
Stack
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;

        while (curr != NULL) {
            if (curr->left == NULL) {
                // Visit current node
                ans.push_back(curr->val);  // ✅ Fixed: used push_back instead of push
                curr = curr->right;
            } else {
                // Find the inorder predecessor (IP)
                TreeNode* IP = curr->left;
                while (IP->right != NULL && IP->right != curr) {
                    IP = IP->right;
                }

                if (IP->right == NULL) {
                    // Create thread
                    IP->right = curr;
                    curr = curr->left;

                } else {
                    // Thread already exists, destroy/Delete it and visit node
                    IP->right = NULL;
                    ans.push_back(curr->val);  
                    curr = curr->right;
                }
            }
        }

        return ans;  
    }
};


/*
Time and Space Complexity:

Time: O(n) — each node is visited at most twice.
Space: O(1) — no recursion or extra stack (in-place traversal).

Morris Inorder Traversal

*/




/*


qno 145  https://leetcode.com/problems/binary-tree-postorder-traversal/description/


145. Binary Tree Postorder Traversal
Easy
Topics

Companies
Given the root of a binary tree, return the postorder traversal of its nodes' values.

 

Example 1:

Input: root = [1,null,2,3]

Output: [3,2,1]

Explanation:



Example 2:

Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]

Output: [4,6,7,5,2,9,8,3,1]

Explanation:



Example 3:

Input: root = []

Output: []

Example 4:

Input: root = [1]

Output: [1]

 

Constraints:

The number of the nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
 

Follow up: Recursive solution is trivial, could you do it iteratively?
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
1,863,580/2.4M
Acceptance Rate
77.4%
Topics
Stack
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* curr = root;
        TreeNode* lastVisited = nullptr;

        while (curr != nullptr || !st.empty()) {
            if (curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            } else {
                TreeNode* node = st.top();
                // If right child exists and not processed yet
                if (node->right && lastVisited != node->right) {
                    curr = node->right;
                } else {
                    ans.push_back(node->val);
                    lastVisited = node;
                    st.pop();
                }
            }
        }
        return ans;
    }
};




/*


qno 3315  https://leetcode.com/problems/construct-the-minimum-bitwise-array-ii/?envType=daily-question&envId=2026-01-21


3315. Construct the Minimum Bitwise Array II
Medium
Topics

Companies
Hint
You are given an array nums consisting of n prime integers.

You need to construct an array ans of length n, such that, for each index i, the bitwise OR of ans[i] and ans[i] + 1 is equal to nums[i], i.e. ans[i] OR (ans[i] + 1) == nums[i].

Additionally, you must minimize each value of ans[i] in the resulting array.

If it is not possible to find such a value for ans[i] that satisfies the condition, then set ans[i] = -1.

 

Example 1:

Input: nums = [2,3,5,7]

Output: [-1,1,4,3]

Explanation:

For i = 0, as there is no value for ans[0] that satisfies ans[0] OR (ans[0] + 1) = 2, so ans[0] = -1.
For i = 1, the smallest ans[1] that satisfies ans[1] OR (ans[1] + 1) = 3 is 1, because 1 OR (1 + 1) = 3.
For i = 2, the smallest ans[2] that satisfies ans[2] OR (ans[2] + 1) = 5 is 4, because 4 OR (4 + 1) = 5.
For i = 3, the smallest ans[3] that satisfies ans[3] OR (ans[3] + 1) = 7 is 3, because 3 OR (3 + 1) = 7.
Example 2:

Input: nums = [11,13,31]

Output: [9,12,15]

Explanation:

For i = 0, the smallest ans[0] that satisfies ans[0] OR (ans[0] + 1) = 11 is 9, because 9 OR (9 + 1) = 11.
For i = 1, the smallest ans[1] that satisfies ans[1] OR (ans[1] + 1) = 13 is 12, because 12 OR (12 + 1) = 13.
For i = 2, the smallest ans[2] that satisfies ans[2] OR (ans[2] + 1) = 31 is 15, because 15 OR (15 + 1) = 31.
 

Constraints:

1 <= nums.length <= 100
2 <= nums[i] <= 109
nums[i] is a prime number.
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
27,656/59.8K
Acceptance Rate
46.3%
Topics
Array
Bit Manipulation
Biweekly Contest 141


*/



class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        for(int i = 0; i < n; i++) {
            int num = nums[i];

            if(num == 2) { // special case
                ans[i] = -1;
                continue;
            }

            bool isFound = false;

            for(int j = 0; j < 32; j++) { // iterate bits LSB → MSB
                if((num & (1 << j)) > 0) { // set bit → skip
                    continue;
                }
                // Found first 0 bit at position j
                int x = num ^ (1 << (j - 1)); // flip previous bit
                ans[i] = x;
                isFound = true;
                break;
            }

            if(!isFound) {
                ans[i] = -1;
            }
        }

        return ans;
    }
};
