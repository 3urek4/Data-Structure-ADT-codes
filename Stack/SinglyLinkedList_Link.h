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