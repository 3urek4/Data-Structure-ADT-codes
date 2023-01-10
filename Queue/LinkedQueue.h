#include <iostream>
#include "Queue.h"
#include "SinglyLinkedList_Link.h"
using namespace std;
// Linked Queue
template<class Elem>
class LQueue: public Queue<Elem>
{
private:
    Link<Elem>* front; // Pointer to the front element
    Link<Elem>* rear; // Pointer to the rear element
    int queueSize; // Number of the elements in the queue

public:
    LQueue(); // Constructor
    void clear();
    bool isEmpty() const;
    bool enqueue(const Elem& item);
    bool dequeue(Elem& it);
    bool frontValue(Elem& it) const;
    int getLength() const;
    void print() const;
    ~LQueue(); // Destructor
};

// Constructor
template<class Elem>
LQueue<Elem>::LQueue() {
    front = rear = new Link<Elem>;
    queueSize = 0;
}

// reinitialize the queue
template<class Elem> 
void LQueue<Elem>::clear() {
    while(front->next != nullptr) {
        rear = front;
        front = front->next;
        delete rear;
    }    
    rear = front;
    queueSize = 0;
}

// determine whether queue is empty or not
template<class Elem>
bool LQueue<Elem>::isEmpty() const {
    if(queueSize == 0) return true;
    else return false;
}

// put an element at the rear of the queue
template<class Elem>
bool LQueue<Elem>::enqueue(const Elem& item) {
    if(isEmpty()) {
        front = rear = new Link<Elem>(item);
    }
    else {
        rear->next = new Link<Elem>(item);
        rear = rear->next;
    }
    queueSize++;
    return true;
}

// put an element at the front of the queue
template<class Elem>
bool LQueue<Elem>::dequeue(Elem& it) {
    if(isEmpty()) return false;
    it = front->element;
    Link<Elem>* temp = front->next;
    delete front;
    front = temp;
    if(front == nullptr) rear = front;
    queueSize--;
    return true;
}

// return the element at the front of the queue
template<class Elem>
bool LQueue<Elem>::frontValue(Elem& it) const {
    if(isEmpty()) return false;
    it = front->element;
    return true;
}

// return the number of elements in the queue
template<class Elem>
int LQueue<Elem>::getLength() const {
    return queueSize;
}

// print out the items in the queue
template<class Elem>
void LQueue<Elem>::print() const {
    if(isEmpty()) {
        cout << "The queue is empty." << endl;
    }
    else {
        cout << "< ";
        Link<Elem>* temp = front;
        for(int i = 0; i < getLength(); i++) {
            cout << temp->element << " ";
            temp = temp->next;
        }
        cout << ">" << endl;
    }
}

// Destructor
template<class Elem>
LQueue<Elem>::~LQueue() {
    clear();
    delete front;
}