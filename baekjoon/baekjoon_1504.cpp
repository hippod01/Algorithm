//https://www.acmicpc.net/problem/1504

#include <iostream>
#include <vector>
#include <queue>
#define INF 1000000

using namespace std;

int n, e;
vector<pair<int,int> > v[801];
int d[801];
int v1, v2;

int dijkstra(int start,int end){

    for(int i=1; i<=n; i++){
        d[i] = INF;
    }

    priority_queue <pair<int, int> > pq;
    pq.push(make_pair(0,start));
    d[start] = 0;

    while(!pq.empty()){
        int cur = pq.top().second;
        int dis = -pq.top().first;

        pq.pop();

        if(d[cur] < dis) continue;

        for(int i=0; i < v[cur].size(); i++){
            int next = v[cur][i].first;
            int nextDis = v[cur][i].second+dis;
            
                if(d[next] > nextDis){
                    d[next] = nextDis;
                    pq.push(make_pair(-nextDis,next));
                }
            
            
        }
    }
    return d[end];
}

int main(void){

    cin >> n >> e;
    for(int i=0; i<e; i++){
        int a,b,c;
        cin >> a >> b >> c;
        v[a].push_back(make_pair(b,c));
        v[b].push_back(make_pair(a,c));
    }
    
    cin >> v1 >> v2;

    int res1 = 0, res2 = 0;
    //1. 1 - v1 - v2 - n
    res1 = dijkstra(1,v1);
    res1 += dijkstra(v1,v2);
    res1 += dijkstra(v2,n);

    //2. 1 - v2 - v1 -n
    res2 = dijkstra(1,v2);
    res2 += dijkstra(v2,v1);
    res2 += dijkstra(v1,n);

    if(res1 >= INF && res2 >= INF){
        cout << "-1" << '\n';
    } else {
        cout << min(res1,res2) << '\n';
    }

    
    
    return 0;
}