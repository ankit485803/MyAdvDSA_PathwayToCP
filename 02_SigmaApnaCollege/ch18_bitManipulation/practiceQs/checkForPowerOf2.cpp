

/*

14th Oct 2026 (Wednesday - fourthPuja Navratri)


*/


#include <iostream>
using namespace std;


bool isPowerOf2(int num) {
    if(!(num & (num-1))) {   //hm bitwise AND & leke with num & (n-1) != 0 then return true waha power of 2 hai
        return true;
    } else {
        return false;
    }
}


int main() {

    cout << isPowerOf2(4) << endl;
    cout << isPowerOf2(16) << endl;
    cout << isPowerOf2(15) << endl;

    return 0;
}