

#include <iostream>
using namespace std;
#include <string>


/*

11th Aug 2025 (Monday) Intro to Inheritance 

When properties & member funct of base class are passed on the derived class.

why use inheritance: code reuseability

*/





class Person {
public: 
    string name;
    int age;

    // Person(string name, int age)  {
    //     this->name = name;
    //     this->age = age;
    // }



    Person() {
        cout << "Parent constructor bhai.. \n";
    }


};




class Student : public Person {
    //name, age ko yah parent class se inheritance kareka

public: 
    string rollno;

    Student() {
        cout << "yah Child constructor.. \n";
    }

    void getInfo() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Roll no: " << rollno << endl;
      
    }
};





int main() {

    Student s1;
    s1.name = "Ankit Contest";
    s1.age = 19;
    s1.rollno = "2313res127";


    s1.getInfo();


    return 0;
}