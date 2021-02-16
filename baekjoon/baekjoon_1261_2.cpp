//https://www.acmicpc.net/problem/1261
//다익스트라로 풀기

#include <iostream>
#include <queue>

using namespace std;

int N,M,cnt;
int map[101][101];
int d[101][101];
int dy[4] = {1,0,-1,0}; 
int dx[4] = {0,1,0,-1};

void dijkstra(){

    priority_queue< pair <int, pair<int, int> > > pq;
    d[0][0] = 0;
    pq.push(make_pair(0, make_pair(0,0)));

    while(!pq.empty()){
        
        int y = pq.top().second.first;
        int x = pq.top().second.second;
        int cost = -pq.top().first;

        pq.pop();

        for(int i=0; i<4; i++){

            int nx = x + dx[i];
            int ny = y + dy[i];

            if(0 <= ny && ny < N && 0 <= nx && nx < M){
                if(d[ny][nx] > cost + map[y][x]){
                    d[ny][nx] = cost + map[y][x];
                    pq.push(make_pair(-d[ny][nx],make_pair(ny,nx)));

                }

            }    
        }
    }
    return;

}


int main(void){

    cin >> M >> N;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            scanf("%1d",&map[i][j]);
            d[i][j] = 1000000;
        }
    }

    dijkstra();

    cout << d[N-1][M-1];
    

    return 0;
}