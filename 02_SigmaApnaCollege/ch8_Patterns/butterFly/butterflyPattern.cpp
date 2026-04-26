

/*

24th April 2026 (Friday)


print the pattern butterfly stars

*      *
**    **
***  ***
********

********
***  ***
**    **
*      *




*/



#include <iostream>
using namespace std;


int main() {
    int n = 4;

    //upperHalf
    for(int i=1; i <= n; i++) {  //outerLoop no of rows

        //innerLoop three parts
        //partA - STARS
        for(int j=1; j <= i; j++) {
            cout << "*";
        }

        //partB - SPACES
        for(int s = 1;  s <= (2*n - 2*i); s++) {
            cout << " "; 
        }
        
        //partC - STARS and newLine because oneRow complete
        for(int j=1; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }



    //lowerHalf
    for(int i = n; i >= 1; i--) {  //rev outerLoop
        //partA - rev kar do
        for(int j = i; j >= 1; j--) {
            cout << "*";
        }

        //partB SPACES same
        for(int s=1; s <= (2*n - 2*i); s++) {
            cout << " ";
        }

        //partC rev
        for(int j = i; j >= 1; j--) {
            cout << "*";
        }
        cout << endl;
    }




    return 0;
}



/*
output

sanja@IITP:~$ cd /mnt/c/Users/sanja/Desktop/LabSession/
sanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$ notepad sigmaApnaCollege.cpp
^Csanja@IITP:/mnt/c/Users/sanja/Desktop/LabSessiong++ sigmaApnaCollege.cpp -o codeRunFile.exe
sanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$ ./codeRunFile.exe
*      *
**    **
***  ***
********
sanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$




finalOutput
sanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$ g++ sigmaApnaCollege.cpp -o codeRunFile.exe && ./codeRunFile.exe
*      *
**    **
***  ***
********
********
***  ***
**    **
*      *
sanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$

*/



#include <iostream>
using namespace std;

int main() {
    int n = 4;

    // Upper half
    for(int i = 1; i <= n; i++) {

        // Left stars
        for(int j = 1; j <= i; j++) {
            cout << "*";
        }

        // Spaces
        for(int s = 1; s <= (2*n - 2*i); s++) {
            cout << " ";
        }

        // Right stars
        for(int j = 1; j <= i; j++) {
            cout << "*";
        }

        cout << endl;
    }

    // Lower half
    for(int i = n; i >= 1; i--) {

        // Left stars
        for(int j = 1; j <= i; j++) {
            cout << "*";
        }

        // Spaces
        for(int s = 1; s <= (2*n - 2*i); s++) {
            cout << " ";
        }

        // Right stars
        for(int j = 1; j <= i; j++) {
            cout << "*";
        }

        cout << endl;
    }

    return 0;
}



#include <iostream>
using namespace std;

int main() {
    int n = 4;

    // Upper half
    for(int i = 1; i <= n; i++) {

        for(int j = 1; j <= i; j++) {
            cout << "*";
        }

        for(int s = 1; s <= (2*n - 2*i); s++) {
            cout << " ";
        }

        for(int j = 1; j <= i; j++) {
            cout << "*";
        }

        cout << endl;
    }

    // Lower half (avoid duplicate middle row)
    for(int i = n-1; i >= 1; i--) {

        for(int j = 1; j <= i; j++) {
            cout << "*";
        }

        for(int s = 1; s <= (2*n - 2*i); s++) {
            cout << " ";
        }

        for(int j = 1; j <= i; j++) {
            cout << "*";
        }

        cout << endl;
    }

    return 0;
}


//git commit -m "feat(sigmaApnaCollege): done the Butterfly pattern by own Ankit (ch8)"