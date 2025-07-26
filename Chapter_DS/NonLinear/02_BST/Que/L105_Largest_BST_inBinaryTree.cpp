

/*

25th July 2025 (Friday) Lec 105 Largest BST in Binary tree

similar to Validate BST ques

method1: Brute force -- TC = O(n*n)
method2: optimum -- TC=O(n) Linear

*/



#include <iostream>
#include <climits>
using namespace std;

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

class Info {
public:
    int mi, ma, sz;

    Info(int minVal, int maxVal, int size) {
        mi = minVal;
        ma = maxVal;
        sz = size;
    }
};

Info helper(Node* root) {
    if (root == NULL) {
        return Info(INT_MAX, INT_MIN, 0); // Empty tree is BST of size 0
    }

    Info left = helper(root->left);   //Post order traversal
    Info right = helper(root->right);

    // If current subtree is BST
    if (root->data > left.ma && root->data < right.mi) {
        int currMin = std::min(root->data, left.mi);
        int currMax = std::max(root->data, right.ma);
        int currSz = left.sz + right.sz + 1;

        return Info(currMin, currMax, currSz);
    }

    // If not BST, return size of largest BST found so far
    return Info(INT_MIN, INT_MAX, std::max(left.sz, right.sz));
}

int largestBSTinBT(Node* root) {
    Info info = helper(root);
    return info.sz;  // max BST size
}









int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(1);
    root->left->right = new Node(8);
    root->right->right = new Node(7);

    cout << largestBSTinBT(root) << endl; // Expected output: 3 (5,1,8 subtree)

    return 0;
}
