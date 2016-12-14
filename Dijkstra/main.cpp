#include <iostream>
#include <stack>
#define M 100
#define N 100

using namespace std;

typedef struct node{
    int matrix[N][M];  //邻接矩阵
    int vertex;
    int edge;
}MGraph;

void Dijkstra(MGraph g, int *dist, int *path, int v0){
    // 初始化
    int i, j , k;
    bool *visited = new bool[g.vertex];
    for(i = 0; i < g.vertex; i++){  // 遍历所有的节点
        if(g.matrix[v0][i] > 0 && i != v0){  // v0这一行单独处理
            dist[i] = g.matrix[v0][i];
            path[i] = v0;            //+++++++++++path 记录最短路径上从v0到i的前一个结点
        }else{
            dist[i] = 1000;
            path[i] = -1;
        }
        visited[i] = false;
        path[v0] = v0;  //单独对v0进行提出的处理
        dist[v0] = 0;
    }
    visited[v0] = true;
    //初始化结束
    for(i = 1; i < g.vertex; i++){ // 循环展开 n - 1 次, 因为源节点已经进行了处理
        int min = 1000;
        int u;
        for(j = 0; j < g.vertex; j++){
            if(visited[j] == false && dist[j] < min){
                min = dist[j];
                u = j;   //   这两行是一个临时的处理, 表示记录了临时的最短路径
            }
        }
        visited[u] = true;
        for(k = 0; k < g.vertex; k++){  //更新临时的处理和路径的值
            if(visited[k] == false && g.matrix[u][k] > 0 && min + g.matrix[u][k] < dist[k]){
                dist[k] = min + g.matrix[u][k];
                path[k] = u;
            }
        }
    }
}

void showPath(int *path, int v, int v0){ // 主要是打印这条路径上所有的结点
    stack<int> s;
    int u = v;
    while(v != v0){
        cout<<"fuck"<<endl;
        s.push(v);
        v = path[v];  //这里就是不断去找该结点的上一个点, 直到找到v0即可
    }
    s.push(v);
    while(!s.empty()){
        cout<< s.top()<<endl;
        s.pop();
    }
}

int main()
{
    int n, e;
    while(cin>>n>>e && e != 0){
        int i, j;
        int s, t, w;   // 存在一条边s->t, 权值为w
        MGraph g;
        int v0;
        int *dist = new int[n];
        int *path = new int[n];
        for(i = 0; i < N; i++){
            for( j = 0; j < M; j++){
                g.matrix[i][j] = 0;
            }
        }
        g.vertex = n;
        g.edge = e;
        for(i = 0; i < e; i++){
            cin>>s>>t>>w;
            g.matrix[s][t] = w;
        }
        cin>>v0;
        Dijkstra(g, dist, path, v0);
//        for(i = 0; i < n; i++){
//            if(i != v0){
//                showPath(path, i, v0);
//                cout<<dist[i]<<endl;
//            }
//        }
        int test[4] = {0, 0, 0, 2};
        showPath(test, 1, 2);

    }
    return 0;
}
