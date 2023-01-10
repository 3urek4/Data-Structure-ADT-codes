#include <iostream>
#include "ArrayBasedQueue.h"
using namespace std;
int main() {
    // Assign maxSize to be a suitable positive integer: 8
    AQueue<int> aqueue(8);

    cout << "Test begins:\n" << endl;

    // Test function enqueue()
    cout << "\nEnqueue 0,1,2,3,4 to the queue in order." << endl;
    aqueue.enqueue(0);
    aqueue.enqueue(1);
    aqueue.enqueue(2);
    aqueue.enqueue(3);
    aqueue.enqueue(4);
    cout << "Now the queue is: ";
    aqueue.print();

    // Test function dequeue()
    cout << "\nDequeue the front." << endl;
    int it1;
    bool result1 = aqueue.dequeue(it1);
    if(result1) {
        cout << "Successfully dequeue: " << it1 << endl;
    }
    else {
        cout << "Failed to dequeue." << endl;
    }
    cout << "Now the queue is: ";
    aqueue.print();

    // Test function frontValue()
    int it2;
    bool result2 = aqueue.frontValue(it2);
    if(result2) {
        cout << "\nThe value of the element at the front of the queue is: " << it2 << endl;
    }
    else {
        cout << "\nFailed to get the value of the element at the front of the queue." << endl;
    }
    
    // Test function getLength()
    cout << "\nNow the number of elements in the queue is: " << aqueue.getLength() << endl; 

    // Test function clear()
    cout << "\nNow reinitialize the queue." << endl;
    aqueue.clear();
    cout << "Now the queue is: ";
    aqueue.print();

    cout << "\nTest completes." << endl;
}