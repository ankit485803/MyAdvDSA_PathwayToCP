git commit -m "feat(sigmaApnaCollege): solve assig two ques today (ch15_introTo2dArr)" 

/*


Question 2 : Print out the sum of the numbers in the second row of the “nums” array. 
Example : 
Input - int nums[ ][ ] = { {1,4,9}, {11,4,3}, {2,2,3} }; 
Output - 18

*/


#include <iostream>
using namespace std;


int sumRow(int nums[3][3], int n, int m) {  //tc=O(n * m), sc=O(1)
    int sum = 0;

    for(int i=0; i<n; i++) {  //rows
        for(int j=0; j<m; j++) {  //cols
            if(i == 1) {  //specially 2nd row calculate reqForProb
                sum += nums[i][j];
            }
        }
    }

    cout << "sum of 2nd row elem = " << sum << endl;
    return sum;
}



int main() {
    int nums[3][3] = { {1, 4, 9},
                       {11, 4, 3},
                       {2, 2, 3}};

    
    sumRow(nums, 3, 3);

    return 0;
}


int sumRow(int nums[3][3], int n, int m) { //optimize tc=O(m), sc=O(1) only because hmko given row two fix only change cols

    int sum = 0;

    for(int j = 0; j < m; j++) {
        sum += nums[1][j];   //directly row=1 and cols = j ko pass as input bhai
    }

    cout << "sum of 2nd row elem = " << sum << endl;

    return sum;
}


