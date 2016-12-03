#include <iostream>

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
    int i;
    int j;
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
        ans[count].i = iFlag;
        ans[count].j = jFlag;
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
            cout<< ans[i].i<< "-" <<ans[i].j << " ";
        }
    }

}

int main()
{
    Graph g;
    Edge ans[6];
    prim(ans, g);
    return 0;
}
