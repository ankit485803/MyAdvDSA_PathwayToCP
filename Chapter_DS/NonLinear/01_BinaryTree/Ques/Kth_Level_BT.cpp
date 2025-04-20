



#include <iostream>
using namespace std;
#include <vector>

/*

find the kth Level of BT




*/






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






//Kth Level of BT
void KthLevel(Node* root, int K) {
    if(root == 0) {  //baseCase
        return;
    }

    if(K == 1) {
        cout << root->data << " ";
        return;
    }

    KthLevel(root->left, K-1);
    KthLevel(root->right, K-1);
}





int main() {


    vector<int> preorder = {1, 2, 7, -1, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node* root = buildTree(preorder);   

    KthLevel(root, 3);
 
    return 0;
}