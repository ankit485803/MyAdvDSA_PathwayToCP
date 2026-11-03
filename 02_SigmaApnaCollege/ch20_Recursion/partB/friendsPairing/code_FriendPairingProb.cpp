


/*

3rd Nov 2026 (Tuesday)
find total no of ways in which n friends can be paired up. Each friend can only be paired once


recursion fun relation: f(n) = f(n-1) + (n-1)*f(n-2);
where (n-1) is a choice


*/


#include <iostream>
#include <string>
using namespace std;


int friendsPairing(int n) {
    if(n == 1 || n == 2) {
        return n;
    }

    // //single
    // friendsPairing(n-1);

    // //pair
    // (n-1) * friendsPairing(n-2);

    return friendsPairing(n-1) + (n-1) * friendsPairing(n-2);
}


int main() {

    cout << "no of ways friends can paired = " << friendsPairing(3) << endl;


    return 0;
}