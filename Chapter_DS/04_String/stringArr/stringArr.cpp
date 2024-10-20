

#include <iostream>
#include <cstring> // For strlen
using namespace std;


// string myStr = " apna college", yah esmai size defined karne ki jarurat nahi hoti h, DYNAMIC + contigous in nature hota h

//jis tarh array chapter mai ek kadam aage VECTOR mila, aise hi character array mai STRING mila


int main() {

    string myStr = "apna college";  //dynamic in nature => runtime resize
    cout << myStr << endl;

    myStr = "Hello world";
    cout << myStr << endl;

    string str1 = "apna";
    string str2 = "college";
    
    string str3 = str1 + " " + str2;  //concatenation
    cout << str3 << endl;

    //compare two str, Lexicography means dictorny-wise hm check karte h kon pahle aaye or dabad mai
    string firstName = "Shardha";
    string secName = "Kumari";

    cout << (firstName == secName) << endl;  //if yes then 1, otherwise 0
    cout << (str1 < str2) << endl;
    cout << firstName.length() << endl;

    //input or ouput
    string yourName;
    cout << "Enter your name : " << endl;

    //cin >> yourName;

    getline(cin, yourName);

    cout << "Output : " << yourName << endl;

    return 0;
}