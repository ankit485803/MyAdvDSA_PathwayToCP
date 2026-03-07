

/*

7th March 2026 (Satursday)

es chapter mai four things we will read
    if, else
    else if
    ternary operator
    switch


hm yah




Integer → Boolean Conversion

When a number is used inside an if condition, C++ converts it to bool.

Conversion rule:

Number	Boolean Value
0	false
any non-zero value (1, 5, -3, 100)	true

So internally:
if(5)
    if(true)

if(0)
        if(false)



*/


#include <iostream>
using namespace std;

int main() {
    int age;
    cout << "Enter your age: ";
    cin >> age;



    if(age >= 18) {  
        cout << "can vote" << endl;
    } else {
        cout << "cannot vote" << endl;
    }

    if(age >= 45) {
        cout << "contest for election" << endl;
    }


    //note yaha  5 means true interally c++ or -5 because this is nonzero nuber, if(0) then false
    if(5) {
        cout << "can vote" << endl;
    }
    if(true)

    

    return 0;
}




#include <iostream>
using namespace std;

int main() {

    if(5) {
        cout << "TRUE block executed\n";
    }

    if(-10) {
        cout << "Negative numbers are also TRUE\n";
    }

    if(0) {
        cout << "This will not print\n";
    }

    cout << "Program finished\n";

    return 0;
}



/*
This comes from C language design.

Originally:
bool type did not exist in early C
integers were used instead

*/