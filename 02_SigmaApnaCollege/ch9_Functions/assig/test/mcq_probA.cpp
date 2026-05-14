

/*

14th May 2026 (Thursday)  MCQ Test link pdf prob

what will the output of following pogrom 

1. What is the purpose of the ‘const’ keyword in C++?
    It declares a constant variable that cannot be modified after initialization.   (ans)
    It is used as a return type of function when constant values are to be returned.
    It denotes a class that cannot be inherited.
    It creates a copy of a variable for use in a function.

2. C++ is a ________________ language. Fill in the blank.
    Case Sensitive
    Object Oriented
    Statically Typed
    All of the above  (ans)

3. What is the decimal form of 1101001.
    102
    103
    104
    105  (ans)

4. What is the binary form of 45.
    110010
    101101   (ans)
    110100
    101010

5. Identify the correct range of signed char.
    -256 to 255
    -128 to 127  (ans)
    0 to 255
    0 to 127

A char is typically 1 byte = 8 bits.
signed char can represent both positive and negative numbers.    
Range=−2n−1 to 2n−1−1

6. Out of these statements, which ones are incorrect?
    The Brackets () have the highest precedence
    The equal to = operator has the lowest precedence
    The addition operator + and the subtraction operator – have an equal precedence
    The division operator / has comparatively higher precedence as compared to a multiplication operator   (ans)


7. What is the value of tip after executing the following code?
int meal = 5;
int tip = 2;
int total = meal + (meal > 6 ? ++tip : --tip);   

ans: 1, total = 5+1

8. Find the output of the following code.
int ++a = 10;
cout << a << " \n " ;

    101
    Compiler error as ++a is not a valid identifier   (ans)
    100
    none of the above

9. Automatic(Implicit) type conversion is possible in which of the possible cases?
    int to char
    int to long  (ans)
    long to char
    double to int

10. Identify the return type of a method that does not return any value.
    int
    void  (ans)
    double
    none




*/

#include <iostream>
using namespace std;
#include <string>


// progA
void printStarPlus() {
    int count = 1;
    while(count <= 15) {
        cout << (count % 2 == 1 ? "****" : "++++");
        ++count;
    }
    cout << endl;
}


// How many times will “Apna College” be printed
int count = 0;
do {
    cout << "Apna College\n";
    count++;
} while(count < 10);





int main() {
    // call funct

    cout << "output of this starsPlus prog: \n";
    printStarPlus();   //8 times *** and 7 times +++++

    int x = 5;
    x *= (3 + 7);
    cout << x << endl;


    // eg
    int i;
    for(i = 1; i<6; i++) {
        if(i > 3) continue;
    }
    cout << i << endl;

    return 0;
}