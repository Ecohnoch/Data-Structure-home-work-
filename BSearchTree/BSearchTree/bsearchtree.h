#ifndef BSEARCHTREE_H
#define BSEARCHTREE_H

#include <iostream>

struct Node{
    int val;
    Node* lChild;
    Node* rChild;
};

class BSearchTree{
public:
    BSearchTree(){
        count = 0;
        root = new Node;
        root->val = 1000;
        root->lChild = NULL;
        root->rChild = NULL;
    }

    void insert(int x);
    void remove(int x);
    bool search(int x);

    void order(Node* h);
    void test();
private:
    int count;
    Node* root;


};







#endif // BSEARCHTREE_H
