

/*

Multiple inheritance: two parentClass ke inherit property to child


*/


#include <iostream> 
#include <string>
using namespace std;


class Teacher {
public:
    int salary;
    string subject;
};

class Student {
public:
    int rollNo;
    float cgpa;
};


class TA : public Teacher, public Student {  //yah pe child two parents ke prop ko inherit kar rahe h 
public:
    string name;

};


int main() {
    TA ta1;
    ta1.name = "shardha khapra";
    ta1.subject = "c++";
    ta1.cgpa = 9.1;

    cout << ta1.name << endl;
    cout << ta1.subject << endl;
    cout << ta1.cgpa << endl;

    return 0;
}