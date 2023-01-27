#include <iostream>
using namespace std;
template<class Elem, class Comp>
class maxHeap
{
private:
    Elem* heap; // Pointer to the heap array
    int maxSize; // Maximum size of the heap
    int n; // Number of elements now in the heap
    void siftdown(int pos); // Put element in place

public:
    maxHeap(Elem* h, int num, int max); // Constructor
    int heapSize() const; // Return current heap size
    bool isLeaf(int pos) const; // True if pos is leaf
    int leftChild(int pos) const; // Return leftChild position
    int rightChild(int pos) const; // Return rightChild position
    int parent(int pos) const; // Return parent position
    bool insert(const Elem& item); // insert item to the heap
    bool removeMax(Elem& it); // remove the max element in the heap
    bool remove(int pos, Elem& it); // remove the element at specified position
    void buildHeap(); // Heapify contents of heap
};

// Constructor
template<class Elem, class Comp>
maxHeap<Elem, Comp>::maxHeap(Elem* h, int num, int max) {
    heap = h;
    n = num;
    maxSize = max;
    buildHeap();
}

// Put element in place
template<class Elem, class Comp>
void maxHeap<Elem, Comp>::siftdown(int pos) {
    while(!isLeaf(pos)) {
        j = leftChild(pos);
        rc = rightChild(pos);
        if((rc < n) && Comp::lt(heap[j], heap[rc])) {
            j = rc;
        }
        if(!Comp::lt(heap[pos], heap[j])) {
            return;
        }
        swap(heap, pos, j);
        pos = j;
    }
}

// Return current heap size
template<class Elem, class Comp>
int maxHeap<Elem, Comp>::heapSize() const {
    return n;
}

// True if pos is leaf
template<class Elem, class Comp>
bool maxHeap<Elem, Comp>::isLeaf(int pos) const {
    return (pos >= n/2) && (pos < n);
}

// Return leftChild position
template<class Elem, class Comp>
int maxHeap<Elem, Comp>::leftChild(int pos) const {
    return 2*pos + 1;
}

// Return rightChild position
template<class Elem, class Comp>
int maxHeap<Elem, Comp>::rightChild(int pos) const {
    return 2*pos + 2;
}

// Return parent position
template<class Elem, class Comp>
int maxHeap<Elem, Comp>::parent(int pos) const {
    return (pos-1) / 2;
}

// insert item to the heap
template<class Elem, class Comp>
bool maxHeap<Elem, Comp>::insert(const Elem& item) {
    if(n >= maxSize) return false;
    int curr = n++;
    heap[curr] = item;
    while((curr != 0) && Comp::gt(heap[curr], heap[parent(curr)])) {
        swap(heap, curr, parent(curr));
        curr = parent(curr);
    }
    return true;
}

// remove the max element in the heap
template<class Elem, class Comp>
bool maxHeap<Elem, Comp>::removeMax(Elem& it) {
    if(n == 0) return false;
    swap(heap, 0, --n);
    if(n != 0) siftdown(0);
    it = heap[n];
    return true;
}

// remove the element at specified position
template<class Elem, class Comp>
bool maxHeap<Elem, Comp>::remove(int pos, Elem& it) {
    bool flag = false;
    if((pos < 0) || (pos >= n)) return false;
    swap(heap, pos, --n);
    while((pos != 0) && (Comp::gt(heap[pos], heap[parent[pos]]))) {
        swap(heap, pos, parent[pos]);
        pos = parent[pos];
        flag = true;
    }
    if(!flag) siftdown(pos);
    it = heap[n];
    return true;
}

// Heapify contents of heap
template<class Elem, class Comp>
void maxHeap<Elem, Comp>::buildHeap() {
    for(int i = n/2 - 1; i >= 0; i--) {
        siftdown(i);
    }
}