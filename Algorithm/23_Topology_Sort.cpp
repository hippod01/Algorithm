//위상정렬 : '순서가 정해져있는 작업'을 차례로 수행해야 할 때 
// 그 순서를 결정해주기 위해 사용하는 알고리즘
//시간 복잡도는 O(V + E), 정점의 갯수 + 간선의 갯수

//DAG(Directed Acyclic Graph)에만 적용이 가능. 
//이것은 사이클이 발생하지 않는 방향 그래프하는 의미
// 사이클이 발생하는 경우 위상 정렬을 수행할 수 없음

//1. 스택을 이용한 방식
//2, 큐를 이용한 방식

//큐를 이용한 방식

//① 진입차수가 0인 정점을 큐에 삽입합니다.
//② 큐에서 원소를 꺼내 연결된 모든 간선을 제거합니다.
//③ 간선 제거 이후에 진입차수가 0이 된 정점을 큐에 삽입합니다.
//④ 큐가 빌 때까지 2번 ~ 3번 과정을 반복합니다. 
//모든 원소를 방문하기 전에 큐가 빈다면 사이클이 존재하는 것이고, 
//모든 원소를 방문했다면 큐에서 꺼낸 순서가 위상 정렬의 결과입니다.

#include <iostream>
#include <queue>
#include <vector>
#define MAX 10

using namespace std;

//indgree = 진입차수
int n, inDegree[MAX];

vector<int> a[MAX];

void topologySort() {

    int result[MAX];
    queue<int> q;

    //진입 차수가 0인 노드를 큐에 삽입
    for(int i= 0; i <=n; i++){
        if(inDegree[i] == 0) q.push(i);
    }
    //정렬이 완전히 수행되려면 n개의 노드를 방문해야함
    for(int i=1; i<=n; i++){
        //n개를 방문하기 전에 큐가 비어버리면 사이클 발생한 것
        if(q.empty()){
            printf("사이클이 발생했습니다");
            return;
        }

        int x = q.front();
        q.pop();
        result[i] = x;

        //연결된 간선 제거
        for(int i = 0; i<a[x].size(); i++){
            int y = a[x][i];
            //진입차수 -1 -> 새롭게 진입차수가 0이 된 정점을 큐에 넣음
            if(--inDegree[y] == 0){
                q.push(y);
            }
        }
    
    }

    //출력
        for(int i = 1; i <= n; i++) {
		    printf("%d ", result[i]);
	    }
}


int main(void) {
	n = 7;
	a[1].push_back(2);
	inDegree[2]++;
	a[1].push_back(5);
	inDegree[5]++;
	a[2].push_back(3); 
	inDegree[3]++;
	a[3].push_back(4); 
	inDegree[4]++;
	a[4].push_back(6); 
	inDegree[6]++;
	a[5].push_back(6); 
	inDegree[6]++;
	a[6].push_back(7); 
	inDegree[7]++;
	topologySort();
}