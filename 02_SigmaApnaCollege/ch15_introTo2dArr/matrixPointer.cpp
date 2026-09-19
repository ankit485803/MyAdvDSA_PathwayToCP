

/*
19th Sep 2026 (Saturday)

Matrix Pointer:

2D array name behaves as a row pointer

*/

#include <iostream>
using namespace std;


int main() {
    int mat[4][4] = { {1, 2, 3, 4},
                      {5, 6, 7, 8},
                      {9, 10, 11, 12},
                      {13, 14, 15, 16}};

    cout << mat << " = " << &mat[0][0] << endl;
    cout << mat + 1 << " != " << &mat[0][1] << endl;                  
    cout << mat + 1 << " = " << &mat[1][0] << endl;                  

    return 0;
}