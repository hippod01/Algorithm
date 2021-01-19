//https://www.acmicpc.net/problem/1978

#include <iostream>
#define MAX 1001

using namespace std;


int a[MAX];

int main(void){
        
    // 1000까지의 모둔 숫자의 소수를 미리 판별, 
    a[1]=1;
    for(int i=2; i<MAX; i++){
        for(int j=i*2;j<MAX;j+=i){
            if(a[j]==1) continue;
            else a[j]=1;
        }
    }
    
    int n, count = 0;
    cin >> n;
    //0 = 소수, 1= 소수X
    for(int i=0; i<n; i++){
        int x;
        cin >>x;
        if(a[x] == 0) count++;
    }

    cout << count;

    return 0;
}