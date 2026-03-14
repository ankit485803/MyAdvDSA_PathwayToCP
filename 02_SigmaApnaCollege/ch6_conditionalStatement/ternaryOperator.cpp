

/*


14th March 2026 (Satursday) TernaryOp


variable = condition ? true : false

bool isAdult = (age >= 18) ? true : false
bool isAdult(int age) {
}


variable = (condition) ? value_if_true : value_if_false;

*/

bool isAdult(int age)
{
    return (age >= 18) ? true : false;
}

bool isAdult(int age)
{
    if (age >= 18)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isAdult(int age)
{ // age >= 18 evaluates to true or false automatically.
    return age >= 18;
}

#include <iostream>
using namespace std;

int main() {
    int age;
    cout << "Enter your age:";
    cin >> age;

    bool isAdult = age >= 18 ? true : false; // 1, 0
    cout << boolalpha;
    cout << "Are you adult: " << isAdult << endl;

    // largest of 2 numb
    int a = 15;
    int b = 20;
    int largestTwoNo = a >= b ? a : b;
    cout << "Largest is = " << largestTwoNo << endl;

    // rightToVote criteria
    int age;
    cout << "Enter your age:";
    cin >> age;

    string canVote = age >= 18 ? "Can vote" : "cannot vote";
    cout << "Voting criteria: " << canVote << endl;
    cout << "Voting criteria: " << (age >= 18 ? "Can vote" : "Cannot vote") << endl;

    //Odd or even
    int num = -13;
    cout << "nums is " << (num % 2 == 0 ? "Even" : "Odd") << endl;

    return 0;
}



/* can i write complete code in capital, does this impact output

Short answer: No, you cannot write the entire C++ code in capital letters. It will affect compilation because C++ is case-sensitive.

What “case-sensitive” means

main, Main, and MAIN are different identifiers in C++.


*/