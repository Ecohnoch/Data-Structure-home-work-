#include<iostream>
#include<algorithm>

using namespacestd;
struct Node{
    int a,b;
}a[100];

int cmp(Node x1,Node x2){
    return x1.b < x2.b;
}

int main(int argc,char *argv[])
{
    int t;
    scanf("%d",&t);
    while(t--){
        cin>>a[t].a >> a[t].b;
        if(a[t].a<a[t].b) swap(a[t].a, a[t].b);
    }
    sort(a, a+t, cmp);//对末端进行排序
    int res = 0; max =- 1000;
    for(int i = 0; i<t; i++){
        if(a[i].a >= max){//贪心算法,算出所有连续(中间有空位)的线段数量,即为最后的答案.
            res++;
            max=a[i].b;
        }
    }
    cout<< res;
    system("pause");
    return 0;
}
