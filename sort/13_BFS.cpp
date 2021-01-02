//너비 우선 탐색 : 너비를 우선(거리가 가까운 순 우선)으로 하여 탐색을 수행하는 탐색 알고리즘, 
// 최단 경로 찾아 줌 -> 최단 길이 보장할 때 많이 사용 (미로 찾기 등)
// 큐를 이용

// 시작 노드를 큐에 삽입하면서 시작
//1. 큐에서 하나의 노드를 꺼내고
//2. 해당 노드에 연결된 노드 중 방문하지 않은 노드를 차례대로 큐에 삽입

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int number = 7;
// 방문처리
int c[7];
vector<int> a[8];

void bfs(int start){
    queue<int> q;

    q.push(start);
    c[start] = true;

    while(!q.empty()){
        int x = q.front();

        q.pop();
        printf("%d ",x);
        
        for(int i=0; i<a[x].size(); i++){
            int y = a[x][i];
            if(!c[y]){
                q.push(y);
                c[y] = true;
            }
        }
    }

}

int main(void) {
	// 1과 2을 연결합니다. 
	a[1].push_back(2);
	a[2].push_back(1);
	// 1과 3를 연결합니다.
	a[1].push_back(3);
	a[3].push_back(1);
	// 2과 3를 연결합니다.
	a[2].push_back(3);
	a[3].push_back(2);
	// 2과 4을 연결합니다. 
	a[2].push_back(4);
	a[4].push_back(2);
	// 2과 5를 연결합니다.
	a[2].push_back(5);
	a[5].push_back(2);
	// 3와 6를 연결합니다.
	a[3].push_back(6);
	a[6].push_back(3);
	// 3와 7을 연결합니다.
	a[3].push_back(7);
	a[7].push_back(3);
	// 4와 5를 연결합니다.
	a[4].push_back(5);
	a[5].push_back(4);
	// 6과 7을 연결합니다.
	a[6].push_back(7);
	a[7].push_back(6); 
	// BFS를 수행합니다.
	bfs(1); 
	return 0;
}