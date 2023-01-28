template<class Elem>
class HuffNode
{
public:
    // Return frequency
    virtual int weight() = 0;
    // Determine type
    virtual bool isLeaf() = 0;
    // Left node subclass
    virtual HuffNode* left() const = 0;
    // Set the node's left child
    virtual void setLeft(HuffNode*) = 0;
    // Right node subclass
    virtual HuffNode* right() const = 0;
    // Set the node's right child
    virtual void setRight(HuffNode*) = 0;
};