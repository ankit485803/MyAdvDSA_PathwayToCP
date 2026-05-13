

/*

Question 4 : Write a function that prints the largest of 3 numbers


*/

#include <iostream>
using namespace std;

// tc=O(1)=sc
int largerAmongThree(int a, int b, int c) {
    if((a >= b) && (a >= c)) {  //case1: for A
        return a;

    } else if((b >= c) && (b >= a)) {  //case2: for B
        return b;

    } else {
        return c;
    } 
}


int main() {
    int a = 2, b = 7, c = 4;

    cout << "Larger these threeNo {" << a << "," << b << "," << c << "} = " << largerAmongThree(a, b, c) << endl; 

    return 0;
}