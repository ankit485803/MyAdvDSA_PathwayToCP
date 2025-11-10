
/*

10th Nov 2025 (Monday) revise concepts LL and solve min 5q easyLevel




*/


#include <iostream>
using namespace std;




class Node {
public:

    //everyNode have two thing data and next pointer location
    int data;
    Node* next;

    //initlize this
    Node(int val) {
        data = val;
        next = NULL; //nextPointer ko hmesa NULL se intilize karte hai

    }
};




//secondClass private rakhte jo List ka hoga fir connect both
class List {
private:
    Node* head;
    Node* tail;

public:
    List() {
        head = tail = NULL;
    }



    //basicStructure is ready hm four operations perform karte hai aab
    void push_front(int val) {
        //take newNode jispe sara kam karenge hm directly head mai nai karte h because Backtravse node ko LL mai nahi kar sakte

        Node* newNode = new Node(val);  //DYNAMIC
        //Node* newNode(val);  //STATIC

        if(head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }      
    }


    void push_back(int val) {
        Node* newNode = new Node(val);

        if(head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_front() {
        if(head == NULL) {
            cout << "LL is empty";
            return;

        } else {
            Node* temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
        }
    }

    void pop_back() {
        if(head == NULL) {
            cout << "LL is empty";
            return;
        } else {
            Node* temp = head;
            while(temp->next != tail) {  //search karo kab tak milta hai tail
                temp = temp->next;
            }
            temp->next = NULL;
            delete tail;
            tail = temp;  //delete ka baad bhi access kar sakte hai
        }
    }





    void printLL() {
        Node* temp = head;

        while(temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }



};








int main() {

    //create one list
    List l1;

    l1.push_front(1);
    l1.push_front(2);
    l1.push_front(3);

    l1.printLL();

    l1.push_back(45);
    l1.printLL();

    l1.pop_front();
    l1.printLL();

    l1.pop_back();
    l1.printLL();


    return 0;
}


