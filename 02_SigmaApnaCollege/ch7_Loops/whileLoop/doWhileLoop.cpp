


/*

20th March 2026 (Friday)


do while loop: ek to ek baar run hoga hi hoga, but not in case of while loop

 

*/


#include <iostream>
using namespace std;

int main() {
    int i = 1;

    do {
        cout << i << " ";
        i++;
    } while(i <= 5);

    cout << endl;

    return 0;
}





#include <iostream>
using namespace std;

int main() {
    int val = 1;

    //diff b/w doWhile and while loop

    do {
        cout << "apna college in do while loop" << endl;
    } while(val > 5);

   
    while(val > 5) {
        cout << "apna college in while loop " << endl;
    }

    return 0;
}