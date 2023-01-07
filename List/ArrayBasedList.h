#include <iostream>
#include "List.h"
using namespace std;
// Array-based(Sequential) list
template<class Elem> 
class AList: public List<Elem> {
private:
    int maxSize; // Maximum size of list
    int listSize; // Maximum size of list
    int curr; // Position of the current element
    Elem* listArray; // Array holding list elements

public:
    AList(int size = 10); // Constructor(10 is default listSize, usually assign a suitable constant value)
    void clear();
    bool isEmpty() const;
    bool insert(const Elem& item);
    bool append(const Elem& item);
    bool remove(Elem& it);
    bool moveToPos(int pos);
    void moveToStart();
    void moveToEnd();
    bool prev();
    bool next();
    int leftLength() const;
    int rightLength() const;
    bool getValue(Elem& it) const;
    void print() const;
    ~AList(); // Destructor
};

// Constructor(the default parameter can be left out of the definition of the function)
template<class Elem>
AList<Elem>::AList(int size) {
    maxSize = size;
    listSize = curr = 0;
    listArray = new Elem[maxSize];
}

// reinitialize the list
template<class Elem>
void AList<Elem>::clear() {
    delete [] listArray;
    listSize = curr = 0;
    listArray = new Elem[maxSize];
}

// determine whether list is empty or not
template<class Elem>
bool AList<Elem>::isEmpty() const { 
    if(listSize == 0) return true; // Prone to logical error
    else return false;
}

// insert an item into the list before the current item
template<class Elem>
bool AList<Elem>::insert(const Elem& item) {
    if(listSize == maxSize) return false;
    for(int i = listSize; i > curr; i--){
        listArray[i] = listArray[i-1];
    }
    listArray[curr] = item;
    listSize++;
    return true;
}

// In the case of a sorted list, function append() is not required. 
// If the list is in ascending order, function insert() can be modified to the following version.
// template<class Elem>
// bool AList<Elem>::insert(const Elem& item) {
//     if(listSize == maxSize) return false;
//     int suitPos = 0;
//     while((listArray[suitPos] < item) && (suitPos < listSize)){
//         suitPos++;
//     }
//     for(int i = listSize; i > suitPos; i--){
//         listArray[i] = listArray[i-1];
//     }
//     listArray[suitPos] = item;
//     listSize++;
//     return true;
// }

// append an item at the end of the list
template<class Elem>
bool AList<Elem>::append(const Elem& item) {
    if(listSize == maxSize) return false;
    listArray[listSize++] = item;
    return true;
}

// remove the item at the current
template<class Elem>
bool AList<Elem>::remove(Elem& it) {
    if(rightLength() == 0) return false;
    it = listArray[curr];
    for(int i = curr; i < listSize - 1; i++) {
        listArray[i] = listArray[i+1];
    }
    listSize--;
    return true;
}

// set the current to the position indicated by the argument
template<class Elem>
bool AList<Elem>::moveToPos(int pos) {
    if((pos >= 0) && (pos <= listSize)) curr = pos;
    return (pos >= 0) && (pos <= listSize);
}

// set the current to the beginning
template<class Elem>
void AList<Elem>::moveToStart() {
    curr = 0;
}

// set the current to the last
template<class Elem>
void AList<Elem>::moveToEnd() {
    curr = listSize;
}

// set the current to the previous item
template<class Elem>
bool AList<Elem>::prev() {
    if(leftLength() == 0) return false;
    curr--;
    return true;
}

// set the current to the next item
template<class Elem>
bool AList<Elem>::next() {
    if(rightLength() == 0) return false;
    curr++;
    return true;
}

// the size of the list before the current(not including the current)
template<class Elem>
int AList<Elem>::leftLength() const {
    return curr;
}

// the size of the list after and including the current
template<class Elem>
int AList<Elem>::rightLength() const {
    return listSize - curr;
}

// return the value of the current item in the argument
template<class Elem>
bool AList<Elem>::getValue(Elem& it) const {
    if(rightLength() == 0) return false;
    it = listArray[curr];
    return true;
}

// print out the items in the list
template<class Elem>
void AList<Elem>::print() const {
    if(isEmpty()) {
        cout << "The Array-Based List is empty!" << endl;
    }
    else {
        cout << "< " ;
        for(int i = 0; i < curr; i++) {
            cout << listArray[i] << " ";
        }
        cout << "| ";
        for(int i = curr; i < listSize; i++) {
            cout << listArray[i] << " ";
        }
        cout << ">" << endl;
    }
}

// Destructor
template<class Elem>
AList<Elem>::~AList() {
    delete [] listArray;
}