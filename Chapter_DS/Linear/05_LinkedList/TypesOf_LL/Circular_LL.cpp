

#include <iostream>
using namespace std;


/* Circular LL: is similar to singly LL, only diff is that head and tail is dirctly connected with a circular line



*/


class Node {

public: 
    int data;
    Node* next;

    //CONSTRUCTOR
    Node(int val) {
        data = val;
        next = NULL;
    }

};


class CircularList{
    Node* head;
    Node* tail;

public: 
    //we can CONSTRUCTOR here
    CircularList() {
        head = tail = NULL;
    }


    void insertAtHead(int val) {
        Node* newNode = new Node(val);

        if(tail == NULL) {  //yaha aap Head or tail kuch bhi de sakte ho our circular LL is empty 
            head = tail = newNode;
            tail->next = head;
        } else {
            newNode->next = head;
            head = newNode;
            tail->next = head;
        }
    }

    void print() {
        if(head == NULL) return;

        cout << head->data << " -> ";
        Node* temp = head->next;

        while(temp != head) {  
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << head->data << endl;
        
    }

    void insertAtTail(int val) {
        Node* newNode = new Node(val);

        if(tail == NULL) {  
            head = tail = newNode;
            tail->next = head;
        } else {
            newNode->next = head;
            tail->next = newNode;
            tail = newNode;
        }

    }

    void deleteAtHead() {

        //case1: when LL is empty
        if(head == NULL) return;

        //case2: when LL have single node
        else if(head == tail) {  
            delete head;  //directly FREE karo HEAD
            head = tail = NULL;

        //case3: if LL have 2 or more node
        } else {
            Node* temp = head;
            head = head->next;
            tail->next = head;

            temp->next = NULL;
            delete temp;

        }
    } 

    void deleteAtTail() {
        if(head == NULL) return;

        else if(head == tail) {
            delete head;
            head = tail = NULL;

        } else {
            Node* temp = tail;

            Node* prev = head;
            while(prev->next != tail) {
                prev = prev->next;

            }

            tail = prev;
            tail->next = head;

            temp->next = NULL;
            delete temp;
        }
    }
};



/* Funct for Circular LL

1. Insert at Head (IAH) or Inset at Beginning
2.  insert at Tail (IAT)
3. delete at head
4. delete at Tail



*/






int main() {

    CircularList cll;

    // cll.insertAtHead(1);
    // cll.insertAtHead(2);
    // cll.insertAtHead(3);

    cll.insertAtTail(1);
    cll.insertAtTail(2);
    cll.insertAtTail(3);

    cll.print();  //original Circular LL


    //cll.deleteAtHead();
    cll.deleteAtTail();
    cll.print();

    cll.deleteAtTail();
    cll.print();


    return 0;
}