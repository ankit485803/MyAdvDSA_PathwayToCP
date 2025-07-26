

/*

26th July 2025 (Satursday) Populate Next Right pointer in each node -- LecNo 106


qno 116   https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/



*/


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        //baseCase
        if(root == NULL || root->left == NULL) {
            return root;
        }
        
        queue<Node *> q;
        q.push(root);
        q.push(NULL);  //mark the end of level

        Node* prev = NULL;

        while(q.size() > 0) {
            Node* curr = q.front();
            q.pop();

            if(curr == NULL) {
                if(q.size() == 0) {
                    break;
                }

                q.push(NULL);


            } else {
                if(curr->left != NULL) {
                    q.push(curr-> left);

                }

                if(curr->right != NULL) {
                    q.push(curr->right);

                }

                if(prev != NULL) {
                    prev->next = curr;
                }
            }

            prev = curr;
        }

        return root; 
    }
};

//TC = O(N) = SC