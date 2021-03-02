//https://www.acmicpc.net/problem/2193

#include <iostream>

using namespace std;

long long d[91];
int n;

void dp(int n){
    
    d[0] = 1; 
    d[1] = 1;
    //결국 점화식을 구해보면 피보나치 수
    for(int i=2; i<n; i++){
        d[i] = d[i-2] + d[i-1];
    }

}

int main(void){

    cin >> n;
    dp(n);
    cout << d[n-1]<< '\n';

    return 0;
}