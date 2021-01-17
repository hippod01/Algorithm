//https://www.acmicpc.net/problem/2217

#include <iostream>
#include <algorithm>

using namespace std;

int a[100001];
int n;

int main(void){
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);

	int max = 0;
	for(int i = 0; i < n; i++) {
		if(max < a[i] * (n - i)) 
            max = a[i] * (n - i);
	}
	return 0;
}
    