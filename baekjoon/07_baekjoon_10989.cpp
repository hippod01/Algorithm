//https://www.acmicpc.net/problem/10989
//메모리제한이 8MB이라 배열에 수를 저장하면 메모리 초과 발생
//시간제한이 3초, 빠른 입출력 사용

#include <iostream>
#define NUMBER 10001

using namespace std;

int a[NUMBER];

int main(void){
    // 빠른 입출력
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        a[temp]++;
    }

    for(int i=0; i<NUMBER; i++){
        for(int j=0; j<a[i]; j++){
            cout << i << '\n';
        }
    }
}