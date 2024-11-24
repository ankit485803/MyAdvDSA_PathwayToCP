
#include <iostream>
using namespace std;


// 2D arr -- have rows * columns in matrix form


int main() {

    int arr[5] = {1, 2, 3, 4, 5};

    int matrix[4][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};         //2d array
    int rows = 4;
    int cols = 3;


    //accessing cell -- using indexing
    cout << matrix[2][1] << endl; 

    //replace the value of cell
    matrix[2][1] = 18;
    cout << "After removing" <<  matrix[2][1] << endl;


    return 0;
}