

/*
One's Complement:

MSE (most sigficiant digit se sign pata chalta hai): 1 then negative and 0 positive

find actual magnitude: using 2's complement

Remember: C++ signed integers use two's-complement representation on modern implementations. The ~ operator flips bits; 
it does not directly calculate the mathematical negative of a number. The formula ~n = -(n+1) explains why ~6 gives -7, not -6


*/

#include <iostream>
using namespace std;


int main() {
    //bitwise operator 
    cout << (~6) << endl;
    cout << (~0) << endl;

    return 0;
}