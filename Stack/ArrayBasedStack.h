#include <iostream>
#include "Stack.h"
using namespace std;
// Array-based Stack
template<class Elem> 
class AStack: public Stack<Elem> 
{
private:
    int maxSize; // Maximum size of stack
    int top; // Index for the next position of the top element of the stack
    Elem* stackArray; // Array holding stack elements 

public:
    AStack(int size = 10); // Constructor(10 is a default stackSize, usually assign a suitable constant value)
    void clear();
    bool isEmpty() const;
    bool push(const Elem& item);
    bool pop(Elem& it);
    bool topValue(Elem& it) const;
    int getLength() const;
    void print() const;
    ~AStack(); // Destructor
};

// Constructor(10 is a default stackSize, usually assign a suitable constant value)
template<class Elem> 
AStack<Elem>::AStack(int size) {
    maxSize = size;
    top = 0;
    stackArray = new Elem[maxSize];
}

// reinitialize the stack 
template<class Elem> 
void AStack<Elem>::clear() {
    delete [] stackArray;
    top = 0;
    stackArray = new Elem[maxSize];
}

// determine whether stack is empty or not
template<class Elem>
bool AStack<Elem>::isEmpty() const {
    if(getLength() == 0) return true;
    else return false;
}

// push an element onto the top of the stack
template<class Elem> 
bool AStack<Elem>::push(const Elem& item) {
    if(getLength() == maxSize) return false;
    stackArray[top++] = item;
    return true;
}

// remove the element at the top of the stack
template<class Elem> 
bool AStack<Elem>::pop(Elem& it) {
    if(isEmpty()) return false;
    it = stackArray[--top];
    return true;
}

// return the value of the top element
template<class Elem> 
bool AStack<Elem>::topValue(Elem& it) const {
    if(isEmpty()) return false;
    it = stackArray[top-1];
    return true;
}

// return the number of elements in the stack
template<class Elem>
int AStack<Elem>::getLength() const {
    return top;
}

// print out the items in the stack
template<class Elem>
void AStack<Elem>::print() const {
    if(isEmpty()) {
        cout << "The stack is empty." << endl;
    }
    else {
        cout << "< ";
        for(int i = 0; i < top; i++) {
            cout << stackArray[i] << " ";
        }
        cout << ">" << endl;
    }
}

// Destructor
template<class Elem> 
AStack<Elem>::~AStack() {
    delete [] stackArray;
}