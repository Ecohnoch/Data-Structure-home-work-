#include <iostream>
#include "heap.h"
using namespace std;

heap::heap(const int n){
    if(n <= 0) return;
    currentSize = 0;
    maxSize = n;
    heapArray = new int[maxSize];
    buildHeap();
}

bool heap::isLeaf(int pos) const{
    return (pos >= currentSize / 2) && (pos < currentSize);
    // 要比 2n 大, 而且要比整个的size小
}

void heap::buildHeap(){
    for(int i = currentSize / 2 - 1; i >= 0; --i){
        siftDown(i); // 反复调用筛选函数
    }
}

int heap::lChild(int pos) const{
    return 2 * pos + 1;
}

int heap::rChild(int pos) const{
    return 2 * pos + 2;
}

int heap::parent(int pos) const{
    return (pos - 1) / 2;
}

bool heap::insert(const int newNode){
    if(currentSize == maxSize) return false;
    heapArray[currentSize] = newNode;
    // 先弄到完全二叉树的那个位置
    siftUp(currentSize);  // 向上调整
    currentSize ++;
    return true;
}


int heap::removeMin(){
    if(currentSize == 0){
        cout<< "*** Error when remove min";
        return -1;
    }
    swap(0, --currentSize);  // 把堆顶元素和  完全二叉树的那个最后的一个元素交换
    if(currentSize > 1) siftDown(0);//从堆顶开始筛选, 维护堆的性质
    return heapArray[currentSize];
}

bool heap::remove(int pos, int node){
    if(pos < 0 || pos >= currentSize) return false;
    node  = heapArray[pos];
    heapArray[pos] =  heapArray[--currentSize];
    // 用最后一个元素值来替代删除位置的元素
    if(heapArray[parent(pos)] > heapArray[pos]){
        siftUp(pos);   //当前元素小于父亲结点的话, 向上调整
    }else{
        siftDown(pos); //当前元素大于父亲结点的话, 向下筛选
    }
    return true;
}

void heap::siftUp(int position){
    int tmpPos = position;
    int tmp = heapArray[tmpPos];
    while(tmpPos > 0 && heapArray[parent(tmpPos)] > tmp){
        // 只要它爸爸比它大, 就换换换
        heapArray[tmpPos] = heapArray[parent(tmpPos)];
        tmpPos = parent(tmpPos);
        // 然后位置不停的上升
    }
    // 找到最后的位置之后,, 才把这玩意给弄到那个位置上面
    heapArray[tmpPos] = tmp;
}

void heap::siftDown(int left){
    int i = left;
    int j = lChild(i);
    int tmp = heapArray[i];
    while(j < currentSize){
        if(j < currentSize && heapArray[j] > heapArray[j + 1]){
            // 让j指向两个儿子中较小的哪一个
            j++;
        }
        if(tmp > heapArray[j]){//如果父节点大于子节点就交换位置
            heapArray[i] = heapArray[j];
            i = j;
            j = lChild(j);
        }else{
            break;
        }
    }
    heapArray[i] = tmp;
}

void heap::swap(int posX, int posY){
    int tmp = heapArray[posX];
    heapArray[posX] = heapArray[posY];
    heapArray[posY] = tmp;
}

void heap::print(){
    int i;
    for(i = 0; i < currentSize; ++i){
        printf("%d ", heapArray[i]);
    }
}

