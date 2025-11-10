



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


    void push_back(int val) {   //O(1)
        Node* newNode = new Node(val);

        if(head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_front() {   //O(1)
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

    void pop_back() {    //O(n)
        if(head == NULL) {
            cout << "LL is empty";
            return;
        } else {
            Node* temp = head;
            while(temp->next != tail) {  //search prevNode karo kab tak milta hai tail
                temp = temp->next;
            }
            temp->next = NULL;
            delete tail;
            tail = temp;  //delete ka baad bhi access kar sakte hai
        }
    }

    void insert(int val, int pos) {   //O(n)
        //case1: LessThanZero
        if(pos < 0) {
            cout << "Invalid position \n";
            return;  //kuch mat karo
        }

        //case2: eqToZero
        if(pos == 0) {
            push_front(val);
            return;
        }

        //case3: rest of the cases
        Node* temp = head;

        for(int i=0; i<pos-1; i++) {
            if(temp == NULL) {  //extraCheck for if position greater thanSizeof LL
                cout << "Invalid position";
                return;
            }

        }
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;

    }





    void printLL() {   //O(n)
        Node* temp = head;

        while(temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }


    int search(int key) {  //O(n) time
        Node* temp = head;
        int idx = 0;

        while(temp != NULL) {
            if(temp->data == key) {
                return idx;
            }
            temp = temp->next;
            idx++;

        }
        return -1;
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
    

    l1.push_front(3);             
    l1.push_front(2);             
    l1.push_front(1);     
    
    l1.printLL();

    l1.insert(49, 1);  //insert val 49 at position 1st index
    //cout << l1.search(2) << endl;
    


    return 0;
}


