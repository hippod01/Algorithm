#include <bits/stdc++.h>

using namespace std;

int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    
    for(int i=n; i>=1; i--){
        for(int j=0; j<n-i; j++){
            cout << " ";
        }
        for(int k=0; k<2*i-1; k++){
            cout << "*";
        }

        cout << "\n";
    }
    
    return 0;
}