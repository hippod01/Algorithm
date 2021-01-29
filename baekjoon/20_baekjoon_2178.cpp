//https://www.acmicpc.net/problem/2178
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int map[101][101];
int v[101][101];
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

void bfs(int x, int y){
    queue<pair<int, int>> q;
    q.push(make_pair(x,y));
    v[x][y] = 1;
    
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();

        //상하좌우 네방향 탐색
        for(int i = 0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            //지도 범위 안
            if(0<=nx && nx<n && 0<= ny && ny<m){
                //방문하지 않았고, 이동할 수 있는 칸일 때
                if(v[nx][ny]==0&&map[nx][ny]==1){
                    q.push(make_pair(nx,ny));
                    v[nx][ny] = v[x][y] + 1;
                }
                else if(v[nx][ny]==0)
                    v[nx][ny] = -1;
            }
        }
    }
}

int main(void){

    
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j =0; j <m; j++){
            scanf("%1d", &map[i][j]);
        }
    }

    bfs(0,0);
    printf("%d\n", v[n-1][m-1]);

    return 0;
}