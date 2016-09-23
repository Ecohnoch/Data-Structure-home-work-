#include <iostream>
#include "linklist.h"


using namespace std;

LinkList linkTheList(LinkList l1, LinkList l2){
    int length = l2.getSize();
    LinkList l3;
    for(int i = 0; i < l1.getSize(); i++){
        l3.insert(l1.getVal(i));
    }

    for( int i = 0; i < length; i++){
        l3.insert(l2.getVal(i));
        cout<<"l2 , val: "<<l2.getVal(i)<<endl;
    }
    for( int i = 0; i < l3.getSize(); i++){
        cout<<"l3, val: "<<l3.getVal(i)<<endl;
    }
    cout<< "l3 position 0: "<< l3.getVal(0)<<endl;
    return l3;
}


int main()
{


    LinkList list;
    list.insert(11); list.insert(23); list.insert(33); list.insert(44);

    LinkList list2;
    list2.insert(22); list2.insert(33);

    LinkList finalList;
    finalList = linkTheList(list, list2);
    cout<< finalList.getVal(1)<<endl;



    return 0;
}
