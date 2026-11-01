

/*

1st  Nov 2026 (Sunday)

Stack Overflow prob due to two reasons:  -- to give SEGMENTATION  FAULT error
oneReason: jab hm infinite recursion code likh dete hai like infiniteLoop
second: without baseCase


*/

#include <iostream>
using namespace std;

void func() {
    cout << "function called..kaam\n";
    func();  //without baseCase
}


int main() {

    func();  //after stack capacity full then give err Segmentation fault (core dumped)

    return 0;
}