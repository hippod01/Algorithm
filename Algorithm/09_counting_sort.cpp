//계수정렬 : 범위 조건이 있는 경우에 한해서 굉장히 빠른 알고리즘 
// 크기를 기준으로 객수를 세는 것
//시간복잡도  : O(N)
#include <stdio.h>

int main(void){
    int temp;
    int count[5];// 범위
    int array[30] = {
        1, 3, 2, 4, 3, 2, 5, 3, 1, 2,
        3, 4, 4, 3, 5, 1, 2, 3, 5, 2,
        3, 1, 4, 3, 5, 1, 2, 1, 1, 1
    };

    //count 초기화
    for(int i=0; i<5; i++){
        count[i] = 0;
    }

    //count 값 증가
    for(int i=0; i <30; i++){
        count[array[i]-1]++;
    }

    for(int i=0; i<5; i++){
        if(count[i] != 0){
            for(int j=0; j<count[i]; j++){
                printf("%d", i+1);

            }
        }
    }


    return 0;
}