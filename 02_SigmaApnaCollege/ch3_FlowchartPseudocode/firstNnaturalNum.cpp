#include <iostream>
using namespace std;

void firstNnaturalNo(int N) {
    for(int i = 1; i <= N; i++) {
        cout << i << " ";
    }
}

int main() {
    int N;
    cout << "Enter N value: ";
    cin >> N;

    cout << "First N natural numbers are: ";
    firstNnaturalNo(N);

    return 0;
}