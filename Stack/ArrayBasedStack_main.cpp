#include <iostream>
#include "ArrayBasedStack.h"
using namespace std;
int main() {
    // Assign maxSize to be a suitable positive integer: 8
    AStack<int> astack(8);

    cout << "Test begins:\n" << endl;

    // Test function push()
    cout << "Push 0,1,2,3 to the stack in order." << endl;
    astack.push(0);
    astack.push(1);
    astack.push(2);
    astack.push(3);
    cout << "Now the stack is: ";
    astack.print();

    // Test function pop()
    cout << "\nPop the top element." << endl;
    int it1;
    bool result1 = astack.pop(it1);
    if(result1) {
        cout << "Successfully pop: " << it1 << endl;
    }
    else {
        cout << "Failed to pop." << endl;
    }
    cout << "Now the stack is: ";
    astack.print();

    // Test function topValue()
    int it2;
    bool result2 = astack.topValue(it2);
    if(result2) {
        cout << "\nThe value of the top element is: " << it2 << endl;
    }
    else {
        cout << "\nFailed to get the value of the top element." << endl;
    }

    // Test function getLength()
    cout << "\nNow the number of elements in the stack is: " << astack.getLength() << endl;

    // Test function clear()
    cout << "\nNow reinitialize the stack." << endl;
    astack.clear();
    cout << "Now the stack is: ";
    astack.print();

    cout << "\nTest completes." << endl;
}