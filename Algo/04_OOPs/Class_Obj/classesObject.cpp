


#include <iostream>
using namespace std;
#include <vector>



/*

Classes & Objects

syntax kuch aisa hai

class Teacher {
    Properity-- likhte hai
    method -- bhi ankit 

}







Note1: jab hm kisi bhi object se uski property ko access karna ho to DOT OPERATOR ka use karte hai
Note2: 

*/




class Teacher {
    //properties or attributes
    string name;
    string dept;
    string subject;
    double salary;



    //methods matlab ankit function hi h sirf class ke andar likhte hai, aur Method = MemberFunction kahate hai because wah member ban jate hai
    void changeDept(string newDept) {
        dept = newDept;
    }
};






int main() {

    //ab hm OBJECT create karte hai teacher ke liye
    Teacher t1;
    // Teacher t2;
    // Teacher t3;
    // Teacher t4;

    t1.name = "Shardha Khapara";
    t1.dept = "C++ Compter Sci";
    t1.subject = "CSE";
    t1.salary = 25000;

    cout << t1.name << endl;  //abhi error dega PRivate member of teacher

    return 0;
}