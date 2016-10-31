#include <iostream>
#include "list.h"
#include "jumplist.h"

jumplist::jumplist()
{
    root = jlist.getHead();
    start = root;
    lNum = 1;
}

Node* jumplist::search(const int x){
    int i = lNum;
    Node* tmp = start;
    Node* tmp2 = start;
    bool flag = false;
    while(i || tmp->next != NULL){
        if(tmp->next->val > x){
            tmp = tmp->down;
            --i;
            if(i == 1 && !flag){
                tmp2 = tmp;
                flag = true;
            }
            continue;
        }
        if(tmp->next->val == x){
            tmp = tmp->next;
            while(--i){ tmp = tmp->down;}
            return tmp;
        }
        tmp = tmp->next;
    }
    if(tmp->next == NULL){
        while(--i){ tmp = tmp->down;}
        return tmp;
    }
    cout<< "***Error when search"<<endl;
    return tmp2;
}

bool jumplist::insert(const int x){

}

bool jumplist::random(){
    if(rand() % 2 == 0) return true;
    else return false;
}

//bool jumplist::insert(const int x){

//}

void jumplist::doText(){
    makeIdeal();
//    search(66);
    cout<<"finished " << search(66)->next->val<<endl;
}

void jumplist::makeIdeal(){
    jlist.insert(23);
    jlist.insert(34);
    jlist.insert(42);
    jlist.insert(50);
    jlist.insert(59);
    jlist.insert(66);
    jlist.insert(72);
    jlist.insert(79);
    append(-2147483647, root, false);
    append(-2147483647, root->up, false);
    append(-2147483647, root->up->up, false);
    append(34, jlist.search(34), false);
    append(50, jlist.search(50), false);
    append(50, jlist.search(50)->up, false);
    append(66, jlist.search(66), false);

    append(79, jlist.search(79), false);
    append(79, jlist.search(79)->up, false);
    append(79, jlist.search(79)->up->up, false);
    root->up->next = jlist.search(34)->up;
    jlist.search(34)->up->next = jlist.search(50)->up;
    jlist.search(50)->up->next = jlist.search(66)->up;
    jlist.search(66)->up->next = jlist.search(79)->up;

    root->up->up->next = jlist.search(50)->up->up;
    root->up->up->next = jlist.search(79)->up->up;
    root->up->up->up->next = jlist.search(79)->up->up->up;
    lNum = 4;
    start = root->up->up->up;
}

void jumplist::append(const int x, Node *node, bool i){
    Node* tmp = new Node;
    tmp->val = x;

    if(i){
        node->next = tmp;
        tmp->pre = node;
        tmp->next = NULL;
    }else{
        node->up = tmp;
        tmp->down = node;
        tmp->up = NULL;
//       lNum ++;
    }
}




