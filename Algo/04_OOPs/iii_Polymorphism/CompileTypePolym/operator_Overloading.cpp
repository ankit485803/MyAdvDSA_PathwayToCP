


#include <iostream>
#include <cstring>
using namespace std;

/*

Like function Overloading, operator (+, =, &, ..) overloading also works


*/







class MyString {
    char* str;
public:
    MyString(const char* s = "") {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }

    // Copy constructor
    MyString(const MyString& other) {
        str = new char[strlen(other.str) + 1];
        strcpy(str, other.str);
    }

    // Assignment operator
    MyString& operator=(const MyString& other) {
        if (this != &other) {
            delete[] str;
            str = new char[strlen(other.str) + 1];
            strcpy(str, other.str);
        }
        return *this;
    }

        ////C++ only provides automatic operator overloads for built-in types (like int, double, std::string, etc.). For user-defined types (like your MyString), you must define how operators work,
    // + operator: concatenate two MyString objects
    MyString operator+(const MyString& other) const {
        char* temp = new char[strlen(str) + strlen(other.str) + 1];
        strcpy(temp, str);
        strcat(temp, other.str);
        MyString result(temp);
        delete[] temp;
        return result;
    }






    // Display method
    void display() const {
        cout << str << endl;
    }

    // << operator: to print with cout
    friend ostream& operator<<(ostream& os, const MyString& obj) {
        os << obj.str;
        return os;
    }

    ~MyString() {
        delete[] str;
    }
};











int main() {
    MyString a("Hello"), b("World");

    cout << a + b << endl;  // Output: HelloWorld

    a = b; // uses overloaded '='
    a.display(); // Output: World

    return 0;
}