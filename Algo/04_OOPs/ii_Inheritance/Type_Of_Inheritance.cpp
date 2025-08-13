
#include <iostream>
using namespace std;
#include <string>



/*


13th Aug 2025 (Wednesday) Type of inheritance: Single Level and Multi level inheritance

this code is eg of multiple level inheritance

*/


class Person {
public: 
    string name;
    int age;

};



class Student : public Person {   
public: 
    int rollno;

};


class GradStudent : public Student {
public:
    string researchArea;
};



int main() {

    GradStudent s1;
    s1.name = "Nishan Niley";
    s1.researchArea = "NESAC NEDERL data repository";

    cout << s1.name << endl;
    cout << s1.researchArea << endl;

    return 0;
}