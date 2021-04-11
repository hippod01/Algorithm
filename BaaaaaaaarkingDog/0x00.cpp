#include <bits/stdc++.h>

using namespace std;


int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    cin >> n >> x;

    //수열 입력
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
        if(arr[i] < x) cout << arr[i] << " ";
    }


    return 0;
}