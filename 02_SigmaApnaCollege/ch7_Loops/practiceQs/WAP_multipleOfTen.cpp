


/*


21st March 2026 (Satursday)


write a program (WAP) where user can keep entering number till they enter the multiple of 10




*/


#include <iostream>
using namespace std;

int main() {
    int num;
    cout << "Enter and showNumb enjoy, without 10 multiples: ";  //wrongAnkitBhai yah array nahi hai 
    cin >> num;
    
    for(int n : num) {
        if(n % 10 == 10) {
            break;
        }
        cout << n << endl;
    }

    return 0;
}




#include <iostream>
using namespace std;

int main() {
    int num;

    while (true) {
        cout << "Enter a number: ";
        cin >> num;

        if (num % 10 == 0) {
            break;
        }

        cout << "You entered: " << num << endl;
    }

    cout << "You entered a multiple of 10. Program ended." << endl;

    return 0;
}




#include <iostream>
using namespace std;

int main() {
    int num;

    do {
        cout << "Enter a number: ";
        cin >> num;

        if (num % 10 != 0) {
            cout << "You entered: " << num << endl;
        }

    } while (num % 10 != 0);

    cout << "Multiple of 10 entered. Program ended." << endl;

    return 0;
}