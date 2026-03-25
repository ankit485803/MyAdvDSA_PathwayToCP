


/*

25th March 2026 (Wednesday)

Nested Loop: matlab Loop ke andar loop hona, esko use karte hai Pattern ko print karne or diff algorithms ko likhne ke liye

es se pahle hm Nested ifelse pade the hm


step1: outerloop - no of rows
step2: innerLoop - no cols or each row mai kitna elem hai COMMON,  aur kitna baar print karna hai aur kya print karna hai
step2: work in innerLoop


*/


#include <iostream>
using namespace std;


int main() {
    int n = 5;  //generalize code into term of n

    for(int i=1; i <= n; i++) {  //outerLoop- no of rows
        int val = i;

        for(int j=1; j <= n; j++) {  //innerLoop - no cols or kitna elelems hai each row mai

            //jab innerLoop end hota hai to ek row complete hota hai bhai
            cout << val << " ";  //kya KAM karna hai
        }
        cout << endl;
    }

    return 0;
}



/*

dryRun this code


*/