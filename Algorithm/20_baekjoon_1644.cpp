//https://www.acmicpc.net/problem/1644

#include <iostream>
#define MAX 4000001

using namespace std;

int a[MAX];

int main(void){

    int n;
    cin >> n;

    a[1] = 1;
    for(int i =2; i<=n; i++){
        if(a[i]==1) continue;
        for(int j = i*2; j<=n; j+=i){
            
            a[j] = 1;
        }
    }

    int sum;
    int count;
    for(int i=2; i<=n; i++){
        sum = i;
        if(a[i] == 0 && i==n) count++;
        for(int j=i+1; j<=n; j++){
            if(a[i] == 0 && a[j] == 0){
                sum += j;
                if(sum == n) count++;
            }
        }        
    }

    cout << count; 

    return 0;
}