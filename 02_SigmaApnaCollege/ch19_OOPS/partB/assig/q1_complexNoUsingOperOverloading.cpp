
git commit -m "feat(sigmaApnaCollege): complete partB this chap, along with polymorphism and abstraction (ch19_OOPS)" 
/*

30th Oct 2026 (Friday)

Question 1 : Create a class to store Complex numbers. Using operator overloading, 
create the logic to subtract one complex number from another. 

Note - In Complex numbers, the real part of 1st gets subtracted from the real part of 
2nd number. Same goes for the imaginary part.


*/


#include <iostream>
using namespace std;

class Complex {
    int real, imag;

public:
    // Constructor
    Complex(int r = 0, int i = 0) {
        real = r;
        imag = i;
    }

    // Overloading - operator
    Complex operator-(Complex c) {
        Complex temp;
        temp.real = real - c.real;
        temp.imag = imag - c.imag;
        return temp;
    }

    // Display complex number
    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};




int main() {
    Complex c1(10, 8);
    Complex c2(4, 3);

    Complex c3 = c1 - c2;

    cout << "First Complex Number: ";
    c1.display();

    cout << "Second Complex Number: ";
    c2.display();

    cout << "Subtraction Result: ";
    c3.display();

    return 0;
}


class Complex {
    int real, imag;
public:
    //constructor
    Complex(int r = 0, int i = 0) {
        real = r;
        imag = i;
    }

    //overloading operator -- mainLogic
    Complex operator-(Complex c) {
        Complex temp;
        temp.real = real - c.real;
        temp.imag = imag - c.imag;  //imaginary part ko imag se hi minus kare
        return temp;
    }

    //display complexNo
    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};