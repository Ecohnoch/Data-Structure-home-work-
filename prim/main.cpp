#include <iostream>
#include <algorithm>

using namespace std;

/*                       0
 *                      /|\
 *                     1-5-4
 *                      \|\|
 *                       2-3
 */

struct Graph{
    int vertex[6] = {0, 1, 2, 3, 4, 5};
    int edge[6][6] = {
        {0, 2, 0, 0, 4, 3},
        {2, 0, 3, 0, 0, 4},
        {0, 3, 0, 5, 0, 1},
        {0, 0, 5, 0, 6, 2},
        {4, 0, 0, 6, 0, 3},
        {3, 4, 1, 2, 3, 0},
    };
};

struct Edge{
    int x;  //起始点
    int y;  //末点
    int w;  //终止点
};

int verNow[6] = {-1, -1, -1, -1, -1, -1};
int verNew[6] = {-1, -1, -1, -1, -1, -1};

void prim(Edge* ans, Graph g){
    int i = 0, j = 0;
    // 预处理
    for(i = 0; i < 6; ++i){
        verNew[i] = i;
    }
    verNew[0] = -1;   //0 是最开始被发现的结点, 所以提出VerNew
    verNow[0] = 0;    //0 被拿到了  verNow里, 现在verNow里只有一个元素0, 其他都是-1
    //预处理结束

    int count = 0; // ans边的个数

    while(verNew[0] != -1 || verNew[1] != -1 || verNew[2] != -1 || verNew[3] != -1 || verNew[4] != -1 || verNew[5] != -1){
        int min = 1000; // 最小边 权值
        int iFlag = 0; int jFlag = 0;

        // 寻找 两个集合中, 最小的那一条边
        for(i = 0; i < 6; ++i){

            for(j = 0; j < 6; ++j){
                if(verNow[i] != -1 && verNew[j] != -1){   //vernow: [0]  vernew: [1, 2, 3, 4, 5] , 如果存在 <v1, v2>有边
                    if(g.edge[i][j] < min && g.edge[i][j] != 0){
                        min = g.edge[i][j];   //min为所有如上的序偶中最小的
                        iFlag = i;
                        jFlag = j;
                    }
                }
            }

        }
        //寻找最小边结束
        cout<< iFlag<< " " <<jFlag<<endl;
        // 把j提出verNew, 加入verNow
        verNow[jFlag] = verNew[jFlag];
        verNew[jFlag] = -1;
        // 把i, j这条边加入ans
        ans[count].x = iFlag;
        ans[count].y = jFlag;
        ans[count].w = g.edge[iFlag][jFlag];
        count ++;


        //检测
        for(i = 0; i < 6; ++i){
            cout<< "verNew["<< i<< "] "<< verNew[i]<< " ";
        }
        cout<< endl;
        for(i = 0; i < 6; ++i){
            cout<< "verNow["<< i<< "] "<< verNow[i]<< " ";
        }
        cout<< endl;
        for(i = 0; i < count; ++i){
            cout<< ans[i].x<< "-w:"<<ans[i].w<<"-" <<ans[i].y << " ";
        }
    }

}

int lChild(int pos){
    return 2 * pos + 1;
}

int rChild(int pos){
    return 2 * pos + 2;
}

int parent(int pos){
    return (pos - 1) / 2;
}

void siftUp(Edge* e, int pos){
    int tmp = pos;
    while(tmp > 0 && e[parent(tmp)].w < e[tmp].w){
        Edge eTmp = e[parent(tmp)];
        e[parent(tmp)] = e[tmp];
        e[tmp] = eTmp;
        tmp = parent(tmp);
    }
}

void siftDown(Edge *e, int last){
    int pos = 0;
    int m = 0;
    while(2 * pos + 2 < last){
        if(e[lChild(pos)].w > e[rChild(pos)].w){
            m = lChild(pos);
        }else
            m = rChild(pos);
        if(e[m].w > e[pos].w){
            Edge tmp = e[m];
            e[m] = e[pos];
            e[pos] = tmp;
            pos = m;
        }else
            break;
    }
}

