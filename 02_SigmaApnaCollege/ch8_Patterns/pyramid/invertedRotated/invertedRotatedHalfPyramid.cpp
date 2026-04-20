


/*

20th April 2026 (Monday)

draw the pattern Inverted & Rotated Half Pyramid

   *
  **
 ***
****




*/

#include <iostream>
using namespace std;

int main() {
    int n = 4;

    for(int i=1; i <= n; i++) {  //outerLoop no of rows
        //yaha two innerLoop lagega 

        //spaces
        for(int s = i; s <= n - 1; s++) {
            cout << " ";
        }
        cout << endl;

        //second innerLoop for star
        for(int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }


    return 0;
}


/*
currenOutput of thisCode

sanja@IITP:~$ cd /mnt/c/Users/sanja/Desktop/LabSession/
sanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$ notepad sigmaApnaCollege.cpp
^Csanja@IITP:/mnt/c/Users/sanja/Desktop/LabSessiong++ sigmaApnaCollege.cpp -o codeRunFile.exe
sanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$ ./codeRunFile.exe

*

**

***

****
sanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$



*/ 