

/*

16th May 2026 (Saturday) DataType Modifiers 

frequently used dataType -  int, short, long long, unsigned

shardhaDi boli thi ki dataType ki size system depend hota hai may vary window and linux mai

*/


#include <iostream>
using namespace std;


int main() {

    cout << " size of int dataType = " << sizeof(int) << endl;
    cout << " size of long dataType = " << sizeof(long) << endl;
    cout << " size of double dataType = " << sizeof(double) << endl;

    cout << "long double size = " << sizeof(long double) << endl;
    cout << "short int size = " << sizeof(short int) << endl;

    cout << "long long size = " << sizeof(long long) << endl;
    cout << "long long int size = " << sizeof(long long int) << endl;

    cout << "unsigned size = " << sizeof(unsigned) << endl;
 
    return 0;
}




/*
output from Linux Ubuntu distribution WSL 
sanja@IITP:~$ cd /mnt/c/Users/sanja/Desktop/LabSession/
sanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$ notepad sigmaApnaCollege.cpp
sanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$ g++ sigmaApnaCollege.cpp -o myRunFile.exe && ./myRunFile.exe
 size of int dataType = 4
 size of long dataType = 8
 size of double dataType = 8
long double size = 16
short int size = 2
long long size = 8
long long int size = 8
unsigned size = 4
sanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$



and output from window terminal
PS D:\GitProj\MyAdvDSA_PathwayToCP> cd "d:\GitProj\MyAdvDSA_PathwayToCP\02_SigmaApnaCollege\ch10_BinaryNumSystem\dataTypeModifier\" ; if ($?) { g++ modifiers.cpp -o modifiers } ; if ($?) { .\modifiers }
 size of int dataType = 4
 size of long dataType = 4
 size of double dataType = 8
long double size = 12
short int size = 2
long long size = 8
long long int size = 8
unsigned size = 4
PS D:\GitProj\MyAdvDSA_PathwayToCP\02_SigmaApnaCollege\ch10_BinaryNumSystem\dataTypeModifier> 




*/


git commit -m "feat(sigmaApnaCollege): covered dataType Modifiers int, short, long long, unsigned (ch10)"