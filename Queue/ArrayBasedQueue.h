#include <iostream>
#include "Queue.h"
using namespace std;
// Array-based Queue(Circular)
template<class Elem>
class AQueue: public Queue<Elem>
{
private:
    int maxSize; // Maximum size of queue
    int front; // Index of front element
    int rear; // Index of rear element
    Elem* queueArray; // Array holding queue elements 

public:
    AQueue(int size = 10); // Constructor(10 is a default stackSize, usually assign a suitable constant value)
    void clear();
    bool isEmpty() const;
    bool enqueue(const Elem& item);
    bool dequeue(Elem& it);
    bool frontValue(Elem& it) const;
    int getLength() const;
    void print() const;
    ~AQueue(); // Destructor
};

// Constructor(10 is a default stackSize, usually assign a suitable constant value)
template<class Elem>
AQueue<Elem>::AQueue(int size) {
    maxSize = size + 1;
    rear = 0;
    front = 1;
    queueArray = new Elem[maxSize];
}

// reinitialize the queue
template<class Elem> 
void AQueue<Elem>::clear() {
    delete [] queueArray;
    rear = 0;
    front = 1;
    queueArray = new Elem[maxSize];
}

// determine whether queue is empty or not
template<class Elem>
bool AQueue<Elem>::isEmpty() const {
    if(front == rear + 1) return true;
    else return false;
}

// put an element at the rear of the queue
template<class Elem>
bool AQueue<Elem>::enqueue(const Elem& item) {
    if((rear + 2) % maxSize == front) return false;
    rear = (rear + 1) % maxSize;
    queueArray[rear] = item;
    return true;
}

// put an element at the front of the queue
template<class Elem>
bool AQueue<Elem>::dequeue(Elem& it) {
    if(isEmpty()) return false;
    it = queueArray[front];
    front = (front + 1) % maxSize;
    return true;
}

// return the element at the front of the queue
template<class Elem>
bool AQueue<Elem>::frontValue(Elem& it) const {
    if(isEmpty()) return false;
    it = queueArray[front];
    return true;
}

// return the number of elements in the queue
template<class Elem>
int AQueue<Elem>::getLength() const {
    return (rear + maxSize - front + 1) % maxSize;
}

// print out the items in the queue
template<class Elem>
void AQueue<Elem>::print() const {
    if(isEmpty()) {
        cout << "The queue is empty." << endl;
    }
    else {
        cout << "< ";
        for(int i = front; i < front + getLength(); i++) {
            cout << queueArray[i % maxSize] << " ";
        }
        cout << ">" << endl;
    }
}

// Destructor
template<class Elem>
AQueue<Elem>::~AQueue() {
    delete [] queueArray;
}