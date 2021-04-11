#include <bits/stdc++.h>

using namespace std;

int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    
    for(int i=n; i>=1; i--){
        for(int j=1; j<=n; j++){
            if(n-i <j){
                cout << "*";
            }else {
                cout << " ";
            }
        }
        cout << "\n";
    }
    
    return 0;
}