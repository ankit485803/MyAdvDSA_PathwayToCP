


#include <iostream>
#include <cstring> // For strlen
using namespace std;



int main() {

    string yourSchoolName = "IIT Patna";

    for(int i=0; i<yourSchoolName.length(); i++) {
        cout << yourSchoolName[i] << " ";
    }

    cout << endl;

    //naming
    string yourName = "Kittu Rani";
    
    for(char ch : yourName) {
        cout << ch << " ";
    }
    cout << endl;


    return 0;
}