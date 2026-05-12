
/*

12th May 2026 (Tuesday)

Function Overloading: multiple functions with the same name but diff parameters

shardhaDi boli jab bhi aap programming mai OVERLOADING suno to uska matlab hota hai sameName ko baar baar use karna 

This is real function overloading because:
    same function name
    different parameter types

ok overloading ko function ke returnType se kuch fark nahi parta hai


sum(int, int)
sum(double, double)
sum(int, double)
sum(int)

C++ decides which function to call using:
number of parameters
type of parameters
order of parameters

This process is called: Function Overloading Resolution
*/


#include <iostream>
using namespace std;

int sum(int a, int b) {
    cout << (a + b) << endl;
    return a + b;
}

double sum2(double a, double b) {
    return a + b;
}

int main() {
    sum(2, 3);
    sum(12, 13);
    sum(2.5, 1.5);  //implicit conversion ho raha ha double to int

    sum2(2.5, 1.5);  //4


    return 0;
}



/*
output
sanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$ g++ sigmaApnaCollege.cpp -o myRunFile.exe && ./myRunFile.exe
5
25
3
sanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$




*/



#include <iostream>
using namespace std;

// int version -- part1: types of parameters
int sum(int a, int b) {
    return a + b;
}

// double version (OVERLOADING)  
double sum(double a, double b) {
    return a + b;
}

//part2: no of parameters
double sum(int a, int b, double c) {
    return a + b + c;
}

int main() {

    cout << sum(2, 3) << endl;
    cout << sum(12, 13) << endl;
    cout << sum(2.5, 1.5) << endl;
    // part2
    cout << sum(2, 1, 3.5) << endl;


    return 0;
}



// see order of parameters demo
#include <iostream>
using namespace std;
// version 1
void show(int a, double b) {
    cout << "int, double" << endl;
}
// version 2
void show(double a, int b) {
    cout << "double, int" << endl;
}
int main() {
    show(2, 3.5);
    show(2.5, 3);
    return 0;
}



git commit -m "feat(sigmaApnaCollege): completed thisChap today and impConcepts binomialCoefficient, primeNo variousMethods, functOverloading learnt (ch9)"