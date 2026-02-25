
#include <iostream>
using namespace std;



/*

__builtin_popcount(x) is a built-in function provided by the GCC (GNU Compiler Collection) and Clang compilers that 
returns the number of set bits (bits with a value of 1, also known as the 
"population count" or Hamming weight) in the binary representation of an unsigned integer


*/




int main() {

    int n = 13;  //1101  inBinary

    cout <<  "total no of 1's bits COUNT in "  << n << " is " << _builtin_popcount(n) << endl;


    return 0;   //ans = 3
}