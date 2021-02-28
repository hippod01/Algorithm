//https://www.acmicpc.net/problem/1932
#include <iostream>
#include <algorithm>

using namespace std;

int n;
int d[501][501];
int t[501][501];

void dp(int n){

    d[0][0] = t[0][0];

    for(int i=1; i<n; i++){
        for(int j=0; j<=i; j++){
            // if(j==0) {
            //     d[i][0] = d[i-1][0]+t[i][0];
            // } else if(j==i){
            //     d[i][j] = d[i-1][j-1] + t[i][j];
            // } else {
            //     d[i][j] = max(d[i-1][j-1]+t[i][j],d[i-1][j]+t[i][j]);
            // }
            d[i][j] = max(d[i-1][j-1]+t[i][j],d[i-1][j]+t[i][j]);
        }
        
    }


}

int main(void){

    cin >> n;

    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            cin >> t[i][j];
        }
    }

    dp(n);
    
    int M = 0;
    for(int i=0; i<n; i++){
        M = max(d[n-1][i],M);
    }
    cout << M << '\n';

    return 0;
}