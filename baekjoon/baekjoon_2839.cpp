//https://www.acmicpc.net/problem/2839

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int d[5001];

void dp(int target){

    if(target <  5 && target > 0){
        if(target == 3) {
            cout << "1" << '\n';
        } else{
            cout << "-1" << '\n';
        } 
    } else {
        d[3] = d[5] = 1;
        for(int i=6; i<=n; i++){
            d[i] = 1+ min(d[i-3],d[i-5]);
        }
        if(d[target] >= 9999) {
            cout << "-1" << '\n';
        } else {
            cout << d[target] << '\n';
        }
    }
    
    
}

int main(void){

    memset(d,9999,sizeof(d));

    cin >> n;
    dp(n);

    return 0;
}