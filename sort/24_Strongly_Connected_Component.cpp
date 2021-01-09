//강한 결합 요소 (SCC) : 그래프 안에서 '강하게 결합된 정점 집합'을 의미
//같은 SCC에 속하는 두 정점은 서로 도달이 가능하다'는 특징
//서로 서로한테 갈 수 있는 경우 같은 scc에 속해 있다.
//사이클이 발생하는 경우 무조건 scc
//강한 결합 요소(SCC)는 그 자체로는 큰 의미가 없고, 위상 정렬과 함께 생각해보았을 때 큰 의미

//scc 추출 알고리즘 :
//코사라주 알고리즘(Kosaraju's Algorithm)과 타잔 알고리즘(Tarjan's Algorithm)

//타잔 알고리즘은 모든 정점에 대해 DFS를 수행하여 SCC를 찾는 알고리즘
// 타잔 알고리즘의 시간 복잡도는 O(V + E)로 위상 정렬의 시간 복잡도와도 동일

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#define MAX 10001

using namespace std;

int id, d[MAX];
bool finished[MAX];
vector<int> a[MAX];
vector<vector<int> > SCC;
stack<int> s;

//dfs는 총 정점의 갯수만큼 실행됨
int dfs(int x){
    //노드마다 고유한 번호를 할당
    d[x] = ++id;
    // 스택에 자기 자신을 삽입
    s.push(x);
    
   int parent = d[x];
   
	for(int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
        //방문하지 않은 노드
        if(d[y]==0) 
            parent = min(parent, dfs(y));
        //처리중인 이웃
        else if(!finished[y])
            parent = min(parent, d[y]);
	}
        //부모 노드가 자기 자신인 경우
        if(parent == d[x]){
            vector<int> scc;
            
            while(1){
                int t = s.top();
                s.pop();
                scc.push_back(t);
                finished[t] = true;
                if(t == x) break;
            }
            SCC.push_back(scc);
        }
    
    // 자신의 부모 값을 반환합니다. 
	return parent;  
}



int main(void) {

	int v = 11;
	a[1].push_back(2);
	a[2].push_back(3);
	a[3].push_back(1);
	a[4].push_back(2);
	a[4].push_back(5);
	a[5].push_back(7);
	a[6].push_back(5);
	a[7].push_back(6);
	a[8].push_back(5);
	a[8].push_back(9);
	a[9].push_back(10);
	a[10].push_back(11);
	a[11].push_back(3);
	a[11].push_back(8);

	for(int i = 1; i <= v; i++) {
		if(d[i] == 0) dfs(i);
	}

	cout << "SCC의 갯수 : " << SCC.size() << "\n";

    // 전체 SCC 출력
	for(int i = 0; i < SCC.size(); i++) {
		printf("%d번째 SCC: ", i + 1);
		for(int j = 0; j < SCC[i].size(); j++) {
			printf("%d ", SCC[i][j]);
		}
		printf("\n");
	}
	return 0;
}