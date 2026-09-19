

/*

Passing matrix pointer to function

ptr[i][j] = *(* (ptr + i) + j)



*/


#include <iostream>
using namespace std;

void func(int mat[][4], int n, int m) {
    cout << "0th row of ptr " << mat << endl;
    cout << "1st row of ptr " << mat + 1 << endl;
    cout << "2nd row of ptr " << mat + 2<< endl;
}


void func2(int (*mat)[4], int n, int m) {
    
}



int main() {
    int mat[4][4] = { {1, 2, 3, 4},
                      {5, 6, 7, 8},
                      {9, 10, 11, 12},
                      {13, 14, 15, 16}};

             
    func(mat, 4, 4);

    return 0;
}