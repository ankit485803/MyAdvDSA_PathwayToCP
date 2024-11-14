

#include <iostream>
using namespace std;

/* Loop on 2d arr

print all the cell of matrix -- using nested loop concept

*/






int main() {

    int arr[5] = {1, 2, 3, 4, 5};

    int matrix[4][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};         //2d array
    int rows = 4;
    int cols = 3;

    
    // //printing alll cell
    // for(int i=0; i<rows; i++) {
    //     for(int j=0; j<cols; j++) {
    //         cout << matrix[i][j] << " ";  //cout karo cell with space 
    //     }

    //     cout << endl;  //space on each row
    // }


    // cout << endl;





    //input taking
    int matrix2[4][3];

    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            cin >> matrix2[i][j];
        }

    }
    cout << endl;

    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            cout << matrix2[i][j] << " ";  //cout karo cell with space 
        }

        cout << endl;  //space on each row
    }


    cout << endl;

    return 0;
}



/* 2d arr in memory

1. row major
2, column major


*/