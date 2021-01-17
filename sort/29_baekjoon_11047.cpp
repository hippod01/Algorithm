//https://www.acmicpc.net/problem/11047

#include <iostream>
using namespace std;

int main(void){
    
    //동전의 종류, 값
    int n, k, count = 0;
    cin >> n >> k;

    int value[n+1];

    for(int i=0; i<n; i++){
        cin >> value[i];
    }
    
    for(int i=n-1; i>=0; i--){
        count += k/value[i];
        k %= value[i];
    }

    cout << count;
    return 0;
}