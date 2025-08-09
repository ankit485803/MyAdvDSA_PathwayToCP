

#include <iostream>
using namespace std;
#include <vector>


/*

three types of constructors: Non-parametried, parametrized, copy constructor

*/


class Teacher {
private:
    double salary;

public:
    //yah non-parameterized constructor
    Teacher() {
        dept = "Computer Science"; //initilize
    }

    string name;
    string dept;
    string subject;

    void changeDept(string newDept) {
        dept = "CSE";
        
    }

    void setSalary(double s) {  
        salary = s;
    }


    double getSalary() { 
        return salary;
    }


};







    int main() {

        Teacher t1;
        Teacher t2;

        t1.name = "Ankit";
        t1.subject = "C++";
        t1.setSalary(25000);
       

        cout << t1.name << endl;
        cout << t1.getSalary() << endl;

        cout << t1.dept << endl;

        return 0;
    }