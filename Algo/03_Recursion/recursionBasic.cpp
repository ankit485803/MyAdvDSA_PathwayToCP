

#include <iostream>
using namespace std;


/* Recursion = funct calls itself

backtracking -- means jis raste se gye usi raste se ana 

*/


void printNums(int n) {
    if(n == 1) {
        cout << "1\n";
        return;

    }

    cout << n << " ";
    printNums(n-1);
}




int main() {

    printNums(6);


    return 0;
}

// TC = O(n) = SC