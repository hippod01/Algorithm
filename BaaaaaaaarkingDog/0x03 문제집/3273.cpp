#include <bits/stdc++.h>

using namespace std;

int arr[1000001];

int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> arr[i];    
    }
    cin >> x;

    sort(arr, arr+n); // 1 2 3 5 7 9 10 11 12 

    int start = 0;
    int end = n-1;
    int cnt = 0;

    while(start < end){
        if(arr[start] + arr[end] == x){
            cnt++;
            end--;
        } else if(arr[start] + arr[end] > x){
            end--;
        } else {
            start++;
        }
    }
    
    cout << cnt << "\n";


    return 0;
}