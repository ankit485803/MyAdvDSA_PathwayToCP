



/* QUES

There are N cars on a highway that can move in both directions. Imagine the highway as a number line. Each car is located at a 
specific position xi on the highway and has a constant velocity vi. Note that velocities can be both negative and positive. 
If the velocity is negative, it means that the car will move in the negative direction with speed equal to the absolute value of 
velocity, whereas if the velocity is positive, it will move in the positive direction. As one can realize, after some time the cars 
might start colliding. We want to maximize the time of the first collision under the condition that we can remove at most M of these cars.

Constraints:

2 ≤ N ≤ 5 * 10^4
1 ≤ M ≤ N - 1
0 ≤ Xi ≤ 10^8
-10^5 ≤ Vi ≤ 10^5
Vi ≠ 0




concept req:  Heap data stru (min-heap), Greedy approach


*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <limits>

using namespace std;

struct Car {
    long long position;
    long long velocity;
};

// Custom comparator to sort cars based on position
bool compareByPosition(const Car& a, const Car& b) {
    return a.position < b.position;
}

// Function to calculate the earliest collision time
double collisionTime(const Car& a, const Car& b) {
    if (a.velocity <= b.velocity) return numeric_limits<double>::infinity();
    return (double)(b.position - a.position) / (a.velocity - b.velocity);
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<Car> cars(N);
    for (int i = 0; i < N; ++i) {
        cin >> cars[i].position >> cars[i].velocity;
    }

    // Sort cars by their positions
    sort(cars.begin(), cars.end(), compareByPosition);

    // Min-heap to store the earliest collision times
    priority_queue<double, vector<double>, greater<double>> collisionTimes;

    // Calculate all possible collision times between adjacent cars
    for (int i = 0; i < N - 1; ++i) {
        double time = collisionTime(cars[i], cars[i + 1]);
        if (time != numeric_limits<double>::infinity()) {
            collisionTimes.push(time);
        }
    }

    // Remove M smallest collision times to maximize the first collision time
    for (int i = 0; i < M && !collisionTimes.empty(); ++i) {
        collisionTimes.pop();
    }

    // The earliest remaining collision time is our answer
    double result = collisionTimes.empty() ? numeric_limits<double>::infinity() : collisionTimes.top();

    if (result == numeric_limits<double>::infinity()) {
        cout << -1 << endl;  // No collision will occur
    } else {
        cout << fixed << result << endl;  // Print the earliest collision time
    }

    return 0;
}






