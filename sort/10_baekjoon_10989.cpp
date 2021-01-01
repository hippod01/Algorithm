// 백준 문제 https://www.acmicpc.net/problem/1431
//계수정렬

#include<iostream>

using namespace std;

int n,m;
int a[10001];

int main(){
    scanf("%d", &n);

    for(int i=0; i < n; i++){
        scanf("%d", &m);
        a[m]++;
    }

    for(int i=0; i<10001; i++){
        while(a[i]!=0){
            printf("%d\n",i);
            a[i]--;
        }
    }

    return 0;
}

