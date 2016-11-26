#ifndef HEAP_H
#define HEAP_H


class heap
{
public:
    heap(const int n);
    virtual ~heap(){delete [] heapArray;}
    bool isEmpty();
    bool isLeaf(int pos) const;
    int lChild(int pos) const;
    int rChild(int pos) const;
    int parent(int pos) const;
    bool remove(int pos, int node);
    bool insert(const int newNode);
    int removeMin();
    void siftUp(int position);
    void siftDown(int left);
    void print();
private:
    int *heapArray;
    int currentSize;
    int maxSize;
    void swap(int posX, int posY);
    void buildHeap();
};

#endif // HEAP_H
