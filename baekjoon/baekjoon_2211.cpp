//https://www.acmicpc.net/problem/2211

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int m,n;
vector<pair<int,int> > v[1001];
int d[1001];
int parent[1001];

void dijkstra(int start){

    d[start] = 0;
    priority_queue <pair <int,int> > pq;
    pq.push(make_pair(0,start));

    while(!pq.empty()){
        
        int cur = pq.top().second;
        int time = -pq.top().first;
        pq.pop();

        if(d[cur] < time) continue;

        for(int i = 0; i < v[cur].size(); i++){

            int next = v[cur][i].first;
            int nextTime = v[cur][i].second + time;

            if(d[next] > nextTime){
                parent[next] = cur;
                d[next] = nextTime;
                pq.push(make_pair(-nextTime, next));
            }
        }

    }



}

int main(void){

    cin >> n >> m;

    for(int i=0; i<m; i++){
        int a,b,c;
        cin >> a >> b >>c;
        v[a].push_back(make_pair(b,c));
        v[b].push_back(make_pair(a,c));
    }

    for(int i=1; i<=n; i++){
        d[i] = 1000000;
    }

    dijkstra(1);

    cout << n-1 << '\n';
    for(int i = 2; i <= n; i++){
        printf("%d %d\n",parent[i],i);
    }

    return 0;
}