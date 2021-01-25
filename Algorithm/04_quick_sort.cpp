//퀵정렬 : 특정한 기준 값(피벗 값, 거의 가장 앞의 값을 사용)으로 큰 숫자와 작은 숫자를 나눠 정렬
//1. 피벗 값을 선택하고 왼쪽에서는 피벗 값보다 큰 값을 찾고 , 오른쪽에서 부터는 피벗 값보다 작은 값을 찾아 둘의 자리를 바꿔준다.
//2. 서로 엇갈리는 경우는 엇갈리는 지점의 두 개의 값 중 작은 값과 피벗 값의 자리를 교체 
//3. 교체 된 원래 피벗 값은 정렬 됨 이 값을 기준점으로 좌우 나뉘어서 다시 제일 앞의 숫자가 피벗값이 되고 각각 다시 1~3의 순서를 반복한다.
//평균 시간 복잡도 : O(N*logN)
//최악 시간 복잡도 : O(N^2)

#include <stdio.h>

int num = 10;
int data[10] = {1,10,5,8,7,6,4,3,2,9};

void quickSort(int *data, int start, int end){
    if(start>= end){ // 원소가 1개인 경우
        return;
    }

    int key = start; // 키는 첫번째 원소
    int i = start+1; // 왼쪽 출발지점
    int j = end; // 오른쪽 출발지점
    int temp;

    while(i<=j){ // 엇갈릴 때까지 반복
        while(data[i] <= data[key]){ // 키 값보다 큰 값을 만날 때까지
            i++;
        }

        while(data[j] >= data[key] && j > start){ // 키 값 보다 작은 값을 만날 때까지
            j--;
        }

        // 위의 두 부분 부등호 방향 바꿔주면 내림차순으로 변경됨

        if(i > j){ //현재 엇갈린 상태면 키 값과 교체
            temp = data[j];
            data[j] = data[key];
            data[key] = temp;

        } else { // 큰 값과 작은 값을 교체
            temp = data[j];
            data[j] = data[i];
            data[i] = temp;
        }

        quickSort(data, start, j-1);
        quickSort(data, j+1, end);
    }
}

int main(void)
{
    quickSort(data, 0, num-1);
    for(int i=0; i<10; i++){
        printf("%d ",data[i]);
    }
    return 0;
}
