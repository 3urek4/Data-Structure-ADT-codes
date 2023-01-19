#include <iostream>
using namespace std;
class VarBinNode 
{
public:
    virtual bool isLeaf() = 0;
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
};

void travesal(VarBinNode* subroot) {
    if(subroot == nullptr) return;
    if(subroot->isLeaf()) {
        cout << "Leaf: " << ((LeafNode*)subroot)->value() << endl;
    }
    else {
        cout << "Internal: " << ((IntlNode*)subroot)->value() << endl;
        travesal(((IntlNode*)subroot)->leftChild());
        travesal(((IntlNode*)subroot)->rightChild());
    }
}