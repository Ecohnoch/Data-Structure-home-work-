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
      if(head->val == 2147483647) return false;
      else return true;
    }
    void insert(int x){
        if(head->val == 2147483647) {head->val = x; size++;}
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

    // delete as value
    void linkDelete(int i){
        for(Node* tmp = head; tmp->next != NULL; tmp = tmp->next){
            if(tmp->next->val == i){
                Node *pdelete = tmp->next;
                if(pdelete->next != NULL)
                    tmp->next = pdelete->next;
                delete pdelete;
                pdelete = NULL;
            }else{
                printf("*** delete wrong, no data in the link list!!");
            }
        }
    }
    //delete as locate
    void deleteLocate(int i){
        Node *tmp = head, *pdelete;
        if( i == 1){
            head = tmp->next;
            delete tmp;
            tmp = NULL;
            size--;
        }else{
            for(int x = 0; x < i - 2; x++){
                tmp = tmp->next;
            }
            pdelete = tmp->next;
            tmp->next = pdelete->next;
            delete pdelete;
            pdelete = NULL;
            size--;
        }
    }

    int search(int i){
        Node *tmp = head;
        for(int x = 0; x < i - 1; x++){
            tmp = tmp->next;
        }
        return tmp->val;
    }

    int locate(int i){
        Node *tmp = head;
        int x = 0;
        for(; x < size; x++){
            if(tmp->val == i){
                return (x+1);
            }
            tmp = tmp->next;
        }
        printf("*** not find !!");
    }

    int getLength(){
        return size;
    }


    void text(){
        insert(11);insert(22);insert(33);
        cout<<head->val <<head->next->val <<head->next->next->val<< size <<endl;
        linkDelete(22);
        cout<<head->val <<head->next->val <<endl;
        deleteLocate(2);
        if(head->next == NULL)
            cout<< head->val;
    }

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
