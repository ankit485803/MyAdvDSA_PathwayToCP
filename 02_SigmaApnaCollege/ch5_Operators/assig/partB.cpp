

#include <iostream>
using namespace std;

int main() {
    int x = 10,  y = 5;

    int exp1 = (y * (x/y  + x/y));  //y* (2+2)
    int exp2 = (y * x/y  + y * x/y); //50/y + 50/y

    cout << exp1 << " ";  //20
    cout << exp2 << "\n";  //10+10

    return 0;
}