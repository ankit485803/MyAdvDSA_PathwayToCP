#include <iostream>
using namespace std;

int sumFirstNaturalNo(int N) {
    int sum = 0;
    for(int i=0; i<=N; i++) {
        sum += i;
    }
    return sum;
}

int sumUsingMaths(int N) {
    int ans = N*(N + 1) / 2;
    return ans;
}


int main() {
    int N;
    cout << "Enter N = ";
    cin >> N;
    
    cout << "Sum of first N natural no = " << sumFirstNaturalNo(N) << endl;
    cout << "sum using maths formula = " << sumUsingMaths(N) << endl;

    return 0;
}

