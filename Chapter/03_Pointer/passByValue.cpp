
#include <iostream>
#include <vector>
using namespace std;

// pass by value -- concept in cpp

void changeA(int a) {  //pass by value
    a = 20;
}

int main() {
    int a = 10;

    changeA(a);

    cout << "Inside Main Function : " << a << endl;  //20
    return 0;
}