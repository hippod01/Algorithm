//하나의 문제를 한 번만 풀도록 하는 알고리즘

// 2^N -> O(N)

#include <stdio.h>

// int dp(int x){
//     if(x == 1) return 1;
//     if(x == 2) return 1;
//     return dp(x-1) + dp(x-2);
// }

// int main(void){
//     printf("%d", dp(10));
// }

//DP로 개선 - 메모이제이션 

int d[100];

int dp(int x){
    if(x == 1) return 1;
    if(x == 2) return 1;
    if(d[x] != 0) return d[x];
    return d[x] = dp(x-1) + dp(x-2);
}

int main(void){
    printf("%d", dp(30));
}