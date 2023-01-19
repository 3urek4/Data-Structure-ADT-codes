#include <iostream>
using namespace std;
class VarBinNode 
{
public:
    virtual bool isLeaf() = 0;
    virtual void trav() = 0;
};

class LeafNode: public VarBinNode
{
private:
    Operand var;

public:
    LeafNode(const Operand& val) {
        var = val;
    }
    bool isLeaf() {
        return true;
    }
    Operand value() {
        return var;
    }
    void trav() {
        cout << "Leaf: " << value() << endl;
    }
};

class IntlNode: public VarBinNode
{
private:
    Operator opx;
    VarBinNode* left;
    VarBinNode* right;

public:
    IntlNode(const Operator& op, VarBinNode* l, VarBinNode* r) {
        opx = op;
        left = l;
        right = r;
    }
    bool isLeaf() {
        return false;
    }
    VarBinNode* leftChild() {
        return left;
    }
    VarBinNode* rightChild() {
        return right;
    }
    Operator value() {
        return opx;
    }
    void trav() {
        cout << "Internal: " << value() << endl;
        if(left != nullptr) {
            left->trav();
        }
        if(right != nullptr) {
            right->trav();
        }
    }
};

void travesal(VarBinNode* subroot) {
    if(subroot != nullptr) {
        subroot->trav();
    }
}