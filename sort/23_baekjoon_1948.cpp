//https://www.acmicpc.net/problem/1948

#include <stdio.h>
#include <vector>
#include <queue>
#define MAX 10001

using namespace std;

class Edge{
    public:
        int node;
        int time;
        Edge(int node, int time){
            this->node = node;
            this->time = time;
        }
};

int n,start,finish;
int inDegree[MAX], result[MAX], c[MAX];
vector<Edge> a[MAX];
vector<Edge> b[MAX];

void topologySort(){

    queue<int> q;
    // 시작점 큐에 삽입
    q.push(start);

    //더이상 방문할 노드가 없을 때 까지
    while(!q.empty()){
        int x= q.front();
        q.pop();
        for(int i=0; i<a[x].size(); i++){

            Edge y = Edge(a[x][i].node,a[x][i].time);
            if(result[y.node]<= y.time+result[x]){
                result[y.node] = y.time + result[x];
            }
            //새롭게 진입차수가 0이 된 정점을 큐에 삽입
            if(--inDegree[y.node] == 0){
                q.push(y.node);
            }
        }
   
    }
    //결과 역추적
        int count = 0;
        q.push(finish);
        while(!q.empty()){
            int y = q.front();
            q.pop();

            for(int i=0; i<b[y].size(); i++){
                Edge x = Edge(b[y][i].node,b[y][i].time);

                //최장 경로(임계경로) 에 포함되는 간선인지 확인
                if(result[y] - result[x.node] == x.time){
                    count++;
                    //큐에 한 번씩 담아 추적
                    if(c[x.node] == 0){
                        q.push(x.node);
                        c[x.node] = 1;
                    }
                }
            }
        }

        printf("%d\n%d", result[finish], count);


}


int main(void){
    int m;
    scanf("%d\n", &n);
    scanf("%d\n", &m);

    for(int i=1; i<=m; i++){
        int x, node, time;
        scanf("%d %d %d", &x, &node, &time);
        a[x].push_back(Edge(node, time));
        b[node].push_back(Edge(x,time));
        inDegree[node]++;
    }
    scanf("%d %d", &start, &finish);
    topologySort();
}