#ifndef LINKLIST_H
#define LINKLIST_H

#include <iostream>

struct Node{
    int val;
    Node* next;
};

class LinkList{
public:
    LinkList(){
        head = new Node;
        head->val = 10000000;
        head->next = NULL;
        size = 0;
    }
    ~LinkList(){
        Node* tmp = head;
        for(; head != NULL;){
            tmp = head;
            head = head->next;
            delete tmp;
            tmp = NULL;
        }
    }

    void insert(int x);
    void positionInsert(int i, int x);
    void remove();
    void positionRemove(int i);

    void change(int i, int x);

    int getVal(int i);
    int getPos(int x);
    Node* getHead(){
        return head;
    }

    int getSize(){
        return size;
    }
    bool isEmpty(){
        if(head->val == 10000000){
            return true;
        }else{
            return false;
        }
    }

    void test();


private:
    Node* head;
    int size;
};

#endif // LINKLIST_H
