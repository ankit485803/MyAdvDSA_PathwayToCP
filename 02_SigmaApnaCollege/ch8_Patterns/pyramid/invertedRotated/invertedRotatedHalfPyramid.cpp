


/*

20th April 2026 (Monday)

draw the pattern Inverted & Rotated Half Pyramid

   *
  **
 ***
****



shardhaDi bolie thi ki kabhi kabhi two or three outerloop ke under two innterloop bhi ho skate hai but apko bigeger prob ko break karte
small mai solve karo easy hoga for patter

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


You should print both spaces and stars on the same line, and only then move to the next line.
Each row = spaces + stars → then newline
*/ 



int main() {
    int n = 4;

    for(int i=1; i <= n; i++) {  //outerLoop no of rows
        //spaces
        for(int s = i; s <= n - 1; s++) {
            cout << " ";
        }
        //cout << endl;  //yaha hmko comments out karna hoga newline because ek to complete nahi hwua ha na es liye Ankit

        //second innerLoop for star
        for(int j = 1; j <= i; j++) {
            cout << "*";
        }
        // move to next line AFTER printing both
        cout << endl;
    }


    return 0;
}



/*
now output
^Csanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$ g++ sigmaApnaCollege.cpp -o codeRunFile.exe
sanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$ ./codeRunFile.exe
   *
  **
 ***
****
sanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$


*/