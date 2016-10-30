#include <iostream>

#define N 4

using namespace std;

struct adj_matrix {
    int vertex[N]; // 节点
    int edge[N][N]; // 边
};   //用邻接矩阵去表示了一个图

struct adj_matrix matrix = {
    {0, 1, 2, 3},

    {
        {0, 0, 0, 1},
        {0, 0, 0, 1},
        {0, 0, 0, 1},
        {1, 1, 1, 0},
    }
};  //一个叫做矩阵的测试案例



//  0-3   1-3   2-3   3-0-1-2          3
//                                    /|\
//                                   0 1 2

int visit[N] = {0, 0, 0, 0}; // 是否被访问过标记

void dfs_visit(struct adj_matrix *G, int u){  // 遍历了该节点
    visit[u] = 1;
    cout << G->vertex[u] << " ";
    for (int v = 0; v < N; v++){ // 表示存在一条边，并这个节点没有被访问
        if (G->edge[u][v] == 1 && visit[v] != 1){  //这里体现出来了深度遍历的思想，
            dfs_visit(G, v);
        }
    }
}

void dfs(struct adj_matrix *G){
    for (int u = 0; u < N; u++){
        if (visit[u] != 1){   //如果没有被访问， 就开始访问它咯，一共访问N次，根据节点的次序
            dfs_visit(G, u);
        }
    }
}

int main(){
    dfs(&matrix);
    // 需要注意这么几个地方：
    // 1. 如果要写测试案例的话，那么可能要用到memset用来给visit全部标记上未被访问
    // 2. 请一定要先画图，然后正确的描述出它的邻接矩阵

    return 0;
}
