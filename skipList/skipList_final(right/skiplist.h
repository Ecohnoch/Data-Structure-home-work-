#ifndef SKIPLIST_H
#define SKIPLIST_H
#define MAX_LEVEL 5

struct Node{
    int val;

    Node* next[MAX_LEVEL];
};


class skipList
{
public:
    skipList();

    bool insert(const int x);
    bool find(const int x)const;
    int random();
    void test();
private:
    Node* root;
    Node* tail;

    int level;

};

#endif // SKIPLIST_H
