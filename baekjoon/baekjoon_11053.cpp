//https://www.acmicpc.net/problem/11053
//가장 긴 증가하는 부분 수열
//참고 : https://bitwise.tistory.com/215

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
int a[1001];
int d[1001];
int sol; 

void dp(int n){
    
    fill_n(d,1001,1);

    for(int i=0; i < n; i++){
        int code = a[i];

        //code 보다 작은 수 카운트(증가하는 수열)
        for(int j=0; j<i; ++j){
            int value = a[j];

            if(code > value){
                d[i] = max(d[i],d[j]+1);
            }
        }
        sol = max(sol,d[i]);
    }
    
}

int main(void){
    //수열의 크기 입력
    cin >> n;
    //수열을 이루고 있는 수 입력
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    dp(n);
    cout << sol << '\n';

    return 0;
}