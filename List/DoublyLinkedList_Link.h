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