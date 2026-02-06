


/*


6th Feb 2026 (Friday)


qno 1382  https://leetcode.com/problems/balance-a-binary-search-tree/

1382. Balance a Binary Search Tree
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
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
302,726/357.5K
Acceptance Rate
84.7%
Topics
Senior
Divide and Conqu


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




/*


no 3131   https://leetcode.com/problems/find-the-integer-added-to-array-i/description/

3131. Find the Integer Added to Array I
Solved
Easy
Topics

Companies
Hint
You are given two arrays of equal length, nums1 and nums2.

Each element in nums1 has been increased (or decreased in the case of negative) by an integer, represented by the variable x.

As a result, nums1 becomes equal to nums2. Two arrays are considered equal when they contain the same integers with the same frequencies.

Return the integer x.

 

Example 1:

Input: nums1 = [2,6,4], nums2 = [9,7,5]

Output: 3

Explanation:

The integer added to each element of nums1 is 3.

Example 2:

Input: nums1 = [10], nums2 = [5]

Output: -5

Explanation:

The integer added to each element of nums1 is -5.

Example 3:

Input: nums1 = [1,1,1,1], nums2 = [1,1,1,1]

Output: 0

Explanation:

The integer added to each element of nums1 is 0.

 

Constraints:

1 <= nums1.length == nums2.length <= 100
0 <= nums1[i], nums2[i] <= 1000
The test cases are generated in a way that there is an integer x such that nums1 can become equal to nums2 by adding x to each element of nums1.
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
80,230/96.9K
Acceptance Rate
82.8%
Topics
Mid Level
Array
Weekly Contest 395


*/


class Solution {
public:
    int addedInteger(vector<int>& nums1, vector<int>& nums2) {  //tc=O(logN), sc=O(1)
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        return nums2[0] - nums1[0];   //diff of any crosspondingIdx
    }
};




/*


qno 3634  https://leetcode.com/problems/minimum-removals-to-balance-array/?envType=daily-question&envId=2026-02-06

3634. Minimum Removals to Balance Array
Medium
Topics

Companies
Hint
You are given an integer array nums and an integer k.

An array is considered balanced if the value of its maximum element is at most k times the minimum element.

You may remove any number of elements from nums​​​​​​​ without making it empty.

Return the minimum number of elements to remove so that the remaining array is balanced.

Note: An array of size 1 is considered balanced as its maximum and minimum are equal, and the condition always holds true.

 

Example 1:

Input: nums = [2,1,5], k = 2

Output: 1

Explanation:

Remove nums[2] = 5 to get nums = [2, 1].
Now max = 2, min = 1 and max <= min * k as 2 <= 1 * 2. Thus, the answer is 1.
Example 2:

Input: nums = [1,6,2,9], k = 3

Output: 2

Explanation:

Remove nums[0] = 1 and nums[3] = 9 to get nums = [6, 2].
Now max = 6, min = 2 and max <= min * k as 6 <= 2 * 3. Thus, the answer is 2.
Example 3:

Input: nums = [4,6], k = 2

Output: 0

Explanation:

Since nums is already balanced as 6 <= 4 * 2, no elements need to be removed.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109
1 <= k <= 105
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
36,199/89.5K
Acceptance Rate
40.5%
Topics
Senior
Array
Sliding Window
Sorting
Biweekly Contest 162


*/


class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {  //tc=O(n) sliddingTwoPointer, sc=O(1)
        sort(nums.begin(), nums.end());
        int n= nums.size();

        int maxLeng = 1;
        int l = 0;  //leftPointer
        for(int r=0; r<n; r++) {
            while((long long ) nums[r] > (long long) nums[l] * k) {
                l++;  //incr
            }
            maxLeng = max(maxLeng, r - l + 1);
        }

        return n - maxLeng;
    }
};


