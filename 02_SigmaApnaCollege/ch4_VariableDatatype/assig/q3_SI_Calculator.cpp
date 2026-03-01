

/*
Question 3 : Build a Simple Interest Calculator.
Input : principal (P), rate (R), time (T)
Output : (P*R*T) / 100


*/

#include <iostream>
using namespace std;

int calculatorSI(int P, int R, int T) {
    int SI = (P*R*T) / 100;
    return SI;
}


int main() {
    int P, R, T;

    cout << "Enter Principle amount P:";
    cin >> P;
    cout << "enter rate R: ";
    cin >> R;
    cout << "enter Time T: ";
    cin >> T;

    cout << "Simple Interest = " << calculatorSI(P, R, T) << endl;

    return 0;
}



#include <iostream>
using namespace std;

double calculatorSI(double P, double R, double T) {
    return (P * R * T) / 100;
}

int main() {
    double P, R, T;

    cout << "Enter Principal amount P: ";
    cin >> P;

    cout << "Enter Rate R (%): ";
    cin >> R;

    cout << "Enter Time T (years): ";
    cin >> T;

    double SI = calculatorSI(P, R, T);

    cout << "Simple Interest = " << SI << endl;

    return 0;
}



// Even Better (Money Formatting)
#include <iomanip>
cout << fixed << setprecision(2);



#include <iostream>
#include <iomanip>   // Added for formatting
using namespace std;

double calculatorSI(double P, double R, double T) {
    return (P * R * T) / 100;
}

int main() {
    double P, R, T;

    cout << "Enter Principal amount P: ";
    cin >> P;

    cout << "Enter Rate R (%): ";
    cin >> R;

    cout << "Enter Time T (years): ";
    cin >> T;

    double SI = calculatorSI(P, R, T);

    // Formatting output to 2 decimal places
    cout << fixed << setprecision(2);

    cout << "Simple Interest = " << SI << endl;

    return 0;
}