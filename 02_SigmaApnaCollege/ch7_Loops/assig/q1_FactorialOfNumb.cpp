


/*


23rd March 2026 (Monday)

Question 1 : WAP to find the Factorial of a number entered by the user.

Hint : factorial of a number (n) = n * (n-1) * (n-2) * (n-3) * ...... * 1
and exists for positive numbers only. We write factorial as n!
So, factorial of 0! = 1, 1! = 1, 2! = 2, 3! = 6, 4! = 24 and so on.
Note- Please do not confuse factorial with NOT EQUAL TO operator, they are not the
same

Q. is factorial of negative number possible
NO
In standard mathematics, the factorial of a negative integer is undefined. 
While the factorial function can be extended to real and complex numbers using the Gamma function (
it still fails to produce a finite value for negative integers, such as -1, -2, -3, etc



*/


#include <iostream>
using namespace std;

int factorialNo(int num) {

    //edgeCases TWO
    if(num < 0) {
        cout << "Invalid inputNo because factorial of negative is not possible";

    } else if(num == 0) {
        return 0;

    } else {
        int fact = 1;
        for(int i=num; i>=1; i--) {
            fact *= i;  //fact = fact * i
        }
        cout << fact << endl;
    }

    
}


int main() {
    int num;
    cout << "Enter numb: ";
    cin >> num;

    cout << "Factorial = " << factorialNo(num) << endl;

    return 0; 
}



/*
^Csanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$ g++ sigmaApnaCollege.cpp -o codeRunFile.exe
sigmaApnaCollege.cpp: In function ‘int factorialNo(int)’:
sigmaApnaCollege.cpp:22:1: warning: control reaches end of non-void function [-Wreturn-type]
   22 | }
      | ^
sanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$


Problems in your code
Function doesn’t return a value in all cases
Your function is declared as int factorialNo(int num) but:
In the negative case → no return
In the positive case → you print but don’t return

That’s why you get:

warning: control reaches end of non-void function


*/



#include <iostream>
using namespace std;

int factorialNo(int num) {

    if(num < 0) {
        cout << "Invalid input because factorial of negative is not possible" << endl;
        return -1;  // indicate error
    } 
    else if(num == 0) {
        return 1;
    } 
    else {
        int fact = 1;
        for(int i = num; i >= 1; i--) {
            fact *= i;
        }
        return fact;   // return ans
    }
}

int main() {
    int num;
    cout << "Enter number: ";
    cin >> num;

    int ans = factorialNo(num);

    if(ans != -1) {
        cout << "Factorial = " << ans << endl;
    }

    return 0; 
}