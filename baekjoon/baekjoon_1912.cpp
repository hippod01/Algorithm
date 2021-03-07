//https://www.acmicpc.net/problem/1912

#include <iostream>
#include <algorithm>

using namespace std;

int main(void){

    int n;
    cin >> n;

    int d[n];
    int map[n];

    for(int i=0; i<n; i++){
        cin >> map[i];
    }

    d[0] = map[0];
    
    //연속된 수 중 구할 수 있는 합 중 가장 큰 합
    int result = d[0];

    cout  << "10" << " ";
    for(int i=1; i<n; i++){
        d[i] = max(d[i-1]+map[i],map[i]);
        result = max(result,d[i]);
    }

    cout << result << '\n';

    return 0;
}