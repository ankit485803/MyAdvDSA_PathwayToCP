g++ sigmaApnaCollege.cpp -o codeRunFile.exe && ./codeRunFile.exe

/*

2nd March 2026 (Tuesday) Assigment Operators


5th March 2026 (Thursday) Assig Operators or Compound assigOp

=
+=    or a = a + 5;   a += 5
-=
*=
/=

similar for rest

*/


#include <iostream>
using namespace std;


int main() {

    //assigOp
    int a = 10;

    a += 5;  //a = a+5 => 15
    cout << a << endl;   //15
    a -= 5;  //a = a-5  
    cout << a << endl;  //5

    a *= 5;  
    cout << a << endl;  //50
    a /= 5;
    cout << a << endl;  //2
    

    return 0;
}