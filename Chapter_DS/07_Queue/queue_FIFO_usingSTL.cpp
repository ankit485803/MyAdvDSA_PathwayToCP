
#include <iostream>
using namespace std;
#include <queue>



/*  Queue dataStruc -- first in first out

15th March 2025 (saturday)

there funct: 
 1. push / enqueue: always from the rear or last
 2. pop/dequeue: first
 3. front

all this funct run in the TC = O(1)

be careful from the keyword DEQUE: double ended queue == It allows fast insertion and deletion of elements at both ends, meaning 
you can add or remove elements from both the front and the back efficiently.



*/


int main() {

    queue<int> q;


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