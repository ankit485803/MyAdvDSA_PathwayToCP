

#include <iostream>
#include <cstring> // For strlen
using namespace std;
#include <algorithm> // For std::reverse



//in char arrray hmko while loop leke karte the, but yaha string wale mai directly C++ STL se karege vvvv very easy

int main() {

    string mystr = "apna college";

    reverse(mystr.begin(), mystr.end());

    cout << mystr << endl;

    return 0;
}
