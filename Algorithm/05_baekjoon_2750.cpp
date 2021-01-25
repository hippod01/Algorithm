//https://www.acmicpc.net/problem/2750
//N개의 수가 주어졌을 때 오름차 순 정렬
//선택정렬로 풀어보기

#include <stdio.h>

int array[1001];

int main(void)
{
    int min, i,j, temp, number, index;
    scanf("%d", &number);
    for(i=0; i<number;i++){
        scanf("%d", &array[i]);
    }

    for(i=0; i<number; i++){
        min = 1001;
        for(j=i; j<number; j++){
            if(min > array[j]){
            min = array[j];
            index = j;
            }
        }
        temp = array[i];
        array[i] = array[index];
        array[index] = temp;
        
    }

    for(i=0; i<number; i++){
        printf("%d\n", array[i]);
    }

    return 0;
}

