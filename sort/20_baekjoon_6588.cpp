//https://www.acmicpc.net/problem/6588

#include <iostream>
#define MAX 1000001

using namespace std;

int a[MAX];

int main(void){
    for(int i=2; i<=MAX; i++){
        a[i] = i;
    }

    for(int i=2; i<=MAX; i++){
        if(a[i] == 0) continue;
        for(int j=i*2; j<=MAX; j+=i){
            a[j] = 0;
        }
    }

    bool find;
    
    while(1){
        int n;
        cin >> n;
        if(n==0) break;
        
        for(int i = n; i >= n / 2; i--) {
			if(a[i] != 0 && a[n - i] != 0) {
				printf("%d = %d + %d\n", n, n - a[i], a[i]);
				find = true;
				break;
			}
		}
        if(!find){
            printf("Goldbach's conjecture is wrong.\n");
        }
    }
    
    

}