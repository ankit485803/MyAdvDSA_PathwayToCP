




#include <iostream>
using namespace std;

class CircularQueue {
    int* arr;         // Pointer to the dynamically allocated array
    int currSize, cap;
    int f, r;         // front and rear indices

public:
    CircularQueue(int size) {
        cap = size;
        arr = new int[cap];  // Allocate memory for the queue array
        currSize = 0;        // Initialize size as 0
        f = 0;               // Initialize front
        r = -1;              // Initialize rear
    }

    // 1st function - push
    void push(int data) {
        if(currSize == cap) {
            cout << "CQ is FULL \n";
            return;
        }

        r = (r + 1) % cap;  // Circular increment of rear
        arr[r] = data;      // Insert the data
        currSize++;         // Increment size
    }

    // 2nd function - pop
    void pop() {
        if(empty()) {
            cout << "CQ is EMPTY \n";
            return;
        }

        f = (f + 1) % cap;  // Circular increment of front
        currSize--;         // Decrement size
    }

    // 3rd function - front
    int front() {
        if(empty()) {
            cout << "CQ is EMPTY \n";
            return -1;  // Return -1 if the queue is empty
        }

        return arr[f];  // Return front element
    }

    // Check if the queue is empty
    bool empty() {
        return currSize == 0;  // Return true if queue is empty
    }

    // Print all elements in the queue
    void printArr() {
        if (empty()) {
            cout << "Queue is empty.\n";
            return;
        }
        
        int i = f;
        while (i != r) {
            cout << arr[i] << " ";
            i = (i + 1) % cap;
        }
        cout << arr[r] << endl;  // Print the last element
    }

    // Destructor to free dynamically allocated memory
    ~CircularQueue() {
        delete[] arr;
    }
};

int main() {
    CircularQueue cq(4);

    cq.push(1);
    cq.push(2);
    cq.push(3);
    cq.push(4);

    cq.push(5); // Should print "CQ is FULL"

    cq.printArr();  // Should print 1 2 3 4

    cout << "Front: " << cq.front() << endl;  // Should print 1
    cq.pop();

    cq.printArr();  // Should print 2 3 4

    return 0;
}
