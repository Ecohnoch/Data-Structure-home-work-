#include <iostream>
#include <queue>
#include "bsearchtree.h"
using namespace std;



bool isBST(Node* root){
    if(root == NULL) return true; //递归出口
    if(!isBST(root->lChild)) return false;
    if(!isBST(root->rChild)) return false; // 这两种情况都说明了要么左边最大大, 要么右边最小小

    //左子树最大值
    Node* tmp = root->lChild;
    if(tmp != NULL){
        while(tmp->rChild != NULL) tmp = tmp->rChild;
        if(root->val < tmp->val)
            return false;
    }
    //右子树最小值
    tmp = root->rChild;
    if(tmp != NULL){
        while(tmp->lChild != NULL) tmp = tmp->lChild;
        if(root->val > tmp->val)
            return false;
    }
    return true;
}

int getDepth(Node* root){
    if(root == NULL){
        return 0;
    }
    int lDepth = getDepth(root->lChild);
    int rDepth = getDepth(root->rChild);
    return (lDepth > rDepth) ? (lDepth + 1) : (rDepth + 1);
}


bool isAVL(Node* root){
    if(!isBST(root)) return false;

    if(root == NULL) return true;
    if(!isAVL(root->lChild)) return false;
    if(!isAVL(root->rChild)) return false;
    int lDepth = getDepth(root->lChild), rDepth = getDepth(root->rChild);
    if(lDepth - rDepth > 1 || rDepth - lDepth > 1){
        return false;
    }
    return true;
}
//度为1的结点
int find1(Node* root){
    if(root == NULL) return 0;
    if((root->lChild == NULL && root->rChild != NULL) || (root->lChild != NULL && root->rChild == NULL)){
        return 1 + find1(root->lChild) + find1(root->rChild);
    }else{
        return find1(root->lChild) + find1(root->rChild);
    }
}
//度为2的结点
int find2(Node* root){
    if(root == NULL) return 0;
    if(root->lChild != NULL && root->rChild != NULL){
        return 1 + find2(root->lChild) + find2(root->rChild);
    }else{
        return find2(root->lChild) + find2(root->rChild);
    }
}
//度为0的结点
int find3(Node* root){
    if(root == NULL) return 0;
    if(root->lChild == NULL && root->rChild == NULL){
        return 1 + find3(root->lChild) + find3(root->rChild);
    }else{
        return find3(root->lChild) + find3(root->rChild);
    }
}
//是不是完全二叉树
//先BFS, 遇到最左的时候标记true, 然后一旦后面出来的节点有孩子, 就挂掉, 一直没有就成功
bool isCompleteTree(Node* root){
    if(root == NULL) return true;
    queue<Node*> q;
    bool isLeaf = false;
    q.push(root);
    //bfs

    while(!q.empty()){
        Node* tmp = q.front();
        q.pop();
        if(isLeaf){
            if(tmp->lChild != NULL || tmp->rChild != NULL){
                return false;
            }
        }else{
            if(tmp->lChild == NULL && tmp->rChild == NULL){
                isLeaf = true;
            }

        }
        if(tmp->lChild != NULL){
//            cout<< tmp->lChild->val<<endl;
            q.push(tmp->lChild);
        }
        if(tmp->rChild != NULL){
//            cout<< tmp->rChild->val<<endl;
            q.push(tmp->rChild);
        }
    }
    return true;
}


int main()
{
    BSearchTree tree;
    tree.test();

    cout<<  isCompleteTree(tree.getRoot())<<endl;
    return 0;
}
