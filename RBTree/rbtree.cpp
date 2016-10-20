#include "rbtree.h"

RBTree::RBTree()
{

}

RBTree::~RBTree(){

}

void RBTree::rightRotate(Node *node){

}

void RBTree::leftRotate(Node *node){

}

void RBTree::colorChangedWhenCase1(Node *node){

}

void RBTree::colorChangedWhenCase3(Node *node){

}

void RBTree::insert(int x){
    // A B two cases, they are symetry.


    // when it is A , there are three cases
    // one is   when x's uncle is "red", Do colorchangedWhenCase1
    // sec is   when x's uncle is "black", and it , its parent, its grandParent are Z, just do rotation , goto Case3
    // thi is   when it, its parent, its grandPa are at a line , do colorChangedWhenCase3

    // ok, it must be a loop, end up with the Node is root;
}

void RBTree::remove(int x){

}

int RBTree::getTheRank(Node* node){
    // size[left(node)]
}

