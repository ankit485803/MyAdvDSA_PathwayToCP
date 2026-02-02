


/*

2nd Feb 2026 (Monday)


qno 129  https://leetcode.com/problems/sum-root-to-leaf-numbers/




129. Sum Root to Leaf Numbers
Medium
Topics

Companies
You are given the root of a binary tree containing digits from 0 to 9 only.

Each root-to-leaf path in the tree represents a number.

For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer.

A leaf node is a node with no children.

 

Example 1:


Input: root = [1,2,3]
Output: 25
Explanation:
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.
Therefore, sum = 12 + 13 = 25.
Example 2:


Input: root = [4,9,0,5,1]
Output: 1026
Explanation:
The root-to-leaf path 4->9->5 represents the number 495.
The root-to-leaf path 4->9->1 represents the number 491.
The root-to-leaf path 4->0 represents the number 40.
Therefore, sum = 495 + 491 + 40 = 1026.
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
0 <= Node.val <= 9
The depth of the tree will not exceed 10.
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
1,230,944/1.8M
Acceptance Rate
69.5%
Topics
Tree
Depth-First Search
Binary Tree


You don’t need to separately think “left sum” and “right sum”; DFS naturally handles both.
previous_number * 10 + current_digit
newNumber = curr * 10 + val


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
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);

    }

private: 
    int dfs(TreeNode* root, int curr) {  //tc=O(n), sc=O(h) due to recussiveStack
        if(!root) return 0;

        curr = curr * 10 + root->val;
        //if leafNode
        if(!root->left && !root->right) {
            return curr;
        }

        return dfs(root->left, curr) + dfs(root->right, curr);
    }


};





/*


qno 988  https://leetcode.com/problems/smallest-string-starting-from-leaf/


988. Smallest String Starting From Leaf
Medium
Topics

Companies
You are given the root of a binary tree where each node has a value in the range [0, 25] representing the letters 'a' to 'z'.

Return the lexicographically smallest string that starts at a leaf of this tree and ends at the root.

As a reminder, any shorter prefix of a string is lexicographically smaller.

For example, "ab" is lexicographically smaller than "aba".
A leaf of a node is a node that has no children.

 

Example 1:


Input: root = [0,1,2,3,4,3,4]
Output: "dba"
Example 2:


Input: root = [25,1,3,1,3,0,2]
Output: "adz"
Example 3:


Input: root = [2,2,1,null,1,0,null,0]
Output: "abc"
 

Constraints:

The number of nodes in the tree is in the range [1, 8500].
0 <= Node.val <= 25
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
218,131/357K
Acceptance Rate
61.1%
Topics
String
Backtracking
Tree
Depth-First Search
Binary Tree
Weekly Contest 122


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
    string smallestFromLeaf(TreeNode* root) {
        string path;
        string ans = "";   // empty means not set yet
        dfs(root, path, ans);
        return ans;
    }

    void dfs(TreeNode* node, string& path, string& ans) {
        if (!node) return;

        // add current character
        path.push_back('a' + node->val);

        // if leaf node
        if (!node->left && !node->right) {
            string leafToRoot = path;
            reverse(leafToRoot.begin(), leafToRoot.end());

            if (ans.empty() || leafToRoot < ans) {
                ans = leafToRoot;
            }
        }

        dfs(node->left, path, ans);
        dfs(node->right, path, ans);

        // backtrack
        path.pop_back();
    }
};




/*


qno 110  https://leetcode.com/problems/balanced-binary-tree/description/

110. Balanced Binary Tree
Easy
Topics

Companies
Given a binary tree, determine if it is height-balanced.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: true
Example 2:


Input: root = [1,2,2,3,3,null,null,4,4]
Output: false
Example 3:

Input: root = []
Output: true
 

Constraints:

The number of nodes in the tree is in the range [0, 5000].
-104 <= Node.val <= 104
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
2,259,173/4M
Acceptance Rate
56.9%
Topics
Tree
Depth-First Search
Binary Tree


*/


class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }

    int height(TreeNode* node) {
        if (!node) return 0;

        int left = height(node->left);
        if (left == -1) return -1;

        int right = height(node->right);
        if (right == -1) return -1;

        if (abs(left - right) > 1) return -1;

        return max(left, right) + 1;
    }
};




/*


qno 3340  https://leetcode.com/problems/check-balanced-string/


3340. Check Balanced String
Easy
Topics

Companies
You are given a string num consisting of only digits. A string of digits is called balanced if the sum of the digits at even indices is equal to the sum of digits at odd indices.

Return true if num is balanced, otherwise return false.

 

Example 1:

Input: num = "1234"

Output: false

Explanation:

The sum of digits at even indices is 1 + 3 == 4, and the sum of digits at odd indices is 2 + 4 == 6.
Since 4 is not equal to 6, num is not balanced.
Example 2:

Input: num = "24123"

Output: true

Explanation:

The sum of digits at even indices is 2 + 1 + 3 == 6, and the sum of digits at odd indices is 4 + 2 == 6.
Since both are equal the num is balanced.
 

Constraints:

2 <= num.length <= 100
num consists of digits only
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
72,311/88K
Acceptance Rate
82.2%
Topics
String
Weekly Contest 422



*/



