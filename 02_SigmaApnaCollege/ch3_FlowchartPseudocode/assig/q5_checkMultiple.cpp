

/*
Question 5 : Flowchart & Pseudocode to print all multiples of 3 from 10 to 50.
Input : none
Output: 12 15 18 21 24 27 30 33 36 39 42 45 48
[Hint: To check if a number is a multiple of 3 we write, num % 3 == 0

*/

#include <iostream>
using namespace std;

void printMultiple() {
    for(int i=10; i<=50; i++) {
        if(i % 3 == 0) {  //multiple of 3
            cout << i << " ";
        }
    }
}


int main() {

    cout << "Print the multiple of 3 between 10 to 50: " << printMultiple() << endl;

    return 0;
}



/*
Your function is void.
👉 void functions do not return anything.

So you cannot use them inside cout <<.
That’s why this will give a compilation error like:
Just call the function separately.


*/

#include <iostream>
using namespace std;

void printMultiple() {
    for(int i = 10; i <= 50; i++) {
        if(i % 3 == 0) {
            cout << i << " ";
        }
    }
}

int main() {

    cout << "Print the multiples of 3 between 10 to 50: ";
    printMultiple();   // just call it
    cout << endl;

    return 0;
}