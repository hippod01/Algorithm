// 힙 정렬 : 힙 트리 구조를 이용하는 정렬 방법
// 힙 : 최솟 값고 최댓값을 빠르게 찾아내기 위해 완전 이진 트리를 기반으로 하는 트리 (최대 힙, 최소 힙)


// 힙 구조로 만들기 ( 힙 생성 알고리즘(heapify algorithm) 사용 )
// 특정한 노드의 두 자식 중에서 더 큰 자식과 자신의 위치를 바꾸는 알고리즘
// 한번 heapify 수행하는 시간 복잡도 O(logN)
// 전체 시간 복잡도 : O(NlogN)
// 실제 시간 복잡도 : O(1/2NlogN) -> O(N)

#include <stdio.h>

int number = 9;
int heap[9] = {7,6,5,8,3,5,9,1,6};

int main(void){
    // 전체 트리 구조를 최대 힙 구조로 바꾼다.
    for(int i= 1; i < number; i++){
        int c  =  i;
        do{
            // 부모노드
            int root = (c-1)/2;
            
            // 자식 노드가 부모 노드보다 크다면 값 변경
            if(heap[root] < heap[c]){
                int temp= heap[root];
                heap[root] = heap[c];
                heap[c] = temp;
            }
            c= root;
        }while(c!=0);
    }

    //크기를 줄어가면서 반복적으로 힙 구성
    //루트 노드 제일 마지막 노드로 - > heapify -> 다시 루트 노드 마지막 노드로 -> heapify
    for(int i= number-1; i>0; i--){
        int temp = heap[0];
        heap[0] = heap[i];
        heap[i] = temp;

        //다시 힙구성
        int root = 0;
        int c = 1;
        do{
            c = 2 * root+1;
            //자식 중에 더 큰 값을 찾기
            if(heap[c]<heap[c+1] && c<i-1){
                c++;
            }

            //루트보다 자식값이 더 크다면 교환
            if(heap[root]<heap[c] && c<i){
                int temp = heap[root];
                heap[root] = heap[c];
                heap[c] = temp;
            }
            root = c;
        }while(c<i);
    }
    for(int i=0; i < number;  i++){
        printf("%d",heap[i]);
    }
}