

/*

10th April 2026 (Friday - afterMetaOpenenvHackathon)

as we know the every char or int stored in pc laptop c++ in ASCII value

print the pattern character pyramid

A
BC
DEF
GHIJ

Ankit
convert this prob into simpler 
1
2 3
4 5 6
7 8 9 10




*/


#include <iostream>
using namespace std;

int main() {  //wrong loop logic applied 
    int n = 10;

    for(int i=1; i <= n; i = i+1) {  //outerLoop no of rows
        for(int j=i; j <= i; j++) {  //innerLoop kya print karna hai aur kab tak
            int val = j;
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}


void charPyramid(int n) {
    char ch = 'A';

    for(int i=1; i <= n; i++) {
        for(int j=1; j <= i; j++) {
            cout << ch << " ";
            ch++;
            // cout << ch++;  //postIncrement hai es liye hm esko bhi kar sakte hai
        }
        cout << endl;
    }
}


int main() {
    int n = 4;  //no of rows
    int num = 1; //startingNo

    for(int i=1; i <= n; i++) {
        for(int j=1; j <= i; j++) {
            cout << num << " ";
            num++;  //updatingVal
        }
        cout << endl;
    }

    cout << "Character pyramid: \n";
    charPyramid(n);

    return 0;
}


