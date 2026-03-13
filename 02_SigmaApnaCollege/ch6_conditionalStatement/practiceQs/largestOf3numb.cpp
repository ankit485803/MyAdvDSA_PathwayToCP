

//print the largest among 3 numb

#include <iostream>
using namespace std;

int main() {
    int numb1 = 2;
    int numb2 = 5;
    int numb3 = -10;

    if(numb1 == numb2 == numb3) {  //case1 for qllEq
        cout << "All the numb are equal" << endl;

    } else if(numb1 > numb2 && numb1 > numb3) {  //case2 for firstNo
        cout << numb1 << endl;

    } else if(numb2 > numb1 && numb2 > numb3) {  //case3: secdNo
        cout << numb2 << endl;
    } else {
        cout << numb3 << endl;
    }
    
    return 0;
}




#include <iostream>
using namespace std;

int main() {
    int numb1 = 2;
    int numb2 = 5;
    int numb3 = -10;

    if(numb1 == numb2 && numb2 == numb3) {   // all equal
        cout << "All the numbers are equal" << endl;

    } else if(numb1 >= numb2 && numb1 >= numb3) {
        cout << "Largest number is: " << numb1 << endl;

    } else if(numb2 >= numb1 && numb2 >= numb3) {
        cout << "Largest number is: " << numb2 << endl;

    } else {
        cout << "Largest number is: " << numb3 << endl;
    }

    return 0;
}