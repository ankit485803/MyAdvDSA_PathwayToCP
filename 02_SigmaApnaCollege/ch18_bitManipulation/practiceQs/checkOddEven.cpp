

/*

method1:  if(num % 2 == 0) even else odd

method2: using bits se hm solve jo faster hota hai
odd: mai rightmost digit -- 1
even:                    -- 0

hn rightmost digit pata karenge through BITMASK  methods se
BITMASK: are used to access specific bits in a byte of data called BIT MASKING

*/



#include <iostream>
using namespace std;


void oddOrEven(int num) {
    if((num & 1) == 0) {  //using BITMASK 
        cout << "even\n";
    } else {
        cout << "odd\n";
    }
}


void oddOrEven(int num) {  //syntax change ifelse condition shorter
    if( ! (num & 1) ) {
        cout << "even\n";
    } else {
        cout << "odd\n";
    }
}


int main() {
    oddOrEven(5);
    oddOrEven(4);

    return 0;
}