

// conept of Logical OR operator in cpp

// The || sign is the logical OR operator in many programming languages, including C++. It evaluates two boolean expressions and
//  returns true if at least one of the expressions is true. If both are false, it returns false.

#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>

bool a = true;
bool b = false;

int main()
{
    bool a = true;
    bool b = false;

    if (a || b)
    {
        // This block will execute because a is true
        cout << "At least one is true." << endl;
    }
    else
    {
        cout << "Both are false." << endl;
    }
}
