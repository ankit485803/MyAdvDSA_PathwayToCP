
#include <iostream>
using namespace std;
#include <vector>


/* queue using LinkedList

1. pop() -- head data
2. push()-- insert data at tail of LL
3. pop()-- delete data from head of LL


*/ 



//create LinkedList
class Node {
    public:
            int data;
            Node* next;

            Node(int val) {
                data = val;
                next = NULL;
            }
};



//create queue
class Queue {
    Node* head;
    Node* tail;

public: 
    Queue() {
        head = tail = NULL;
    }

    //1st funct-push
    void push(int val) {  //insert data at tail--TC=O(1)
        int data;
        data = val;


        Node* newNode = new Node(data);

        if(empty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;

        }


    }

    //2nd fun-pop
    void pop() {  //TC  = O(1)
        if(empty()) {
            cout << "LL is EMPTY \n";
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    //3rd funt--front
    int front() {  //O(1)
        if(empty()) {
            cout << "LL is EMPTY \n";
            return -1;
        }
        return head->data;
    }

    bool empty() {  //O(1)
        return head == NULL;

    }




};





int main() {

    Queue q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);  //1 2 3 4

    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();

    }

    cout << endl;

    return 0;
}