#include <iostream>
using namespace std;

struct re{    // linkList, link the node of HashTable
    int n;
    re* next;
};

class HashTable{
    // the struct of HashTable, and the size, the count
private:
    //node as an Array
    re * node[15];
    //intalizied in constructor .
    int size ;
    int count ;

public:
    //constructor function
   HashTable(){
        count = 0; size = 15;
        //intalization for 2-dimensions array(pointer)
        for (int ti=0;ti<15;ti++) 
            node[ti] = new re;  //every node has a head of linkList
        //if(!node) exit(0);
        for(int i = 0; i < size; i++)
        {
            node[i]->next = NULL;
            node[i]->n = 2147483647;//set a integer that never appears in your data
        }
    }

    inline int hash(int key){ //inline function, learn it by yourself.
        return key % this->size;//add a "this" to stress
    }

    void insert_hashTable(int val){
        //if the data never appeared
        re* tmp;
        int t = hash(val);
        //for-loop can be used in this way!!
        for (tmp = node[t]->next;tmp!=NULL;tmp = tmp->next)
            if (tmp->n==val)
            {
                //if data appeared
                printf("Data Repeated!");
                return;
            }
        tmp = node[t];
        while(tmp->next!=NULL);
        tmp->next = new re;
        tmp = tmp->next;
        tmp->n = val;
        tmp->next = NULL;


    }
    //if data is found, return true; else return false
    bool find_hashTable(int i)
    {
        //
        re* temp = node[hash(i)];
        //for-loop can also be used in this way!
        for (;temp!=NULL;temp = temp->next)
            if (temp->n==i)
                return true;
        return false;
    }

};

int main()
{
    HashTable table;
    //table.init_hashTable();
    table.insert_hashTable(32);
    table.insert_hashTable(44);
    table.insert_hashTable(45);
    cout<< table.find_hashTable(44) <<endl;
    return 0;
}
