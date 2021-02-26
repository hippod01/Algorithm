//https://www.acmicpc.net/problem/9095
//점화식..!

#include <iostream>

using namespace std;

int n;
int d[12];

void dp(int x){
    d[1] = 1;
    d[2] = 2;
    d[3] = 4;
    for(int i = 4; i<=x; i++){
        d[i] = d[i-1] + d[i-2] + d[i-3];
    }
    cout << d[x] << '\n';
}

int main(void){

    int tc;
    cin >> tc;
    while(tc--){

        cin >> n;
        dp(n);

    }

    return 0;
}