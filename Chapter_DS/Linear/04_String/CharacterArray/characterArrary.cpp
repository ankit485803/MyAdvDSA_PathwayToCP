

// this is Character Array, or called C-String  

#include <iostream>
#include <cstring> // For strlen
using namespace std;


/*

every character koi end karo null char '\0' se otherwise not valid
LITERALS:  means that - which  value not changed in programming


*/




int main() {

    char myStr[] = {'a', 'b', 'c', '\0'};    
    char myStr2[] = "Hello";   //string LITERALS

    int myArr[] = {1, 2, 3};  //print the memory address
    //cout << myArr << endl;


    cout << myStr << endl;  //CONSTANT POINTERS
    
    cout << strlen(myStr) << endl;  //length of string
    cout << myStr2 << endl;
    cout << myStr2[4] << endl;

    return 0;
}