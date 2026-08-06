
/*


1.1 In C++:
Double quotes (" ") are for strings.
Single quotes (' ') are for a single character.

For example:
'A'      // Correct: a character
"Hello"  // Correct: a string


1.2 In c++ arrayName ko internally convert into  POINTER


1.3
for (initialization; condition; update) {
    // body
}


for (int i = n; ; i++) {
An empty condition is treated as always true.
for (int i = n; true; i++) {

or 
int i = n;
while (true) {
    ...
    i++;
}




1.4





*/



//1.1
cout << "Largest Elem = " << maxElem << endl;
cout << "Min = " << min << endl;


//1.2
#include <iostream>
using namespace std;

int main() {
    int a = 5;
    int *ptr = &a;
    cout << ptr << endl;   // 0x...

    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(int);

    cout << *arr << endl;
    cout << *(arr + 1) << endl;  //arr[1] dereference
    cout << *(arr + 2) << endl;  //arr[2]

    return 0;
}



//1.3 src: D:\GitProj\MyAdvDSA_PathwayToCP\0_Arjuna_CP\HappyNewYr26\08_Aug\q6_smallestDivisibleDigitProd.cpp
for (int i = n; ; i++) {
    // Check if i satisfies the condition
    if (prod % t == 0)
        return i;   // Stop as soon as the answer is found
}


//1.4
