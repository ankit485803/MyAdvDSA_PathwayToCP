

/*

PostOrder traversal (there are recursive traversal)

doing: left, right, root


*/

#include <iostream>
using namespace std;
#include <vector>



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


int main() {


    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    Node* root = buildTree(preorder);   // TC=O(n)
    
    // preOrder(root);
    // cout << endl;
    
    inOrder(root);
    cout << endl;

    postOrder(root);
    cout << endl;
    
    return 0;
}