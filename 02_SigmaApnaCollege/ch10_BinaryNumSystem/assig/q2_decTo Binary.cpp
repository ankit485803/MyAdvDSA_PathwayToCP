

/*

Question 2 : Convert the following decimal numbers into binary forms :
● 25
● 49
● 31
● 88




*/


#include <iostream>
using namespace std;

int decToBinary(int num) {
    int n = num;
    int binForm = 0;
    int pow = 1;  //10^0, 10^1, 10^2,....

    while(n > 0) {
        int rem = n % 2;  //divide by 2
        binForm += rem * pow;
        pow = pow * 10;
        n = n / 2; //decrease Num which give quotient
    }

    return binForm;
}

int main() {
    int num = 25;

    cout << "Binary Form = " << decToBinary(num) << endl;
    return 0;
}



#include <iostream>
using namespace std;

int decToBinary(int num) {
    int n = num;
    int binForm = 0;
    int pow = 1;

    while(n > 0) {
        int rem = n % 2;

        binForm += rem * pow;

        pow = pow * 10;
        n = n / 2;
    }

    return binForm;
}

int main() {

    cout << "25 -> " << decToBinary(25) << endl;
    cout << "49 -> " << decToBinary(49) << endl;
    cout << "31 -> " << decToBinary(31) << endl;
    cout << "88 -> " << decToBinary(88) << endl;

    return 0;
}



/* output
sanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$ g++ sigmaApnaCollege.cpp -o myRunFile.exe && ./myRunFile.exe
Decimal Form of 111111 = 63
Decimal Form of 10110 = 22
Decimal Form of 10011 = 19
Decimal Form of 110010 = 50
sanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$ g++ sigmaApnaCollege.cpp -o myRunFile.exe && ./myRunFile.exe
111111 -> 63
10110 -> 22
10011 -> 19
110010 -> 50
sanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$ g++ sigmaApnaCollege.cpp -o myRunFile.exe && ./myRunFile.exe
Binary Form = 11001
sanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$ g++ sigmaApnaCollege.cpp -o myRunFile.exe && ./myRunFile.exe
25 -> 11001
49 -> 110001
31 -> 11111
88 -> 1011000
sanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$

*/