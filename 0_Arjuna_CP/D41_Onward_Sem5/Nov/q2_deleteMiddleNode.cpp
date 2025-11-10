
#include <iostream>
using namespace std;


/*

10th Nov 2025 (Monday) revise concepts LL and solve min 5q easyLevel


LL is Linear DS, dynamiceNature, non-contigious memoryAllocation, vairableSize
we need two class for constructe lL: Node class and List class and linked both them

inserate and search for tomarrow



*/



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

    void pop_front() {
        if(head == NULL) {
            cout << "LL is empty";
        } else {
            Node* temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
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

    l1.


    return 0;
}




/*




*/