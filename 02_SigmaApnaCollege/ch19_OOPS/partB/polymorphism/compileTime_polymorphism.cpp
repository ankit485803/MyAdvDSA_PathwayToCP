


/*

Two types of compile time Polymorphism
Function Overloading (LOADING), and Operator overloading


*/


#include <iostream>
#include <string>
using namespace std;

//eg of Function Overloading
class Print {
public:
    void show(int x) {
        cout << "int: " << x << endl;
    }

    void show(string str) {
        cout << "string: " << str << endl;
    }

     
};



int main() {
    Print obj1;
    obj1.show(26);
    obj1.show("apnacollege");


    return 0;
}


//eg operator overloading
class Complex {
    int real;
    int img;  //imaginary part no

public:
    Complex(int r, int i) {
        real = r;
        img = i;
    }

    void showNum() {
        cout << real << " + " << img << "i \n";
    }

    void operator + (Complex &c2) {  //yaha pe hm operator kar rahe h
        int resReal = this->real + c2.real;
        int resImg = this->img + c2.img;
        Complex c3(resReal, resImg);

        cout << "res = ";
        c3.showNum();
    }
};




int main() {
    Complex c1(1, 2);
    Complex c2(3, 4);

    c1.showNum();
    c2.showNum();

    c1 + c2;

    return 0;
}