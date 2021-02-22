//https://www.acmicpc.net/problem/10282

#include <iostream>
#include <queue>
#include <vector>
#define INF 987654321

using namespace std;

int n, d, c;
vector<pair<int,int> > v[10001];
int t[10001];


void dijkstra(int start){

    priority_queue <pair <int,int> > pq;
    pq.push(make_pair(0,start));
    t[start] = 0;
    
    while(!pq.empty()){

        int cur = pq.top().second;
        int time = -pq.top().first;

        pq.pop();

        if(t[cur] < time) continue;

        for(int i = 0; i < v[cur].size(); i++){

            int next = v[cur][i].first;
            int nextTime = v[cur][i].second + time;

            if(t[next] > nextTime){
                t[next] = nextTime;
                pq.push(make_pair(-nextTime,next));
                
            }
        }

    }

}

int main(void){

    int tc;
    cin >> tc;

    while(tc--){

        //컴퓨터의 개수, 의존성 개수, 해킹당한 컴퓨터 번호
        cin >> n >> d >> c;

        for(int i = 1; i <= n; i++){
            v[i].clear();
            t[i] = INF;
        }

        for(int i = 0; i < d; i++){
            int a,b,s;
            cin >> a >> b >> s;
            v[b].push_back(make_pair(a,s));
        }

        dijkstra(c);

        int cnt = 0;
        int time = 0;

        for(int i = 1; i <= n; i++){
            if(t[i] != INF) {
                cnt++;
                if(time < t[i]){
                    time = t[i];
                }
            }
        }
        printf("%d %d\n",cnt, time);

    }    

    return 0;
}