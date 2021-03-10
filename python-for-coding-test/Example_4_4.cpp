#include <iostream>

using namespace std;

int N, M, x, y, d;
bool v[51][51];
int map[51][51];
int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};


void turn_left(){
    d = d-1;
    if(d == -1) d = 3;
}

int main(void){

    // 맵의 세로 그기, 가로 크기
    cin >> N >> M;

    // 게임 캐릭터가 있는 칸의 좌표(a,b) 바라보는 방향 d (0:북, 1:동, 2:남, 3:서)    
    cin >> y >> x >> d;

    // 맵 ( 육지:0, 바다:1 )
    for(int i = 0; i < N; i++){
        for(int j = 0; i < M; i++){
            int x;
            cin >> x;
            map[i][j] == x;
        }
    }
    v[y][x] = true;
    
    int cnt = 1;
    int turn_time = 0;
    
    //(0:북, 1:동, 2:남, 3:서)
    while(1){
        //방향 반시계 방향으로 회전
        turn_left();
        int nx = x + dx[d]; 
        int ny = y + dy[d];

        // 왼쪽으로 방향을 틀어 직진하였을 때 방문하지 않은 육지의 칸이 있다면
        if(v[ny][nx] == false && map[ny][nx] == 0){
            v[ny][nx] = true;
            x = nx;
            y = ny;
            cnt += 1;
            turn_time = 0;
            continue;
        // 방문하지 않은 칸이 없거나, 바다인 경우
        } else {
            turn_time += 1;
        }
        //네 방향 모두 갈 수 없는 경우
        if(turn_time == 4){
            //바라보는 방향을 유지한 채로 한 칸 뒤로 간다.
            ny = y - dy[d];
            nx = x - dx[d];
            //한 칸 뒤로 간 곳이 바다 인 경우 움직임을 멈춘다.
            if(map[ny][nx] == 0){
                x = nx;
                y = ny;    
            } else break;
            turn_time = 0;
            
        }
    }

    cout << cnt << '\n';

    return 0;
}

// #include <bits/stdc++.h>

// using namespace std;

// int n, m, x, y, direction;
// // 방문한 위치를 저장하기 위한 맵을 생성하여 0으로 초기화
// int d[50][50];
// // 전체 맵 정보
// int arr[50][50];

// // 북, 동, 남, 서 방향 정의
// int dx[] = {-1, 0, 1, 0};
// int dy[] = {0, 1, 0, -1};

// // 왼쪽으로 회전
// void turn_left() {
//     direction -= 1;
//     if (direction == -1) direction = 3;
// }

// int main(void) {
//     // N, M을 공백을 기준으로 구분하여 입력받기
//     cin >> n >> m;
//     // 현재 캐릭터의 X 좌표, Y 좌표, 방향을 입력받기
//     cin >> x >> y >> direction;
//     d[x][y] = 1; // 현재 좌표 방문 처리

//     // 전체 맵 정보를 입력 받기
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             int x;
//             cin >> x;
//             arr[i][j] = x;
//         }
//     }

//     // 시뮬레이션 시작
//     int cnt = 1;
//     int turn_time = 0;
//     while (true) {
//         // 왼쪽으로 회전
//         turn_left();
//         int nx = x + dx[direction];
//         int ny = y + dy[direction];
//         // 회전한 이후 정면에 가보지 않은 칸이 존재하는 경우 이동
//         if (d[nx][ny] == 0 && arr[nx][ny] == 0) {
//             d[nx][ny] = 1;
//             x = nx;
//             y = ny;
//             cnt += 1;
//             turn_time = 0;
//             continue;
//         }
//         // 회전한 이후 정면에 가보지 않은 칸이 없거나 바다인 경우
//         else turn_time += 1;
//         // 네 방향 모두 갈 수 없는 경우
//         if (turn_time == 4) {
//             nx = x - dx[direction];
//             ny = y - dy[direction];
//             // 뒤로 갈 수 있다면 이동하기
//             if (arr[nx][ny] == 0) {
//                 x = nx;
//                 y = ny;
//             }
//             // 뒤가 바다로 막혀있는 경우
//             else break;
//             turn_time = 0;
//         }
//     }

//     cout << cnt << '\n';
// }