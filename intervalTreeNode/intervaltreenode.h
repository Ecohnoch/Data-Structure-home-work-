#ifndef INTERVALTREENODE_H
#define INTERVALTREENODE_H

#include <iostream>
struct Node{
    int left;
    int right;
    Node* lChild;
    Node* rChild;
    Node* parent;

    bool color = false; // true is red, false is black
    int m;
    int size;      //OS-Tree expand
    int rank;      //Many trees has this expand
};

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
    void insert(int i);
    void insert(int l, int r);



    // aux func
    int getM(Node* );
    int getSize(Node* );
    int getRank(Node* );

    void rightRotate(Node* );
    void leftRotate(Node* );
    void test();
    void testInterval();
    void testRBT();

};

#endif // INTERVALTREENODE_H
