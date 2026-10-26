
git commit -m "feat(sigmaApnaCollege): start newCh  and covers access modifiers, getter and setters, encapsulation, constructor (ch19_OOPS)" 

/*

21st Oct 2026 (Wednesday)

Access Modifiers:
  private: data & methods accessible inside class  -- also use in friend function
  public: data & methods accessible to everyone
  protected: data & methods accessible inside class & to its derived class

ok







*/


#include <iostream>
using namespace std;


class Student {
    //properties
    string name;   //yah by default private
public:
    float cgpa;

    //methods
    void percentage() {
        cout << (cgpa * 10) << "% \n";
    }
};


class instaUser {
    int id;
    string username;
    string password;
    string bio;

    void deactivate() {
        cout << "deleting account\n";
    }

    void editBio(string newBio) {
        bio = newBio;
    }
}


int main() {
    Student s1;   //object create hoga memory main aur space allocate bhi ho jayega
    cout << sizeof(s1) << endl;  //34 kuch bites string ke liye aur kuch cgpa

    s1.name = "shardha";
    cout << s1.name << endl;

    return 0;
}