void removeMin(Edge *e){
    int lastNum = 19;
    int i = 0;
    for(; i < 20; ++i){
        Edge tmp = e[0];
        e[0] = e[lastNum - i];
        e[lastNum - i] = tmp;
        siftDown(e, lastNum - i);
    }
    if(e[1].w > e[2].w){
        Edge temp = e[1];
        e[1] = e[2];
        e[2] = temp;
    }
    if(e[0].w > e[1].w){
        Edge temp = e[0];
        e[0] = e[1];
        e[1] = temp;
    }
    if(e[1].w > e[2].w){
        Edge temp = e[1];
        e[1] = e[2];
        e[2] = temp;
    }

//    Edge tmp = e[0];
//    e[0] = e[9];
//    e[9] = tmp;
//    siftDown(e, 9);

//    tmp = e[0];
//    e[0] = e[8];
//    e[8] = tmp;
//    siftDown(e, 8);

//    tmp = e[0];
//    e[0] = e[7];
//    e[7] = tmp;
//    siftDown(e, 7);

//    tmp = e[0];
//    e[0] = e[6];
//    e[6] = tmp;
//    siftDown(e, 6);
}

bool buildHeap(Edge* e){
    int i = 0;
    for(i = 0; i < 20; ++i){
        siftUp(e, i);
    }
    return true;
}

void testHeap(){
    Edge e[20];
    e[0].w = 10;
    e[1].w = 4;
    e[2].w = 6;
    e[3].w = 5;
    e[4].w = 12;
    e[5].w = 7;
    e[6].w = 1;
    e[7].w = 8;
    e[8].w = 2;
    e[9].w = 3;
    e[10].w = 11;
    e[11].w = 15;
    e[12].w = 13;
    e[13].w = 16;
    e[14].w = 17;
    e[15].w = 18;
    e[16].w = 14;
    e[17].w = 19;
    e[18].w = 5;
    e[19].w = 6;
    buildHeap(e);
    removeMin(e);
    for(int i = 0; i < 20; ++i){
        cout<< e[i].w <<endl;
    }
}

void Kluskal(Edge *ans, Graph g){
    int i, j, sn1, sn2, k = 0;
    int vset[6]; //判断两个顶点是否联通
    Edge e[20];  //存放所有的边
    ans = new Edge;

    // 初始化e[10], 把所有的边存进去
    for(i = 0; i < 6; i++){
        for(j = 0; j < 6; j++){
            if(g.edge[i][j] != 0){
                e[k].x = i;
                e[k].y = j;
                e[k].w = g.edge[i][j];
                k++;
        }
    }
    // 结束初始化e[10], 对e[10]根据权值进行排序
    buildHeap(e);
    removeMin(e);
    for(int i = 0; i < 10; ++i){
        cout<< e[i].w <<endl;
    }

    for (i=0; i< 6;i++){                                    //初始化辅助数组
        vset[i] = i;
    }
    k = 1;                                                   //生成的边数，最后要刚好为总边数
    j = 0;                                                   //E中的下标
    while(k < 6){
        sn1 = vset[e[j].x];
        sn2 = vset[e[j].y];                                  //得到两顶点属于的集合编号
//        cout<< sn1<<" "<< sn2<<endl;
        if (sn1 != sn2){                                      //不在同一集合编号内的话，把边加入最小生成树
            printf("%d-%d, %d\n", e[j].x, e[j].y, e[j].w);
            k++;
            for (i = 0 ;i < 6; i++)  {
                if (vset[i] == sn2){
                    vset[i] = sn1;
                }
            }
        }
        j++;
    }
}

int main()
{
    Graph g;
    Edge ans[6];
    Kluskal(ans, g);
//    prim(ans, g);
    return 0;
}
