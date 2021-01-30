//https://www.acmicpc.net/problem/7576

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, result;
int v[1001][1001];
int map[1001][1001];
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
queue<pair<int, int>> q;

void bfs(int x, int y){
    
    v[x][y] = true;

    while(!q.empty()){
        
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0 <= nx && nx < n && 0 <= ny && ny < m){
                // printf("%d, %d\n", nx,ny);
                if(v[nx][ny] == false && map[nx][ny] == 0){
                    map[nx][ny] = map[x][y] + 1;
                    v[nx][ny] = true;
                    q.push(make_pair(nx,ny));
                } 
            }
        }
    }

}

int main(void){
    

    cin >> m >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
            if(map[i][j]==1){
                q.push(make_pair(i,j));
            }
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(v[i][j] == false && map[i][j] == 1){
                bfs(i,j);
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map[i][j] == 0){
                cout << "-1";
                return 0;
            } else{
                result = max(result, map[i][j]-1);
                
            }
            // cout << map[i][j] << ' ';
        }
        // cout << '\n';
    }
    cout << result;



    return 0;
}