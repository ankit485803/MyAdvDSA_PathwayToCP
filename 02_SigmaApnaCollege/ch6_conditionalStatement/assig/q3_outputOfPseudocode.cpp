/*

Question3:Whatwillbethevalueofx&yinthefollowingprogram:
int main() {
int a = 63, b = 36;
bool x = (a < b) ? true : false;
int y = (a > b) ? a : b;
cout << x << "," << y << endl;
return 0;
}

*/


#include <iostream>
using namespace std;

int main() {

    int a = 63, b = 36;

    bool x = (a < b) ? true : false;    //x = false means 0
    int y = (a > b)  ? a : b;    //y = 63

    cout << boolalpha;
    cout << x << "," << y  << endl;   //false, 63

    return 0;
}