//https://www.acmicpc.net/problem/2150

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

//항상 처음 방문하는 노드만 실행, N번 수행
int dfs(int x){
    //노드마다 고유한 번호 입력
    d[x] = ++id;
    //스택에 자기 자신 넣음
    s.push(x);
    int result = d[x];
    for(int i =0; i<a[x].size();i++){
        int y = a[x][i];

        //방문하지 않은 이웃 노드일 경우
        if(d[y] == 0) {
            result = min(result, dfs(y));

        //방문은 했지만 아직 처리 중인 이웃노드 : 부모 노드 정보 설정
        } else if(!finished[y]){
            result = min(result, d[y]);
        }

    }

    //부모 노드가 자기 자신인 경우 scc 형성
    if(result == d[x]){
        vector<int> scc;
        while(1){
            int t = s.top();
            s.pop();
            scc.push_back(t);
            finished[t] = true;
            if(t==x) break;
        }
        sort(scc.begin(), scc.end());
        SCC.push_back(scc);
    }
    
    return result;
}

int main(void){
    //정점, 간선
    int v, e;
    scanf("%d %d",&v, &e);

    //정점 연결 간선 정보
    for(int i=1; i<=e; i++){
        int x, y;
        scanf("%d %d",&x ,&y);
        a[x].push_back(y);
    }

    for(int i=1; i<=v; i++){
        if(d[i] == 0) dfs(i);
    }
    // scc 개수 출력
    printf("%lu\n", SCC.size());
    //하나의 scc에 속한 정점의 번호 오름차순으로 정렬하여 출력, 
    //각 SCC의 줄 끝에 -1 출력하여 끝을 나타냄
    sort(SCC.begin(), SCC.end());

    for(int i=0; i<SCC.size(); i++){
        for(int j=0; j<SCC[i].size(); j++){
            printf("%d ",SCC[i][j]);
        }
        printf("-1\n");
    }
    return 0;
}

