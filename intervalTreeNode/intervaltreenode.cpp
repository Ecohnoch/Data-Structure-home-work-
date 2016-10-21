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
    if(direction) node->lChild = tmp;
    else node->rChild = tmp;
}

void intervalTreeNode::preOrder(Node* node){
    cout<< node->left<<" "<< node->right<< " " << getM(node) <<endl;
    if(node->lChild != NULL)
        preOrder(node->lChild);
    if(node->rChild != NULL)
        preOrder(node->rChild);

}

void intervalTreeNode::test(){
    preOrder(root);
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


