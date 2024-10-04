
#include <iostream> // Required for cout
using namespace std; // So you can use cout without std:: prefix

int main() {
    cout << "Hello, World!";   // Output the text  
    cout << "Ankit Kumar" << "Samarth Mishra" << endl;
    cout << "Ramu Kumar";
    cout << "Ankit" << "\n" " Kumar";
    cout << "Apna \n College" << endl;
    // dataTypes
    int age = 25;
    cout << "The age of Ankit is:" << age << endl;
    cout << "Interger store a RAM in comp is:" << sizeof (age) << endl;
    string mySchoolName = "IIT Patna";
    cout << "Name of my School is:" << mySchoolName << "and size of string is stored:" << sizeof(mySchoolName) << endl;
    char grade = 'A';
    cout << "What is your grade?" << grade << "size of char stored in RAM is:" << sizeof(grade) << endl;

    float PI = 3.14;
    bool isSafe = true;
    double price = 100.99;
    cout << isSafe << endl;  //yah trur ko 1 aur false ko 0 se

    return 0;
}

