

/*

Friend Class and Function: 
can access private and protected members of other classes in which it is declared as a friend

*/


#include <iostream>
#include <string>
using namespace std;

class A {
    string secret = "secret data";
    friend class B;
    friend void revealSecret(A &obj); 
};

class B {  //become a friend class of A
public:
    void showSecret(A &obj) {
        cout << obj.secret << endl;
    }
};


void revealSecret(A &obj) {
    cout << obj.secret << endl;  //But secret is a string data member, not a function. So, you should access it without parentheses:
}


int main() {
    A a1;
    B b1;

    b1.showSecret(a1);

    return 0;
}