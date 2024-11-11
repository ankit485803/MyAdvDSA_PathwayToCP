
#include <iostream>
using namespace std;
#include <cmath> 


/* Digits in Numb

3 works: Count, print, & sum of digits



*/


//printing the digits in numb in REVERSE-ORDER
void printDigits(int n) {
    while(n != 0) {
        int digit = n % 10;
        cout << digit << endl;

        n = n / 10;
    }
    
}



//count the digits
void countDigits(int n) {
    int count = 0;

    while(n != 0) {
        int digit = n % 10;   //make sepatate each digits from numb by dividing by 10
        count ++;

        n = n / 10;
    }

    cout << "The count of digits in numb = " << count << endl;
}


//Sum the digits
void sumDigits(int n) {   //TC = O(log10 n) if divide by 3 then TC = O(log3 n)
    int sum = 0;

    while(n != 0) {
        int digit = n % 10;
         sum += digit;

        n = n / 10;
    }

    cout << "The sum of digits in numb = " << sum << endl;
}




int main() {

    int n = 3568;

    //printDigits(n);

    //countDigits(n);
    //sumDigits(n);

 
    cout << (int) (log10(n) + 1) << endl;      //shortcut to print the count of digit

    return 0;

    
}