#include <iostream>
#include <algorithm>

using namespace std;

struct Graph{
//    int vertex[6] = {0, 1, 2, 3, 4, 5};
//    int edge[6][6] = {
//        {0, 2, 0, 0, 4, 3},
//        {2, 0, 3, 0, 0, 4},
//        {0, 3, 0, 5, 0, 1},
//        {0, 0, 5, 0, 6, 2},
//        {4, 0, 0, 6, 0, 3},
//        {3, 4, 1, 2, 3, 0},
//    };

    //    v2    .
    //     .     \6
    //   2||5  13\
    //    .   10-  .
    //    v1  .-9  v3
    int vertex[3] = {0, 1, 2};
    int edge[3][3] = {
        {0, 5, 10},
        {2, 0, 13},
        {9, 6,  0},
    };
};

struct Edge{
    int x;  //起始点
    int y;  //末点
    int w;  //终止点
};

void floyd(Graph g,int e[3][3], int path[3][3]){
    int i, j, v;
    int n = 3;
    for(i = 0; i < n; ++i){   //对两个矩阵进行初始化
        for(j = 0; j < n; ++j){
            if(i == j){
                e[i][j] = 0;
                path[i][j] = i;
            }else{
                e[i][j] = 1000;
                path[i][j] = -1;
            }
        }
    }

    // 给e初始化
    //for(edge in alledges)
    //  e[i][j] = g.weight[i][j]
    for(i = 0; i < n; ++i){
        for(j = 0; j < n; ++j){
            e[i][j] = g.edge[i][j];
            path[i][j] = i;
        }
    }
    for(v = 0; v < n; ++v)
        for(i = 0; i < n; ++i)
            for(j = 0; j < n; ++j)
                if(e[i][j] > e[i][v] + e[v][j]){  //遇到更短的就更新, 然后加入path
                    e[i][j] = e[i][v] + e[v][j];
                    path[i][j] = v;
                }

    for(i = 0; i < n; ++i){
        for(j = 0; j < n; ++j){
            cout<< e[i][j]<<" ";
        }
        cout<< endl;
    }
    cout<<endl;
    for(i = 0; i < n; ++i){
        for(j = 0; j < n; ++j)
            cout<< path[i][j]<<" ";
        cout<< endl;
    }
}
int main()
{
    Graph g;
    int ans[3][3];
    int path[3][3];
    floyd(g, ans, path);
    return 0;
}
