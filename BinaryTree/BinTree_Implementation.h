#include <iostream>
#include "BinTree_Node.h"
using namespace std;
// Binary Tree Node Implementation
template<class Elem>
class BinNodePtr: public class BinNode<Elem>
{
private:
    Elem value; // The node's value
    BinNodePtr* lc; // Pointer to left child
    BinNodePtr* rc // Pointer to right child

public:
    // Two Constructors
    BinNodePtr() {
        lc = rc = nullptr;
    }
    BinNodePtr(ELem item, BinNodePtr* left = nullptr; BinNode* right = nullptr) {
        value = item;
        lc = left;
        rc = right;
    }

    // Return the node's value
    Elem& val() {
        return value;
    }

    // Set the node's value
    void setVal(const Elem& item) {
        value = item;
    }

    // Return the node's left child
    inline BinNodePtr* left() const {
        return lc;
    }

    // Set the node's left child
    void setLeft(BinNide<Elem>* left) {
        lc = (BinNodePtr*)left;
    }

    // Return the node's right child
    inline BinNodePtr* right() const {
        return rc;
    }

    // Set the node's right child
    void setRight(BinNide<Elem>* right) {
        rc = (BinNodePtr*)right;
    }

    // Return true if the node is a leaf, false otherwise
    bool isLeaf() {
        return (lc == nullptr) && (rc == nullptr);
    }
};