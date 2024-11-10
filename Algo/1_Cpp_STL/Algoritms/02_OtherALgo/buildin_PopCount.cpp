


#include <iostream>
using namespace std;

#include <algorithm>
#include <vector>

/*  Count Set Bits -- this is not available for all compiler, only for gcc so not freq used in company

but can used in Competivive progr CP

_builtin_popcount()
_builtin_popcount I ()
_builtin_popcount II ()


long: This is typically used when you need a larger integer range than int. The size of long can vary between systems (usually 4 or 8 bytes).
long long: This guarantees at least 64 bits (8 bytes) and is used for very large integers beyond the range of long.


*/

int main() {
    int n_int = 15;
    long int n_long = 15;
    long long int n_long_long = 15;

    // Count the number of set bits in n
    cout << __builtin_popcount(n_int) << endl;       // Output: 4
    cout << __builtin_popcountl(n_long) << endl;     // Output: 4
    cout << __builtin_popcountll(n_long_long) << endl; // Output: 4

    return 0;
}