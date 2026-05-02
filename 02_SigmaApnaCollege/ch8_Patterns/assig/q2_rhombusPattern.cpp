

/*

1st May 2026 (Friday)

Question 2 : Print the Rhombus Pattern.
For n = 5

    *****
   *****
  *****
 *****
*****


bhai yaha rightMost wale spaces ke bare mai mat socho sirf front wale spaces print kar do wah auto set ho jayga

in whatsapp languages
myThoughtProcess:
    outerLoop - no of rows (int i=1; i<=n; i++) oneOuterLoop req
    innerLoop - kya karna hai aur kab tak workDone (twoWork ho raha ha eachRow mai) one spaces & fix CONSTANT no of stars printed - req twoInnerLoop
                         spaces: jo deceases ho raha hai (int s=1; s <= n-i; s++) cout << " ";
                         stars: yah fix hai jo independence of i value (int j=1; j <= n; j++) cout << "*"
    
    jab one completeRow print ho ja hmko newline hoga
    cout << endl;                      


*/



#include <iostream>
using namespace std;


int main() {  //tc=O(n^2) due to nestedLoop, sc=O(1)
    int n = 5;

    for(int i=1; i <= n; i++) {  //outerLoop
        //twoParts innerLoop workDone

        for(int s = 1; s <= n-i; s++) {  //SPACES
            cout << " ";
        }
        for(int j=1; j <= n; j++) {
            cout << "*";
        }

        cout << endl;  //one newLine afterOneCompleteRow
    }

    return 0;
}



/*
See it vvvery carefully output diff b/w gcc and g++

sanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$ gcc sigmaApnaCollege.cpp -o myRun
/usr/bin/ld: /tmp/cc2NRfHE.o: warning: relocation against `_ZSt4cout' in read-only section `.text'
/usr/bin/ld: /tmp/cc2NRfHE.o: in function `main':
sigmaApnaCollege.cpp:(.text+0x32): undefined reference to `std::cout'
/usr/bin/ld: sigmaApnaCollege.cpp:(.text+0x3a): undefined reference to `std::basic_ostream<char, std::char_traits<char> >& std::operator<< <std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&, char const*)'
/usr/bin/ld: sigmaApnaCollege.cpp:(.text+0x63): undefined reference to `std::cout'
/usr/bin/ld: sigmaApnaCollege.cpp:(.text+0x6b): undefined reference to `std::basic_ostream<char, std::char_traits<char> >& std::operator<< <std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&, char const*)'
/usr/bin/ld: sigmaApnaCollege.cpp:(.text+0x7e): undefined reference to `std::basic_ostream<char, std::char_traits<char> >& std::endl<char, std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&)'
/usr/bin/ld: sigmaApnaCollege.cpp:(.text+0x88): undefined reference to `std::cout'
/usr/bin/ld: sigmaApnaCollege.cpp:(.text+0x90): undefined reference to `std::ostream::operator<<(std::ostream& (*)(std::ostream&))'
/usr/bin/ld: warning: creating DT_TEXTREL in a PIE
collect2: error: ld returned 1 exit status
sanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$ g++ sigmaApnaCollege.cpp -o myRun
sanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$


Why this happens
gcc → for C programs
g++ → for C++ programs (automatically links libstdc++, which includes std::cout, std::endl, etc.)

Difference Between gcc and g++  
The GNU Compiler Collection, abbreviated as GCC provides multiple compilers to compile source codes of different programming languages, mainly C and C++. In its command line interface, it provides two commands "gcc" and "g++" which are used to invoke the compiler to compile the given source code to executable file.

What "gcc" Command Do?
The command "gcc" is used to invoke the corresponding compiler for multiple programming languages like C, C++, objective C, etc. It recognizes the complier that is to be used from the extension of the provided source file.
src: https://www.geeksforgeeks.org/cpp/difference-between-gcc-and-g/


*/

for(int s = 1; s <= n-i; s++) cout << " ";
for(int j = 1; j <= n; j++) cout << "*";


#include <iostream>
#include <string>
using namespace std;

int main() {
    int n = 5;

    for(int i = 1; i <= n; i++) {
        cout << string(n - i, ' ') << string(n, '*') << '\n';
    }
}