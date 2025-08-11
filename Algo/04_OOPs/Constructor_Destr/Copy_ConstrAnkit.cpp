


#include <iostream>
#include <string>
using namespace std;


/*

jab dynamic allocation memory hota hai to fir Deep copy constr used hota hai

interview mai puch sakte hai

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

    ~Student() {
        delete cgpaPtr;
    }

    void getInf() {
        cout << "Name: " << name << endl;
        cout << "CGPA: " << *cgpaPtr << endl;
    }
};

int main() {
    Student s1("Amrtha Di Rakshabandhan", 8.37);
    Student s2(s1); // Deep copy

    s2.name = "Ankit Kumar";
    *s2.cgpaPtr = 9.2;

    cout << "S1 info:" << endl;
    s1.getInf();
    cout << "S2 info:" << endl;
    s2.getInf();

    return 0;
}



// how to run through powershell window

//PS C:\Users\sanja\Desktop\GitHub_ankit485803\MyAdvDSA_PathwayToCP\Algo\04_OOPs\Constructor> 
// g++ Copy_ConstrAnkit.cpp -o Copy_ConstrAnkit ; .\Copy_ConstrAnkit
