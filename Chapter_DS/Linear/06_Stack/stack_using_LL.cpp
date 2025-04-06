




#include <iostream>
#include <vector>
#include <list>
using namespace std;



/*

concepts to run the stack in vector using three funct
(i) push stack = ll.push_front(val)
(ii) top stack => return ll.front()
(iii) pop stack => ll.pop_front()


*/


class Stack {
    list<int> ll;

public: 

    void push(int val) {  //TC=O(1)
        ll.push_front(val);
    }


    void pop() { //O(1)
        ll.pop_front();
    }



    int top() { // O(1)
        if (!empty()) {
            return ll.front();
        } else {
            throw runtime_error("Stack is empty"); // Or return a sentinel value
        }
    }
    




    //this give true
    bool empty() {
        
        return ll.size() == 0;
    }
   




};




int main() {

    Stack myStack;

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    myStack.push(40);

    while(! myStack.empty()) {
        cout << myStack.top() << " ";
        myStack.pop();
    }

    cout << endl;   // 40, 30, 20, 10
    return 0;
};