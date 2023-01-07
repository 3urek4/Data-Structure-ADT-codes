#include <iostream>
#include "List.h"
#include "SinglyLinkedList_Link.h"
// #include "FreeList_Link.h"
// #include "DoublyLinkedList_Link.h"
using namespace std;
// Linked List implementation
template<class Elem>
class LList: public List<Elem> {
private:
    Link<Elem>* head; //Point to list header
    Link<Elem>* tail; //Pointer to last Elem
    Link<Elem>* fence; //Pointer to the node exactly before the current node
    int leftCnt; // Size of the list before the current node
    int rightCnt; // Size of the list after and including the current node

    // Initialization routine
    void init() {
        head = tail = fence = new Link<Elem>;
        leftCnt = rightCnt = 0;
    }

    // Remove all nodes to free store
    void removeAll() {
        while(head != nullptr) {
            fence = head;
            head = head->next;
            delete fence;
        }
    }

public:
    LList();
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
    ~LList();
};

// Constructor
template<class Elem>
LList<Elem>::LList() {
    init();
}

// reinitialize the list
template<class Elem>
void LList<Elem>::clear() {
    removeAll();
    init();
}

// determine whether list is empty or not
template<class Elem>
bool LList<Elem>::isEmpty() const {
    if(leftCnt + rightCnt == 0) return true;
    return false;
}

// insert an item to the current position
template<class Elem>
bool LList<Elem>::insert(const Elem& item) {
    fence->next = new Link<Elem>(item, fence->next);
    rightCnt++;
    if(fence == tail) tail = fence->next;
    return true;
}

// append an item at the end of the list
template<class Elem>
bool LList<Elem>::append(const Elem& item) {
    tail = tail->next = new Link<Elem>(item);
    rightCnt++;
    return true;
}

// remove the item at the current position
template<class Elem>
bool LList<Elem>::remove(Elem& it) {
    if(rightLength() == 0) return false;
    Link<Elem>* temp = fence->next;
    it = fence->next->element;
    fence->next = temp->next;
    if(tail == temp) tail = fence;
    delete temp;
    rightCnt--;
    return true;
}


// Set fence to the position indicated by the argument
template<class Elem>
bool LList<Elem>::moveToPos(int pos) {
    if((pos < 0) || (pos > leftCnt + rightCnt)) return false;
    fence = head;
    for(int i = 0; i < pos; i++) {
        fence = fence->next;
    }
    leftCnt = pos;
    rightCnt = leftCnt + rightCnt - pos;
    return true;
}

// set fence to the header
template<class Elem>
void LList<Elem>::moveToStart() {
    fence = head;
    rightCnt += leftCnt; 
    leftCnt = 0;
}

// set fence to the tail
template<class Elem>
void LList<Elem>::moveToEnd() {
    fence = tail;
    leftCnt += rightCnt; 
    rightCnt = 0;
}

// set fence to the previous item
template<class Elem>
bool LList<Elem>::prev() {
    if(leftLength() == 0) return false;
    Link<Elem>* temp = fence;
    fence = head;
    while(fence->next != temp) {
        fence = fence->next;
    }
    leftCnt--;
    rightCnt++;
    return true;
}

// set fence to the next item
template<class Elem>
bool LList<Elem>::next() {
    if(rightLength() == 0) return false;
    fence = fence->next;
    leftCnt++;
    rightCnt--;
    return true;
}

// Size of the list before the current node
template<class Elem>
int LList<Elem>::leftLength() const {
    return leftCnt;
}

// Size of the list after and including the current node
template<class Elem>
int LList<Elem>::rightLength() const {
    return rightCnt;
}

// return the value of the current item in the argument
template<class Elem>
bool LList<Elem>::getValue(Elem& it) const {
    if(rightLength() == 0) return false;
    it = fence->next->element;
    return true;
}

// print out the items in the list
template<class Elem>
void LList<Elem>::print() const {
    if(isEmpty()) {
        cout << "The Linked List is empty." << endl;
    }
    else {
        cout << "< ";
        Link<Elem>* temp = head;
        while(temp != fence) {
            cout << temp->next->element << " ";
            temp = temp->next;
        }
        cout << "| ";
        while(temp != tail) {
            cout << temp->next->element << " ";
            temp = temp->next;
        }
        cout << ">" << endl;
    }
}

// Destructor
template<class Elem>
LList<Elem>::~LList() {
    removeAll();
}