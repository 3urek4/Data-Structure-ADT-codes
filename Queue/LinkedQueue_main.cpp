#include <iostream>
#include "LinkedQueue.h"
using namespace std;
int main() {
    LQueue<int> lqueue;
    
    cout << "Test begins:\n" << endl;

    // Test function enqueue()
    cout << "\nEnqueue 0,1,2,3,4 to the queue in order." << endl;
    lqueue.enqueue(0);
    lqueue.enqueue(1);
    lqueue.enqueue(2);
    lqueue.enqueue(3);
    lqueue.enqueue(4);
    cout << "Now the queue is: ";
    lqueue.print();

    // Test function dequeue()
    cout << "\nDequeue the front." << endl;
    int it1;
    bool result1 = lqueue.dequeue(it1);
    if(result1) {
        cout << "Successfully dequeue: " << it1 << endl;
    }
    else {
        cout << "Failed to dequeue." << endl;
    }
    cout << "Now the queue is: ";
    lqueue.print();

    // Test function frontValue()
    int it2;
    bool result2 = lqueue.frontValue(it2);
    if(result2) {
        cout << "\nThe value of the element at the front of the queue is: " << it2 << endl;
    }
    else {
        cout << "\nFailed to get the value of the element at the front of the queue." << endl;
    }
    
    // Test function getLength()
    cout << "\nNow the number of elements in the queue is: " << lqueue.getLength() << endl; 

    // Test function clear()
    cout << "\nNow reinitialize the queue." << endl;
    lqueue.clear();
    cout << "Now the queue is: ";
    lqueue.print();

    cout << "\nTest completes." << endl;
}
