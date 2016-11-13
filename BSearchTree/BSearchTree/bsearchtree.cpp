#include <stack>
#include "bsearchtree.h"

using namespace std;

void BSearchTree::insert(int x){
    if(root->val == 1000){
        root->val = x;
        count = 1;
    }else{
        Node* tmp = root;
        while(tmp != NULL){
            if(x >= tmp->val){
                if(tmp->rChild == NULL){
                    Node* tmp2 = new Node;
                    tmp2->val = x;
                    tmp2->lChild = NULL;
                    tmp2->rChild = NULL;
                    tmp->rChild = tmp2;
                    break;
                }
                tmp = tmp->rChild;

            }else{
                if(tmp->lChild == NULL){
                    Node* tmp2 = new Node;
                    tmp2->val = x;
                    tmp2->lChild = NULL;
                    tmp2->rChild = NULL;
                    tmp->lChild = tmp2;
                    break;
                }
                tmp = tmp->lChild;
            }
        }
    }
}
void BSearchTree::remove(int x){

}

void BSearchTree::preOrder(Node* h){
    if(h == NULL)
        return ;
    else{
        printf("val: %d\n", h->val);
        preOrder(h->lChild);
        preOrder(h->rChild);
    }
}

void BSearchTree::inOrder(Node* h){
    if(h == NULL)
        return ;
    else{
        inOrder(h->lChild);
        printf("val: %d\n", h->val);
        inOrder(h->rChild);
    }
}

void BSearchTree::postOrder(Node* h){
    if(h != NULL)
    {
        postOrder(h->lChild);
        postOrder(h->rChild);
        cout<<h->val<<" ";
    }
}

void BSearchTree::preOrder2(Node *h){
    stack<Node*> s;
    Node* tmp = h;
    while(tmp != NULL || !s.empty()){
        while(tmp != NULL){
            cout<<tmp->val<<" ";
            s.push(tmp);
            tmp = tmp->lChild;
        }
        if(!s.empty())
        {
            tmp = s.top();
            s.pop();
            tmp = tmp->rChild;
        }
    }
}

void BSearchTree::inOrder2(Node *h){
    stack<Node*> s;
    Node* tmp = h;
    while(tmp!=NULL || !s.empty()){
        while(tmp != NULL){
            s.push(tmp);
            tmp = tmp->lChild;
        }
        if(!s.empty())
        {
            tmp = s.top();
            cout<<tmp->val<<" ";   //here
            s.pop();
            tmp = tmp->rChild;
        }
    }
}

void BSearchTree::postOrder2(Node *h){
    stack<Node*> s;
    Node *cur;
    Node *pre = NULL;
    s.push(h);
    while(!s.empty())
    {
        cur = s.top();
        if((cur->lChild==NULL && cur->rChild==NULL)||
           (pre!=NULL && (pre == cur->lChild || pre==cur->rChild))){
            //如果当前结点没有孩子结点或者孩子节点都已被访问过
            cout<<cur->val<<" ";  //打印数据
            s.pop();
            pre = cur;
        }else{
            if(cur->rChild != NULL)
                s.push(cur->rChild);  // 先进右边的
            if(cur->lChild != NULL)
                s.push(cur->lChild);
        }
    }
}

void BSearchTree::levelOrder(Node *h){
    deque<Node*> q1, q2;  //两个队列, 最后交换
    q1.push_back(h);
    while(!q1.empty()) {
        while(!q1.empty()) {
            Node *temp = q1.front();
            q1.pop_front();
            cout << temp->val << " ";
            if(temp->lChild)
                q2.push_back(temp->lChild);
            if(temp->rChild)
                q2.push_back(temp->rChild);
        }// 现在q1为空,然后这一层下面所有的已经入队了
        cout<<endl;
        q1.swap(q2);
    }
}

bool BSearchTree::search(int x){
    Node* tmp = root;
    while(tmp != NULL){
        if(x == tmp->val)
            return true;
        else if(x > tmp->val){
            tmp = tmp->rChild;
        }else if(x < tmp->val){
            tmp = tmp->lChild;
        }
    }
    return false;
}

void BSearchTree::test(){
    insert(11);insert(22);insert(13);insert(35);
    insert(21);insert(7);

    //     11
    //
    levelOrder(root);
    cout<<endl;

}







