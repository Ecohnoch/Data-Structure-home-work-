#ifndef BSEARCHTREE_H
#define BSEARCHTREE_H

#include <iostream>

struct Node{
    int val;
    Node* lChild;
    Node* rChild;
    Node* parent;
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

    void preOrder(Node* h);
    void preOrder2(Node* h);
    void inOrder(Node* h);
    void inOrder2(Node *h);
    void postOrder(Node *h);
    void postOrder2(Node* h);

    void levelOrder(Node* h);
    void test();

    void preInGetTree(int* pre, int* in, Node* r, Node* tmp);

    Node* getRoot(){return root;}
private:
    int count;
    Node* root;


};







#endif // BSEARCHTREE_H
