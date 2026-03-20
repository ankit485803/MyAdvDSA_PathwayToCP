

//print the sum of digits of a numb using while loop, n = 10829





/*

shardha di boli: kisi bhi numb % 10 lene se lastDigit milega, aur numb / 10 karne se lastDigit remove karna hai




*/

#include <iostream>
using namespace std;
#include <vector>

int digitSum(int numb) {  //tc=O(n), sc=O(1)
    //step1: extract digits from numb
    vector<int> digits;
    
    while(numb > 0) {
        int last = numb % 10;  //moduloOP se lastInt
        digits.push_back(last);
        numb /= 10;  //removeLast 
    }

    //step2: calculateDigitSum
    int sum = 0, i=0;
    while(i < digits.size()) {
        sum += digits[i];
        i++;
    }

    return sum;

}





int digitSumConstantTime(int numb) {
    int sum = 0;
    while(numb > 0) {  //tc= O(no of digits) = O(1)
        int last = numb % 10;
        sum += last;
        numb /= 10;
    }
    return sum;
}



//ques: print the sum of odd digits of numb using while loop 

//create secondFunct
int oddDigitSum(int numb) {
    int sum = 0;
    while(numb > 0) {
        int last = numb % 10;

        if(last % 2 != 0) {  //checkOdd
            sum += last;
        }
        numb /= 10; //removeLastDigit from numb
    }

    return sum;
}


int main() {
    int numb = 10829;

    cout << "Sum of digits = " << digitSum(numb) << endl;
    cout << "Sum of only ODD digits = " << oddDigitSum(numb) << endl;

    return 0;
}




/*

✍️ Pseudocode (Optimized)


FUNCTION digitSum(n)
    sum ← 0

    WHILE n > 0 DO
        last ← n % 10
        sum ← sum + last
        n ← n / 10
    END WHILE

    RETURN sum
END FUNCTION




🔍 Dry Run (Optimized)
numb = 10829

sum = 0

sum = 0 + 9 = 9
sum = 9 + 2 = 11
sum = 11 + 8 = 19
sum = 19 + 0 = 19
sum = 19 + 1 = 20



✔ Correct Complexity:

Time Complexity: O(d), where d = number of digits

It is NOT truly O(1) (constant time)

👉 It’s only effectively constant if integer size is fixed (like 32-bit), but in theory → O(d)




FUNCTION oddDigitSum(n)
    sum ← 0

    WHILE n > 0 DO
        last ← n % 10

        IF last is odd THEN
            sum ← sum + last
        END IF

        n ← n / 10
    END WHILE

    RETURN sum
END FUNCTION
*/


