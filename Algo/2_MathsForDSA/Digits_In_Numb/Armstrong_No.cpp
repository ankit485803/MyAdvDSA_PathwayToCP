
#include <iostream>
using namespace std;



/* Armstrong Number -- is a sum of cube of each digits is equal to that numb

e.g. 156, 371, 1



*/

bool isArmstrong(int n) {
    int copyN = n;  //make copy of original numb
    int sumOfCubes = 0;

    while(n != 0) {
        int dig = n % 10;
        sumOfCubes += (dig * dig * dig);

        n = n / 10;
    }

    return sumOfCubes == copyN;

}



int main() {

    int n = 153;
    int n2 = 371;
    int n3 = 111;

    if(isArmstrong(n3)) {
        cout << "is a armstong number \n";
    } else {
        cout << "NOT is a armstong number \n";
    }


    return 0;
}