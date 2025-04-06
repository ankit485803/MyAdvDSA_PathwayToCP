

/*

genearlly DFS (depth first search) happen in Preorder, inorder, postorder traversal
wereas BFS (breadth) in Level Order Traversal




🔍 Depth First Search (DFS)
DFS explores as deep as possible before backtracking.

✅ Common DFS Traversals:
Preorder: Root → Left → Right
Inorder: Left → Root → Right
Postorder: Left → Right → Root

📌 Typically implemented using recursion or a stack.









🌊 Breadth First Search (BFS)
BFS explores level by level from the root node.
✅ Known as Level Order Traversal:


Traverses nodes level by level from top to bottom, left to right.
📌 Implemented using a queue.


BFS we do using ITERATIVE approach

*/






#include <iostream>
using namespace std;
#include <vector>
#include <queue>


class Node {
    public:
        int data;
        Node* left;
        Node* right;
    
        //create a CONSTRACTOR
        Node(int val) {
            data  = val;
            left = right = NULL;
        }
    };
    


static int idx = -1;
Node* buildTree(vector<int> preorder) {
    idx++;

    if(preorder[idx] == -1) {
        return NULL;
    }

    Node* root = new Node(preorder[idx]);
    root->left = buildTree(preorder);  //LEFT
    root->right = buildTree(preorder);  //RIGHT


    return root;
}


//PREORDER
void preOrder(Node* root) {
    if(root == NULL) {
        return;
    }

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}


//INORDER using Recurssion  -- TC=O(n)
void inOrder(Node* root) {
    if(root == NULL) {
        return;
    }

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

//postorder -- TC=O(n)
void postOrder(Node* root) {
    if(root == NULL) {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}



//Level Order Traversal
void LevelOrderTrav(Node* root) {
    queue<Node*> q;
    
    q.push(root);

    while(q.size() > 0) {
        Node* curr = q.front();
        q.pop();

        cout << curr->data << " ";

        if(curr->left  !=  NULL) {
            q.push(curr->left);
        }

        if(curr->right != NULL) {
            q.push(curr->right);
        }
    }

    cout << endl;
}



int main() {


    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    Node* root = buildTree(preorder);   // TC=O(n)
    
    cout << "Preorder: ";
    preOrder(root);
    cout << "\nInorder: ";
    inOrder(root);
    cout << "\nPostorder: ";
    postOrder(root);


    cout << "\nLevel Order: ";
    LevelOrderTrav(root);


    return 0;
}



// now print each elements level-wise

// diagonal wise and linewise