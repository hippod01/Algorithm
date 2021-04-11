#include <bits/stdc++.h>

using namespace std;

int sum = 0;
int arr[9] = { 0, };

int sol(int sum, int arr[]){
    for(int i=0; i<9; i++){
        for(int j=i+1; j<9; j++){
            if((sum - arr[i] - arr[j]) == 100){
                arr[i] = 0;
                arr[j] = 0;
                return 0;
            }   
        }
    }
}

int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i=0; i<9; i++){
        cin >> arr[i];
        sum += arr[i];
    }
    
    sol(sum, arr);
    
    sort(arr, arr+9);

    for(int i=2; i<9; i++){
        if(arr[i] != 0){
            cout << arr[i] << "\n";
        }
    }

    return 0;
}