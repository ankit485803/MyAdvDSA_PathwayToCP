


/*  deque = double ended queue

1. push -- front, back
2. pop -- back, front
3. front, back



*/




#include <iostream>
#include <deque>
using namespace std;

int main() {
    // Create a deque of integers
    deque<int> dq;


    dq.push_back(1);
    dq.push_back(2);
    dq.push_back(3);


    dq.push_front(4); // Now deque is: 4, 1, 2, 3

    // Output the front and back elements
    cout << "Front: " << dq.front() << ", Back: " << dq.back() << endl;  // Front: 4, Back: 3





    cout << "Size of deque: " << dq.size() << endl;  






    // Check if the deque is empty
    if (dq.empty()) {
        cout << "Deque is empty!" << endl;
    } else {
        cout << "Deque is not empty!" << endl;  // It is not empty
    }

    return 0;
}

