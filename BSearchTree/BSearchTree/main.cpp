#include <iostream>
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




int main()
{
    BSearchTree tree;
    tree.insert(11);
    tree.insert(22);
    tree.insert(7);
    tree.insert(5);
    tree.insert(4);
    tree.insert(33);
    tree.insert(44);
    tree.insert(13);
    tree.insert(8);
    cout<< isAVL(tree.getRoot()) <<endl;
    return 0;
}
