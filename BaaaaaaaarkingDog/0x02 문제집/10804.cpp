#include <bits/stdc++.h>

using namespace std;

int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[21];

    for(int i=0; i<20; i++){
        arr[i] = i+1;
    }
    
    int n = 10;
    while(n--){
        int a, b;
        cin >> a >> b;
        reverse(arr+a-1, arr+b);
        //vector의 원소를 역순으로 변경 <Algorithm>헤더 안에 Reverse 함수 사용
        // reverse(v[a], v[b]);
    }

    for(int i=0; i<20; i++){
        cout << arr[i] << " ";
    }

    
    return 0;
}