
#include <iostream>
using namespace std;

int main() {
    int x = 200, y = 50, z = 100;

    if(x > y && y > z) {  //false
        cout << "Hello \n";
    }
    
    if(z > y && z < x) {  //true
        cout << "c++ \n";
    }

    if((y + 200) < x && (y + 150) < z) {  //false
        cout << "Hello C++ \n";
    }

    return 0;
}