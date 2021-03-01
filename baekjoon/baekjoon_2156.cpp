//https://www.acmicpc.net/problem/2156

#include <iostream>
#include <algorithm>
using namespace std;

int n;
int d[10001];
int wine[10001];

//가장 많은 양의 포도주를 마실 수 있도록 하는 프로그램
void dp(int n){
    d[1] = wine[1];
    d[2] = max(wine[1]+wine[2], wine[2]);

    for(int i=3; i<=n; i++){
        d[i] = max(d[i-3]+wine[i-1]+wine[i], d[i-2]+wine[i]);
        //*포도주를 두 번 연속 안먹을 경우*
        d[i] = max(d[i], d[i-1]);
    }

}

int main(void){

    //포도주 잔의 개수
    cin >> n;
    //포도주의 양
    for(int i=1; i<=n; i++){
        cin >> wine[i];
    }

    dp(n);

    cout << d[n] << '\n';

    return 0;
}