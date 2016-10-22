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
    intervalTreeNode();
    void append(Node* node, bool direction, int l, int r);
    void preOrder(Node*);
    int getM(Node* );
    int getSize(Node* );
    int getRank(Node* );

    void rightRotate(Node* );
    void leftRotate(Node* );
    void test();
};

#endif // INTERVALTREENODE_H
