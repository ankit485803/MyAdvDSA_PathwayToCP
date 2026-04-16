

/*


11th April 2026 (Saturday), 16th April 2026 (Thursday)

print the Hollow Rectangle pattern


*****
*   *
*   *
*****

length = 5, breadth = 4 




*/


#include <iostream>
using namespace std;


int main() {
    int leng = 5;  //given
    int breadth = 4;

    for(int i=1; i <= breadth; i++) {  //outerLoop: no of rows which is breadth here
        //twoCases
        //case1: fistRow, or lastRow
        if(i == 1 || i == breadth) {
            for(int j=1; j <= leng; j++) {  //innerLoop: kya print karna hai aur kab tak
                cout << "*";
            }
            cout << endl;

        } else {  //case2: middlePart HOLLOW
            for(int j=1; j <= leng; j++) {
                cout << "*   *";
            }
            cout << endl;
        }


    }

    return 0;
}


/*

^Csanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$ g++ sigmaApnaCollege.cpp -o codeRunFile.exe
sanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$ ./codeRunFile.exe
*****
*   **   **   **   **   *
*   **   **   **   **   *
*****
sanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$



current output

*/




int main() { 
    int leng = 5, breadth = 4;

    for(int i=1; i <= breadth; i++) {

        //case1: firstR, lastR 
        if(i == 1 || i == breadth) {
            for(int j=1; j <= leng; j++) {
                cout << "*";
            }
            cout << endl;

        } else {  //case2: middleR SPACE

            cout << "*";  //fistStar
            for(int j=1; j <= leng-2; j++) {  //give SPACE
                cout << " ";
            }
            cout << "*";  //lastStar 
            cout << endl;  //newLine
        }
    }

    return 0; 
}


//tc=O(l * b), sc=O(1)