#include <bits/stdc++.h>

using namespace std;

int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);

    long long a, b, d;
    cin >> a >> b;

    if(a>b){
        long long temp = b;
        b = a;
        a = temp;
    } 
        
    d = (b-a)-1;

    if ( a == b ){
        cout << "0" << "\n";
    } else {
        cout << d << "\n";
    }

    for(long long i = a+1; i <= b-1; i++){
        cout << i << " ";
    }

    
    return 0;
}