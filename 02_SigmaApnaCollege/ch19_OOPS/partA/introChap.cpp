
git commit -m "feat(sigmaApnaCollege): start new chap (ch19_OOPS)" 

/*

21st Oct 2026 (Wednesday)



*/


#include <iostream>
using namespace std;


class Student {
    //properties
    string name;
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

    return 0;
}