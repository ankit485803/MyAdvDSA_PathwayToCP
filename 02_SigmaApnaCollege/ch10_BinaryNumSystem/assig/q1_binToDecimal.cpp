

/*

20th May 2026 (Wednesday)

*Try to use the proper as well as the shortcut method of powers of 2, as taught in the
lecture.


Question 1 : Convert the following binary numbers into decimal forms :
        ● 111111
        ● 10110
        ● 10011
        ● 110010



*/


#include <iostream>
using namespace std;


int binToDecimal(int num) {
    int n = num;  //makeCopy
    int decForm = 0;
    int pow = 1;  //2^0, 2^1, 2^2, 2^3, ....

    while(n > 0) {
        int lastD = n % 10;
        decForm += lastD * pow;  //mainLogic
        pow = pow * 2;  //updation
        n = n / 10;  //removeLast
    }

    return decForm;
}

int main() {
    int num1 = 111111;
    int num2 = 10110;  //eg2
    int num3 = 10011;
    int num4 = 110010;

    cout << "Decimal Form of " << num1 << " = " << binToDecimal(num1) << endl; 
    cout << "Decimal Form of " << num2 << " = " << binToDecimal(num2) << endl; 
    cout << "Decimal Form of " << num3 << " = " << binToDecimal(num3) << endl; 
    cout << "Decimal Form of " << num4 << " = " << binToDecimal(num4) << endl; 


    return 0;
}



#include <iostream>
using namespace std;

int binToDecimal(int num) {
    int n = num;
    int decForm = 0;
    int pow = 1;

    while(n > 0) {
        int lastD = n % 10;
        decForm += lastD * pow;

        pow = pow * 2;
        n = n / 10;
    }

    return decForm;
}

int main() {

    cout << "111111 -> " << binToDecimal(111111) << endl;
    cout << "10110 -> " << binToDecimal(10110) << endl;
    cout << "10011 -> " << binToDecimal(10011) << endl;
    cout << "110010 -> " << binToDecimal(110010) << endl;

    return 0;
}