#include <iostream>

using namespace std;

struct Node{
    int val;
    Node *lChild;
    Node *rChild;
};

class BTree{
public:
    BTree(){
        root = new Node;
        root->lChild = NULL;
        root->rChild = NULL;
        breadth = 0;
        depth = 0;
    }
    ~BTree(){}

    void insert();
    void remove();
    void preOrder();


private:
    Node *root;
    int breadth;
    int depth;

};



int main(int argc, char *argv[])
{
    cout << "Hello World!" << endl;
    return 0;
}
