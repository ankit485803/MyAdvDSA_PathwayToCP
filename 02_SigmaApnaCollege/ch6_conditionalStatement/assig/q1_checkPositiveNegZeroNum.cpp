


/*

16th March 2026 (Monday)


Question1:WriteaC++programtogetanumberfromtheuserandprintwhether
it's positive,negative or zero.



*/


#include <iostream>
using namespace std;

int main() {
    int num;
    cout << "Enter num: ";
    cin >> num;

    if(num == 0) {   //numberLine is used here
        cout << "Num is zero" << endl;
    } else if(num > 0) {
        cout << "Num is positive" << endl;
    } else {
        cout << "Num is negative" << endl;
    }



    return 0;
}



#include <iostream>
using namespace std;

int main() {
    int num;

    cout << "Enter number: ";
    cin >> num;

    if (num > 0)
        cout << "Number is positive" << endl;
    else if (num < 0)
        cout << "Number is negative" << endl;
    else
        cout << "Number is zero" << endl;

    return 0;
}