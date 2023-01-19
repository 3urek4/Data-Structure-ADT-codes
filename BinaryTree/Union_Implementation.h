#include <iostream>
using namespace std;
enum NodeType {leaf, internal};
class VarBinNode 
{
public:
    NodeType myType;
    union {
        struct {
            VarBinNode* left;
            VarBinNode* right;
            Operator opx;
        } intl;
        Operand var;
    };
    VarBinNode(const Operand& val) {
        myType = leaf;
        var = val;
    }
    VarBinNode(const Operator& op, VarBinNode* l, VarBinNode* r) {
        myType = internal;
        intl.opx = op;
        intl.left = l;
        intl.right = r;
    }
    bool isLeaf() {
        return myType == leaf;
    }
    VarBinNode* leafChild() {
        return intl.left;
    }
    VarBinNode* rightChild() {
        return intl.right;
    }
};

void travesal(VarBinNode* subroot) {
    if(subroot == nullptr) return;
    if(subroot->isLeaf()) {
        cout << "Leaf: " << subroot->var << endl;
    }
    else {
        cout << "Internal: " << subroot->intl.opx << endl;
        travesal(subroot->leafChild());
        travesal(subroot->rightChild());
    }
}