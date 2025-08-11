




#include <iostream>
using namespace std;
#include <vector>


/*

three types of constructors: Non-parametried, parametrized, copy constructor

note4: ek class mai SAME NAME ka ek se jada bhi constructor ho skate hai but vairable diff-- Multiple constructor called 
CONSTRUCTOR - OVERLOADING (part of polymorisms)

*/


class Teacher {
private:
    double salary;

public:
    // non-parameterized 
    // Teacher() {
    //     dept = "Computer Science"; //initilize
    // }




    //parameterized constructor
    Teacher(string n, string d, string s, double sal) {
        name = n;
        dept = d;
        subject = s;
        salary = sal;
    }

    
    
    string name;
    string dept;
    string subject;

    void changeDept(string newDept) {
        dept = "CSE";
        
    }

    void getInfo() {
        cout << "Name: " << name << endl; 
        cout << "Dept: " << dept << endl; 
        cout << "Subject: " << subject << endl; 
        cout << "Salary: " << salary << endl; 
    }


};







    int main() {

        Teacher t1("Asfa Siddiqui", "URSD", "Microclimate", 24000);
        t1.getInfo();

        return 0;
    }