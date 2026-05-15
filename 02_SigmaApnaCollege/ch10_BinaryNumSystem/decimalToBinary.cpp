

/*

convert decimal to binary form
given num = 18

concepts: 
step1: divide by 2 till the num become 1 
step2: put remainder into reverseOrder to binaryForm

*/

#include <iostream>
using namespace std;

int decimalToBinary(int num) {
    int binaryForm = 0;

    while(num > 0) {
        int rem = num % 2;
    }
}

int main() {
    int num = 18;

    cout << "Binary form = " << decimalToBinary(num) << endl;

    return 0;
}


/*
The missing part is:
    Store each remainder.
    Build the binary number in reverse order.
    Reduce the number using num /= 2.

*/



#include <iostream>
#include <cmath>
using namespace std;

int decimalToBinary(int num) {  //tc=O(logN), sc=O(1)
    int binaryForm = 0;
    int place = 0;

    while(num > 0) {
        int rem = num % 2;

        binaryForm += rem * pow(10, place);

        num /= 2;  //So the number is reduced by half every time, no of iteration tc=O(logN)
        place++;
    }

    return binaryForm;
}

int main() {
    int num = 18;

    cout << "Binary form = " << decimalToBinary(num) << endl;

    return 0;
}



/*output
sanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$ g++ sigmaApnaCollege.cpp -o myRunFile.exe && ./myRunFile.exe
decimal form = 18
sanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$ g++ sigmaApnaCollege.cpp -o myRunFile.exe && ./myRunFile.exe
Binary form = 10010
sanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$



*/

git commit -m "feat(sigmaApnaCollege): coverred binaryToDecimal and decimalToBinary concepts (ch10)"