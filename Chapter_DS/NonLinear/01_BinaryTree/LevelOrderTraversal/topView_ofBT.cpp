

#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

/*
Top View of Binary Tree using Level Order Traversal

https://www.hackerrank.com/challenges/tree-top-view/problem

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

static int idx = -1;

Node* buildTree(vector<int> preOrder) {
    idx++;
    if (preOrder[idx] == -1) {
        return NULL;
    }

    Node* root = new Node(preOrder[idx]);
    root->left = buildTree(preOrder);
    root->right = buildTree(preOrder);
    return root;
}

// Top View
void topView(Node* root) {
    if (!root) return;

    queue<pair<Node*, int>> q;   // (Node, Horizontal Distance)
    map<int, int> m;             // HD -> Node's data

    q.push({root, 0});           

    while (!q.empty()) {
        Node* curr = q.front().first;
        int currHD = q.front().second;
        q.pop();

        if (m.find(currHD) == m.end()) {
            m[currHD] = curr->data;
        }

        if (curr->left) {
            q.push({curr->left, currHD - 1});
        }

        if (curr->right) {
            q.push({curr->right, currHD + 1});
        }
    }

    // Print the top view
    for (auto it : m) {
        cout << it.second << " ";
    }
    cout << endl;
}

int main() {
    vector<int> preOrder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node* root = buildTree(preOrder);

    topView(root);

    return 0;
}




//similar ques BottomView
