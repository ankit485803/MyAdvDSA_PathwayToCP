
#include <iostream>
using namespace std;

// diagonal sum


// int diagoanlSum(int mat[][4], int n) {  //TC=O(n^2) because of nested loop
//     int sum = 0;

//     for(int i=0; i<n; i++) {
//         for(int j=0; j<n; j++) {
//             if(i == j) {
//                 sum += mat[i][j];
//             } else if(j == n-i-1) {
//                 sum += mat[i][j];
//             }
//         }
//     }

//     return sum;

// }





int diagoanlSum(int mat[][4], int n) {  //TC=O(n) 
    int sum = 0;

    //primary diag (PD) = j = i
    // SD = j = n-i-1

    for(int i=0; i<n; i++) {
        sum += mat[i][i];

        if(i != n-i-1) {    //not again sum common elem
            sum += mat[i][n-i-1];
        }
    }

 

    return sum;

}







int main() {

    int matrix[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};         
    int n = 4;

    cout << diagoanlSum(matrix, n) << endl;

    return 0;

}