


// print each elel at every level

#include <iostream>
using namespace std;
#include <vector>
#include <queue>


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








//Level Order Traversal
void LevelOrderTrav(Node* root) {
    queue<Node*> q;
    
    q.push(root);
    q.push(NULL);




    while(q.size() > 0) {
        Node* curr = q.front();
        q.pop();

        if(curr == NULL) {
            if(!q.empty()) {
                cout << endl;
                q.push(NULL);
                continue;
            } else {
                break;
            }
        }

        cout << curr->data << " ";

        if(curr->left  !=  NULL) {
            q.push(curr->left);
        }

        if(curr->right != NULL) {
            q.push(curr->right);
        }
    }

    cout << endl;
}



int main() {


    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    Node* root = buildTree(preorder);   // TC=O(n)
    



    cout << "Level Order are as below at each level (LineWise):\n ";

    LevelOrderTrav(root);


    return 0;
}



// now print each elements level-wise

