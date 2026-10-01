

/*

1st Oct 2026 (Thursday)

some special funct jo ki <cstring> header file ke andar exit karte hai

i. strcopy(dest, src): to copy string from source to destination
ii. strcat(str1, str2): to concatenate or join str1 with str2
iii. strcmp(str1, str2): compare 2 strings based on values (-ve, 0, +ve)

#include <cstring> //for using strlen() funct

*/


#include <iostream>
#include <cstring>  //cstring headerFile STL
using namespace std;


int main() {
    char str1[100];
    //str1 = "apna college";  //error

    strcpy(str1, "apna college");  //dest: apna college, src: str1
    cout << str1 << endl;

    return 0;
}



int main() {
    char str1[100];
    char str2[100] = "hello world";

    strcpy(str1, str2);  //dest: str1, src: str2
    cout << str1 << endl;

    return 0;
}


//ii. concat
int main() {
    char str1[100] = "hello";
    char str2[100] = "world";

    strcat(str1, str2);  
    cout << str1 << endl;

    return 0;
}
//iii. compare
int main() {
    char str1[100] = "abc";
    char str2[100] = "xyz";
    char str3[100] = "abc";

    cout << strcmp(str1, str2) << endl; //firstLetter compare karta hai internally ASCII value se, not related with strlength bhai
    
    cout << strcmp(str1, str3) << endl;  //same means 0, jab first str choti hoga to -ve values random and vice-versa

    return 0;
}