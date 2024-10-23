

#include <iostream>
using namespace std;
#include <queue>


/* Priority Queue -- in deep we will read later, 

Priority queue use interally max heap or min-heap == CBT (complete binary tree)

priority_queue<int> q;


//comparator yaha use karte h, jab hmko ascending or descending order mai data ko sort karna h
priority_queue<int, vector<int>,  greater<int>> q;

some imp operations:
1. push, emplace   -- TC=O(log(n))
2. top  -- O(1)
3. pop  -- O(log(n))   because interally tree build ho rahi h
4. size  
5. empty


we can visualize the priority queue like stack, it's is tree like structure interally




*/



int main() {

    //priority_queue<int> q;

    //reverse order priority 
    priority_queue<int, vector<int>, greater<int>> q; 

    q.push(5);
    q.push(3);
    q.push(10);
    q.push(4);


    //printing
    while(! q.empty()) {
        cout << q.top() << " ";
        q.pop();
    }
    cout << endl;
    


    return 0;
}