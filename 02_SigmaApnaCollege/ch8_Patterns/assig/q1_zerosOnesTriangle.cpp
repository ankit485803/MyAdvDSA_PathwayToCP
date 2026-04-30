

/*

28th April 2026 (Tuesday)

Question 1 : Print the 0-1 Triangle Pattern.
For n = 5

1
01
101
0101
10101


we observe: at evenIdx 010101 and at oddIdx 10101


Ankit converts inot this simple subProb
1
00
111
0000
11111


*/


#include <iostream>
using namespace std;
#include <string>




int main() {
    int n = 5;

    for(int i=1; i <= n; i++) {  //outerLoop - no of rows
        string ones = "1";
        string zeros = "0";  //yah evenIdx pe

        if(i % 2 == 0) {
            for(int j = 1; j <= i; j++) {  //innerLoop kya print karna hai aur kab tak
                cout <<  zeros;
            }
            cout << endl;

        } else {
            for(int j=1; j <= i; j++) {
                cout << ones;
            }
            cout << endl;
        }
        
    }

    return 0;
}



/*
output for currCode

sanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$ g++ sigmaApnaCollege.cpp -o codeRunFile.exe
sanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$ ./codeRunFile.exe
1
00
111
0000
11111
sanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$


*/




int main() {
    int n = 5;

    for(int i=1; i <= n; i++) {
        for(int j=1; j <= i; j++) {

            if( (i + j) % 2 == 0) {  //evenPlace pe yah hoga combination of i, j
                cout << "1";
            } else {  //Odd
                cout << "0";
            }
        }
        cout << endl;  //newLine dena hoga aab because innerLoop completed onePass
    }

    return 0;
}



/*
output
101101010110101sanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$ g++ sigmaApnaCollege.cpp -o codeRunFile.exe && ./codeRunFile.exe
1
01
101
0101
10101
sanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$ g++ sigmaApnaCollege.cpp -o codeRunFile.exe && ./codeRunFile.exe


🧠 Small Insight (important for interviews)

Instead of %, you can also think:

If row starts with:
odd row → starts with 1
even row → starts with 0
Then just alternate

*/


#include <iostream>
using namespace std;

int main() {
    int n = 5;

    for(int i = 1; i <= n; i++) {
        int start = (i % 2 == 0) ? 0 : 1;

        for(int j = 1; j <= i; j++) {
            cout << start;
            start = 1 - start;  // toggle
        }
        cout << endl;
    }

    return 0;
}