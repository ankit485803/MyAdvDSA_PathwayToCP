


/*

Break statement concepts to terminate the loop

💡 Key Concept of break
👉 break immediately terminates the loop, no matter:
    loop condition
    remaining iterations
    Control jumps outside the loop.


*/




#include <iostream>
using namespace std;

int main() {
    int i = 1;

    while(i <= 10) {
        if(i == 3) {
            break;
        }
        cout << i << endl;
        i++;
    }

    cout << "Out of the loop now here used BREAK" << endl;

    return 0;
}



