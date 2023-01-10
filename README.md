<p align="center">
  <img src="https://miro.medium.com/max/1200/1*KpDOKMFAgDWaGTQHL0r70g.png" style="width:400px;" />
</p>

<h1 align="center">Data-Structure-ADT-codes</h1>

<p align="center">
该仓库代码是将数据结构课程代码根据个人习惯和思考进行些许修改的版本，并加入了测试代码，旨在保存代码和复习巩固
</p>

# Table of Contents

- [List](#list)
  - [Array-based(Sequential) List](#array-basedsequential-list)
  - [Linked List](#linked-list)
    - [Singly Linked List](#singly-linked-list)
    - [FreeList](#freelist)
    - [Doubly Linked List](#doubly-linked-list)
- [Stack](#stack)
  - [Array-based(Sequential) Stack](#array-basedsequential-stack)
  - [Linked Stack](#linked-stack)
- [Queue](#queue)
  - [Array-based(Sequential) Queue](#array-basedsequential-queue)
  - [Linked Queue](#linked-queue)


# List

线性表的C++抽象类说明 `List.h`​ ：

```cpp
template<class Elem>
class List {
public:
    // reinitialize the list
    virtual void clear() = 0;

    // determine whether list is empty or not
    virtual bool isEmpty() const = 0;

    // insert an item into the list before the current item
    virtual bool insert(const Elem& item) = 0;

    // insert an item into the list at the end of the list
    virtual bool append(const Elem& item) = 0;

    // remove the item at the current
    virtual bool remove(Elem& it) = 0;

    // set the current to the position indicated by the argument
    virtual bool moveToPos(int pos) = 0;

    // set the current to the beginning
    virtual void moveToStart() = 0;

    // set the current to the last
    virtual void moveToEnd() = 0;

    // set the current to the previous item
    virtual bool prev() = 0;

    // set the current to the next item
    virtual bool next() = 0;

    // the size of the list before the current(not including the current)
    virtual int leftLength() const = 0;

    // the size of the list after and including the current
    virtual int rightLength() const = 0;

    // return the value of the current item in the argument
    virtual bool getValue(Elem& it) const = 0;

    // print out the items in the list
    virtual void print() const = 0;
};
```

## Array-based(Sequential) List

顺序表的实现 `ArrayBasedList.h`​ ：

```cpp
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
    AList(int size = 10); // Constructor(10 is a default listSize, usually assign a suitable constant value)
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
```

顺序表实现的测试代码 `ArrayBasedList_main.cpp`​ ：

```cpp
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
```

## Linked List

链表的实现 `LinkedList.h`​ ：

```cpp
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
```

链表实现的测试代码 `LinkedList_main.cpp`​ ：

```cpp
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
```

### Singly Linked List

单链表结点类的定义 `SinglyLinkedList_Link.h`​ ：

```cpp
// Singly Linked List node
template<class Elem>
class Link {
public:
    Elem element; // Value for this node
    Link* next; // Pointer to next node

    Link(const Elem& elemVal, Link* nextVal = nullptr) {
        element = elemVal;
        next = nextVal;
    }
    Link(Link* nextVal = nullptr) {
        next = nextVal;
    }
};
```

### FreeList

可利用空间表节点类的定义 `FreeList_Link.h`​ ：

```cpp
// Singly Linked List node with freelist
template <class Elem> class Link {
private:
    static Link<Elem>* freelist; // Head
public:
    Elem element; // Value for this node
    Link* next; // Point to next node
  
    Link(const Elem& elemval, Link* nextval = nullptr) { 
        element = elemval; 
        next = nextval; 
    }
    Link(Link* nextval = nullptr) { 
        next=nextval; 
        }
    void* operator new(size_t); // Overload new operator
    void operator delete(void*); // Overload delete operator
};

template <class Elem> // Overload new operator
void* Link<Elem>::operator new(size_t) {
    if (freelist == NULL) return ::new Link;
    Link<Elem>* temp = freelist; // Reuse
    freelist = freelist->next;
    return temp; // Return the link
}

template <class Elem> // Overload delete operator
void Link<Elem>::operator delete(void* ptr) {
    ((Link<Elem>*)ptr)->next = freelist; // Put on freelist
    freelist = (Link<Elem>*)ptr;
}
```

### Doubly Linked List

双链表结点类的定义 `DoublyLinkedList_Link.h`​ ：

```cpp
// Doubly Linked List node
template <class Elem> class Link {
public:
    Elem element; // Value for this node
    Link* next; // Pointer to next node
    Link* prev; // Pointer to previous node

    Link(const Elem& elemVal, Link* prevPtr = nullptr, Link* nextPtr = nullptr) { 
        element = elemVal; 
        prev = prevPtr; 
        next = nextPtr; 
    }
    Link(Link* prevPtr = nullptr, Link* nextPtr = nullptr) { 
        prev = prevPtr; 
        next = nextPtr; 
    }
};
```

# Stack

栈的C++抽象类说明 `stack.h`​ ：

```cpp
template<class Elem>
class Stack {
public:
    // reinitialize the stack 
    virtual void clear() = 0;

    // determine whether stack is empty or not
    virtual bool isEmpty() const = 0;

    // push an element onto the top of the stack
    virtual bool push(const Elem& it) = 0;

    // remove the element at the top of the stack
    virtual bool pop(Elem& it) = 0;

    // return the value of the top element
    virtual bool topValue(Elem& it) const = 0;

    // return the number of elements in the stack
    virtual int getLength() const = 0;

    // print out the items in the stack
    virtual void print() const = 0;
};
```

## Array-based(Sequential) Stack

顺序栈的实现 `ArrayBasedStack.h`​ ：

```cpp
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
```

顺序栈实现的测试代码 `ArrayBasedStack_main.cpp`​ ：

```cpp
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
```

## Linked Stack

链式栈的实现 LinkedStack.h ：

```cpp
#include <iostream>
#include "Stack.h"
#include "SinglyLinkedList_Link.h"
using namespace std;
// Linked Stack
template<class Elem>
class LStack: public Stack<Elem>
{
private:
    Link<Elem>* top; // Pointer to the top element of the stack
    int stackSize; // Number of the elements in the stack

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
```

链式栈实现的测试代码 `LinkedStack_main.cpp`​ ：

```cpp
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
```

# Queue

队列的C++抽象类说明 `Queue.h`​ ：

```cpp
template<class Elem>
class Queue
{
public:
    // reinitialize the queue
    virtual void clear() = 0;

    // determine whether queue is empty or not
    virtual bool isEmpty() const = 0;

    // put an element at the rear of the queue
    virtual bool enqueue(const Elem& item) = 0;

    // remove an element at the front of the queue
    virtual bool dequeue(Elem& it) = 0;

    // return the element at the front of the queue
    virtual bool frontValue(Elem& it) const = 0;

    // return the number of elements in the queue
    virtual int getLength() const = 0;

    // print out the items in the queue
    virtual void print() const = 0;
};
```

## Array-based(Sequential) Queue

顺序队列的实现 `ArrayBasedQueue.h`​ ：

```cpp
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
```

顺序队列实现的测试代码 `ArrayBasedQueue_main.cpp`​ ：

```cpp
#include <iostream>
#include "ArrayBasedQueue.h"
using namespace std;
int main() {
    // Assign maxSize to be a suitable positive integer: 8
    AQueue<int> aqueue(8);

    cout << "Test begins:\n" << endl;

    // Test function enqueue()
    cout << "\nEnqueue 0,1,2,3,4 to the queue in order." << endl;
    aqueue.enqueue(0);
    aqueue.enqueue(1);
    aqueue.enqueue(2);
    aqueue.enqueue(3);
    aqueue.enqueue(4);
    cout << "Now the queue is: ";
    aqueue.print();

    // Test function dequeue()
    cout << "\nDequeue the front." << endl;
    int it1;
    bool result1 = aqueue.dequeue(it1);
    if(result1) {
        cout << "Successfully dequeue: " << it1 << endl;
    }
    else {
        cout << "Failed to dequeue." << endl;
    }
    cout << "Now the queue is: ";
    aqueue.print();

    // Test function frontValue()
    int it2;
    bool result2 = aqueue.frontValue(it2);
    if(result2) {
        cout << "\nThe value of the element at the front of the queue is: " << it2 << endl;
    }
    else {
        cout << "\nFailed to get the value of the element at the front of the queue." << endl;
    }
  
    // Test function getLength()
    cout << "\nNow the number of elements in the queue is: " << aqueue.getLength() << endl; 

    // Test function clear()
    cout << "\nNow reinitialize the queue." << endl;
    aqueue.clear();
    cout << "Now the queue is: ";
    aqueue.print();

    cout << "\nTest completes." << endl;
}
```

## Linked Queue

链式队列的实现 `LinkedQueue.h`​ ：

```cpp
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
```

链式队列实现的测试代码 `LinkedQueue_main.cpp`​ ：

```cpp
#include <iostream>
#include "LinkedQueue.h"
using namespace std;
int main() {
    LQueue<int> lqueue;
  
    cout << "Test begins:\n" << endl;

    // Test function enqueue()
    cout << "\nEnqueue 0,1,2,3,4 to the queue in order." << endl;
    lqueue.enqueue(0);
    lqueue.enqueue(1);
    lqueue.enqueue(2);
    lqueue.enqueue(3);
    lqueue.enqueue(4);
    cout << "Now the queue is: ";
    lqueue.print();

    // Test function dequeue()
    cout << "\nDequeue the front." << endl;
    int it1;
    bool result1 = lqueue.dequeue(it1);
    if(result1) {
        cout << "Successfully dequeue: " << it1 << endl;
    }
    else {
        cout << "Failed to dequeue." << endl;
    }
    cout << "Now the queue is: ";
    lqueue.print();

    // Test function frontValue()
    int it2;
    bool result2 = lqueue.frontValue(it2);
    if(result2) {
        cout << "\nThe value of the element at the front of the queue is: " << it2 << endl;
    }
    else {
        cout << "\nFailed to get the value of the element at the front of the queue." << endl;
    }
  
    // Test function getLength()
    cout << "\nNow the number of elements in the queue is: " << lqueue.getLength() << endl; 

    // Test function clear()
    cout << "\nNow reinitialize the queue." << endl;
    lqueue.clear();
    cout << "Now the queue is: ";
    lqueue.print();

    cout << "\nTest completes." << endl;
}
```

