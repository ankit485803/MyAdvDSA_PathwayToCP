

/*
https://www.hackerrank.com/contests/codequest-iitp/challenges/tree-height-of-a-binary-tree/



The height of a binary tree is the number of edges between the tree's root and its furthest leaf. For example, the following binary tree is of height :

image
Function Description

Complete the getHeight or height function in the editor. It must return the height of a binary tree as an integer.

getHeight or height has the following parameter(s):

root: a reference to the root of a binary tree.
Note -The Height of binary tree with single node is taken as zero.

Input Format

The first line contains an integer , the number of nodes in the tree.
Next line contains  space separated integer where th integer denotes node[i].data.

Note: Node values are inserted into a binary search tree before a reference to the tree's root node is passed to your function. In a binary search tree, all nodes on the left branch of a node are less than the node value. All values on the right branch are greater than the node value.

Constraints



Output Format

Your function should return a single integer denoting the height of the binary tree.

Sample Input

image

Sample Output

3
Explanation

The longest root-to-leaf path is shown below:



*/






#include <iostream>
#include <algorithm>
using namespace std;

// Define the structure for a binary tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Function to insert a node into a binary search tree
Node* insert(Node* root, int data) {
    if (root == nullptr) {
        return new Node(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }

    return root;
}

// Function to calculate the height of the binary tree
int getHeight(Node* root) {
    if (root == nullptr) {
        return -1; // Base case: empty tree
    }

    // Get the height of left and right subtrees
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    // Return the greater height plus one for the current node
    return 1 + max(leftHeight, rightHeight);
}

int main() {
    int n;
    cin >> n;  // Number of nodes in the tree
    Node* root = nullptr;

    // Insert the nodes into the binary search tree
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        root = insert(root, data);
    }

    // Compute and output the height of the binary tree
    cout << getHeight(root) << endl;

    return 0;
}
