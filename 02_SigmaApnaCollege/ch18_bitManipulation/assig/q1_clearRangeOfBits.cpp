


/*

16th Oct 2026 (Friday - sixth day Navratri) but not continue on time due to continentWise target 

21st OCt 2026 (Wednesday)

Question 1 : Write a Function to clear the range of bits from i to j in a given number. (i 
& j are counted backwards from the right end of the number)



approachFirst: BruteFore  tc=O(n), sc=O(1)
                step1: convert decToBinary
                stp2: main logic removing bite -- start loop
                step3: return final ans in decForm


approach2: using bit mask techniques  tc=O(1)=sc


*/


#include <iostream>
#include <cmath>
using namespace std;


// Step 1: Decimal to binary
int decToBin(int num) {
    int place = 0, binForm = 0;

    while(num > 0) {
        int rem = num % 2;  //find remainder and put it into revOrder
        binForm += rem * pow(10, place);
        num /= 2;
        place++;
    }
    return binForm;
}

// Step 2: Binary to decimal
int binToDec(int num) {
    int decForm = 0, exponent = 0;

    while(num > 0) {
        int lastD = num % 10;
        decForm += lastD * pow(2, exponent);
        exponent++;
        num /= 10;
    }
    return decForm;
}


// Step 3: Clear bits from i to j
int clearBitRange(int num, int i, int j) {
    int binaryNum = decToBin(num);
    int ans = 0;
    int place = 0;

    //mainLogic
    while(binaryNum > 0) {
        int lastDig = binaryNum % 10;

        // Clear the bit if its position is between i and j
        if(place >= i && place <= j) {
            lastDig = 0;  //delete matlab 1 ko zero kar do
        }

        ans += lastDig * pow(10, place);
        binaryNum /= 10;
        place++;
    }
    // Step 4: Convert the result back to decimal
    return binToDec(ans);
}





int main() {
    int num = 15;
    int i = 1, j = 2;

    cout << clearBitRange(num, i, j) << endl;

    return 0;
}



//optimized
int clearBitRange(int num, int i, int j) {
    // Step 1: Create mask with 1s to the left of j
    int a = (~0) << (j + 1);

    // Step 2: Create mask with 1s to the right of i
    int b = (1 << i) - 1;

    // Step 3: Combine both masks
    int mask = a | b;

    // Step 4: Clear bits from i to j
    return num & mask;
}