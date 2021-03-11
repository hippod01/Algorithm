//https://www.onlinegdb.com/online_c++_compiler

#include <iostream>

using namespace std;

int n, m, x, y, d;
//방문 여부 저장
int v[50][50];
// 맵 정보
int arr[50][50];

int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};


void turn_left(){
    d = d-1;
    if(d == -1) d = 3;
}

int main(void){

    // 맵의 세로 크기, 가로 크기
    cin >> n >> m;
    // 게임 캐릭터가 있는 칸의 좌표(a,b) 바라보는 방향 d (0:북, 1:동, 2:남, 3:서)    
    cin >> y >> x >> d;

    // 맵 ( 육지:0, 바다:1 )
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int temp;
            cin >> temp;
            arr[i][j] = temp;
        }
    }
    v[y][x] = 1;
    
    int cnt = 1;
    int turn_time = 0;

    
    while(1){
        //방향 반시계 방향으로 회전
        //(0:북, 1:동, 2:남, 3:서)
        turn_left();
        int nx = x + dx[d]; 
        int ny = y + dy[d];
        // printf("ny : %d, nx : %d, d : %d, cnt : %d, turn_time : %d\n", ny, nx, d, cnt, turn_time);
        // 왼쪽으로 방향을 틀어 직진하였을 때 방문하지 않은 육지의 칸이 있다면
        if(v[ny][nx] == 0 && arr[ny][nx] == 0){
            v[ny][nx] = 1;
            x = nx;
            y = ny;
            cnt += 1;
            turn_time = 0;
            continue;
        // 방문하지 않은 칸이 없거나, 바다인 경우
        } else turn_time += 1;
        

        //네 방향 모두 갈 수 없는 경우
        if(turn_time == 4){
            //바라보는 방향을 유지한 채로 한 칸 뒤로 간다.
            ny = y - dy[d];
            nx = x - dx[d];
            //한 칸 뒤로 간 곳이 바다 인 경우 움직임을 멈춘다.
            if(arr[ny][nx] == 1){
                  break;
            } else {
                x = nx;
                y = ny;  
            }
            turn_time = 0;            
        }

    }
    cout << cnt << '\n';
    return 0;
}
