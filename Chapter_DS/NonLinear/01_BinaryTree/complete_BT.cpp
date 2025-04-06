

#include <iostream>
using namespace std;
#include <vector>



/*

6th April 2025 (Sunday) IIRS

BUID BINARY TREE
BT ko hm node ke form mai banate h: Node -> left and right



Levels 
Height = level of tree
Subtree = small part


solve (root) {   // using BT recursion
    solve[lefSubTree]
    solve[rightSubTree]

    calculate the solution for the root 
}



preorder matlab root-left-right data hai store

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
}






int main() {


    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};


    return 0;
}