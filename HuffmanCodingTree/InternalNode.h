#include "HuffmanNode.h"
template<class Elem>
class IntlNode: public HuffNode<Elem>
{
private:
    HuffNode<Elem>* lc; // left child
    HuffNode<Elem>* rc; // right child
    int wgt; // subtree weight
public:
    // Constructor
    IntlNode(HuffNode<Elem>* l, HuffNode<Elem>* r) {
        wgt = l->weight() + r->weight();
        lc = l;
        rc = r;
    }
    // Return frequency
    int weight() {
        return wgt;
    }
    // Determine type
    bool isLeaf() {
        return false;
    }
    // Left node subclass
    HuffNode* left() const {
        return lc;
    }
    // Set the node's left child
    void setLeft(HuffNode<Elem>* b) {
        lc = (HuffNode*)b;
    }
    // Right node subclass
    HuffNode* right() const {
        return rc;
    }
    // Set the node's right child
    void setRight(HuffNode<Elem>* b) {
        rc = (HuffNode*)b;
    }
};