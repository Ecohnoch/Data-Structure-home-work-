#ifndef JUMPLIST_H
#define JUMPLIST_H

#include "list.h"
using namespace std;

#define __ClassicalText__

class jumplist
{
private:
    list jlist;
    Node* root;
    Node* start;
    int lNum;

public:
    jumplist();
    Node* search(const int x);
    bool insert(const int x);
    bool random();

#ifdef __ClassicalText__
    void doText();
    void makeIdeal();
    void append(const int x, Node* node, bool i);
        // node, 1: next, 2: up
#endif
};

#endif // JUMPLIST_H
