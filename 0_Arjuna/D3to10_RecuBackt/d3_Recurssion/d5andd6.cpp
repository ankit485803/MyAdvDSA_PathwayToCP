

// question practice on recursion -- sum of 1 + 2+ 3+ ... N


#include <iostream>
using namespace std;


//create a fun to calculate the sum using recurssion
int sum_One_To_N(int n) {

    if(n == 1) {
        return 1;  //BASE CASE
    } else {
        return n + sum_One_To_N(n-1);  //RECURSSIVE CALL
    }
}


int main() {

    int n;
    cout << "Enter the number" ;
    cin >> n;

    cout << "The sum of number from 1 to " << n << " is = " << sum_One_To_N(n) << endl;

    return 0;
}


/*  be Alert !!

No, the current recursive method will not work for negative numbers like -15, because it is designed to calculate the sum of 
positive integers starting from 1 to n. Recursion assumes 
that you're summing up from 1 upwards, and it depends on a positive base case (n = 1), which doesn't apply to negative numbers.




*/