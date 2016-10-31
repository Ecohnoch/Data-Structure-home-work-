#ifndef LIST_H
#define LIST_H

#include<iostream>
#define __TEXT__
struct Node{
    int val;
    Node* pre;
    Node* next;
    Node* down = NULL;
    Node* up = NULL;
};

class list
{
private:
    Node* root;
    int size;
public:
    list();
    ~list() {delete [] root;}
    bool insert(const int x);
    bool insert(const int x, unsigned int i);
    Node* search(const int x);
    bool remove(unsigned int i);
    Node* getHead()const{return root;}
    int getSize()const{return size;}

#ifdef __TEXT__
    void test();
#endif
};

#endif // LIST_H
