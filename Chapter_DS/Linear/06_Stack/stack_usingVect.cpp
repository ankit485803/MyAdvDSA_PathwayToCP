

#include <iostream>
using namespace std;
#include <vector>


/*
concepts to run the stack in vector using three funct
(i) push stack = v.push_back(val)
(ii) top stack => return V[V.size() - 1];
(iii) pop stack => v.pop_back()




*/

class Stack {
    vector<int> v;

public: 

    void push(int val) {  //TC=O(1)
        v.push_back(val);
    }


    void pop() { //O(1)
        v.pop_back();

    }

    // int top() { //O(1)
    //     return v[v.size() - 1];

    // }


    int top() { // O(1)
        if (!empty()) {
            return v[v.size() - 1];
        } else {
            throw runtime_error("Stack is empty"); // Or return a sentinel value
        }
    }
    




    //this give true
    bool empty() {
        
        return v.size() == 0;
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