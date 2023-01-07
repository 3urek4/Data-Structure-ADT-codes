#include <iostream>
#include "ArrayBasedList.h"
using namespace std;
int main() {
    // Assign maxSize to be a suitable positive integer: 8
    AList<int> alist(8); 

    cout << "Test begins:\n" << endl;

    // Test function append()
    cout << "Append 0,1,2,3 to the list in order." << endl;
    alist.append(0);
    alist.append(1);
    alist.append(2);
    alist.append(3);
    cout << "Now the list is: ";
    alist.print();

    // Test function moveToPos()
    cout << "\nMove the current position to position 1." << endl;
    alist.moveToPos(1);
    cout << "Now the list is: ";
    alist.print();

    // Test function insert()
    cout << "\nInsert integer 1 to the current position." << endl;
    alist.insert(1);
    cout << "Now the list is: ";
    alist.print();

    // Test function remove()
    cout << "\nRemove the current element: ";
    int it1;
    bool result1 = alist.remove(it1);
    if(result1) {
        cout << "Successfully removed." << endl;
    } else {
        cout<<"Failed to remove."<<endl;
    }
    cout << "Now the list is: ";
    alist.print();

    // Test function moveToStart()
    cout << "\nMove the current position to the beginning." << endl;
    alist.moveToStart();
    cout << "Now the list is: ";
    alist.print();

    // Test function next()
    cout << "\nMove the current position to the next one: ";
    bool result2 = alist.next();
    if(result2) {
        cout << "Successfully moved." << endl;
    } else {
        cout << "Failed to moved." << endl;
    }
    cout << "Now the list is: ";
    alist.print();

    // Test function leftLength()
    int LLength = alist.leftLength();
    cout << "\nNow the size of the list before the current is: " << LLength << endl;

    // Test function moveToEnd()
    cout << "\nMove the current position to the end." << endl;
    alist.moveToEnd();
    cout << "Now the list is: ";
    alist.print();

    // Test function prev()
    cout << "\nMove the current position to the previous one: " << endl;
    bool result3 = alist.prev();
    if(result3) {
        cout << "Successfully moved." << endl;
    } else {
        cout << "Failed to moved." << endl;
    }
    cout << "Now the list is: ";
    alist.print();

    // Test function rightLength()
    int RLength = alist.rightLength();
    cout << "\nNow the size of the list after and including the current is: " << RLength << endl;

    // Test function getValue()
    int it2;
    bool result4 = alist.getValue(it2);
    if(result4) {
        cout << "\nThe value of the current element is: " << it2 << endl;
    } else {
        cout << "\nFailed to get the value of the current element." << endl;
    }

    // Test function clear()
    cout << "\nNow reinitialize the list." << endl;
    alist.clear();
    cout << "Now the list is: ";
    alist.print();

    cout << "\nTest completes." << endl;
}