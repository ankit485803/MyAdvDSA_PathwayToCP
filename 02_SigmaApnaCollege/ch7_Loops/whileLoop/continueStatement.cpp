


/*

continute statement matlab esko chorke sare print kar do

🔍 What continue does

continue ka matlab hota hai:

➡️ Current iteration ko skip karo aur next iteration pe chalo


*/


#include <iostream>
using namespace std;

int main() {

    for(int i=1; i<=10; i++) {
        if(i == 3) {
            continue;   //matlbe three ko chorke sare print kar do numb
    }
        cout << i << endl;
    }

    return 0;
}




for(int i = 1; i <= 10; i++) {
    if(i % 2 != 0) {
        continue; // skip odd numbers
    }
    cout << i << endl;
}