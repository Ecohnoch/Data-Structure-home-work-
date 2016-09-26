#include <iostream>
#include <algorithm>
#include <cstring> //用到了memset函数

using namespace std;
int a[51][51];
int d[51][51];
int n;

int f(int i, int j){
    if(d[i][j] >= 0){  // 判断是否已经经过了处理
        return d[i][j];
    }
    if(i == n){
        return a[i][j] + 0;
    }else{  // 最重要的一步, 每一次都保存它子问题的答案
        return d[i][j] = a[i][j] + max(f(i+1, j), f(i+1,j+1));
    }
}
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        memset(d, -1, sizeof(d));   // 将d内所有空间赋值-1, 为了表示是否被计算过,因为计算过的都为正数
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= i; ++j){
                scanf("%d", &a[i][j]);
            }
        }
        printf("%d\n", f(1, 1));
    }
    system("pause");
    return 0;
}
