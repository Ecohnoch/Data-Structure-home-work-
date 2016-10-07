#include "bsearchtree.h"

void BSearchTree::insert(int x){
    if(root->val == 1000){
        root->val = x;
        count = 1;
    }else{
        Node* tmp = root;
        while(tmp != NULL){
            if(x >= tmp->val){
                if(tmp->rChild == NULL){
                    Node* tmp2 = new Node;
                    tmp2->val = x;
                    tmp2->lChild = NULL;
                    tmp2->rChild = NULL;
                    tmp->rChild = tmp2;
                    break;
                }
                tmp = tmp->rChild;

            }else{
                if(tmp->lChild == NULL){
                    Node* tmp2 = new Node;
                    tmp2->val = x;
                    tmp2->lChild = NULL;
                    tmp2->rChild = NULL;
                    tmp->lChild = tmp2;
                    break;
                }
                tmp = tmp->lChild;
            }
        }
    }
}
void BSearchTree::remove(int x){

}

void BSearchTree::order(Node* h){
    if(h == NULL)
        return ;
    else{
        printf("val: %d\n", h->val);
        order(h->lChild);
        order(h->rChild);
    }
}

bool BSearchTree::search(int x){
    Node* tmp = root;
    while(tmp != NULL){
        if(x == tmp->val)
            return true;
        else if(x > tmp->val){
            tmp = tmp->rChild;
        }else if(x < tmp->val){
            tmp = tmp->lChild;
        }
    }
    return false;
}

void BSearchTree::test(){
    insert(11);insert(22);insert(13);insert(35);
    insert(21);insert(7);
    order(root);
    if(search(36)){
        printf("Search true");
    }else{
        printf("Search false");
    }
}







