#include <iostream>
using namespace std;

void patternPrint() {
    for(int i = 4; i >= 1; i--) {
        cout << " * " << endl;
    }
}



void pattern2Print() {  //tc=O(n^2) dues to nestedLoop, sc=O(1)
    for(int i=4; i>=1; i--) {  //outerLoop: controls rows
        for(int j=1; j<=i; j++) {  //innerLoop: no of stars in each rows
            cout << "* ";
        }
        cout << endl;
    }
}

int main() {

    cout << "See pattern:\n";
    pattern2Print();   // Call function normally

    return 0;
}