//다익스트라 알고리즘은 하나의 정점에서 출발했을 때 다른 모든 정점으로의 최단 경로를 구하는 알고리즘

//플로이드 와샬 알고리즘 : '모든 정점'에서 '모든 정점'으로의 최단 경로
// '거쳐가는 정점'을 기준으로 최단 거리를 구하는 것
//다이나믹 프로그래밍 기술에 의거

//X에서 Y로 가는 최소 비용 VS X에서 노드 1로 가는 비용 + 노드 1에서 Y로 가는 비용
//O(n^3)

#include <stdio.h>

int number = 4;
int INF = 10000000;

//자료 배열을 초기화
int a[4][4] = {
	{0, 5, INF, 8},
	{7, 0, 9, INF},
	{2, INF, 0, 4},
	{INF, INF, 3, 0}
};

void floydWarchall(){
    //결과 그래프 초기화
    int d[number][number];

    for(int i=0; i<number; i++){
        for(int j=0;j<number; j++){
            d[i][j] = a[i][j];
        }
    }


    //k= 거쳐가는 노드, i = 출발노드, j=도착 노드
    for(int k = 0; k < number; k++){
        for(int i=0; i < number; i++){
            for(int j=0; j<number; j++){
                if(d[i][k]+d[k][j] < d[i][j]){
                    d[i][j] = d[i][k]+d[k][j];
                }
            }
        }
    }

    // 결과 출력
    for(int i=0; i<number; i++){
        for(int j=0;j<number; j++){
            printf("%3d",d[i][j]);
        }
        printf("\n");
    }
}

int main(void){

    floydWarchall();
}