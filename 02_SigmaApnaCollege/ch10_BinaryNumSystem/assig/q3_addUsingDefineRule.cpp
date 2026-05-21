

/*

Question 3 : Following are the rules of adding 2 binary digits :
        0 + 0 = 0,carry = 0
        1 + 0 = 1,carry = 0
        0 + 1 = 1,carry = 0
        1 + 1 = 0,carry = 1
So, in math if 2 + 3 = 5, in binary it looks like
  10
+ 11
-----
ans = 101


Using this method, try to add these 2 numbers (63 & 22) in their binary form and
verify that the binary output is equal to the decimal value 85.

myApproach:
step1: create helperFunct to convert decToBin
step2: define customRules of addition  given in prob
step3: summation and check by normal maths approach


*/



#include <iostream>
using namespace std;

// step1: conversion
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


//step2: customRules define


// step3: summation and verification



int main() {
    int a = 63, b = 22;

    return 0;
}



#include <iostream>
using namespace std;

// Convert decimal to binary (as int)
int decToBinary(int num) {
    int binForm = 0;
    int pow = 1;
    while (num > 0) {
        int rem = num % 2;
        binForm += rem * pow;
        pow *= 10;
        num /= 2;
    }
    return binForm;
}

// Add two binary numbers using binary rules
int addBinary(int a, int b) {
    int result = 0;
    int carry = 0;
    int pow = 1;

    while (a > 0 || b > 0 || carry > 0) {
        int bit1 = a % 10;
        int bit2 = b % 10;

        int sum = bit1 ^ bit2 ^ carry; // XOR for sum
        carry = (bit1 & bit2) | (bit2 & carry) | (bit1 & carry); // AND-OR for carry

        result += sum * pow;
        pow *= 10;

        a /= 10;
        b /= 10;
    }

    return result;
}

int main() {
    int a = 63, b = 22;

    int binA = decToBinary(a);
    int binB = decToBinary(b);

    cout << "Binary of " << a << " = " << binA << endl;
    cout << "Binary of " << b << " = " << binB << endl;

    int binSum = addBinary(binA, binB);
    cout << "Binary Sum = " << binSum << endl;

    int decimalSum = a + b;
    cout << "Decimal Sum = " << decimalSum << endl;

    return 0;
}



/*
output

sanja@IITP:~$ cd /mnt/c/Users/sanja/Desktop/LabSession/
sanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$ notepad sigmaApnaCollege.cpp
^Csanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$ g++ sigmaApnaCollege.cpp -o myRunFile.exe && ./myRunFile.exe
Binary of 63 = 111111
Binary of 22 = 10110
Binary Sum = 1010101
Decimal Sum = 85
sanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$

*/