
/*

print the pseudocode 



*/

#include <iostream>
using namespace std;


int main() {
    int a = 32;
    int *ptr = &a;

    char ch = 'A';  //ASCII value of 'A' is 65
    char &cho = ch;  //cho is a reference to ch, so cho and ch are the same variable.

    cho += a;
    *ptr += ch;

    cout << a << " , " << ch << endl;  //wrong 32, A

    return 0;
}


/*
sanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$ g++ sigmaApnaCollege.cpp -o myRunFile.exe && ./myRunFile.exe
129 , a
sanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$

because
cho += a changes 'A' → 'a'.
*ptr += ch adds the ASCII value of 'a' (97) to a (32), giving 129.


*/


git commit -m "feat(sigmaApnaCollege): done with assig all the ques and ready for newChap starts ArrayPartI (ch11)"