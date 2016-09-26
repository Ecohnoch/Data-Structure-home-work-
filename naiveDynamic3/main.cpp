#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    // 状态转移方程: maxLen[1] = 1; maxLen[k] = max{maxLen[i]} + 1
    int N, a[1000], dp[1000], max = 1, maxLen = 1;
    memset(dp, 1, sizeof(dp));
    scanf("%d", &N);
    for(int i = 0; i < N; ++i){
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < N; ++i){
        max = 0;
        for(int j = 0; j < i; ++j){
            if(a[j] < a[i] && dp[j] > max){
                max = dp[j];   //通过可能已经获知的子问题解, 求最大值中
            }
        }
        dp[i] = max + 1;   //当前序列最大值 + 1, 因为尾数是大于整个系列的尾数
        if(dp[i] > maxLen){
            maxLen = dp[i];
        }
    }
    cout<< maxLen;
    return 0;
}
