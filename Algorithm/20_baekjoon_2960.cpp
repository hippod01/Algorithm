//https://www.acmicpc.net/problem/2960

#include <iostream>
#define MAX 10001

using namespace std;

int a[MAX];

int main(void){
    int n,k;
    cin >> n >> k;
    int count =0;
    
    for(int i=2; i<=n; i++){
        if(a[i] == 1) continue;
        count++;
        if(count == k) cout << i;
        
        for(int j=i*2; j<=n; j+=i){
            if(a[j] == 1) continue;
            a[j] = 1;
            count++;
            if(count == k) cout << j;
        }
    }

}