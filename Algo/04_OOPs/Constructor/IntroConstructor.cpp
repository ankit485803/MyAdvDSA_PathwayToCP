

#include <iostream>
using namespace std;
#include <vector>

/*

9th Aug 2025 (Saturday - Happy Rakshabandha) Constructor

Constructor: special method involved automatically at time of object creation. Used for initialisation

features:
i. Same name as Class
ii. Consturctor doesn't have a return type
iii. only called once (automatically), at obj creation
iv Memory allocation happens when constructor is called


three types of constructors: Non-parametried, parametrized, copy constructor




note1: Constructor ko compiler automatice banata hai or coder/programmer apna se banata hai
note2: ek baar hi constructor ko call karte hai
note3: constructor ko aap hmesa PUBLIC bana hai private/protected nahi because interally call jata hai esko
note4: ek class mai SAME NAME ka ek se jada bhi constructor ho skate hai but vairable diff

*/




class Teacher {
private:
    double salary;

public:
    // ek function banate hai jiska return type kuch bhi nahi hai void/int/null
    Teacher() {
        cout << "Hi world, I am consturctor made by ankit bhai coder \n";

        dept = "Computer Science"; // initilize
    }

    string name;
    string dept;
    string subject;

    void changeDept(string newDept) {
        dept = "CSE";
        
    }

    void setSalary(double s) { //esko SETTER bolte hai
        salary = s;
    }


    double getSalary() { // GETTER function - for validate
        return salary;
    }


};







    int main() {
        // yaha jab hm object banat hai, to compiller automatic CONSTRUCTOR CALL katna h
        Teacher t1;
        Teacher t2;

        t1.name = "Ankit";
        t1.subject = "C++";
        t1.setSalary(25000);
       

        cout << t1.name << endl;
        cout << t1.getSalary() << endl;

        cout << t1.dept << endl;

        return 0;
    }