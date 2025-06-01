

#include <iostream>
#include <vector>
using namespace std;


/*  1st June 2025 (Sunday) new DS chapter: Binary Search Tree lec no 96

in any BT to search any node, TC = O(n)




BST mai Inorder traversal hmesa sorted order mai hota hai

OPERATION in BST: insert, search, delete, 
Que. How to build BST or inset nodes in BST


*/



class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val) {
            data = val;
            left = right = NULL;
        }
};


Node* insert(Node* root, int val) {
    if(root == NULL) {
        return new Node(val);
    }

    if(val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }

    return root;
}


//kaise check kare
void inorder(Node* root) {
    if(root == NULL) {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);

}




Node* buildBST(vector<int> arr) {  //O(height), jab hmko Balanced BST hoga then TC=O(log N)
    Node* root = NULL;

    for(int val : arr) {
        root = insert(root, val);

    }
    return root;

}


//searching
bool search(Node* root, int key) {  //O(Height)
    if(root == NULL) {
        return false;
    }

    if(root->data == key) {
        return true;

    } else if(key < root->data) {
        return search(root->left, key);

    } else {
        return search(root->right, key);
    }

}









int main() {

    vector<int> arr = {3, 2, 1, 5, 6, 4};

    Node* root = buildBST(arr);
    inorder(root);
    cout << endl;


    //searching if exist return 1 otherwise 0
    cout << search(root, 5);  //1

    return 0;
}