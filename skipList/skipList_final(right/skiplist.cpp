#include <ctime>
#include <iostream>

#include "skiplist.h"

using namespace std;

skipList::skipList()
{
    root = new Node;
    root->val = -2147483647;
    tail = new Node;
    tail->val = 2147483647;
    for(int i = 0; i < MAX_LEVEL; i++){
        root->next[i] = tail;
        tail->next[i] = NULL;
    }
    level = 0;
}

bool skipList::find(const int x) const{
    Node* fromRoot = root;
    for(int i = level; i >= 0; --i){
        while(fromRoot->next[i] != NULL && fromRoot->next[i]->val < x){
            fromRoot = fromRoot->next[i];
        }
        if(fromRoot->next[i]->val == x){
            return true;
        }
    }
    return false;
}

bool skipList::insert(const int x){
    Node* tmp = new Node;
    tmp->val = x;
    int tmpLevel = random();

    Node* fromRoot = root;
    for(int i = level; i >= 0; --i){
        if(fromRoot->next[i]->val == x){
            cout<< "Already exist"<<endl;
            return false;
        }
        while(fromRoot->next[i] != NULL && fromRoot->next[i]->val < x){
            fromRoot = fromRoot->next[i];
        }
    }
    tmp->next[0] = fromRoot->next[0];
    fromRoot->next[0] = tmp;
    level = level > tmpLevel ? level : tmpLevel;
    for(int i = 1; i <= tmpLevel; ++i){
        Node* findPos = root;
        while(findPos->next[i]->val < x){findPos = findPos->next[i];}
        tmp->next[i] = findPos->next[i];
        findPos->next[i] = tmp;
    }
    return true;
}



int skipList::random(){
    srand((unsigned)time(NULL));
    srand(rand());
    srand(rand());
    int count = 0;
    int randomTable[MAX_LEVEL];
    for(int i = 0; i < MAX_LEVEL; ++i){
        randomTable[i] = rand()%2;
        if(randomTable[i]){
            count ++;
        }else {break;}
    }
    return count;
}

void skipList::test(){
    cout<<"ran: "<<random()<<endl;
    insert(3);
    insert(4);
    insert(5);
    insert(6);
    insert(7);


    cout<<"lev: "<<level<<endl;
    for(int i = 0; i <= level; ++i){
        Node* p = root;
        while(p != NULL){
            cout<<p->val<<" ";
            p = p->next[i];
        }
        cout<<endl;
    }

    cout<<find(6)<<endl;
}
