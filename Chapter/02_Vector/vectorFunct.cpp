
#include <iostream>
using namespace std;
#include <vector>

// vector function = size, push_back, pop_back, front, back, at


int main() {
    vector<int> myPushVect;

    cout << "Initial size = " << myPushVect.size() << endl;

    // Adding elements to the vector
    myPushVect.push_back(25); // Example of adding an element
    cout << "Size after push back = " << myPushVect.size() << endl;

    // Printing the elements of the vector
    for (int val : myPushVect) {
        cout << val << endl;
    }

    // Removing the last element
    myPushVect.pop_back();
    cout << "Size after pop back = " << myPushVect.size() << endl;

    return 0;
}