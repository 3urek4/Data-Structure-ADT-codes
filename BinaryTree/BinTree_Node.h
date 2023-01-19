// Binary Tree Node Abstract Class
template<class Elem>
class BinNode
{
    // Return the node's value
    virtual Elem& val() = 0;

    // Set the node's value
    virtual void setVal(const Elem&) = 0;

    // Return the node's left child
    virtual BinNode* left() const = 0;

    // Set the node's left child
    virtual void setLeft(BinNide*) = 0;

    // Return the node's right child
    virtual BinNode* right() const = 0;

    // Set the node's right child
    virtual void setRight(BinNide*) = 0;

    // Return true if the node is a leaf, false otherwise
    virtual bool isLeaf() = 0;
};