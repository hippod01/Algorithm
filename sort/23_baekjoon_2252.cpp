//위상 정렬 기초 문제
//2252번 줄 세우기: https://www.acmicpc.net/problem/2252

#include <stdio.h>
#include <vector>
#include <queue>
#define MAX 32001

using namespace std;


int n, inDegree[MAX], result[MAX];
vector<int> a[MAX];


void topologySort(){
    queue<int> q;
    // 진입차수가 0인 노드를 큐에 삽입
    for(int i=1; i<=n; i++){
        if(inDegree[i] == 0){
            q.push(i);
        }
    }

    //정렬이 완전히 수행되려면 n개의 노드를 방문해야 함
    for(int i=1; i<=n; i++){
        int x = q.front();
        q.pop();

        result[i] = x;
        for(int j=0; j<a[x].size(); j++){
            int y = a[x][j];
            //새롭게 진입차수가 0이 된 정점을 큐에 삽입
            if(--inDegree[y] == 0) q.push(y);

        }
    }

    //출력
    for(int i=1; i<=n; i++){
        printf("%d ", result[i]);
    }

}

int main(void){
    int m;
    scanf("%d %d", &n, &m);
    for(int i=1; i<=m; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        a[x].push_back(y);
        inDegree[y]++;
    }

    topologySort();
}