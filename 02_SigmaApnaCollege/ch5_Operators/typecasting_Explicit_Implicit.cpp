

/*

1. Implicit Conversion (Automatic)
Also called Type Promotion or Coercion.
👉 Happens automatically by the compiler when converting one data type to another.

char → int → long → long long → float → double


2. Explicit Conversion (Type Casting)
When YOU force the conversion.


double d = 3.7;
int x = (int)d;

*/

int x = 10;
double y = x;   // int → double (automatic)

char c = 'A';
int x = c;  // char → int (ASCII value 65)



#include <iostream>
using namespace std;

int main() {

    cout << ((bool)3 + 2) << endl;  //3
    cout << (23.5 + 2 + 'A') << endl;  // 90.5

    return 0;
}