#include <iostream>
#include "LinkedList.h"
using namespace std;
int main() {
    LList<int> llist;

    cout << "Test begins:\n" << endl;

    // Test function append()
    cout << "Append 0,1,2,3 to the list in order." << endl;
    llist.append(0);
    llist.append(1);
    llist.append(2);
    llist.append(3);
    cout << "Now the list is: ";
    llist.print();

    // Test function moveToPos()
    cout << "\nMove the fence to position 1." << endl;
    llist.moveToPos(1);
    cout << "Now the list is: ";
    llist.print();

    // Test function insert()
    cout << "\nInsert integer 1 to the current position." << endl;
    llist.insert(1);
    cout << "Now the list is: ";
    llist.print();

    // Test function remove()
    cout << "\nRemove the current element: ";
    int it1;
    bool result1 = llist.remove(it1);
    if(result1) {
        cout << "Successfully removed." << endl;
    } else {
        cout<<"Failed to remove."<<endl;
    }
    cout << "Now the list is: ";
    llist.print();

    // Test function moveToStart()
    cout << "\nMove the fence to the header." << endl;
    llist.moveToStart();
    cout << "Now the list is: ";
    llist.print();

    // Test function next()
    cout << "\nMove the fence to the next one: ";
    bool result2 = llist.next();
    if(result2) {
        cout << "Successfully moved." << endl;
    } else {
        cout << "Failed to moved." << endl;
    }
    cout << "Now the list is: ";
    llist.print();

    // Test function leftLength()
    int LLength = llist.leftLength();
    cout << "\nNow the size of the list before the current is: " << LLength << endl;

    // Test function moveToEnd()
    cout << "\nMove the fence to the tail." << endl;
    llist.moveToEnd();
    cout << "Now the list is: ";
    llist.print();

    // Test function prev()
    cout << "\nMove the fence to the previous one: " << endl;
    bool result3 = llist.prev();
    if(result3) {
        cout << "Successfully moved." << endl;
    } else {
        cout << "Failed to moved." << endl;
    }
    cout << "Now the list is: ";
    llist.print();

    // Test function rightLength()
    int RLength = llist.rightLength();
    cout << "\nNow the size of the list after and including the current is: " << RLength << endl;

    // Test function getValue()
    int it2;
    bool result4 = llist.getValue(it2);
    if(result4) {
        cout << "\nThe value of the current element is: " << it2 << endl;
    } else {
        cout << "\nFailed to get the value of the current element." << endl;
    }

    // Test function clear()
    cout << "\nNow reinitialize the list." << endl;
    llist.clear();
    cout << "Now the list is: ";
    llist.print();

    cout << "\nTest completes." << endl;
}