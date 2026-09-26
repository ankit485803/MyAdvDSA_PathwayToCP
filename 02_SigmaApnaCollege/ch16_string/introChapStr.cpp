
git commit -m "feat(sigmaApnaCollege): start newChap and cover basic of char and char array (ch16_string)" 

/*

26th Sep 2026 (Saturday)
three thing we'll read in this chapter: char, char arr[], string c++ STL

char takes 1 byte (8 bits) memory size store in ASCII (American Standard Code for Information Interchange) value encoding 0 and 1 digits
small: 'a'  to 'z'
capital: 'A' to 'Z'
special character: '@', '$', ... etc, '0' to '9'


learn some value
'a' -> 97
'b' -> 98
'c' -> 99
'a' -> 97


'A' -> 65
'B' -> 66
'C' -> 67  and so on..


*/


#include <iostream>
using namespace std;


int main() {
    char ch1 = 'a';
    char ch2 = 'X';
    char ch3 = '%';
    char ch4 = '9';
    char ch5 = '\n';  //next new line \n 
    char ch6 = '\t';  //use to give one tab space

    cout << "ch1 = " << ch1 << endl;
    cout << "size of ch1 in byte = " << sizeof(2 * ch1) << endl;

    return 0;
}


//find position of char in english alphabet: char ch - 'a'   esmail internally TYPE-CONVERSION ho raha hota hai
int main() {
    char ch1 = 'F';
    int pos = ch1 - 'A';  //nth position of F in abc alphabet

    cout << pos << endl;

    return 0;
}