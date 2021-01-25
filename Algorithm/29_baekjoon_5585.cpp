//https://www.acmicpc.net/problem/5585

#include <iostream>

using namespace std;

int main(void){
    
    int n, count = 0;
    cin >> n;
    n = 1000-n;

    count += n/500;
    n %= 500;
    count += n/100;
    n %= 100;
    count += n/50;
    n %= 50;
    count += n/10;
    n %= 10;
    count += n/5;
    n %= 5;
    count += n/1;

    cout << count;

    return 0;
}