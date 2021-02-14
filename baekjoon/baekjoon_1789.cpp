//https://www.acmicpc.net/problem/1789

#include <iostream>

using namespace std;

int main(void){

    //자연수의 합 S
    long long s;
    cin >> s;

    long long sum = 0;
    long long cnt =0;
    while(s >= sum){
        cnt++;
        sum += cnt;

    }

    cout << cnt-1 << '\n';

    return 0;
}