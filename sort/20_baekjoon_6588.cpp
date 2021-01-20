//https://www.acmicpc.net/problem/6588

#include <iostream>
#define MAX 1000001

using namespace std;

int a[MAX];

int main(void){
    
    a[1] = 1;
	for(int i = 2; i <= MAX; i++) {
		for(int j = i * 2; j <= MAX; j += i) {
			if(a[j] == 1) continue;
			else a[j] = 1;
		}
	}

    bool find;
    
    while(1) {
		int n;
		scanf("%d", &n);
		if(n == 0) break;
		bool find = false;
		for(int i = n; i >= n / 2; i--) {
			if(a[i] == 0 && a[n - i] == 0) {
				printf("%d = %d + %d\n", n, n - i, i);
				find = true;
				break;
			}
		}
		if(!find) {
			printf("Goldbach's conjecture is wrong.\n");
		}
	}
    
    

}