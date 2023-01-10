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