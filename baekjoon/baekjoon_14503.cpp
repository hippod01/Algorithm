//https://www.acmicpc.net/problem/14503

#include <iostream>

using namespace std;

int n,m,r,c,d;
int cnt = 1;
int map[51][51];
//청소 여부
int v[51][51];
//북, 동, 남, 서
int dy[] = {-1, 0, 1, 0};
int dx[] = { 0, 1, 0,-1};   

int bdy[] = {1, 0, -1, 0};
int bdx[] = {0, -1, 0, 1};

void dfs(int y, int x, int d){

    //4방향 탐색
    for(int i=d-1; i>d-5; i--){
        int nk = (i+4)%4;
        int ny = y + dy[nk];
        int nx = x + dx[nk];
        if(0 <= ny && ny < n && 0 <= nx && nx < m){
            if(map[ny][nx] == 0 && v[ny][nx] == 0){
                v[ny][nx] = 1;
                cnt++;
                dfs(ny,nx,nk);
                return;
            }
        }
    }

    int by = y + bdy[d];
    int bx = x + bdx[d];
    
    if(map[by][bx] == 1) return;
    else dfs(by,bx,d);

}

int main(void){

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    //세로, 가로
    cin >> n >> m;
    //청소기 현재 좌표, 바라보는 방향
    //0 : 북, 1 : 동, 2 : 남, 3 : 서
    cin >> r >> c >> d;
    v[r][c] = 1;
    //0 빈칸, 1 벽
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int temp;
            cin >> temp;
            map[i][j] = temp;
        }
    }
    
    dfs(r,c,d);

    cout << cnt << '\n';

    return 0;
}

//시간 초과
// while(1){
        
    //     //0 : 북, 1 : 동, 2 : 남, 3 : 서
    //     int ny = r + dy[d];
    //     int nx = c + dx[d];
    //     if( 0<= ny && ny < n && 0<= nx && nx < m){
        
    //         if(v[ny][nx] == 0 && map[ny][nx] == 0){
    //             turn(d);
    //             v[ny][nx] = 1;
    //             cnt += 1;
    //             turn_time = 0;
    //             r = ny;
    //             c = nx;
    //             continue;
    //         } else{
    //             turn(d);
    //             turn_time += 1;
    //         }
    //     }

    //     if(turn_time == 4){
    //         int nd = d-1;
    //         if(nd == -1) d = 3;
            
    //         int ny = r + dy[nd];
    //         int nx = c + dx[nd];
            
    //         if(map[ny][nx] == 1){
    //             break;
    //         } else{
    //             r = ny;
    //             c = nx;
    //         }
    //     }

    // }


