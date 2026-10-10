

/*

Binary SHIFT operator:

Left shift <<
   a << b  :  a* 2^b

Right shift  >>
    a >> b :  a/ 2^b


*/


#include <iostream>
using namespace std;


int main() {
    //left shift
    cout << (7 << 2) << endl;
    cout << (7 >> 2) << endl;  //rightShift

    return 0;
}