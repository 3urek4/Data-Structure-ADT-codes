#include "HuffmanNode.h"
#include "LeafNode.h"
#include "InternalNode.h"
#include "HuffmanCompare.h"
template <class Elem>
class HuffTree {
private:
    HuffNode<Elem>* theRoot;
public:
    HuffTree(Elem& val, int freq)
        { theRoot = new LeafNode<Elem>(val,freq);}
    HuffTree(HuffTree<Elem>* l, HuffTree<Elem>* r)
        { theRoot = new IntlNode<Elem>(l->root(), r->root());}
    ~HuffTree() {}
    HuffNode<Elem>* root() { 
        return theRoot; 
    }
    int weight() { 
        return theRoot->weight(); 
    }
    HuffTree<Elem>* buildHuff(SLList<HuffTree<Elem>*,HHCompare<Elem>>* f1)
    {
        HuffTree<Elem>* temp1, *temp2, *temp3;
        for (f1->setStart();
            f1->leftLength() + f1->rightLength() > 1;
            f1->setStart()) { //While at least two items left
                f1->remove(temp1); // Pull first two trees off the list
                f1->remove(temp2);
                temp3 = new HuffTree<Elem>(temp1, temp2);
                f1->insert(temp3); // Put the new tree back on list
                delete temp1; // Delete the remnants
                delete temp2;
            }
        return temp3;
    }
};
