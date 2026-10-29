

/*

29th Oct 2026 (Thursday)

Abstraction (4th pillar of oops)
Hiding all unnecessary details & showing only imp parts is called abstraction

two ways to implement: Abstraction class and Pure Virtual fun

aisa function jiska koi clear definition nahi hota hai called Pure Virtual 


*/


#include <iostream>
#include <string>
using namespace std;

//abstract class
class Shape {
public:
    virtual void draw() = 0;  //pure virtual fun or abstract fun
};


class Circle : public Shape {
public:
    void draw() {
        cout << "draw circle..\n";
    }
};

class Square : public Shape {
public:
    void draw() {
        cout << "draw square..\n";
    }
};



int main() {
    Circle circ1;
    circ1.draw();

    Square squ1;
    squ1.draw();

    Shape s1;
    s1.draw();  //error virtual dega

    return 0;
}