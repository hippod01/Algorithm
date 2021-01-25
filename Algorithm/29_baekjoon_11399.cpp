//https://www.acmicpc.net/problem/11399

#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    //사람수
    int n;
    cin >> n;

    int t[n];

    for(int i=0; i<n; i++){
        cin >> t[i];
    }
    sort(t,t+n);

    int s,sum = 0;
    
    for(int i=0; i<n; i++){
        s += t[i];
        sum += s;
    }

    cout << sum;

    return 0;

}