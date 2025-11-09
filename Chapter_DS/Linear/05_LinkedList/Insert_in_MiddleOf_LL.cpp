

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;  // Initialize the next pointer to NULL
    }
};

class List {
private:
    Node* head;  
    Node* tail;   

public:
    List() {
        head = tail = NULL;
    }

    void push_front(int val) {   // TC=O(1)
        Node* newNode = new Node(val);  // Create a new dynamic node

        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }


    void push_back(int val) {  // O(n)=TC
        Node* newNode = new Node(val);  

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;  
        }
    }


    void pop_front() {  // O(1)=TC
        if(head == NULL) {
            cout << "LL is empty \n";
            return;
        }

        Node* temp = head;
        head = head ->next;
        temp->next = NULL;

        delete temp;
    }


    void insert(int val, int pos) {   //TC=O(n)
        if(pos < 0) {
            cout << "Invalid pos \n";
            return;
        }

        if(pos == 0) {
            push_front(val);
            return;
        }


        Node* temp = head;
        for(int i=0; i<pos-1; i++) {
            if(temp == NULL) {          //extraCheck
                cout << "Invalid pos \n";
                return;
            }
            temp = temp->next;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;

    }

    // Method to print the list
    void printLL() {   //TC=O(n)
        Node* temp = head;

        while (temp != NULL) {
            cout << temp->data << " -> ";  // Print the data of each node
            temp = temp->next;  // Move to the next node
        }
        cout << "NULL" << endl;  // Indicating the end of the list
    }

    void pop_back() {  //O(n)
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

    int search(int key) {
        Node* temp = head;
        int idx = 0;

        while(temp != NULL) {
            if(temp->data == key) {
                return idx;
            }

            temp = temp->next;
            idx++;
        }

        return -1;  //is not found 
    }
};




int main() {
    List ll;

    // Adding nodes at the front
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);

    ll.insert(4,1);  //inset at 1st index and val = 4

    //ll.push_back(4);
    //ll.pop_front();
    //ll.pop_back();

    cout << ll.search(15) << endl;


    ll.printLL();

    return 0;
}
