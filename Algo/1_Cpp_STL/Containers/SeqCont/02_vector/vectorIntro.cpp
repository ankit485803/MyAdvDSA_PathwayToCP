

#include <iostream>
#include <vector>
using namespace std;

// vector is dynamic + resize

/*
c++ container same hi funct use karte h

1. size & capacity
2. push_back & pop_back

3. emplace_back

4. at()  or[]    --- accessing the index of vect

5. front & back



all these fucntion work on TC = O(1) constant time complex
*/




int main() {

    vector<int> myVect;  //0

    myVect.push_back(1);
    myVect.push_back(2);
    myVect.push_back(3);
    myVect.push_back(4);
    myVect.push_back(5);
    myVect.emplace_back(6);  //underworking hai

    myVect.pop_back();  //// Removes the last element (which is 6)

    //printing vect
    for(int val : myVect) {
        cout << val << " ";
    }
    cout << endl;


    //indexing
    cout << "val at index 2 is : " << myVect[2] << " or " << myVect.at(2) << endl;


    //print 1st and last elem
    cout << "Front elem of vect = " << myVect.front() << endl;
    cout << "Last elem of vect = " << myVect.back() << endl;



    //cout << "Size of vector = " << myVect.size() << endl;  
    //cout << "Capacity of vector = " << myVect.capacity() << endl;  

    return 0;
}