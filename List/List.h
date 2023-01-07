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