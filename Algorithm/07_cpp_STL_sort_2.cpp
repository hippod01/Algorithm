#include <iostream>
#include <algorithm>

using namespace std;

// 정렬 기준 만들기

// 기본 :오름차순 정렬 기준
// bool compare(int a, int b){
//     return a < b;
// }
// 내림차순 정렬 기준
bool compare(int a, int b){
    return a > b;
}

int main(void){
    int a[10] = {9,3,5,4,1,10,8,6,7,2};
    // 배열이름, 배열 갯수
    sort(a,a+10,compare);

    for(int i= 0; i< 10; i++){
        cout << a[i] << " " ;
    
    }
}