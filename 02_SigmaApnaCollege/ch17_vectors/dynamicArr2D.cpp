

/*

6th Oct 2026 (Tuesday)

2D dynamic memory allocation

STL: 

*/

#include <iostream>
using namespace std;


int main() {
    int rows, cols;
    cout << "enter rows : ";
    cin >> rows;
    cout << "enter cols : ";
    cin >> cols;

    
    int* *matrix = new int*[rows];  //main syntax to allocate memory in 2D arr

    for(int i=0; i<rows; i++) { 
        matrix[i] = new int[cols];
    }


    //data store
    int x = 1;
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            matrix[i][j] = x++;
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // cout << matrix[2][2] << endl;
    // cout << *(* (matrix+2) + 2) << endl;
    

    return 0;
}