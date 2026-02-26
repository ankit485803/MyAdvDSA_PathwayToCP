

/*
Question 2 : Flowchart & Pseudocode to calculate the AVERAGE of 3 Numbers.
Input : a, b, c
Output : (a+b+c)/3

*/

#include <iostream>
using namespace std;

int main() {
    int first, secd, third;

    cout << "Enter first no: ";
    cin >> first;
    cout << "Enter second no: ";
    cin >> secd;
    cout << "Enter third no: ";
    cin >> third;

    double avg = (first + secd + third) / 3.0;

    cout << "Average = " << avg << endl;

    return 0;
}