//https://www.acmicpc.net/problem/2750

#include <iostream>
#include <algorithm>
#define NUMBER 1001

using namespace std;

int a[NUMBER];

int main(void){

    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    sort(a,a+n);

    for(int i=0; i<n; i++){
        cout << a[i] << '\n';
    }

}

