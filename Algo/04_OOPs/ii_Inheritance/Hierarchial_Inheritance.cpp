




#include <iostream>
using namespace std;
#include <string>


class Person {
public: 
    string name; 
    int age;
};


class Student : public Person {
public: 
    int rollno;

};


class Teacher : public Person {
public: 
    string subject;
 
};





int main() {

    Teacher t1;
    t1.name = "Ankit Kumar Amazon";
    t1.subject = "Software Engg";

    cout << t1.name << endl;
    cout << t1.subject << endl;

    return 0;
}