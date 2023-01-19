#include "BinTree_Implementation.h"
// Preorder traversal
template<class Elem>
void preorder(BinNode<Elem>* subroot) {
    if(subroot == nullptr) return;
    visit(subroot);
    preorder(subroot->left());
    preorder(subroot->right());
}

// Postorder traversal
template<class Elem>
void postorder(BinNode<Elem>* subroot) {
    if(subroot == nullptr) return;
    postorder(subroot->left());
    postorder(subroot->right());
    visit(subroot);
}

// Inorder traversal
template<class Elem>
void inorder(BinNode<Elem>* subroot) {
    if(subroot == nullptr) return;
    inorder(subroot->left());
    visit(subroot);
    inorder(subroot->right());
}