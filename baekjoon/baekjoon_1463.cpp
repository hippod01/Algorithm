//https://www.acmicpc.net/problem/1463

#include <iostream>
#include <algorithm>

using namespace std;

int n;
int d[1000001];

void dp(int x){

    d[1] = 0;
    for(int i = 2; i <= x; i++){
        d[i] = d[i-1] + 1;
        if(i % 3 == 0){
            d[i] = min(d[i], d[i/3]+1);
        } 
        if(i % 2 == 0){
            d[i] = min(d[i], d[i/2]+1);
        } 
    }
    cout << d[x] << '\n';

}

int main(void){

    cin >> n;
    dp(n);

    return 0;
}
