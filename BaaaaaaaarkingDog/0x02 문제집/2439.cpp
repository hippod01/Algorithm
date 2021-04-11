#include <bits/stdc++.h>

using namespace std;

int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(n-j < i){
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << "\n";
    }
    
    return 0;
}