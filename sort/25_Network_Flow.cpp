//네트워크 플로우(Network Flow)
//특정한 지점에서 다른 지점으로 데이터가 얼마나 많이 흐르고 있는가를 측정하는 알고리즘

//최대 유량(Max Flow) 문제 
//각 간선에 정해진 용량이 있을 때 A에서 B로 최대로 보낼 수 있는 유량의 크기를 구하는 문제
//BFS(너비 우선 탐색)을 이용하는 것이 일반적. 이것을 에드몬드 카프(Edmonds-Karp) 알고리즘
//에드몬드 카프 알고리즘의 시간 복잡도는 O(VE^2)

#include <iostream>
#include <vector>
#include <queue>

#define MAX 100
#define INF 100000000

using namespace std;

// n 정점  result  : 최대 유량
int n = 6, result;
//c 용량, f 유량, d 방문여부,
int c[MAX][MAX], f[MAX][MAX], d[MAX];
vector<int> a[MAX];

void maxFlow(int start, int end){
    while(1){
        fill(d,d+MAX, -1);
		queue<int> q;
		q.push(start);

		while(!q.empty()){
			int x = q.front();
			q.pop();

			for(int i=0; i<a[x].size(); i++){
				int y = a[x][i];
				
				//방문하지 않은 노드 중에 용량이 남은 경우
				if(c[x][y] - f[x][y] > 0 && d[y]== -1){
					q.push(y);
					d[y] = x;// 경로를 기억
					//도착지에 도달한 경우
					if(y == end) break;
				}

			}
		}
		//모든 경로를 찾은 뒤에 탈출
		if(d[end] == -1) break; 

		int flow = INF;

		// 거꾸로 최소 유량 탐색
		for(int i = end; i != start; i = d[i]) {  
			flow = min(flow, c[d[i]][i] - f[d[i]][i]);
		}
		//최소 유량만큼 추가
		for(int i = end; i != start; i = d[i]) {
			f[d[i]][i] += flow;
			f[i][d[i]] -= flow;
		}
		result += flow;
    }
}

int main(void) {
	a[1].push_back(2);
	a[2].push_back(1);
	c[1][2] = 12;
	
	a[1].push_back(4);
	a[4].push_back(1);
	c[1][4] = 11;
	
	a[2].push_back(3);
	a[3].push_back(2);
	c[2][3] = 6;
	
	a[2].push_back(4);
	a[4].push_back(2);
	c[2][4] = 3;
	
	a[2].push_back(5);
	a[5].push_back(2);
	c[2][5] = 5;
	
	a[2].push_back(6);
	a[6].push_back(2);
	c[2][6] = 9;
	
	a[3].push_back(6);
	a[6].push_back(3);
	c[3][6] = 8;
	
	a[4].push_back(5);
	a[5].push_back(4);
	c[4][5] = 9;
	
	a[5].push_back(3);
	a[3].push_back(5);
	c[5][3] = 3;
	
	a[5].push_back(6);
	a[6].push_back(5);
	c[5][6] = 4;

	maxFlow(1, 6);
	printf("%d", result);
}
