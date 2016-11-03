#include <iostream>

#include "list.h"

using namespace std;

list::list()
{
    root = new Node;
    root->val = -2147483647;
    root->next = NULL;
    root->pre = NULL;
    size = 0;
}

bool list::insert(const int x){
    Node* tmp = root;
    while(tmp->next != NULL){tmp = tmp->next;}
    Node *ist = new Node;
    ist->val = x;
    ist->next = NULL;
    ist->pre = tmp;
    tmp->next = ist;
    size ++;
    return true;
}

bool list::insert(const int x, unsigned int i){
    Node* tmp = root;
    unsigned int j = 0;
    for(; j < i; j++){
        tmp = tmp->next;
    }
    Node* ist = new Node;
    ist->val = x;
    if(tmp->next != NULL){
        Node* tmp2 = tmp->next;
        tmp2->pre = ist;
        ist->next = tmp2;
        tmp->next = ist;
        ist->pre = tmp;
    }else{
        tmp->next = ist;
        ist->pre = tmp;
        ist->next = NULL;
    }
    size ++;
    return true;
}

Node* list::search(const int x){
    Node* tmp = root;
    while(tmp->next != NULL){
        if(tmp->val == x){
            return tmp;
        }
        tmp = tmp->next;
    }
    if(tmp->val == x) return tmp;
    cout<< "***Can't find the node"<<endl;
    return root;
}

bool list::remove(unsigned int i){
    Node* tmp = root;
    unsigned int j = 0;
    for(; j < i; j++){
        tmp = tmp->next;
    }
    if(tmp == root){
        cout<< "***No node to remove"<<endl;
        return false;
    }
    if(tmp->next == NULL){
        Node* tmp2 = tmp->pre;
        tmp2->next = NULL;
    }else{
        Node* tmp2 = tmp->pre;
        Node* tmp3 = tmp->next;
        tmp2->next = tmp3;
        tmp3->pre = tmp2;
    }
    delete tmp;
    tmp = NULL;
    size --;
    return true;
}

void list::test(){
    insert(11);
    insert(22);
    insert(33);
    insert(44, 2);
    insert(55, 4);
    insert(33, 0);
    cout<<remove(3)<<remove(0)<<remove(1)<<endl;
    Node* tmp = root;

    Node* tmp2 = search(33);
    cout<< "debug" <<tmp2->next->val <<endl;
    while(tmp != NULL){
        cout<< tmp->val <<endl;
        tmp = tmp->next;
    }
}

