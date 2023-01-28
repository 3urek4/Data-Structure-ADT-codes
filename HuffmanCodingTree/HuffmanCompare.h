template <class Elem> 
class HHCompare {
public:
    static bool lt(HuffTree<Elem>* x, HuffTree<Elem>* y) { 
        return x->weight() < y->weight(); 
    }
    static bool eq(HuffTree<Elem>* x, HuffTree<Elem>* y) { 
        return x->weight() = = y->weight(); 
    }
    static bool gt(HuffTree<Elem>* x, HuffTree<Elem>* y) { 
        return x->weight() > y->weight(); 
    }
};