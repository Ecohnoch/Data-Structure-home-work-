#include <algorithm>
#include <iostream>
#include "intervaltreenode.h"
using namespace std;

intervalTreeNode::intervalTreeNode()
{
      root = new Node;
      root->left = 12;
      root->right = 19;
      root->m = 19;
      root->lChild = NULL;
      root->rChild = NULL;
      root->parent = NULL;
      append(root,true, 5, 11);
      append(root->lChild, true, 4, 8);
      append(root->lChild, false, 15, 18);
      append(root->lChild->rChild, true, 7, 10);
      append(root, false, 21, 23);
}

void intervalTreeNode::append(Node *node, bool direction, int l, int r){
    Node* tmp = new Node;
    tmp->left = l;
    tmp->right = r;
    tmp->m = r;
    tmp->lChild = NULL;
    tmp->rChild = NULL;
    tmp->parent = node;
    if(direction) node->lChild = tmp;
    else node->rChild = tmp;
}

void intervalTreeNode::preOrder(Node* node){
    cout<< node->left<<" "<< node->right<< " m:" << getM(node)<< " size: "<< getSize(node)<< " rank"<< getRank(node) <<endl;
    if(node->lChild != NULL)
        preOrder(node->lChild);
    if(node->rChild != NULL)
        preOrder(node->rChild);

}

int intervalTreeNode::getM(Node *node){
    if(node == NULL)
        return -1;
    else{
        if(node->lChild == NULL)
            return node->m;
        node->m = max(node->m, getM(node->lChild));
        if(node->rChild == NULL)
            return node->m;
        node->m = max(node->m, getM(node->rChild));
        return node->m;
    }
}

int intervalTreeNode::getSize(Node *node){
    if(node == NULL)
        return -1;
    else{
        if(node->lChild == NULL && node->rChild == NULL)
            return 1;
        if(node->rChild == NULL)
            return getSize(node->lChild) + 1;

        if(node->lChild == NULL)
            return getSize(node->rChild) + 1;

        node->size = 1 + getSize(node->rChild) + getSize(node->lChild);
        return node->size;
    }
}

int intervalTreeNode::getRank(Node *node){
    if(node == NULL)
        return -1;
    else{
        if(node->lChild == NULL)
            return 1;
        return getSize(node->lChild) + 1;
    }
}


void intervalTreeNode::leftRotate(Node *node){
    if(node->lChild == NULL)
        return;
    if(node->lChild->rChild == NULL){
        node->lChild->rChild = node;
        node->lChild = NULL;
    }else{
        node->rChild = node->lChild->rChild;
        node->lChild->rChild = node;
        if(node->parent == NULL){
            root = node->lChild;
            return;
        }
        if(node->parent->lChild == node)
            node->parent->lChild = node->lChild;
        else
            node->parent->rChild = node->lChild;
    }
}


void intervalTreeNode::rightRotate(Node *node){
    if(node->rChild == NULL)
        return;
    if(node->rChild->lChild == NULL){
        node->rChild->lChild = node;
    }else{
        node->lChild = node->rChild->lChild;
        node->rChild->lChild = node;
        if(node->parent == NULL){
            root = node->rChild;
            return;
        }
        if(node->parent->lChild == node)
            node->parent->lChild = node->rChild;
        else
            node->parent->rChild = node->rChild;
    }
}

void intervalTreeNode::test(){
    Node* tmp = root->lChild;
    cout<<"debug + "<< tmp->parent->left<<endl;
    //leftRotate(root);
    preOrder(tmp);
}
