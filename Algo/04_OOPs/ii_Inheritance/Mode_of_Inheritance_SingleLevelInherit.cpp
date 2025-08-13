


#include <iostream>
using namespace std;
#include <string>



/*

13th Aug 2025 (Wednesday) Mode of inheritance: Public, private, protected 

Single level inheritance


*/




class Person {
public: 
    string name;
    int age;

    //jab parametrized constr
    Person(string name, int age)  {
        this->name = name;
        this->age = age;
    }



    Person() {
        cout << "Parent constructor bhai.. \n";
    }


};





class Student : private Person {   //hm change kar rahe hai public to private

public: 
    int rollno;

    Student(string name, int age, int rollno) : Person(name, age) {
        this->rollno = rollno;
    }

    void getInfo() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Roll no: " << rollno << endl;
      
    }
};





int main() {

    Student s1("Abhijeet DSA CP", 22, 2312);
   
    s1.getInfo();

    cout << s1.name;  //yah error dega because hm private banye hai


    return 0;
}