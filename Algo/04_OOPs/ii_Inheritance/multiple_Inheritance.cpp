

#include <iostream>
using namespace std;
#include <string>


/*

Multiple inheriance

*/



class Student {
public: 
    string name;
    int rollno;

};


class Teacher {
public: 
    string subject;
    double salary;
};




// TA means teaching assistant
class TA : public Student, public Teacher {

};



int main() {

    TA t1;
    t1.name = "Ankit Kumar Amazon";
    t1.subject = "Software Engg";

    cout << t1.name << endl;
    cout << t1.subject << endl;

    return 0;
}