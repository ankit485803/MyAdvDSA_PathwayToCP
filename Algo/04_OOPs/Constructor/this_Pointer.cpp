

#include <iostream>
using namespace std;
#include <vector>


/*

10th Aug 2025 (Sunday) this pointer

this is a special pointer in c++ that points to the current object
this -> prop is same as (this).prop



recap this concept C:\Users\sanja\Desktop\GitHub_ankit485803\MyAdvDSA_PathwayToCP\Chapter_DS\Linear\03_Pointer\introPointer.cpp


*/



class Teacher {
private:
    double salary;

public:
    string name;
    string dept;
    string subject;



    // non-parameterized 
    Teacher() {
        dept = "Computer Science"; //initilize
    }



    //parameterized constructor
    Teacher(string name, string dept, string subject, double salary) {
        this->name = name;
        this->dept = dept;
        this->subject = subject;
        this->salary = salary;
    }

    


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