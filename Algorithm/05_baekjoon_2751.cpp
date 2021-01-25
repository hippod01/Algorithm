//https://www.acmicpc.net/problem/2751
//N의 수가 주어졌을 때 오름차순으로 정렬 (N>백만) - 퀵 정렬 사용
// 100만개 이상이라 병합정렬, 힙정렬 사용해야 하지만 퀵도 정답처리 됨

#include <stdio.h>

int data[1000001];

void quickSort(int *data, int start, int end){
    if(start >= end){
        return;
    } 

    int key = start;
    
    int i = start+1, j = end, temp;
    
    while(i <= j){
        while(data[i] <= data[key]){
            i++;
        }
        while(data[j] >= data[key] && j> start){
            j--;
        }

        if(i > j){
            temp = data[j];
            data[j] = data[key];
            data[key] = temp;
        } else{
            temp = data[i];
            data[i] = data[j];
            data[j] = temp;
        }
    }

    quickSort(data, start, j-1);
    quickSort(data, j+1, end);


}


int main(void)
{
    int number;
    
    scanf("%d", &number);

    for(int i=0; i<number; i++){
        scanf("%d", &data[i]);
    }

    quickSort(data, 0, number-1);

    for(int i=0; i<number; i++){
        printf("%d\n", data[i]);
    }

    return 0;
}