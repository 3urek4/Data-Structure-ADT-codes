#include <iostream>
#include "Dictionary.h"
#include "BinTree_Node.h"
#include "BinTree_Implementation.h"
using namespace std;
template<class Key, class Elem, class KEComp, class EEComp>
class BST: public Dictionary<Key, Elem, KEComp, EEComp>
{
private:
    BinNode<Elem>* root;
    int nodeCnt;
    void clearhelp(BinNode<Elem>*);
    BinNode<Elem>* inserthelp(BinNode<Elem>*, const Elem&);
    BinNode<Elem>* deletemin(BinNode<ELem>*, BinNode<Elem>*&);
    BinNode<Elem>* removehelp(BinNode<Elem>*, const Key&, BinNode<Elem>*&);
    bool findhelp(BinNode<Elem>*, const Key&, Elem&) const;
    void printhelp(BinNode<Elem>*, int) const;

public:
    BST() {
        root = nullptr;
        nodeCnt = 0;
    }
    ~BST() {
        clearhelp(root);
    }
    void clear() {
        clearhelp(root);
        root = nullptr;
        nodeCnt = 0;
    }
    bool insert(const Elem& item) {
        root = inserthelp(root, item);
        nodeCnt++;
        return true;
    }
    bool remove(const Key& k, Elem& it) {
        BinNode<Elem>* temp = nullptr;
        root = removehelp(root, k, temp);
        if(temp == nullptr) return false;
        it = temp->val();
        delete temp;
        nodeCnt--;
        return true;
    }
    bool removeAny(Elem& it) {
        if(root == nullptr) return false;
        BinNode<Elem>* temp;
        root = deletemin(root, temp);
        it = temp->val();
        delete temp;
        nodeCnt--;
        return true;
    }
    bool find(const Key& k, Elem& item) const {
        return findhelp(root, k, item);
    }
    int size() {
        return nodeCnt;
    }
    void print() const {
        if(root == nullptr) {
            cout << "The BST is empty." << endl;
        }
        else {
            printhelp(root, 0);
        }
    }
};

template<class Key, class Elem, class KEComp, class EEComp>
void BST<Key, Elem, KEComp, EEComp>::clearhelp(BinNode<Elem>* subroot) {
    if(subroot == nullptr) return;
    clearhelp(subroot->left());
    clearhelp(subroot->right());
    delete subroot;
}

template<class Key, class Elem, class KEComp, class EEComp>
BinNode<Elem>* BST<Key, Elem, KEComp, EEComp>::inserthelp(BinNode<Elem>* subroot, const Elem& item) {
    if(subroot == nullptr) return new BinNodePtr<Elem>(item, nullptr, nullptr);
    if(EEComp::lt(item, subroot->val())) {
        subroot->setLeft(inserthelp(subroot->left(), item));
    }
    else {
        subroot->setRight(inserthelp(subroot->right(), item));
    }
    return subroot;
}

template<class Key, class Elem, class KEComp, class EEComp>
BinNode<Elem>* BST<Key, Elem, KEComp, EEComp>::deletemin(BinNode<ELem>* subroot, BinNode<Elem>*& min) {
    if(subroot->left() == nullptr) {
        min = subroot;
        return subroot->right();
    }
    else {
        subroot->setLeft(
            deletemin(subroot->left(), min);
        )
        return subroot;
    }
}

template<class Key, class Elem, class KEComp, class EEComp>
BinNode<Elem>* BST<Key, Elem, KEComp, EEComp>::removehelp(BinNode<Elem>* subroot, const Key& k, BinNode<Elem>*& t) {
    if(subroot == nullptr) return nullptr;
    else if(KEComp::lt(k, subroot->val())) {
        subroot->setLeft(removehelp(subroot->left(), k, t));
    }
    else if(KEComp::gt(k, subroot->val())) {
        subroot->setRight(removehelp(subroot->right(), k, t));
    }
    else {
        BinNode<Elem>* temp;
        if(subroot->left() == nullptr) {
            subroot = subroot->right();
        }
        else if(subroot->right() == nullptr) {
            subroot = subroot->left();
        }
        else {
            subroot->setRight(removehelp(subroot->right(), k, temp));
            Elem te = subroot->val();
            subroot->setVal(temp->val());
            temp->setVal(te);
            t = temp;
        }
    }
    return subroot;
}

template<class Key, class Elem, class KEComp, class EEComp>
bool BST<Key, Elem, KEComp, EEComp>::findhelp(BinNode<Elem>* subroot, const Key& k, Elem& item) const {
    if(subroot == nullptr) return false;
    else if(KEComp::lt(k, subroot->val())) {
        return findhelp(subroot->left(), k, item);
    }
    else if(KEComp::gt(k, subroot->val())) {
        return findhelp(subroot->right(), k, item);
    }
    else {
        item = subroot->val();
        return true;
    }
}

template<class Key, class Elem, class KEComp, class EEComp>
void BST<Key, Elem, KEComp, EEComp>::printhelp(BinNode<Elem>* subroot, int level) const {
    if(subroot == nullptr) return nullptr;
    printhelp(subroot->left(), level+1);
    for(int i = 0; i < level; i++) {
        cout << " ";
    }
    cout << subroot->val() << endl;
    printhelp(subroot->right(), level+1);
}