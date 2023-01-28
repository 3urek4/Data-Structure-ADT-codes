#include "HuffmanNode.h"
#include "FrequencyPair.h"
template<class Elem>
class LeafNode: public HuffNode<Elem>
{
private:
    FreePair<Elem>* it;
public:
    // Constructor
    LeafNode(const Elem& val, int freq) {
        it = new FreePair<Elem>(val, freq);
    }
    // Return freepair
    FreePair<Elem>* val() {
        return it;
    }
    // Return frequency
    int weight() {
        return it->weight();
    }
    // Determine type
    bool isLeaf() {
        return true;
    }
    // Left node subclass
    HuffNode* left() const {
        return nullptr;
    }
    // Set the node's left child
    void setLeft(HuffNode*) {}
    // Right node subclass
    HuffNode* right() const {
        return nullptr;
    }
    // Set the node's right child
    void setRight(HuffNode*) {}
};