

/*

Question 3 : Create a base class Person with attributes name and age. 
Derive a class Student from Person and add an additional attribute studentID. 
Implement a method displayStudentInfo( ) in the Student class to display all details. 

In main function Student class object will be created in this format: 
Student student("Alice", 20, "S12345");

*/


#include <iostream>
using namespace std;


class Person {
public:
    string name;
    int age;

};


//make derived jo inheritance property from person class
class Student : public Person {
    int studentID;
    
    //method bante hai
    void displayStudentInfo() {
        cout << "name: \n";
    }
};



int main() {


    return 0;
}


#include <iostream>
#include <string>
using namespace std;

// Base class
class Person {
protected:
    string name;
    int age;

public:
    Person(string n, int a) {
        name = n;
        age = a;
    }
};

// Derived class
class Student : public Person {
private:
    string studentID;

public:
    // Constructor
    Student(string n, int a, string id) : Person(n, a) {
        studentID = id;
    }

    // Display student information
    void displayStudentInfo() {
        cout << "Student Name: " << name << endl;
        cout << "Student Age: " << age << endl;
        cout << "Student ID: " << studentID << endl;
    }
};

int main() {
    Student student("Alice", 20, "S12345");

    student.displayStudentInfo();

    return 0;
}
