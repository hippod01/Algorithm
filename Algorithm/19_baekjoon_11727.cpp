// DP - Tiling 문제
//https://www.acmicpc.net/problem/11727

#include <stdio.h>

int d[1001];

int dp(int x){
    if (x == 1) return 1;
    if (x== 2) return 3;
    if (d[x] != 0) return d[x];
    return d[x] = dp(x-1) + 2 * dp(x-2) % 10007;
    // %10007 : n이 커질 때 오버플로우 막기 위함
}

int main(void){
    int x;
    scanf("%d", &x);
    printf("%d", dp(x));
}