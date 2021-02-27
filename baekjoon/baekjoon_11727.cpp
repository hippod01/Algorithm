//https://www.acmicpc.net/problem/11727

#include <iostream>

using namespace std;

int d[1001];

int dp(int x){
    d[1] = 1;
    d[2] = 3;
    if(d[x] != 0) return d[x];
    return d[x] = (dp(x-1) + (2*dp(x-2))) % 10007;

}

int main(void){

    int n;
    cin >> n;

    cout << dp(n) << '\n';

    return 0;
}