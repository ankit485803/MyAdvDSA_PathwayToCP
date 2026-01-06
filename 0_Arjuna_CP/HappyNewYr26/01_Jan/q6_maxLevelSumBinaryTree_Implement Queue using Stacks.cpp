



/*

6th Jan 2026 (Tuesday)


qno 1161  https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/?envType=daily-question&envId=2026-01-06
conceptUsed: DFS BFS of binaryTree



1161. Maximum Level Sum of a Binary Tree
Solved
Medium
Topics

Companies
Hint
Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.

Return the smallest level x such that the sum of all the values of nodes at level x is maximal.

 

Example 1:


Input: root = [1,7,0,7,-8,null,null]
Output: 2
Explanation: 
Level 1 sum = 1.
Level 2 sum = 7 + 0 = 7.
Level 3 sum = 7 + -8 = -1.
So we return the level with the maximum sum which is level 2.
Example 2:

Input: root = [989,null,10250,98693,-89388,null,null,null,-32127]
Output: 2
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-105 <= Node.val <= 105
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
434,141/640.5K
Acceptance Rate
67.8%
Topics
Tree
Depth-First Search
Breadth-First Search
Binary Tree
Weekly Contest 150




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
    int maxLevelSum(TreeNode* root) {   //tc=O(n)=sc
        if (!root) return 0;

        queue<TreeNode*> q;  //BFS level by level traverseApporach 
        q.push(root);

        int level = 1;
        int ansLevel = 1;
        long long maxSum = LLONG_MIN;

        while (!q.empty()) {
            int size = q.size();
            long long currSum = 0;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                currSum += node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            if (currSum > maxSum) {
                maxSum = currSum;
                ansLevel = level;
            }

            level++;
        }

        return ansLevel;
    }
};





/*


qno 3798  https://leetcode.com/problems/largest-even-number/


3798. Largest Even Number
Easy
Topics

Companies
Hint
You are given a string s consisting only of the characters '1' and '2'.

You may delete any number of characters from s without changing the order of the remaining characters.

Return the largest possible resultant string that represents an even integer. If there is no such string, return the empty string "".

 

Example 1:

Input: s = "1112"

Output: "1112"

Explanation:

The string already represents the largest possible even number, so no deletions are needed.

Example 2:

Input: s = "221"

Output: "22"

Explanation:

Deleting '1' results in the largest possible even number which is equal to 22.

Example 3:

Input: s = "1"

Output: ""

Explanation:

There is no way to get an even number.

 

Constraints:

1 <= s.length <= 100
s consists only of the characters '1' and '2'.
 
Discover more
Knowledge Expansion Resources
Seen this question in a real interview before?
1/5
Yes
No
Accepted
27,641/39.6K
Acceptance Rate
69.8%
Topics
String
Weekly Contest 483



*/



class Solution {
public:
    string largestEven(string s) {  //tc=O(n), sc=O(1)
        int lastTwo = -1;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '2') {
                lastTwo = i;
            }
        }
        
        if (lastTwo == -1) return "";
        
        return s.substr(0, lastTwo + 1);
    }
};





/*


qno 1952  https://leetcode.com/problems/three-divisors/



1952. Three Divisors
Easy
Topics

Companies
Hint
Given an integer n, return true if n has exactly three positive divisors. Otherwise, return false.

An integer m is a divisor of n if there exists an integer k such that n = k * m.

 

Example 1:

Input: n = 2
Output: false
Explantion: 2 has only two divisors: 1 and 2.
Example 2:

Input: n = 4
Output: true
Explantion: 4 has three divisors: 1, 2, and 4.
 

Constraints:

1 <= n <= 104
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
125,892/197.9K
Acceptance Rate
63.6%
Topics
Math
Enumeration
Number Theory
Weekly Contest 252


*/



class Solution {
public:
    bool isThree(int n) {
        int x = sqrt(n);
        
        if (x * x != n) return false;
        
        // Check if x is prime
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) return false;
        }
        
        return x > 1;
    }
};





class Solution {
public:
    bool isThree(int n) {
        int count = 0;

        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                int d1 = i;
                int d2 = n / i;

                if (d1 == d2) {
                    count++;
                } else {
                    count += 2;
                }
            }
        }

        return count == 3;
    }
};





/*



qno 225  https://leetcode.com/problems/implement-stack-using-queues/description/


225. Implement Stack using Queues
Solved
Easy
Topics

Companies
Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).

Implement the MyStack class:

void push(int x) Pushes element x to the top of the stack.
int pop() Removes the element on the top of the stack and returns it.
int top() Returns the element on the top of the stack.
boolean empty() Returns true if the stack is empty, false otherwise.
Notes:

You must use only standard operations of a queue, which means that only push to back, peek/pop from front, size and is empty operations are valid.
Depending on your language, the queue may not be supported natively. You may simulate a queue using a list or deque (double-ended queue) as long as you use only a queue's standard operations.
 

Example 1:

Input
["MyStack", "push", "push", "top", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 2, 2, false]

Explanation
MyStack myStack = new MyStack();
myStack.push(1);
myStack.push(2);
myStack.top(); // return 2
myStack.pop(); // return 2
myStack.empty(); // return False
 

Constraints:

1 <= x <= 9
At most 100 calls will be made to push, pop, top, and empty.
All the calls to pop and top are valid.
 

Follow-up: Can you implement the stack using only one queue?

 
Discover more
Debugging
Resume writing services tech
Seen this question in a real interview before?
1/5
Yes
No
Accepted
1,063,625/1.5M
Acceptance Rate
68.9%
Topics
Stack
Design
Queue




*/




class MyStack {
public:
    queue<int> q1;
    queue<int> q2;

    MyStack() {
        
    }
    
    void push(int x) {  //O(n)
        while(!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        
        q1.push(x);

        while(!q2.empty()) {
            q1.push(q2.front());
            q2.pop();

        }
    }
    
    int pop() {
        int ans = q1.front();
        q1.pop();
        return ans;

    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */





/*
 
 
qno 232  https://leetcode.com/problems/implement-queue-using-stacks/description/
 


232. Implement Queue using Stacks
Solved
Easy
Topics

Companies
Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

Implement the MyQueue class:

void push(int x) Pushes element x to the back of the queue.
int pop() Removes the element from the front of the queue and returns it.
int peek() Returns the element at the front of the queue.
boolean empty() Returns true if the queue is empty, false otherwise.
Notes:

You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.
 

Example 1:

Input
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 1, 1, false]

Explanation
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
myQueue.peek(); // return 1
myQueue.pop(); // return 1, queue is [2]
myQueue.empty(); // return false
 

Constraints:

1 <= x <= 9
At most 100 calls will be made to push, pop, peek, and empty.
All the calls to pop and peek are valid.
 

Follow-up: Can you implement the queue such that each operation is amortized O(1) time complexity? In other words, performing n operations will take overall O(n) time even if one of those operations may take longer.

 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
1,372,906/2M
Acceptance Rate
69.0%
Topics
Stack
Design
Queue
 
 
*/




class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;

    MyQueue() {
        
    }
    
    void push(int x) {
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();

        }

        s1.push(x);

        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        int ans = s1.top();
        s1.pop();
        return ans;

    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */