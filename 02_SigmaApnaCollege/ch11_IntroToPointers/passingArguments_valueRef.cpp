

/*

19th June 2026 (Friday) Passing Arguments - By value and Reference 



*/


#include <iostream>
using namespace std;


void changeA(int a) {
    a = 20;
    cout << a << "\n";
}


//pass by reference using pointer
void changeA_usingPtr(int ptr) {
    *ptr = 20;
    cout << *ptr << "\n";
}

int main() {
    int a = 10;
    changeA(a);
    changeA_usingPtr(&a);   //ref using ptr

    cout << a << "\n";   //pass by value

    return 0;
}



void changeA_usingRef(int &a) {
    a = 20;
}



git commit -m "feat(sigmaApnaCollege): completed this chap and covered last parts passByvalue and passByRef (ch11)"