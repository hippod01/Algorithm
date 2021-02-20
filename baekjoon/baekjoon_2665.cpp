//https://www.acmicpc.net/problem/2665

#include <iostream>
#include <queue>

using namespace std;

int map[51][51];
int n;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int d[51][51];

int dijkstra(){

    priority_queue <pair <int, pair <int,int> > > pq;
    pq.push(make_pair(0,make_pair(0,0)));
    d[0][0] = 0;

    while(!pq.empty()){

        int y = pq.top().second.first;
        int x = pq.top().second.second;
        int cnt = -pq.top().first;
        //printf("y : %d, x : %d, cnt : %d\n",y,x,cnt);
        pq.pop();

        if(d[y][x] < cnt) continue;

        if(y == (n-1) && x == (n-1)) return cnt;

        for(int i=0; i<4; i++){

            int ny = y + dy[i];
            int nx = x + dx[i];

            if(0 <= ny && ny < n && 0 <= nx && nx < n){
                // 흰 방
                int nextCnt = cnt;
                //검은 방일 때
                if(map[ny][nx] == 0){
                    nextCnt = cnt + 1;
                }
                //printf("ny : %d, nx : %d, nextCnt : %d\n",ny,nx,nextCnt);
                if(d[ny][nx] > nextCnt){
                    d[ny][nx] = nextCnt;
                    pq.push(make_pair(-nextCnt,make_pair(ny,nx)));
                }
            }
            
        }

    }
}

int main(void){

    cin >> n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            //0 검은 방, 1 흰 방
            scanf("%1d", &map[i][j]);
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            d[i][j] = 1000000;
        }
    }

    cout << dijkstra() << '\n';

    return 0;
}