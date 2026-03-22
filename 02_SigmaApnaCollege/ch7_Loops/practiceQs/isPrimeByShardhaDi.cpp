

/*


hmko ek bhi factors kafi hota hai batane mai wah numb prime hai or nahi


*/


#include <iostream>
using namespace std;
#include <cmath>

int main() {
    int n = 9;

    bool isPrime = true;  //assume pahle se 
    for(int i=2; i <= n-1; i++) {
        if(n % i == 0) {
            isPrime = false;  // i is factor of n; i completely divides n; n is nonPrime
            break;
        }
    }

    // if(isPrime == true) {
    //     cout << "Numb is prime" << endl;
    // } else {
    //     cout << "numb is non-prime" << endl;
    // }


    if(isPrime) {  //yah Ankit bhai ye rahe same hota hai without wrie true because always true
        cout << "Numb is prime" << endl;
    } else {
        cout << "numb is NOT prime" << endl;
    }



    return 0;
}



    bool isPrime = true;  
    for(int i=2; i <= sqrt(n); i++) {   //yah dono same hai sir cmath preprocessor dictory include karna hoga
    for(int i=2; i * i <= n; i++) {   

        if(n % i == 0) {
            isPrime = false;   
            break;
        }
    }