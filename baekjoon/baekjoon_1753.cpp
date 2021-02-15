//https://www.acmicpc.net/problem/1753

#include <iostream>
#include <vector>
#include <queue>
#define INF 100000000
using namespace std;

// 정점의 개수, 간선의 개수, 시작 정점
int V, E, K;
//간선정보
vector< pair <int, int> > a[20001];
//최소비용
int result[20001];

void dijkstra(int start){

    priority_queue < pair <int, int> > pq;
    pq.push(make_pair(0,start));
    result[start] = 0;
    
    while(!pq.empty()){
        int current = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();

        if(result[current] < cost) continue;

        for(int i=0; i < a[current].size(); i++){

            int next = a[current][i].second;
            int nextCost = cost + a[current][i].first;
            if(nextCost < result[next]){
                result[next] = nextCost;
                pq.push(make_pair(-nextCost, next));
            }
        }

        
    }


}

int main(void){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V >> E >> K;
    
    for(int i=1; i<=E; i++){
        int u, v, w;
        cin >> u >> v >> w;
        a[u].push_back(make_pair(w, v));
    }

    // 기본적으로 연결되지 않은 경우 비용은 무한
	for(int i = 1; i <= V; i++) {
		result[i] = INF;
	}

    dijkstra(K);

    for(int i = 1; i <= V; i++) {
        if(result[i] == INF){
            cout << "INF" << '\n';    
        } else{
            cout << result[i] << '\n';
        }
	}

    return 0;
}