

/*

String in C++
OOPS: Class, Object, Member Functions & Properties

ye four terms more used like OOPS also in string
i. class: ek entity hoti hai jisko blueprint hoti hai object banane ki 
ii. Object: ek individual entity hota h
iii. Member Function: yah ek class ke function hai usko use karte hai with bahut sare methods 


### PROPERTY of str:
C++ Strings are objects of pre-defined string class in STL.
It have useful member functions.
It are dynamic (their size can change at run time).
It support operators like +, ==, >, < etc.
It are stored contiguously in memory.


okk

*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    string str = "hello";
    cout << str << endl;

    str = "yellow";
    cout << str << endl;  //runTime mai memory allocation change called DYNAMIC  

    return 0;
}


//taking input str like same char
int main() {
    string str;
    getline(cin, str);

    cout << "your entered string : " << str << endl;
    cout << "size = " << str.length() << endl;

    cout << str[0] << endl;
    cout << str[1] << endl;  //iterate each str index like char 
    cout << str[2] << endl;

    return 0;
}