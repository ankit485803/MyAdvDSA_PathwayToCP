
#include <iostream>
using namespace std;

// we can apply Linked list in C++ using two ways: from c++ STL with name LIST and from scratch 

/*
LL is a linear data structure that consists of a sequence of nodes. Each node contains data and a pointer (or reference) to the next 
node in the sequence.
 The most commonly used types of linked lists are singly linked lists, doubly linked lists, and circular linked lists.


Four major function of LL:
(i) push front
(ii) push back
(iii) pop front: which delete the value from front side of LL
(iv) pop back


*/


#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // Constructor to initialize the node with a value
    Node(int val) {
        data = val;
        next = NULL;  // Initialize the next pointer to NULL
    }
};

class List {
private:
    Node* head;  // Private member for the head of the list
    Node* tail;  // Private member for the tail of the list

public:
    // Constructor to initialize an empty list
    List() {
        head = tail = NULL;
    }

    // Method to insert a node at the beginning (push_front)
    void push_front(int val) {
        Node* newNode = new Node(val);  // Create a new dynamic node

        if (head == NULL) {
            // If the list is empty, the new node becomes both the head and tail
            head = tail = newNode;
        } else {
            // If the list is not empty, insert the new node at the front
            newNode->next = head;
            head = newNode;
        }
    }

    // Method to insert a node at the end (push_back)
    void push_back(int val) {
        Node* newNode = new Node(val);  // Create a new dynamic node

        if (head == NULL) {
            // If the list is empty, the new node becomes both the head and tail
            head = tail = newNode;
        } else {
            // If the list is not empty, add the new node to the end
            tail->next = newNode;
            tail = newNode;  // Update the tail pointer to the new node
        }
    }


    void pop_front() {
        if(head == NULL) {
            cout << "LL is empty \n";
            return;
        }

        Node* temp = head;
        head = head ->next;
        temp->next = NULL;

        delete temp;
    }

    // Method to print the list
    void printLL() {
        Node* temp = head;

        while (temp != NULL) {
            cout << temp->data << " -> ";  // Print the data of each node
            temp = temp->next;  // Move to the next node
        }
        cout << "NULL" << endl;  // Indicating the end of the list
    }

    void pop_back() {
        if(head == NULL) {
            cout << "LL is empty \n";
            return;
        }

        Node* temp = head;
        while(temp->next != tail) {
            temp = temp->next;

        }

        temp->next = NULL;
        delete tail;
        tail = temp;
    }
};

int main() {
    List ll;

    // Adding nodes at the front
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);

    // Printing the linked list after push_front operations
    cout << "List after push_front operations: ";
    ll.printLL();

    // Adding a node at the back
    ll.push_back(4);

    ll.pop_front();

    // Printing the linked list after push_back operation
    cout << "List after pop_front operation: ";
    ll.printLL();

    ll.pop_back();
    ll.printLL();

    return 0;
}

