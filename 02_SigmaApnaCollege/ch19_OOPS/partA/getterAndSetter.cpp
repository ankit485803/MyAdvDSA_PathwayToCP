

/*

26th Oct 2026 (Monday)

Getter & Setter in c++
getter: yah value return karke deta hai from setter

*/


#include <iostream>
#include <string>
using namespace std;


class Student {
    string name;  //bydefault private
    float cgpa;

public:
    void getPercentage() {
        cout << (cgpa * 10) << "% \n";
    }

    //setters
    void setName(string nameVal) {
        name = nameVal;
    }

    void setCgpa(float cgpaVal) {
        cgpa = cgpaVal;
    }


    //getter: yah value return karke deta hai from setter
    string getName() {
        return name;
    }

    float getCgpa() {
        return cgpa;
    }

};


int main() {
    Student s1;
    s1.setName("shardha");
    s1.setCgpa(9.1);

    cout << s1.getName() << endl;
    cout << s1.getCgpa() << endl;


    return 0;
}