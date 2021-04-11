#include <bits/stdc++.h>

using namespace std;

int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[7] = {0,};
    int ans = 0;
    int maxnum = -1;

    for(int i=0; i<3; i++){
        int temp;
        cin >> temp;
        arr[temp]++;
    }

    for(int i=1; i<=6; i++){
        if(arr[i] == 3){
            ans = 10000 + ( i * 1000);
            break;

        } else if(arr[i] == 2){
            ans = 1000 + ( i * 100);
            break;

        } else if(arr[i] == 1){
            maxnum = max(i, maxnum);
        }
    }
    
    if(ans){
        cout << ans << "\n";
    } else {
        cout << maxnum * 100 << "\n";
    }

    return 0;
}