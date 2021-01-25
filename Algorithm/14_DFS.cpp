//깊이 우선 탐색(depth first search) : 스택
// 스택을 사용하지 않아도 컴퓨터는 구조적으로 항상 스택의 원리를 사용하기 때문에 재귀함수 사용

//시작 노드 스택에 넣어주고 방문처리 해주고 시작
//1. 스택의 최상단 노드를 확인합니다.
//2. 최상단 노드에게 방문하지 않은 인접 노드가 있으면 그 노드를 스택에 넣고 방문처리합니다. 
//   방문하지 않은 인접 노드가 없으면 스택에서 최상단 노드를 뺍니다.

#include <iostream>
#include <vector>

using namespace std;

int number = 7;
// 방문처리
int c[7];
vector<int> a[8];


void dfs(int x){
    if(c[x]) return;
    c[x] = true;
    cout << x << ' ';
    for(int i=0; i<a[x].size(); i++){
        int y = a[x][i];
        dfs(y);
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
	dfs(1); 
	return 0;
}