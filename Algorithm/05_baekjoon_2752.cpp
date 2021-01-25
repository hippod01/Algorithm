//https://www.acmicpc.net/problem/2752
//입력 받은 수 정렬 - 선택정렬

#include <stdio.h>

int array[3];
int main(void)
{
    int min, i,j, temp, index;

    for(i=0; i<3;i++){
        scanf("%d", &array[i]);
    }

    for(i=0; i<3; i++){
        min = 1000001;
        for(j=i; j<3; j++){
            if(min > array[j]){
            min = array[j];
            index = j;
            }
        }
        temp = array[i];
        array[i] = array[index];
        array[index] = temp;
        
    }

    for(i=0; i<3; i++){
        printf("%d ", array[i]);
    }

    return 0;
}