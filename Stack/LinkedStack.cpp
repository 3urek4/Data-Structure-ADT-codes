#include <iostream>
#include "LinkedStack.h"
using namespace std;
int main() {
    LStack<int> lstack;

    cout << "Test begins:\n" << endl;

    // Test function push()
    cout << "Push 0,1,2,3 to the stack in order." << endl;
    lstack.push(0);
    lstack.push(1);
    lstack.push(2);
    lstack.push(3);
    cout << "Now the stack is: ";
    lstack.print();

    // Test function pop()
    cout << "\nPop the top element." << endl;
    int it1;
    bool result1 = lstack.pop(it1);
    if(result1) {
        cout << "Successfully pop: " << it1 << endl;
    }
    else {
        cout << "Failed to pop." << endl;
    }
    cout << "Now the stack is: ";
    lstack.print();

    // Test function topValue()
    int it2;
    bool result2 = lstack.topValue(it2);
    if(result2) {
        cout << "\nThe value of the top element is: " << it2 << endl;
    }
    else {
        cout << "\nFailed to get the value of the top element." << endl;
    }

    // Test function getLength()
    cout << "\nNow the number of elements in the stack is: " << lstack.getLength() << endl;

    // Test function clear()
    cout << "\nNow reinitialize the stack." << endl;
    lstack.clear();
    cout << "Now the stack is: ";
    lstack.print();

    cout << "\nTest completes." << endl;
}