

/*
Question 3 : Flowchart & Pseudocode to calculate the LARGEST of 3 Numbers.
Input : a, b, c
Output : Largest of a, b, c

*/


#include <iostream>
using namespace std;

int largerNo(int a, int b, int c) {
    if(a>=b && a>=c) {  //case1 for a
        return a;

    } else if(b>=a && b>=c) {  //case2 for b
        return b; 
    } else {
        return c;
    }
}



int main() {
    int a, b, c;

    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;
    cout << "Enter c: ";
    cin >> c;

    cout << "Larger among these 3 numbers = " << largerNo(a, b, c) << endl;
    return 0;
}