#include <iostream>
#include "Stack.h"
#include "SinglyLinkedList_Link.h"
using namespace std;
// Linked Stack
template<class Elem>
class LStack: public Stack<Elem>
{
private:
    Link<Elem>* top;
    int stackSize;

public:
    LStack(); // Constructor
    void clear();
    bool isEmpty() const;
    bool push(const Elem& item);
    bool pop(Elem& it);
    bool topValue(Elem& it) const;
    int getLength() const;
    void print() const;
    ~LStack(); // Destructor
};

// Constructor
template<class Elem>
LStack<Elem>::LStack() {
    top = nullptr;
    stackSize = 0;
}

// reinitialize the stack 
template<class Elem>
void LStack<Elem>::clear() {
    while(top != nullptr) {
        Link<Elem>* temp = top;
        top = top->next;
        delete temp;
    }
    stackSize = 0;
}

// determine whether stack is empty or not
template<class Elem>
bool LStack<Elem>::isEmpty() const {
    if(top ==  nullptr) return true;
    return false;
}

// push an element onto the top of the stack
template<class Elem>
bool LStack<Elem>::push(const Elem& item) {
    top = new Link<Elem>(item, top);
    stackSize++;
    return true;
}

// remove the element at the top of the stack
template<class Elem>
bool LStack<Elem>::pop(Elem& it) {
    if(isEmpty()) return false;
    it = top->element;
    Link<Elem>* temp = top->next;
    delete top;
    top = temp;
    stackSize--;
    return true; 
}

// return the value of the top element
template<class Elem>
bool LStack<Elem>::topValue(Elem& it) const {
    if(isEmpty()) return false;
    it = top->element;
    return true;
}

// return the number of elements in the stack
template<class Elem>
int LStack<Elem>::getLength() const {
    return stackSize;
}

// print out the items in the stack
template<class Elem>
void LStack<Elem>::print() const {
    if(isEmpty()) {
        cout << "The stack is empty." << endl;
    }
    else {
        Elem tempArray[getLength()];
        int index = 0;
        Link<Elem>* temp = top;
        while(temp != nullptr) {
            tempArray[index++] = temp->element;
            temp = temp->next;
        }
        cout << "< ";
        for(int i = getLength() - 1; i >= 0; i--) {
            cout << tempArray[i] << " ";
        }
        cout << ">" << endl;
    }
}

// Destructor
template<class Elem>
LStack<Elem>::~LStack() {
    clear();
}