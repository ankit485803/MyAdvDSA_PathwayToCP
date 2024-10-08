// data is a fuel for development

#include <iostream>  
using namespace std;  

//we can find smaller and larger, INT_MAX, INT_MINI

int main() {
    int size = 5;
    int marks[size];

    for(int i=0; i<size; i++) {
        cin >> marks[i];  //taking input from user
    }

    //loops : 0 to size-1
    for(int i=0; i<size; i++) {
        cout << marks[i] << endl;
    }

    return 0;

}