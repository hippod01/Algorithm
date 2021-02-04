//https://www.acmicpc.net/problem/10026

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n, cnt = 0, cnt2 = 0;
char map[101][101];
int v[101][101];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
queue< pair<int,int> > q;

void bfs(int i, int j){

    v[i][j] = true;
    q.push(make_pair(i,j));

    while(!q.empty()){
        
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(0 <= ny && ny < n && 0 <= nx && nx < n){
                if(!v[ny][nx] && map[y][x] == map[ny][nx]){
                    q.push(make_pair(ny,nx));
                    v[ny][nx] = true;
                }
            }
            
        }
        
    }

}

int main(void){

    cin >> n;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
           cin >> map[i][j];
        }
    }

    //색약X
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(v[i][j] == false){
                bfs(i,j); 
                cnt++;           
            }
        }
    }

    memset(v,false,sizeof(v));
    
    //색약
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(map[i][j] == 'G'){
                map[i][j] = 'R';
            }
        }
    }

     for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(v[i][j] == false){
                bfs(i,j); 
                cnt2++;           
            }
        }
    }
    
    cout << cnt << ' ' << cnt2;


    return 0;
}