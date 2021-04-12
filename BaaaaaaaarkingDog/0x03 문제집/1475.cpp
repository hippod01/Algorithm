#include <bits/stdc++.h>

using namespace std;

int arr[10];

int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    for(auto c : s){
        int temp = c-'0';
        arr[c-'0']++;
        
    }

    int cnt = 0;
    int sum = 0;
    for(int i=0; i<10; i++){
        if(i == 6 || i == 9){
            sum += arr[i];
            cnt = max((sum+1)/2, cnt);
        } else { 
            cnt = max(arr[i], cnt);
        }
    }

    cout << cnt << "\n";


    return 0;
}