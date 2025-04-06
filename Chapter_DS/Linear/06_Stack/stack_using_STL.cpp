

#include <iostream>
#include <stack>  //yahi STl se
using namespace std;


int main() {

    stack<int> myStack;

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