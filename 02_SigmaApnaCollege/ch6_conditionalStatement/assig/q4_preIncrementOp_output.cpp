

/*

Question4:What’llbetheoutputoftheprogram:
int main() {
int a = 5;
if (++a*5 <= 25) {
cout<<"Hello\n";
} else {
cout<<"Bye\n";
}


*/


#include <iostream>
using namespace std;

int main() {
    int a = 5;

    if(++a *5 <= 25) {   //pre-incrementOp
        cout << "Hello \n";
    } else {
        cout << "Bye \n";
    }

    return 0;
}


/*


⚠️ Important Concept

Difference between pre-increment and post-increment:
| Operator | Meaning                  | Example Result     |
| -------- | ------------------------ | ------------------ |
| `++a`    | increment first          | `a=5 → 6`          |
| `a++`    | use first then increment | `5 then becomes 6` |




*/