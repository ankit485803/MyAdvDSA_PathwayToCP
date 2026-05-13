

/*

Question 2 : Write a function to calculate the sum of digits of a number.



*/


#include <iostream>
using namespace std;


int digitSum(int num) {  //tc=O(logN), sc=O(1)
    int sum = 0;
    while(num > 0) {
        sum = sum + (num % 10);  //sum + lastD
        num /= 10;  //removeLastD
    }
    return sum;
}



int main() {
    int num = 236;

    cout << "sum of digits of {" << num << "} = " << digitSum(num) << "\n";

    return 0;
}