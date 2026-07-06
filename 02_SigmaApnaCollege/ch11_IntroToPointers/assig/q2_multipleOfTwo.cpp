

/*

output of multiple of two pseudocode 

Key Concept
    int &a → Reference parameter
    No copy of the variable is created.
    Changes inside the function affect the original variables.


*/

#include <iostream>
using namespace std;


void multipleBy2(int &a, int &b, int &c) {
    a *= 2;
    b *= 2;  //b = b * 2
    c *= 2;
}


int main() {
    int x = 1, y = 2, z = 3;

    multipleBy2(x, y, z);
    
    cout << x << y << z << "\n";   //2, 4, 6  -> 246

    return 0;
}