


#include <iostream>
using namespace std;


int main() {
    cout << "Welcome to SI calculation using mathsFormula: \n";
    int P, R, T;

    // takingInput
    cout << "Enter principle amount P: ";
    cin >> P;
    cout << "Enter interest rate R: ";
    cin >> R;
    cout << "Enter time T: ";
    cin >> T;

    // applied MathemacticalFornula
    int SI = (P * R * T) / 100;

    cout << "Simple Interest = " << SI << endl;

    return 0;
}



if (P < 0 || R < 0 || T < 0) {
    cout << "Invalid input! Values cannot be negative." << endl;
    return 0;
}





int main() {
    cout << "Welcome to SI calculation using mathsFormula: \n";
    double P, R, T;

    // takingInput
    cout << "Enter principle amount P: ";
    cin >> P;
    cout << "Enter interest rate R: ";
    cin >> R;
    cout << "Enter time T: ";
    cin >> T;

    // applied MathemacticalFornula
    double SI = (P * R * T) / 100;

    cout << "Simple Interest = " << SI << endl;

    return 0;
}





/*

🔎 But Is Negative Principal Practical?
💰 In Real Life Finance:
    It depends on interpretation.

1️⃣ Negative Principal (P < 0)
Normally:
Principal = money invested or loan amount

So it should be positive

But negative principal can represent:
    📉 Debt from your perspective
    📊 Cash flow modeling
    🏦 Accounting systems (assets vs liabilities)


*/