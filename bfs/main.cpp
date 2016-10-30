#include <iostream>
#include <queue>
using namespace std;

#define N 4
#define __TEXT__

struct adj_matrix{
    int vertex[N];  //节点的容器
    int edge[N][N]; //边
};// 用邻接矩阵去表示了一个图
#ifdef __TEXT__

adj_matrix matrix = {
    {0, 1, 2, 3},
    {
        {0, 0, 1, 1},
        {0, 0, 0, 1},
        {1, 0, 0, 0},
        {1, 1, 0, 0},
    }
};
#endif

//  0-3   1-3   2-3   3-0-1-2          3    从0开始的话便是-------     0
//                                    /|\       理想输出为0231        /\
//                                   0 1 2                         2  3
//                                                                 /
//                                                                1

int visit[N] = {0, 0, 0, 0}; //表示这个节点是否被访问过

void bfs(adj_matrix *G, int v){
//    for(int i = 0; i < N; i++){
//        if(visit[i] != 1){  //如果没有被访问过，就来愉快的开始bfs吧
//            bfs_visit(G, i);
//        }
//    }  //哈哈，被骗了吧，这个地方是不能这样瞎递归的
//      一种特殊的bfs就是树的层序遍历，你能用递归么？所以我们还是老老实实开个队列
    visit[v] = 1;
    queue<int> q; //队列，用来保存每一层的信息，然后一层搞完之后全部出对
    q.push(G->vertex[0]);
    while(!q.empty()){
        v = q.front();
        cout<< v<<endl;
        q.pop();
        for(int i = 0; i < N; i++){ //遍历所有的节点
            if(visit[i] != 1 && G->edge[v][i] == 1){ //没有被访问到的节点
                q.push(i);
                visit[i] = 1;
            }
        }
    }
}

int main()
{
    bfs(&matrix, 0);
    return 0;
}
