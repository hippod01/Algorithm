#include <bits/stdc++.h>

using namespace std;

int arr[12];

int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    for(int i=0; i<n; i++){
        int s,y;
        cin >> s >> y;
            //여학생
        if(s == 0){
            arr[y]++;
        } else {
            //남학생
            arr[y+6]++;
        }
    }

    int cnt = 0;

    for(int i=1; i<=12; i++){
        // cout << arr[i] << " ";
        if(arr[i] == 0) continue;

        if(arr[i] < k) {
            cnt += 1;
        } else if ( arr[i]%k == 0 ){
            cnt += arr[i]/k;
        } else {
            cnt += arr[i]/k;
            cnt +=1;
        }

    }

    cout << cnt << "\n";


   
    

    return 0;
}