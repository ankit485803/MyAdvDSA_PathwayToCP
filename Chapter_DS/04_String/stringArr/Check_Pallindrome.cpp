

#include <iostream>
#include <string>
#include <algorithm> // For std::reverse
using namespace std;

int main() {
    string mystr = "madam"; // You can change this to test other strings

    // Create a copy of the original string
    string reversedStr = mystr;

    // Reverse the copied string
    reverse(reversedStr.begin(), reversedStr.end());




    // Check if the original string is the same as the reversed string
    if (mystr == reversedStr) {
        cout << mystr << " is a palindrome." << endl;
    } else {
        cout << mystr << " is not a palindrome." << endl;
    }



    

    return 0;
}



