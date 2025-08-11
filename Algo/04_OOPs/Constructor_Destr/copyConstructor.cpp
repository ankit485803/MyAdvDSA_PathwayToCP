


#include <iostream>
using namespace std;
#include <vector>


/*

copy constructor: specail constr (default) used to copy properties of one object into another

two types of copy: shallow copy & deep copy
shallow copy= of an obj copies all of the member values from one obj to another
deep copy = not only copies the member values but also makes copies of any dynamically allocated memory that the members point to.


problem aata hai shallow copy mai dynamic memory allocation - heap ke form mai



*/




class Teacher {
private:
    double salary;

public:
    string name;
    string dept;
    string subject;



    //parameterized constructor
    Teacher(string name, string dept, string subject, double salary) {
        this->name = name;
        this->dept = dept;
        this->subject = subject;
        this->salary = salary;
    }


    //apna kudak ka copy constr bana sakte hai
    Teacher(Teacher &originalObj) {   //pass by reference
        cout << "I am custom copy constructor bhai ankit... \n";
        this->name = originalObj.name;
        this->dept = originalObj.dept;
        this->subject = originalObj.subject;
        this->salary = originalObj.salary;
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

    Teacher t1("Ankit", "URSD", "Google SWE", 24000);
    //t1.getInfo();

    // Teacher t2(t1);   //yah default copy constructor invoke ho gaya tha
    // t2.getInfo();


    Teacher t2(t1);   //es bar mera custom copy constr call hoga
    t2.getInfo();


    return 0;
}