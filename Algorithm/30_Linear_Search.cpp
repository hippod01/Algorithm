//순차 탐색(Linear Search)과 이분 탐색(Binary Search)
//저장되어 있는 데이터를 탐색하는 방법

//순차 탐색(Linear Search)
//데이터의 정렬 유무에 상관 없이 앞에서부터 데이터를 하나씩 확인하여 탐색하는 알고리즘

#include <iostream>
#define NUMBER 10

using namespace std;

int a[] = {8, 3, 4, 5, 1, 9, 6, 7, 2, 0};
int d = 7;

int main(void){
    for(int i=0; i<NUMBER; i++){
        if(a[i] == d){
            cout << i+1 << "번째에서 찾았습니다.";
        }
    }
}
