//https://www.acmicpc.net/problem/1916

#include <iostream>
#include <vector>
#include <queue>
#define INF 100000000

using namespace std;

vector<pair< int, int> > ml[1001];
int d[1001];

void dijkstra(int start){
    
    priority_queue< pair <int, int> >  pq;
    pq.push(make_pair(0,start));
    d[start] = 0;

    while(!pq.empty()){

        int current = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();

        if(d[current] < cost) continue;

        for(int i=0; i<ml[current].size(); i++){

            int next = ml[current][i].second;
            int nextCost = ml[current][i].first + cost;

            if(nextCost < d[next]){
                d[next] = nextCost;
                pq.push(make_pair(-nextCost, next));
            }

        }

    }

}

int main(void){

    //도시의 개수, 버스의 개수
    int N,M;
    cin >> N >> M;

    for(int i=1; i<=M; i++){
        //간선 정보
        int a, cost, b;
        cin >> a >> b >> cost;
        ml[a].push_back(make_pair(cost,b));

    }

    for(int i=1; i<=N; i++){
        d[i] = INF;
    }

    int start, end;
    cin >> start >> end;

    dijkstra(start);

    cout << d[end]<< '\n';



    return 0;
}