



// In C++, a vector is a part of the Standard Template Library (STL) and is used to store a dynamic array of elements. 
// Vectors automatically manage memory and allow you to easily add, remove, and access elements. 

#include <iostream>
using namespace std;
#include <vector>

// vector concept in cpp
int main() {

    vector <int> myVec = {100, 1222, 34};  //three vector
    cout << myVec[2] << endl;

    //another form
    vector <int> myVec (5, 0);
    cout << myVec[0] << endl;
    cout << myVec[1] << endl;
    cout << myVec[2] << endl;
    cout << myVec[3] << endl;

    vector <char> myVec = {'a', 'b', 'c', 'd', 'e'};
    cout << "size = " << myVec.size() << endl;

    myVec.pop_back();
    cout << myVec.back();
    cout << myVec.front();
    cout << myVec.at(2);


    for (char val : myVec) {
        cout << val << endl;     //for each loop
    }


    return 0;
}