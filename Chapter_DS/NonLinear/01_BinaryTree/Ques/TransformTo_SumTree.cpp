
#include <iostream>
using namespace std;
#include <vector>


/*
4th May 2025 (Sunday) Lec no 91



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


//PREORDER
void preOrder(Node* root) {
    if(root == NULL) {
        return;
    }

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}


// Transform to Sum Tree  -- TC=O(n)
int SumTree(Node* root) {
    if(root == NULL) {
        return 0;
    }

    int leftSum = SumTree(root->left);
    int rightSum = SumTree(root->right);

    root->data += leftSum + rightSum;
    return root->data;
}




int main() {


    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    Node* root = buildTree(preorder);   // TC=O(n)
    
    cout << "before conversion : "; 
    preOrder(root);
    cout << endl;
    
     // Call the conversion function
     SumTree(root);


    cout << "after conversion : " ;
    preOrder(root);
    cout << endl;


    
    return 0;
}
