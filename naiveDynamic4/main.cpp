#include <iostream>
#include <algorithm>

using namespace std;
char s1[100], s2[100];
int dpRes[100][100]; //开始要全部初始化为-1, 表示未被计算
int dp(int i, int j){
    if(dpRes[i][j] > 0){
        return dpRes[i][j];
    }
    if( i == 0 || j == 0){
        if(s1[i] == s1[j]){
            return 1;
        }else{
            return 0;
        }
    }else{
        if(s1[i] == s2[j]){

            return dpRes[i][j] = dp(s1[i - 1], s2[i - 1]) + 1;
        }else if( s1[i] != s2[j]){
            return dpRes[i][j] = max(dp(s1[i - 1], s2[j]), dp(s1[i], s2[j - 1]));
        }
    }
}


int main()
{
    int m , n;
    memset(dpRes, -1, sizeof(dpRes));
    cin>>m >>n;
    for(int i = 0; i < m; i++){
        cin>>s1[i];
    }
    for(int j = 0; j < n; j++){
        cin>>s2[j];
    }
    cout<< dp(m - 1,n - 1);
    return 0;
}
