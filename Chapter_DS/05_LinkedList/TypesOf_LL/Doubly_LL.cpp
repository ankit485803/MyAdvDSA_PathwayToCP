
#include <iostream>
using namespace std;


// Type of LL: Singly, Doubly, Circular 


/* In inverview or placement /intern, most ques ask from Singly LL

In singly LL: only have data + next

In doubly LL: have data + next + prev



Q. Diff b/w PUBLIC or PRIVATE class
Ans: Public class ko hm baad mai access karte h, but jab PRIVATE class ho ga to nahi

Hm HEAD or TRAIL two node ko create karte h

*/



class Node {
    public:
        int data;
        Node* next;
        Node* prev;

        //constractor
        Node(int val) {
            data = val;
            next = prev = NULL;
        }
};




//Doubly LL class
class DoublyList {
    Node* head;
    Node* tail;

public:
    DoublyList() {
        head = tail = NULL;
    }

    void push_front(int val) {
        Node* newNode = new Node(val);

        if(head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            newNode->prev = newNode;
            head = newNode;
        }
    }

    void print() {
        Node* temp = head;

        while(temp != NULL) {
            cout << temp->data << " <=> ";
            temp = temp->next;
        }
        cout << "NULL \n";
    };

    void push_back(int val) {
        Node* newNode = new Node(val);

        if(head == NULL) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    };

    void pop_front() {
        if(head == NULL) {     //BASE CASE
            cout << "your DLL is empty";
        }

        Node* temp = head;
        head = head->next;

        if(head != NULL) {
            head->prev = NULL;
        }

        temp->next = NULL;
        delete temp;
        
    };

    void pop_back() {
        if(head == NULL) {
            cout << "DLL is empty \n";
            return;
        }


        Node* temp = tail;
        tail = tail->prev;

        if(tail->next = NULL) {
            tail->next = NULL;
            temp->prev = NULL;
            delete temp;
        }

    };

};


/* Function in Doubly LL

1. push front
2. push back
3. pop front: delete element from front --- means apko delete karana hoga DONO CONNECTION ko
4. pop back
5.




*/


int main() {

    DoublyList dll;

    // dll.push_front(1);
    // dll.push_front(2);
    // dll.push_front(3);

    dll.push_back(1);
    dll.push_back(2);
    dll.push_back(3);

    //dll.pop_front();
    dll.pop_back();



    dll.print();

    
    return 0;
}