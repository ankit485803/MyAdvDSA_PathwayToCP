
#include <iostream>
using namespace std;
#include <vector>



/*
10th April 2025 (Thursday)

Height = max depth, max dist from root to leaf
jab bhi hmko tree ka ques aaye to hmko RECURSION kw tarh sochna hai -- told by Shardha didi

*/


class Node {
    public:
        int data;
        Node* left;
        Node* right;

    //create constructor
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


static int idx = -1;
Node* buildTree(vector<int> preorder) {
    idx++;
    if(preorder[idx] == -1) {
        return nullptr;
    }

    Node* root = new Node(preorder[idx]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);


    return root;
}


void printTree(Node* root) {
    if (root == nullptr) {
        return;
    }

    cout << root->data << " ";
    printTree(root->left);
    printTree(root->right);
}





//height of a tree using RECURSIOVE thinking Ankit -- TC=O(n)
int height(Node* root) {
    if(root == NULL) {
        return 0;
    }

    int leftHt = height(root->left);
    int rightHt = height(root->right);

    return max(leftHt, rightHt) + 1;

}



//count of node-- TC=O(n)
int countNode(Node* root) {

    if(root == NULL) {
        return 0;
    }

    int leftCount = countNode(root->left);
    int rightCount = countNode(root->right);
    return leftCount + rightCount + 1;
}


//sum of node
int sumNode(Node* root) {
    if(root == NULL) {
        return 0;
    }

    int leftSum = sumNode(root->left);
    int rightSum = sumNode(root->right);
    return leftSum + rightSum + root->data;    //pahali bar mai Ankit is missing the current node's own value 
}



int main() {

    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node* root = buildTree(preorder);
 
    cout << "Binary Tree (Preorder Traversal): ";
    printTree(root);
    cout << endl;

    


    //cout << "Height of BT = " << height(root) << endl;
    //cout << "Count Node = " << countNode(root) << endl;
    cout << "Sum of Node = " << sumNode(root) << endl;


}