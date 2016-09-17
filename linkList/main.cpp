#include <iostream>

using namespace std;

struct Node{
    int val;
    Node* next;
};

class LinkList{
public:
    LinkList(){
        head = new Node;
        head->val = 2147483647;
        head->next = NULL;
        size = 0;
    }

    bool isEmpty(){
      if(head->val == NULL) return false;
      else return true;
    }
    void insert(int x){
        if(head->val == 2147483647) head->val = x;
        else{
            Node* tmp = head;
            while(tmp->next != NULL) {tmp = tmp->next;}
            tmp->next = new Node;
            tmp = tmp->next;
            tmp->val = x;
            tmp->next = NULL;
            size++;
        }
    }
    void text(){
        insert(11);insert(22);insert(33);
        cout<<head->val <<head->next->val <<head->next->next->val <<endl;
    }

    void linkDelete(int i){
        for(Node* tmp; tmp != NULL; tmp = tmp->next){
            if(tmp->next->val == i){
                //delete
            }
        }
    }

    int search(int i);
    int locate(int i);
    void getLength();
private:
    int size;
    Node* head;
};


int main()
{
    LinkList text;
    text.text();
    return 0;
}
