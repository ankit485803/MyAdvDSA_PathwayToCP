

/*

print all binary str of size N without any consecutive 1s


*/

#include <iostream>
#include <string>
using namespace std;


void binString(int n, int lastPlace, string ans) {
    //basecase
    if(n == 0) {
        cout << ans << endl;
        return;
    }

    if(lastPlace != 1) {
        binString(n-1, 0, ans + '0');
        binString(n-1, 1, ans + '1');
    } else {
        binString(n-1, 0, ans + '0');
    }
}


int main() {
    string ans = "";  //emptyStr se initialize 

    binString(3, 0, ans);
    return 0;
}




//without place 
void binString(int n, string ans) {
    if(n == 0) {
        cout << ans << endl;
        return;
    }

    if(ans[ans.size()-1]  != '1') {
        binString(n-1, ans + '0');
        binString(n-1, ans + '1');
    } else {
        binString(n-1, ans + '0');
    }
}

int main() {
    string ans = "";  

    binString(3, ans);
    return 0;
}
