


/*

6th May 2026 (Wednesday) Forward Declaration - PARTS of funct
forward declaration: matlab hmne aage aake pahle hi declare kar diya hai

Declaration: the function's name, return type, and parameters (if any)
Definition: the body of function 



*/


int a;  //declare jiske inside abhi garbage values hai
a = 10;  //assign value

//ek hi line mai declare aur assign 
int a = 10;

//eg1
#include <iostream>
using namespace std;

int main() {
    sayHello();

    return 0;
}

void sayHello() {
    cout << "Hello \n";
}


/* this error for this eg1  because compiler works from top to bottom while compiling 

sanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$ g++ sigmaApnaCollege.cpp -o myRunFile.exe && ./myRunFile.exe
sigmaApnaCollege.cpp: In function ‘int main()’:
sigmaApnaCollege.cpp:6:5: error: ‘sayHello’ was not declared in this scope
    6 |     sayHello();
      |     ^~~~~~~~
sanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$


*/



#include <iostream>
using namespace std;

void sayHello();  //hmko declare karna parega forward declaration: matlab hmne aage aake pahle hi declare kar diya hai

int main() {
    sayHello();

    return 0;
}

void sayHello() {
    cout << "Hello \n";
}


/* now output eg2
sanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$ g++ sigmaApnaCollege.cpp -o myRunFile.exe && ./myRunFile.exe
Hello
sanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$

git commit -m "feat(sigmaApnaCollege): covered function returnType and forwardDeclaration concepts (ch9)"
*/