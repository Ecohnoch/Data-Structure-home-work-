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

    int homeWork1(){
        Node *tmp = head;
        Node *tmp2 = head;
        int min = tmp->val, count = 0;
        for(; tmp->next != NULL; tmp = tmp->next){
            if(tmp->val < min){
                min = tmp->val;
            }
        }

        for(tmp = head; tmp->next != NULL; tmp = tmp->next){
            if(tmp->val == min) {
                count++;
            }
        }
        cout<< count<<endl;
        for(int i = 0; i < count; i++){
            for(tmp = head; tmp->next != NULL; tmp = tmp->next){
                if(tmp->val == min){
                    for(tmp2 = head; tmp2->next != NULL; tmp2 = tmp2->next);
                    tmp->val = tmp2->val;
                    tmp2 = NULL;
                    size--;

                }
            }
        }

        cout<<"min = "<<min<<endl;
        return min;
    }

    void testHW1(){
        insert(0);
        insert(0);
        insert(1);
        insert(1);

        for(int i = 4; i < 10; i++){
            insert(i);
        }

        Node* tmp = head;
        homeWork1();
        for( int i = 0; i < size; i++){
            cout<< tmp->val <<endl;
            tmp = tmp->next;
        }
    }

    void testDelete(){
        Node* tmp = head;
        insert(1); insert(2); insert(3);
        linkDelete(2);
        for(; tmp != NULL; tmp = tmp ->next){
            cout<< tmp->val <<endl;
        }
    }

    void homeWork2(int x){
        linkDelete(x);
    }

    void testHW2(){
        Node* tmp = head;
        insert(0);
        insert(0);
        insert(1);
        insert(0);
        insert(1);
        insert(1);
        insert(1);
        for(int i = 5; i < 10; i++){
            insert(i);
        }
        insert(1);
        linkDelete(1);
        for(; tmp!=NULL; tmp = tmp->next){
            cout<< tmp->val << endl;
        }
    }

    void homeWork3(int s, int t){
        for(int i = s; i <= t; i ++){
            linkDelete(i);
        }
    }

    void testHW3(){
        Node* tmp = head;
        for(int i = 0; i < 10; i++){
            insert(i);
        }
        homeWork3(4, 9);
        for(; tmp != NULL; tmp = tmp->next){
            cout<< tmp->val <<endl;
        }
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
        Node* tmp = head;
        Node* pdelete;

        for(tmp = head; tmp->next != NULL; ){
            if(tmp->val == i){
                pdelete = head;
                head = tmp->next;
                tmp = head;
                delete pdelete;
                pdelete = NULL;
                size--;
            }else if(tmp->next == NULL){
                pdelete = tmp;
                delete pdelete;
                pdelete = NULL;
                break;
                size--;
            }else if(tmp->next->val == i){
                pdelete = tmp->next;
                tmp->next = pdelete->next;
                delete pdelete;
                pdelete = NULL;
                size--;
            }else{
                tmp = tmp->next;
            }
        }
        return;
    }

private:
    int size;
    Node* head;
};


int main()
{
    LinkList text;
    text.testHW1();
    return 0;
}
