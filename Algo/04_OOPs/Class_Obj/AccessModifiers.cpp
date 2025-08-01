
#include <iostream>
using namespace std;
#include <vector>


/*

three ACCESS MODIFIERS 

data = means property or attributes

private: data & methods accessible inside class
public: data & methods accessible to everyone
protected - data & methods accessible inside class & to its derived class -- eska concept upcoming lecture INHERITANT mai clear hoga


By default c++ mai sabhi chiz attribute, member function privae hote hai

*/



class Teacher {
private: 
    double salary;  //yah sirf Accountant team hi access kar sakte hai

public:
    //step1: properity or attribute likhte h
    string name;
    string dept;
    string subject;
    

    //step2: method likhte hai memberFunct
    void changeDept(string newDept) {
        dept = newDept;
    }
};



int main() {

    //step3: ab hm OBJECT creae karte hai
    Teacher t1;
    Teacher t2;

    //value assign: object se propetry ko access karte hai using DOT operator
    t1.name = "Ankit";
    t1.dept = "CSE";
    t1.subject = "OOPs";
    //t1.salary = 50000;


    cout << t1.name << endl;

    return 0;
}