#include<iostream>


#include "linklist.h"


void LinkList::insert(int x){
    Node* tmp = head;
    if(head->val == 10000000){
        head->val = x;
        size = 1;
    }else{
        while(tmp->next != NULL)
            tmp = tmp->next;
        Node* tmp2;
        tmp2 = new Node;
        tmp2->val = x;
        tmp->next = tmp2;
        tmp2->next = NULL;
        size ++;
    }
}

void LinkList::positionInsert(int i, int x){
    Node* tmp = head;
    if(i == 0){
        Node* tmp2;
        tmp2 = new Node;
        tmp2->val = x;
        tmp2->next = head;
        head = tmp2;
        size ++;
    }else if(i > size - 1){
        printf( "*** Input i error!! \n");
    }else{
        for(int j = 0; j < i - 1; j++){
            tmp = tmp->next;
        }
        Node* tmp2;
        tmp2 = new Node;
        tmp2->val = x;
        tmp2->next = tmp->next;
        tmp->next = tmp2;
        size ++;
    }
}


void LinkList::remove(){
    Node* tmp = head;
    Node* pDelete;
    if(tmp->next == NULL){
        tmp->val = 10000000;
        size = 0;
    }else{
        for(; tmp->next->next != NULL; tmp = tmp->next);
        pDelete = tmp->next;
        tmp->next = NULL;
        delete pDelete;
        pDelete = NULL;
        size --;
    }
}

void LinkList::positionRemove(int i){
    Node* tmp = head;
    Node* pDelete;
    if(i == 0){
        head = head->next;
        delete tmp;
        tmp = NULL;
        size = 0;
    }else if(i > size - 1){
        printf("*** input error!!!\n");
    }
    else{
        for(int j = 0; j < i - 1; j++){
            tmp = tmp->next;
        }
        pDelete = tmp->next;
        tmp->next = pDelete->next;
        delete pDelete;
        pDelete = NULL;
        size --;
    }
}

void LinkList::change(int i, int x){
    Node* tmp = head;
    if(i >= size || i < 0){
        printf("*** input error");
    }else{
        for(int j = 0; j < i; j++){
            tmp = tmp->next;
        }
        tmp->val = x;
    }
}

int LinkList::getVal(int i){
    Node* tmp = head;
    if(i < 0 || i >= size){
        printf("*** input error!!!\n");
        return 10000000;
    }else{
        for(int j = 0; j < i; j++){
            tmp = tmp->next;
        }
        return tmp->val;
    }
}

int LinkList::getPos(int x){
    Node* tmp = head;
    int count = 0;
    for(; tmp->next != NULL; tmp = tmp->next){
        if(tmp->val == x){
            return count;
        }
        count ++;
    }
    printf("*** can't find the value\n");
}


void LinkList::test(){
    insert(33);
    insert(22);
    insert(0);
    insert(1);
    change(1, 23);

//   -----------------------------------
    Node* tmp = head;
    for(; tmp != NULL; tmp = tmp->next){
        printf("val: %d \n", tmp->val);
    }
    printf("size: %d\n", size);
    printf("position: %d", getPos(23));
}

