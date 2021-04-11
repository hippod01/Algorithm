#include <bits/stdc++.h>

using namespace std;

int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);

    //0~9저장
    int arr[10] = {0,};
    int a, b, c;
    cin >> a >> b >> c;

    int result = a*b*c;
    while(result>0){
        int num = result % 10;
        arr[num]++;
        result /= 10;
    }

    for(int i=0; i<10; i++){
        cout << arr[i] << "\n";
    }
    

    return 0;
}