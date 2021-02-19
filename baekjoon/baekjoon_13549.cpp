//https://www.acmicpc.net/problem/13549

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n,k;
priority_queue <pair <int, int> > pq;
void move(int, int);
bool v[100001];
int d[100001];

int dijkstra(int start){
    
    pq.push(make_pair(0,start));
    d[start] = 0;
    v[start] = true;

    while(!pq.empty()){
        int cur = pq.top().second;
        int time = -pq.top().first;
        v[cur] = true;

        pq.pop();
        // printf("cur : %d, time : %d\n", cur, time);

        if(cur == k) return time;

        move(cur*2, time+0);
        move(cur-1, time+1);
        move(cur+1, time+1);
        
        
    }

    return -1;
}

void move (int next, int time) {
    if(0 <= next && next <= 100000){
        if(v[next] == false){
            pq.push(make_pair(-time, next));
            d[next] = time;
        }
        if(v[next] == true && d[next] > time){
            pq.push(make_pair(-time, next));
            d[next] = time;
        }
        
    }
}


int main(void){

    cin >> n >> k;

    cout << dijkstra(n) << '\n';

    return 0;
}