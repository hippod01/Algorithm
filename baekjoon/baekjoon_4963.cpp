//https://www.acmicpc.net/problem/4963

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int w, h, cnt =0;
bool v[51][51];
int map[51][51];
int dx[] = {0,1,0,-1, 1,-1,-1, 1};
int dy[] = {1,0,-1,0, 1, 1,-1,-1};
vector<int> result;

void dfs(int y, int x){
    v[y][x] = true;
    
    for(int i=0; i<8; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if( 0 <= nx && nx < w && 0 <= ny && ny < h){
            if(!v[ny][nx] && map[ny][nx] == 1){            
                // printf("ny : %d, nx : %d\n",ny,nx);
                dfs(ny,nx);
            }
        }

    }

}

int main(void){


    while(1){

        cin >> w >> h;
        if(w == 0 && h == 0) break;

        cnt = 0;
        memset(v,0,sizeof(v));
        memset(map,0,sizeof(map));

        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                cin >> map[i][j];
            }
        }
        
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if(map[i][j] == 1 && !v[i][j]){
                    dfs(i,j);
                    cnt++;
                }
            }
        }
        result.push_back(cnt);

    }
    
    for(int i=0; i<result.size(); i++){
        cout << result[i] << '\n';
    }
    

    return 0;
}