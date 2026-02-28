
#include <iostream>
using namespace std;
#include <iomanip>   // Needed for setprecision

int main() {
    int age;
    char grad = 'A';    //in singleCollon
    bool isAdult = true;
    float cgpa = 9.21;
    double price = 99.91;

    float PI = 3.14159265359;
    double PI2 = 3.14159265359;

    cout << "Size of int dataType (in bytes) = " << sizeof(int) << endl;
    cout << "Size of char = " << sizeof(char) << endl;
    cout << "Size of bool = " << sizeof(bool) << endl;
    cout << "Size of float = " << sizeof(float) << endl;


    cout << setprecision(12) << "PI = " << PI << endl;
    cout << setprecision(12) << "PI2 = " << PI2 << endl;

    return 0;
}