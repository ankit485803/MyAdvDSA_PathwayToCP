

#include <iostream>
using namespace std;
#include <string>


/*

Shallow & deep copy constr

*/



class Student {
public:
    // string name;  //abhi tak static memory allocation 
    // double cgpa;



    string name;  //dynamic Memory allocation
    double *cgpaPtr;



    Student(string name, double cgpa) {
        this->name = name;
        cgpaPtr = new double;
        *cgpaPtr = cgpa;

    }

    //apna default copy constr
    Student(Student &obj) {
        this->name = obj.name;
        this->cgpaPtr = obj.cgpaPtr;

    }



    void getInf() {
        cout << "Name: " << name << endl;
        cout << "CGPA: " << *cgpaPtr << endl;
    }

};



int main() {
    Student s1("Amrtha Di Rakshabandhan", 8.37);
    Student s2(s1); //Ankit
 

    Student s2(s1);  //dfault copy constr
    *(s2.name) = "Ankit Kumar";
    *(s2.cgpaPtr) = 9.2;
    s1.getInf();


    return 0;
}