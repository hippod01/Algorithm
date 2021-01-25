//https://www.acmicpc.net/problem/1929

#include <iostream>
#define MAX 1000001

using namespace std;

int a[MAX];

int main(void){
    //초기화
    for(int i=2; i<=MAX; i++){
        a[i] = i;
    }
    //소수 판별
    for(int i=2; i<=MAX; i++){
        if(a[i] == 0) continue;
        for(int j=2*i; j<=MAX; j+=i){
            a[j] = 0;
        }
    }

    int n,m;
    cin >> n >> m;

    for(int i=n; i<=m; i++){
        if(a[i]!=0){
            cout << a[i] << "\n";
        }
    }

    return 0;
}