class Solution {
public:
    bool isBalanced(string num) {
        int evenIdx = 0;
        int oddIdx = 0;

        for(int i=0; i<num.size(); i++) {
            int curr = num[i] - '0';
            if(i % 2 == 0) {
                evenIdx += curr;
            } else {
                oddIdx += curr;
            }
        }

        // if(evenIdx == oddIdx) {
        //     return true;
        // }
        // return false; 

        return evenIdx == oddIdx;
    }
};






/*


qno 3013  https://leetcode.com/problems/divide-an-array-into-subarrays-with-minimum-cost-ii/?envType=daily-question&envId=2026-02-02


Code
Testcase
Testcase
Test Result
3013. Divide an Array Into Subarrays With Minimum Cost II
Hard
Topics

Companies
Hint
You are given a 0-indexed array of integers nums of length n, and two positive integers k and dist.

The cost of an array is the value of its first element. For example, the cost of [1,2,3] is 1 while the cost of [3,4,1] is 3.

You need to divide nums into k disjoint contiguous subarrays, such that the difference between the starting index of the second subarray and the starting index of the kth subarray should be less than or equal to dist. In other words, if you divide nums into the subarrays nums[0..(i1 - 1)], nums[i1..(i2 - 1)], ..., nums[ik-1..(n - 1)], then ik-1 - i1 <= dist.

Return the minimum possible sum of the cost of these subarrays.

 

Example 1:

Input: nums = [1,3,2,6,4,2], k = 3, dist = 3
Output: 5
Explanation: The best possible way to divide nums into 3 subarrays is: [1,3], [2,6,4], and [2]. This choice is valid because ik-1 - i1 is 5 - 2 = 3 which is equal to dist. The total cost is nums[0] + nums[2] + nums[5] which is 1 + 2 + 2 = 5.
It can be shown that there is no possible way to divide nums into 3 subarrays at a cost lower than 5.
Example 2:

Input: nums = [10,1,2,2,2,1], k = 4, dist = 3
Output: 15
Explanation: The best possible way to divide nums into 4 subarrays is: [10], [1], [2], and [2,2,1]. This choice is valid because ik-1 - i1 is 3 - 1 = 2 which is less than dist. The total cost is nums[0] + nums[1] + nums[2] + nums[3] which is 10 + 1 + 2 + 2 = 15.
The division [10], [1], [2,2,2], and [1] is not valid, because the difference between ik-1 and i1 is 5 - 1 = 4, which is greater than dist.
It can be shown that there is no possible way to divide nums into 4 subarrays at a cost lower than 15.
Example 3:

Input: nums = [10,8,18,9], k = 3, dist = 1
Output: 36
Explanation: The best possible way to divide nums into 4 subarrays is: [10], [8], and [18,9]. This choice is valid because ik-1 - i1 is 2 - 1 = 1 which is equal to dist.The total cost is nums[0] + nums[1] + nums[2] which is 10 + 8 + 18 = 36.
The division [10], [8,18], and [9] is not valid, because the difference between ik-1 and i1 is 3 - 1 = 2, which is greater than dist.
It can be shown that there is no possible way to divide nums into 3 subarrays at a cost lower than 36.
 

Constraints:

3 <= n <= 105
1 <= nums[i] <= 109
3 <= k <= n
k - 2 <= dist <= n - 2
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
12,481/31.2K
Acceptance Rate
40.0%
Topics
Array
Hash Table
Sliding Window
Heap (Priority Queue)
Biweekly Contest 122


*/



/*************************************************************** C++ *************************************************/
//Approach (Sliding Window using ordered sets)
//T.C : O(n * log(k)), set operations are logarithmic
//S.C : O(k), set stores (k-1) elements
class Solution {
public:
    typedef long long ll;
    typedef pair<ll, ll> P;

    ll minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();

        set<P> kMinimum; //stores (k-1) minimum elements
        set<P> remaining;

        ll sum = 0; //stores sum of (k-1) min elements

        int i = 1;
        while(i - dist < 1) {
            kMinimum.insert({nums[i], i});
            sum += nums[i];
            if(kMinimum.size() > k-1) {
                P temp = *kMinimum.rbegin();
                sum -= temp.first;
                remaining.insert(temp);
                kMinimum.erase(temp);
            }
            i++;
        }

        ll result = LONG_MAX; //stores min sum of (k-1) elements
        //0, 1, ...... i
        while(i < n) {
            kMinimum.insert({nums[i], i});
            sum += nums[i];

            if(kMinimum.size() > k-1) {
                P temp = *kMinimum.rbegin();
                sum -= temp.first;
                remaining.insert(temp);
                kMinimum.erase(temp);
            }

            result = min(result, sum);

            //shift window
            //i-dist wala element will be removed
            P remove = {nums[i-dist], i-dist};
            if(kMinimum.count(remove)) {
                kMinimum.erase(remove);
                sum -= remove.first;

                if(!remaining.empty()) {
                    P temp = *remaining.begin();
                    kMinimum.insert(temp);
                    sum += temp.first;
                    remaining.erase(temp);
                }
            } else {
                remaining.erase(remove);
            }

            i++;
        }

        return nums[0] + result;
    }
};