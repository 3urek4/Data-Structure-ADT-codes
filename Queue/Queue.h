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