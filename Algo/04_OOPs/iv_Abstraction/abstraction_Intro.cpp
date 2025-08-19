
#include <iostream>
using namespace std;
#include <string>


/*



19th Aug 2025 (Tuesday) Abstraction
pahle hi read kar liye the


Abstraction: Holding all unnecessary details & showing only the imp points

earlier we have read DATA HIDING concept jo sirf hide karta h, but Abstraction hide bhi karta h aur ho imp h usko dekhta bhi h

ways of use Abstraction: access modifier - private, protected, public
way2: Abstract classes
        * Abstract classes are used to provide a base class from which other classess can be derived
        * They cannot be instantiated and are meant to be inherited
        * Abstract classes are typically used to define an interface for derived classes.



*/




class Shape {  //yah automatic abstract class banta hai

    virtual void draw() = 0;   //pure virtual funct

};


class Circle : public Shape {
public:
    void draw() {
        cout << "Drawing a circle Ankit paintng skills childhood \n";
    }
};



int main() {

    //Shape s1;   //Abstract class ka sirf kam hai blue point ka eska object nahi bana sakte hai
    //s1.draw();  //error throw karega




    Circle c1;
    c1.draw();
    


    return 0;
}