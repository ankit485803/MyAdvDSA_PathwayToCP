


/*

3rd April 2026 (Friday)

esmia two innerLoop need hoga

print the 

But a proper pyramid should be Symmetry leftSpace == rightSpace 
   1
  123
 12345
1234567



ankitFormual to print space make by observation on penPaper drawDiagram

spaceEachCell = (totalSpace - currSpaceCell) / 2
s = (n - i) / 2;



*/


#include <iostream>
using namespace std;

int main() {
    int n = 7;

    for(int i=1; i<=n; i=i+2) {  //outloop oddNo tak iterate karna chahiye so that SYMMETRY hoga
        
        //innerLoop1 jo space print karena usingAnkitFormula 
        for(int s = 1; s <= (n - i)/2;  s++) {
            cout << " ";
        }

        //innerLoop2: jo numb print 
        for(int j=1; j <= i; j++) {
            int val = j;
            cout << val;
        }
        cout << endl;  //goToNewLine
    }

    

    return 0;
}