
#include <iostream>
using namespace std;
#include <string>
#include <vector>



/*


12th Aug 2025 (Tuesday - Sem5 will be stated from next week Monday)

** Default Member Access
struct → members are public by default.
class → members are private by default.




*/




// struct Node {
//     int data;
//     Node* left;
//     Node* right;
//     Node(int val) {
//         data = val;
//         left = right = nullptr;
//     }
// };





class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};




//find Predecessor & successor in BST

Node* rightMostInLeftSubtree(Node* root) {
    Node* ans;

    while(root != NULL) {
        ans = root;
        root = root->right;
    }

    return ans;
}




Node* leftMostInRightSubtree(Node* root) {
    Node* ans;

    while(root != NULL) {
        ans = root;
        root = root->left;
    }

    return ans;
}





vector<int> getPredSucc(Node* root, int key) {
    // 0th position pe pred, 1st positon succ

    Node* curr = root;
    Node* pred = NULL;
    Node* succ = NULL;


    while(curr != NULL) {
        if(key < curr->data) {
            succ = curr;
            curr = curr->left;

        } else if(key > curr->data) {
            pred = curr;
            curr = curr->right;

        } else {

            if(curr->left != NULL) {
                //inorder pred
                pred = rightMostInLeftSubtree(curr->left);

            } 
            if(curr->right != NULL) {
                //inorder succ
                succ = leftMostInRightSubtree(curr->right);

            }

            break;
        }
    }

    return { pred ? pred->data : -1, succ ? succ->data : -1 };

}


int main() {

    Node* root = new Node(6);
    root->left = new Node(4);
    root->right = new Node(8);
    root->left->left = new Node(1);
    root->left->right = new Node(5);
    root->right->left = new Node(7);
    root->right->right = new Node(9);


    int key = 7;
    vector<int> ans = getPredSucc(root, key);

    cout << "Predecessor: " << ans[0] << endl;
    cout << "Successor: " << ans[1] << endl;


    return 0;
}
