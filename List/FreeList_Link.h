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