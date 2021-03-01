//https://www.acmicpc.net/problem/2748
// 자료형 선언

#include <iostream>
using namespace std;

int n;
long long d[91];

long long dp(int n){
   
    if(n == 0) return 0; 
    else if(n == 1 || n == 2) return 1;
    
    if(d[n]!= 0) return d[n];
    else return d[n] = dp(n-1)+ dp(n-2);

    return d[n];
    
}


int main(void){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    
    cout << dp(n) << '\n';

    return 0;

}