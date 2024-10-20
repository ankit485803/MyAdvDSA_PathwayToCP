

#include <iostream>
#include <cstring> // For strlen
using namespace std;

//taking input and output in character arr, hm delimitor dete h taki special char koi enter kar to stop printing


// cin.getline(str, No of char, delimitor); 


int main() {

    char myStr[12]; //must give size of char of empty str

    cout << "Enter the Char array : " ;
    //cin >> myStr;
    cin.getline(myStr, 12);
    //cin.getline(myStr, 100, '$');

    //cout << "Output : " << myStr << endl;

    for(char ch : myStr) {
        cout << ch << " ";
    }
    cout << endl;


    return 0;
}