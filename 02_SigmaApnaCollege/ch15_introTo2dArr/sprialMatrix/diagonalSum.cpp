

/*

19th Sep 2026 (Saturday)

calculate the diagonalSum of given matrix
there are two types of diagonal: primary (principal diag where i==j) and secondary diagonal where j = n-i-1



*/


#include <iostream>
using namespace std;


int diagSum(int mat[][4], int n) {   //tc=O(n^2), sc=O(1) using nestedLoops
    int sum = 0;

    for(int i=0; i<n; i++) {  //rows
        for(int j=0; j<n; j++) {  //cols
            if(i == j) {  //primary diagSum
                sum += mat[i][j];

            } else if(j == n-i-1) {  //secondary diagSum
                sum += mat[i][j];
            }
        } 
    }

    cout << "sum = " << sum << endl;
    return sum;
}   


int main() {
    int mat[4][4] = { {1, 2, 3, 4},
                       {5, 6, 7, 8},
                       {9, 10, 11, 12},
                       {13, 14, 15, 16}};

    diagSum(mat, 4);

    return 0;
}


//optimization  tc=O(N), sc=O(1) using singleLoop
int diagSum(int mat[][4], int n) {
    int sum = 0;

    for(int i=0; i<n; i++) {
        sum += mat[i][i];  //pd    hmko alag se j calculate karne ki zarort nahi hai

        if(i != n-i-1) {
            sum += mat[i][n-i-1];  // sd
        }
    }
    cout << "sum = " << sum << endl;
    return sum; 
}