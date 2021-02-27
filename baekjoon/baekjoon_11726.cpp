//https://www.acmicpc.net/problem/11726
//타일링 문제

#include <iostream>

using namespace std;

int n;
int d[1001];

int dp(int x){
    d[1] = 1;
    d[2] = 2;
    if(d[x] != 0) return d[x];
    return d[x] = (dp(x-1) + dp(x-2)) % 10007;

}

int main(void){

    cin >> n;

    cout << dp(n) << '\n';

    return 0;
}