//삽입 정렬 : 각 숫자를 적절한 위치에 삽입 (필요할 때만 위치를 바꿈)
//시간 복잡도 : O(N^2)
//선택, 버블, 삽입 중에서 가장 빠름

#include <stdio.h>

int main(void){
    int i,j,temp;
    int array[10] = {1,10,5,8,7,6,4,3,2,9};

    for(i=0; i<9; i++){
        j=i;
        while(array[j] > array[j+1]){
            temp = array[j];
            array[j] = array[j+1];
            array[j+1] = temp;
            j--;
        }
    }
    for(i=0; i<10; i++){
        printf("%d ",array[i]);
    }

    return 0;
}
