//https://www.acmicpc.net/problem/7569

#include <iostream>
#include <queue>

using namespace std;

int n,m,h, cnt = 0;
int map[101][101][101];
bool v[101][101][101];
int dx[] = {0,1,0,-1,0,0};
int dy[] = {1,0,-1,0,0,0};
int dz[] = {0,0,0,0,1,-1};
queue<pair<int, pair<int, int> > > q;

void bfs(){
    
    while(!q.empty()){
        
        int z = q.front().first;
        int y = q.front().second.first;
        int x = q.front().second.second;
        v[z][y][x] = true;

        q.pop();

        for(int i=0; i<6; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];
            
            if(0 <= nx && nx < m && 0 <= ny && ny < n && 0 <= nz && nz < h){
                if(map[nz][ny][nx] == 0 && v[nz][ny][nx] == false){
                    q.push(make_pair(nz,make_pair(ny,nx)));
                    map[nz][ny][nx] = map[z][y][x] + 1;
                    v[nz][ny][nx] = true;
                } 
            } 
        }
    }

    
}

int main(void){

    cin >> m >> n >> h;

    for(int i = 0; i < h ; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < m; k++){
                cin >> map[i][j][k];
                if(map[i][j][k] == 1){
                    q.push(make_pair(i,make_pair(j,k)));
                    
                }
                
            }
        }
    }


    bfs();
    
    // for(int i = 0; i < h ; i++){
    //     for(int j = 0; j < n; j++){
    //         for(int k = 0; k < m; k++){
    //             cout << map[i][j][k];
    //         }
    //         cout << '\n';
    //     }
    //     cout << '\n';
    // }

    int result = 0;
    for(int i = 0; i < h ; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < m; k++){
                if(map[i][j][k] == 0){
                    cout << "-1" << '\n';
                    return 0;
                }
                result = max(result,map[i][j][k]);
            }
        }
    }

    cout << result-1 << '\n';
    
    return 0;
}


