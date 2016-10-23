#include <algorithm>
#include <iostream>
#include <stack>
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
      testRBT();
}

void intervalTreeNode::testInterval(){
    append(root,true, 5, 11);
    append(root->lChild, true, 4, 8);
    append(root->lChild, false, 15, 18);
    append(root->lChild->rChild, true, 7, 10);
    append(root, false, 21, 23);
    root->lChild->color = true;
    root->lChild->rChild->lChild->color = true;
}

void intervalTreeNode::testRBT(){
    root->left = 11;
    append(root, true, 2, 2);
    root->lChild->color = true;
    append(root->lChild, true, 1, 1);
    append(root->lChild, false, 7, 7);
    append(root->lChild->rChild, true, 5, 5);
    root->lChild->rChild->lChild->color = true;
    append(root->lChild->rChild, false, 8, 8);
    root->lChild->rChild->rChild->color = true;
    append(root, false, 14, 14);
    append(root->rChild, false, 15, 15);
    root->rChild->rChild->color = true;
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
    cout<< node->left<<" "<< node->right<<" color: "<< (node->color?"red":"black") <<endl;
    if(node->lChild != NULL)
        preOrder(node->lChild);
    if(node->rChild != NULL)
        preOrder(node->rChild);
}

void intervalTreeNode::inOrder(){
    stack<Node*> s;
    stack<int> sv;
    Node* tmp = root;
    int tRank = 0;
    while(tmp != NULL || !s.empty())
    {
        while(tmp != NULL)
        {
            sv.push(tmp->left);
            s.push(tmp);
            tmp=tmp->lChild;
        }
        tmp = s.top();
        s.pop();
        sv.pop();
        tRank++;
        tmp->rank = tRank;
        cout<< tmp->left<< " " <<tmp->rank <<endl;
        tmp = tmp->rChild;
    }
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
        if(node->parent == NULL){
            return getSize(node->lChild) + 1;
        }else{
            if(node->parent->rChild == node){
                if(node->lChild == NULL)
                    return getRank(node->parent) + 1;
                return getRank(node->parent) + getSize(node->lChild) + 1;
            }else{
                if(node->lChild == NULL)
                    return 1;
                return getSize(node->lChild) + 1;
            }
        }
    }
}


void intervalTreeNode::leftRotate(Node *node){
    if(node->rChild == NULL)
        cout<< "***Error when left rotate!"<<endl;
    else{
        Node* tmp = node->rChild;
        if(tmp->lChild != NULL)
            node->rChild = tmp->lChild;
        else
            node->rChild = NULL;
        tmp->lChild = node;
        if(node->parent != NULL)
            if(node->parent->lChild == node)
                node->parent->lChild = tmp;
            else
                node->parent->rChild = tmp;
        else
            root = tmp;
    }
}


void intervalTreeNode::rightRotate(Node *node){
    if(node->lChild == NULL)
        cout<< "***Error when right rotate"<<endl;
    else{
        Node* tmp = node->lChild;
        if(tmp->rChild != NULL)
            node->lChild = tmp->rChild;
        else
            node->lChild = NULL;
        tmp->rChild = node;
        if(node->parent != NULL)
            if(node->parent->lChild == node)
                node->parent->lChild = tmp;
            else
                node->parent->rChild = tmp;
        else
            root = tmp;
    }
}

void intervalTreeNode::insert(int x){
    Node* tmp = root;
    bool direction = false;  // true -> left, false -> right;
    while(1){
        if(tmp->left >= x){
            if(tmp->lChild == NULL){
                direction = true;
                break;
            }else
                tmp = tmp->lChild;
        }else{
            if(tmp->rChild == NULL){
                direction = false;
                break;
            }else
                tmp = tmp->rChild;
        }
    }
    Node* node = new Node;
    node->left = x;
    node->lChild = NULL;
    node->rChild = NULL;
    node->color = true;
    if(direction){
        tmp->lChild = node;
    }else
        tmp->rChild = node;
    node->parent = tmp;
    // ↑ find the position , and insert it;

    //case A
    if(node->parent == NULL)
        root = node;

    while(node->parent->color){

        if(node->parent->parent == NULL){
            if(node->parent->lChild == node){
                if(node->parent->rChild->color == false){
                    node->parent->lChild->color = false;
                }else
                    node->parent->lChild->color = true;
            }else{
                if(node->parent->lChild->color == false){
                    node->parent->rChild->color = false;
                }else
                    node->parent->rChild->color = true;
            }
        }


        if(node->parent->parent->lChild == node->parent){
            if(node->parent->parent->rChild == NULL || node->parent->parent->rChild->color){
                node->parent->parent->color = true;
                node->parent = false;
                if(node->parent->parent->rChild != NULL)
                    node->parent->parent->rChild = false;
                node = node->parent->parent;
            }else{
                if(node->parent->rChild == node){
                    node = node->parent;
                    leftRotate(node);
                }else
                    node = node->parent;
                node->color = false;
                node->lChild->color = true;
                node->parent->color = true;
                rightRotate(node->parent);
                node->lChild->color = true;
                node->rChild->color = true;
            }
        }else{
            if(node->parent->parent->lChild == NULL || node->parent->parent->lChild->color){
                node->parent->parent->color = true;
                node->parent = false;
                if(node->parent->parent->lChild != NULL)
                    node->parent->parent->lChild = false;
                node = node->parent->parent;
            }else{
                if(node->parent->lChild == node){
                    node = node->parent;
                    rightRotate(node);
                }else
                    node = node->parent;
                node->color = false;
                node->rChild->color = true;
                node->parent->color = true;
                leftRotate(node->parent);
                node->rChild->color = true;
                node->lChild->color = true;
            }
        }
    }

    root->color = false;

}




void intervalTreeNode::test(){
    //insert(4);
    preOrder(root);
}
