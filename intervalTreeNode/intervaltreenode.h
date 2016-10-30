#ifndef INTERVALTREENODE_H
#define INTERVALTREENODE_H
/////////////////////////////////////////////////////
//   1, 红黑+动态顺序统计+区间树节点声明  Node
//   2, intervalTree 声明            intervalTreeNode
//   3, 测试程序                      main()
/////////////////////////////////////////////////////
#define __TEST__

#include <iostream>
////////////////////////////////////////////////////
//  1, 结点定义   Node
////////////////////////////////////////////////

template <class T>
class intervalTreeNodel;

template <class T>
struct Node{    //节点
    friend class intervalTreeNode<T>;
    T getKey(){ return key;}  //获得键值
private:
    T key;
    int left;
    int right;
    Node<T>* lChild;
    Node<T>* rChild;
    Node<T>* parent;

    bool color = false; // true is red, false is black
    int m;
    int size;      //OS-Tree expand
    int rank;      //Many trees has this expand
};

//////////////////////////////////////////////////
// 2. 红黑树 类声明
//////////////////////////////////////////////////

template <class T>
class intervalTreeNode
{
private:
    Node* root;

public:
    // pre func
    intervalTreeNode();
    void append(Node* node, bool direction, int l, int r);
    void preOrder(Node*);
    void inOrder();

    //main func
    void insert(T data);
    void insert(int i);
    void insert(int l, int r);
    Node<T>* search(T key);

    Node* os_select(Node* , int i);


    // aux func
    int getM(Node<T>* );
    int getSize(Node<T>* );
    int getRank(Node<T>* );

    void rightRotate(Node<T>* );
    void leftRotate(Node<T>* );
    void rbInsertFixUp(Node<T>*);


#ifdef __TEST__
    void test();
#endif

};

#endif // INTERVALTREENODE_H
