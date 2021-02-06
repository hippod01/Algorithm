//https://www.acmicpc.net/problem/14502

#include <iostream>
#include <queue>
using namespace std;

int n,m,result;
int map[9][9];
int temp_map[9][9];
int virus_map[9][9];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

void copymap(){
    for(int i=0; i <n; i++){
        for(int j=0; j<m; j++){
            temp_map[i][j] = map[i][j];
        }
    }
}

void copymap_virus() {
  for(int i=0; i <n; i++){
        for(int j=0; j<m; j++){
            virus_map[i][j] = temp_map[i][j];
        }
    }
}

void bfs(){
    copymap_virus();

    queue<pair<int, int> > q;

    for(int i=0; i <n; i++){
        for(int j=0; j<m; j++){
            if(map[i][j] == 2){
                q.push(make_pair(i,j));
            }
        }
    }

    while(!q.empty()){
        pair<int,int> p = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            int ny = p.first + dy[i];
            int nx = p.second + dx[i];

            if( 0 <= nx && nx < m && 0 <= ny && ny < n){
                if(virus_map[ny][nx] == 0){
                    virus_map[ny][nx] = 2;
                    q.push(make_pair(ny,nx));
                }
                
            }

        }
    }

    // 0의 개수 
    int cnt = 0;
    for(int i=0; i <n; i++){
        for(int j=0; j<m; j++){
            if(virus_map[i][j] == 0) cnt++;
        }
    }

    result = max(cnt, result);

}

void dfs(int a){
    if(a == 3){
        bfs();
        return;
    } else{
        for(int i=0; i <n; i++){
            for(int j=0; j<m; j++){
                if(temp_map[i][j] == 0){
                    temp_map[i][j] = 1;
                    dfs(a+1);
                    temp_map[i][j] = 0;
                }
            }
        }
    }
}


int main(void){

    cin >> n >> m;

    for(int i=0; i <n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
        }
    }

    for(int i=0; i <n; i++){
        for(int j=0; j<m; j++){
            if(map[i][j] == 0){
                copymap();
                temp_map[i][j] = 1;
                dfs(1);
                temp_map[i][j] = 0;
            }
        }
    }

    cout << result; 
    return 0;
}