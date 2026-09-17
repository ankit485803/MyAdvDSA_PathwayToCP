

/*

Input and Ouput in 2D array


*/

#include <iostream>
using namespace std;

int main() {
    int arr[3][4];   //initialize 2D arr with 3*4 size rows*cols, n*m
    int n = 3, m = 4;

    for(int i=0; i < n; i++) {  //tc=O(n * m)
        for(int j=0; j < m; j++) {
            cin >> arr[i][j];  
        }
    }


    for(int i=0; i < n; i++) {
        for(int j=0; j < m; j++) {
            cout << arr[i][j] << " ";  
        }
        cout << endl;
    }

    return 0;
}