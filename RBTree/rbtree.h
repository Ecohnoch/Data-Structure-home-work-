#ifndef RBTREE_H
#define RBTREE_H

//RBTree

struct Node{
    int val;
    bool color;
    Node* lChild;
    Node* rChild;

    int size;   // expand
};



class RBTree
{
public:
    RBTree();
    ~RBTree();
    void insert(int x);
    void remove(int x);

    void order();
    int getTheRank(Node* node);


    //aux functions
    void rightRotate(Node* node);
    void leftRotate(Node* node);
    void colorChangedWhenCase1(Node* node);
    void colorChangedWhenCase3(Node* node);
private:
    Node* root;


};

#endif // RBTREE_H
