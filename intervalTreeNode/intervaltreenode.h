#ifndef INTERVALTREENODE_H
#define INTERVALTREENODE_H

#include <iostream>
struct Node{
    int left;
    int right;
    Node* lChild;
    Node* rChild;

    bool color = false; // true is red, false is black
    int m;
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


    void test();
};

#endif // INTERVALTREENODE_H
