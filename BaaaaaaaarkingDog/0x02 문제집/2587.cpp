#include <bits/stdc++.h>

using namespace std;

int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[5];
    int sum = 0;

    for(int i =0; i<5; i++){
        cin >> arr[i];
        sum += arr[i];
    }

    //평균
    cout << sum/5 << "\n";
    sort(arr, arr+5);
    //중간 값
    cout << arr[2] << "\n";

    return 0;
}