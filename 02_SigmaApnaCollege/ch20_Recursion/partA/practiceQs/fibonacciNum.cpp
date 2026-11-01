

/*

1st Nov 2026 (Sunday)

*/

#include <iostream>
using namespace std;


int fibonacci(int n) {
    //baseCase jo pahle se known hai hmko
    if(n == 0 || n == 1) {
        return n;  //0, 1
    }

    return fibonacci(n-1) + fibonacci(n-2);
}


int main() {

    cout << "nth fibonacci num = " << fibonacci(5) << endl;
    return 0;
}