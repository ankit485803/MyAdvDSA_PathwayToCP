


#include <iostream>
#include <string>
using namespace std;



/*

11th Aug 2025 (Monday) Deconstructor-- opposite of constr

deallocating the memory or deleting, automatic call hota hai, dynamie memroy allocation 


company level pe ques puch, 
*/



class Student {
public:
    string name;
    double *cgpaPtr;

    Student(string name, double cgpa) {
        this->name = name;
        cgpaPtr = new double;
        *cgpaPtr = cgpa;
    }

    // Deep copy constructor
    Student(const Student &obj) {
        this->name = obj.name;
        this->cgpaPtr = new double;
        *this->cgpaPtr = *obj.cgpaPtr;
    }




    //destructor banate hai
    ~Student() {
        cout << "Hi, I delete everything bhai \n";
        delete cgpaPtr;  //memory leak problem
    }




    void getInf() {
        cout << "Name: " << name << endl;
        cout << "CGPA: " << *cgpaPtr << endl;
    }
};








int main() {
    Student s1("Saurav Ji GATE", 8.37);
    s1.getInf();

    return 0;
}


