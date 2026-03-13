
// 13th March 2026 (Friday - after LandRegistryBhalwaBari)


#include <iostream>
using namespace std;

int main() {
    float income;  //in Lakh
    cout << "Enter your income in lakh: ";
    cin >> income;

    if(income < 5) {
        cout << "Income including tax (0 percent) = " << income + (income * 0)/100 << endl;

    } else if(income >= 5 || income <= 10) {
        cout << "Income included tax (20 percent) = " << income + (income * 20)/100 << endl;

    } else{  //greater than 10
        cout << "Income included tax (30 percent) = " << income + (income * 30)/100 << endl;
    }


    return 0;
}



#include <iostream>
using namespace std;

int main() {
    float income;
    cout << "Enter your income in lakh: ";
    cin >> income;

    float taxRate;

    if(income < 5) {
        taxRate = 0;
    }
    else if(income <= 10) {
        taxRate = 20;
    }
    else {
        taxRate = 30;
    }

    float finalIncome = income + (income * taxRate) / 100;

    cout << "Income including tax = " << finalIncome << endl;

    return 0;
}



#include <iostream>
#include <iomanip>   // for formatting
using namespace std;

int main() {
    float income;
    cout << "Enter your income in lakh: ";
    cin >> income;

    float taxRate;

    if(income < 5) {  //incomeSLAB
        taxRate = 0;
    }
    else if(income <= 10) {
        taxRate = 20;
    }
    else {
        taxRate = 30;
    }

    float finalIncome = income + (income * taxRate)/100;

    cout << fixed << setprecision(2);
    cout << "Income including tax = " << finalIncome << " lakh" << endl;
    float rupees = finalIncome * 100000;   //If you want it in Rupees instead of Lakh
    cout << "Income including tax = Rs " << rupees << endl;

    return 0;
}