


#include <iostream>
using namespace std;
#include <vector>


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

    void setSalary(double s) { //esko SETTER bolte hai
        salary = s;
    }
    double getSalary() { // GETTER function - for validate
        return salary;
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
    t1.setSalary(65000);

    cout << t1.name << endl;
    cout << t1.getSalary() << endl;

    return 0;
}