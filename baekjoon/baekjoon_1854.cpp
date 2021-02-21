//https://www.acmicpc.net/problem/1854

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n,m,k;
vector<pair<int,int> > v[1001];
//k번째 구하는 큐
priority_queue<int> heap[1001];

void dijkstra(){

    priority_queue<pair <int, int> > pq;

    pq.push(make_pair(0,1));
    heap[1].push(0);

    while(!pq.empty()){

        int cur = pq.top().second;
        int time = -pq.top().first;
        pq.pop();

        for(int i = 0; i < v[cur].size(); i++){
            int next = v[cur][i].first;
            int nextTime = v[cur][i].second + time;

            //k번째 보다 적을 때 다음 값을 Push
            if(heap[next].size() < k){
                heap[next].push(nextTime);
                pq.push(make_pair(-nextTime, next));    
            
            //K가지 수(k번째 최단거리)를 가진 큐안에 nextTime 보다 큰 수가 들어있을 때 빼고 더 작은 수를 넣어줌
            } else if (heap[next].top() > nextTime){
                heap[next].pop();
                heap[next].push(nextTime);
                pq.push(make_pair(-nextTime, next));    
            }
        }

    }

}

int main(void){
    
    //도시 수, 간선 수, k번째 최단경로
    cin >> n >> m >> k;
    
    for(int i = 0; i < m; i++){
        int a,b,c;
        cin >> a >> b >> c;
        v[a].push_back(make_pair(b,c));
    }


    dijkstra();

    for(int i=1; i<=n; i++){
        if(heap[i].size() < k){
            cout << "-1" << '\n';
        } else{
            cout << heap[i].top() << '\n';
        }
    }



    return 0;
}