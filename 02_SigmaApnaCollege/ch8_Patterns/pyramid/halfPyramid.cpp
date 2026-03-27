


/*


27th March 2026 (Friday - HappyRamnavi)


print the half Pyramid pattern


1
12
123
1234


*/


#include <iostream>
using namespace std;

int main() {
    int n = 4;

    for(int i=1; i <= n; i++) {  //outer no of rows
        for(int j=1; j <= i; j++) {  //innerLoop kya printKarna hai
            int val = j;
            cout << val << " ";
        }
        cout << endl;  //newLine
    }

    return 0;
}



/*
Reverse Half Pyramid

1234
123
12
1


*/



#include <iostream>
using namespace std;

int main() {
    int n = 4;

    for(int i = n; i >= 1; i--) {
        for(int j = 1; j <= i; j++) {
            cout << j;
        }
        cout << endl;
    }

    return 0;
}