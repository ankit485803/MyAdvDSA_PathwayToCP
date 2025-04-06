


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





int main() {


    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    Node* root = buildTree(preorder);   // TC=O(n)
    cout << root->data << endl;
    
    cout << root->left->data << endl;
    cout << root->right->data << endl;
    return 0;
}