//https://www.acmicpc.net/problem/1261
//1. bfs로 풀기

#include <iostream>
#include <queue>

using namespace std;

int n,m;
int map[101][101];
bool v[101][101];
int dy[4] = {1,0,-1,0}; 
int dx[4] = {0,1,0,-1};


void bfs(int y, int x){
    priority_queue < pair< int, pair<int, int> > > q;
    q.push(make_pair(0,make_pair(y,x)));
    v[y][x] = true;

    while(!q.empty()){

        int y = q.top().second.first;
        int x = q.top().second.second;
        int cnt = -q.top().first;
        
        q.pop();

        if(y == (n-1) && x == (m-1)){
            cout << cnt << '\n';
            return;
        }

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0 <= ny && ny < n && 0 <= nx && nx < m){
                if(v[ny][nx] == false){    
                    if(map[ny][nx] == 1){
                        q.push(make_pair(-(cnt+1),make_pair(ny,nx)));
                    } else {
                        q.push(make_pair(-cnt, make_pair(ny,nx)));
                    }
                    v[ny][nx] = true;
                } 
            }
        }
    }
    

    
}

int main(void){

    //가로, 세로
    cin >> m >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%1d", &map[i][j]);
        }
    }
    
    bfs(0,0);

    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         cout << map[i][j] << ' ';
    //     }
    //     cout <<  '\n';
    // }

    return 0;
}