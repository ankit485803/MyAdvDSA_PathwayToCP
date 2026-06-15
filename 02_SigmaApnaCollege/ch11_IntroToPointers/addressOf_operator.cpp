

/*

address of operator print


*/

#include <iostream>
using namespace std;

int main() {
    int a = 5;

    cout << "address of a = " << &a << "\n";

    return 0;
}



/* output

sanja@IITP:~$ cd /mnt/c/Users/sanja/Desktop/LabSession/
sanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$ ls
mapper.py  myRunFile.exe  reducer.py  scrape.py  sigmaApnaCollege.cpp  wiki.txt
sanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$ notepad sigmaApnaCollege.cpp
^Csanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$ g++ sigmaApnaCollege.cpp -o myRunFile.exe
sanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$ ./myRunFile.exe
address of a = 0x7ffc6c0ad8e4
sanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$



*/