#include <algorithm>
#include <iostream>
#include <stack>
#include "intervaltreenode.h"
using namespace std;

template <class T>
intervalTreeNode<T>::intervalTreeNode()
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

template <class T>
void intervalTreeNode<T>::testInterval(){
    append(root,true, 5, 11);
    append(root->lChild, true, 4, 8);
    append(root->lChild, false, 15, 18);
    append(root->lChild->rChild, true, 7, 10);
    append(root, false, 21, 23);
    root->lChild->color = true;
    root->lChild->rChild->lChild->color = true;
}

template <class T>
void intervalTreeNode<T>::testRBT(){
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


template <class T>
void intervalTreeNode<T>::append(Node<T> *node, bool direction, int l, int r){
    Node<T>* tmp = new Node<T>;
    tmp->left = l;
    tmp->right = r;
    tmp->m = r;
    tmp->lChild = NULL;
    tmp->rChild = NULL;
    tmp->parent = node;
    if(direction) node->lChild = tmp;
    else node->rChild = tmp;
}

template <class T>
void intervalTreeNode<T>::preOrder(Node<T>* node){
    cout<< node->left<<" "<< node->right<<" color: "<< (node->color?"red":"black") <<endl;
    if(node->lChild != NULL)
        preOrder(node->lChild);
    if(node->rChild != NULL)
        preOrder(node->rChild);
}

template <class T>
void intervalTreeNode<T>::inOrder(){
    stack<Node<T>*> s;
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

template <class T>
int intervalTreeNode<T>::getM(Node<T> *node){
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

template <class T>
int intervalTreeNode<T>::getSize(Node<T> *node){
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

template <class T>
int intervalTreeNode<T>::getRank(Node<T> *node){
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

template <class T>
void intervalTreeNode<T>::leftRotate(Node<T> *node){
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

template <class T>
void intervalTreeNode<T>::rightRotate(Node<T> *node){
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

template <class T>
void intervalTreeNode<T>::insert(int x){
    Node<T>* tmp = root;
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
    Node<T>* node = new Node<T>;
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
    rbInsertFixUp(tmp);

}

template <class T>
Node<T>* os_select(Node<T>* node, i){
    int r = getSize(node->lChild) + 1;
    if( i == r)
        return node;
    else if(i < r){
        return os_select(node->lChild, i);
    }else
        return os_select(node->rChild, i - r);
}

template <class T>
void intervalTreeNode<T>::rbInsertFixUp(Node<T> *z){
    while( z->p->color  == true ){
        if( z->p == z->p->p->left ){  //case A
            _rbTreeNode<T> * y = z->p->p->right;
            if( y->color == true ){
                z->p->color = false;
                y->color = false;
                z->p->p->color = true;
                z = z->p->p;
            }
            else{
                if( z == z->p->right ){
                    z = z->p;
                    leftRotate( z );
                }//
                z->p->color = false;
                z->p->p->color = true;
                z->p->right->color = false;
                rightRotate( z->p->p );
            }
        }
        else{   // case B
            _rbTreeNode<T> * y = z->p->p->left;
            if( y->color == true ){
                z->p->color = false;
                y->color = false;
                z->p->p->color = true;
                z = z->p->p;
            }
            else{
                if( z == z->p->left ){
                    z = z->p;
                    rightRotate( z );
                }
                z->p->color = false;
                z->p->p->color = true;
                z->p->left->color = false;
                leftRotate( z->p->p );
            }
        }
    }
    root->color = false;
}



template <class T>
void intervalTreeNode<T>::test(){
    insert(4);
    preOrder(root);
}
