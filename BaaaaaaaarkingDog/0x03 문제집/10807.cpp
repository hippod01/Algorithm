#include <bits/stdc++.h>

using namespace std;

int arr[200];

int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, target;
    cin >> n;

    for(int i=1; i<=n; i++){
        int temp;
        cin >> temp;
        arr[temp+100]++;
    }

    cin >> target;
    cout << arr[target+100] << "\n";

    

    return 0;
}