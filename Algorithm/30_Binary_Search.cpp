// 이분 탐색(Binary Search)
//이미 데이터가 정렬이 되어 있는 상황에서 범위를 반씩 좁혀가며 데이터를 빠르게 탐색하는 알고리즘
//시간 복잡도 O(Log2N)
//이러한 이분 탐색의 개념은 AVL 트리, B트리, 분할 정복 등에서 넓게 적용되므로 매우 중요

#include <iostream>
#define NUMBER 12

using namespace std;

int a[] = {1, 3, 5, 7, 9, 11, 14, 15, 18, 19, 25, 28};
int d = 7;

int search(int start, int end, int target){
    if(start>end) return -1;
    int mid  = (start+end)/2;
    if(a[mid] == target) return mid;
    else if(a[mid] > target) return search(start, mid-1, target);
    else return search(mid+1, end, target);
}

int main(void){
    int result = search(0,NUMBER-1, d);
    if(result != -1){
        cout << result+1 << "번째에서 찾았습니다.";
    }
}