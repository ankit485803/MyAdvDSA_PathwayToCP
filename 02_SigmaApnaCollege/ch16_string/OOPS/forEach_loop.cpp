
git commit -m "feat(sigmaApnaCollege): cover cstring headerFile STL and OOPS for string (ch16_string)" 
/*

2nd Oct 2026 (Friday) For Each in string


*/


#include <iostream>
#include <string>
using namespace std;


int main() {
    string str = "apna college";

    // for(int i=0; i < str.length(); i++) {  //dot operator use karke hai member function se call karne ki liye yah part of OOPS hai bhai
    //     cout << str[i] << " ";
    // }
    // cout << "\n";


    //second ways: jab hmko index ki need nahi ho
    for(char ch : str) {
        cout << ch << " ";
    }
    cout << endl;

    return 0;
}


/* Output same bothWays 
^Csanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$ g++ sigmaApnaCollege.cpp -o myRunFile.exe && ./myRunFile.exe
a p n a   c o l l e g e
sanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$ g++ sigmaApnaCollege.cpp -o myRunFile.exe && ./myRunFile.exe
a p n a   c o l l e g e
sanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$


*/