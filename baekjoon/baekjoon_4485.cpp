//https://www.acmicpc.net/problem/4485

#include <iostream>
#include <queue>

using namespace std;

int n, cnt = 0;
int map[126][126];
int dx[4] = {0,1,0,-1}; 
int dy[4] = {1,0,-1,0};
int d[126][126];


int dijkstra(int y, int x){

    d[y][x] = map[y][x];
    priority_queue <pair <int, pair<int,int> > > pq;
    pq.push(make_pair(-map[y][x],make_pair(y,x)));

    while(!pq.empty()){

        int curY = pq.top().second.first;
        int curX = pq.top().second.second;
        int rupee = -pq.top().first;
        pq.pop();

        // printf("y : %d, x : %d, rupee : %d\n",curY,curX,rupee);
        
        if(curY == (n-1) && curX == (n-1)) return rupee;

        if(d[curY][curX] < rupee) continue;

        for(int i=0; i<4; i++){
            
            int ny = curY + dy[i];
            int nx = curX + dx[i];
            int nextRupee = map[ny][nx] + rupee;
            // printf("ny : %d, nx : %d, nextRupee : %d\n",ny,nx,nextRupee);
            if(0 <= ny && ny <n && 0 <= nx && nx < n){
                if(d[ny][nx] > nextRupee){
                    d[ny][nx] = nextRupee;
                    pq.push(make_pair(-nextRupee, make_pair(ny,nx)));
                }
            }

        }

    }

}

int main(void){

    
    while(1){

        cin >> n;
        if(n==0) break;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                d[i][j] = 1000000;
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin >> map[i][j];
            }
        }

        dijkstra(0,0);

        printf("Problem %d: %d\n", ++cnt,d[n-1][n-1]);
        

    }

    return 0;
}