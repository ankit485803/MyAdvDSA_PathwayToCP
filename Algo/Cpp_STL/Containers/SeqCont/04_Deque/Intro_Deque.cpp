

// Deque: Double Ended Queue, which is very similar to list


//rest all operation of list is similar applicable hai yah bhi

#include <iostream>
using namespace std;
#include <deque>

// Be aler another keyword: Dequeue ==  means kisi bhi Queue se element ko pop karna


int main() {

    deque<int> d = {1, 2, 3, 4, 5};



    for(int val : d) {
        cout << val;
    }
    cout << endl;

    //randon access the index in deques is possible
    cout << d[2] << endl;


    return 0;
}



/* diff b/w List and Deque

In list : is using DLL (doublu linkedlist) 

in Deque:  dynamic arrarys - jise random access possible hai, but not in list

e.g.  d[2] -- correct syntax ,  l[2] -- wrong error dega


*/