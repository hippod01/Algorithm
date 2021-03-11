//https://www.acmicpc.net/problem/14499

#include <iostream>

using namespace std;

int N, M, x, y, k;
int map[20][20];
//int dice[4][3];
int dice[6] = {0,0,0,0,0,0};


//이동 명령 동쪽 1, 서쪽 2, 북쪽 3, 남쪽 4
int dx[] = {1, -1, 0, 0};
int dy[] = {0,  0,-1, 1};



void dice_move(int dm){

    int dice0 = dice[0]; int dice1 = dice[1]; int dice2 = dice[2];
    int dice3 = dice[3]; int dice4 = dice[4]; int dice5 = dice[5];
    
    if(dm == 0){
    //동
    dice[1] = dice5; dice[2] = dice1; dice[3] = dice2; dice[5] = dice3;
    } else if(dm == 1){
    //서
    dice[1] = dice2; dice[2] = dice3; dice[3] = dice5; dice[5] = dice1;
    } else if(dm == 2){
    //북
    dice[0] = dice2; dice[2] = dice4; dice[4] = dice5; dice[5] = dice0;
    } else if(dm == 3){
    //남
    dice[0] = dice5; dice[2] = dice0; dice[4] = dice2; dice[5] = dice4;
    }
    
    cout << dice[2] << '\n';
    // int copy_dice[4][3];
    // for(int i=0; i<4; i++){
    //     for(int j=0; j<3; j++){
            
    //         int ndy = i+dice_dy[dm];
    //         int ndx = j+dice_dx[dm];
            
    //         if(-1 == ndy) ndy = 3;
    //         else if (4 == ndy) ndy = 0;
            
    //         if(-1 == ndx) ndx = 2;
    //         else if (3 == ndx) ndx = 0;

    //         copy_dice[ndy][ndx] = dice[i][j];
    //     }
    // }

    // for(int i=0; i<4; i++){
    //     for(int j=0; j<3; j++){
    //         dice[i][j] = copy_dice[i][j];
    //     }
    // }
    
    // cout << dice[1][1] << '\n';
    
}


void move(int m){
    m = m-1;
    
    //이동한 위치
    int nx = x + dx[m];
    int ny = y + dy[m];
    
    if (0 <= ny && ny < N && 0 <= nx && nx < M){
        // cout << ny << " " << nx << '\n';    
        //주사위 굴리기
        dice_move(m);
        if(map[ny][nx] != 0){
            dice[5] = map[ny][nx];
            map[ny][nx] = 0;
        } else{
            map[ny][nx] = dice[5];
        }
        x = nx;
        y = ny;
        
    } 
    
}


int main(void){

    //지도 크기, 세로, 가로
    cin >> N >> M;
    //주사위를 놓은 곳의 좌표
    cin >>y >> x >> k;
    
    //지도 정보 입력
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            int temp;
            cin >> temp;
            map[i][j] = temp;
        }
    }

    //이동 명령 동쪽 1, 서쪽 2, 북쪽 3, 남쪽 4
    for(int i=0; i<k; i++){
        int temp;
        cin >> temp;
        move(temp);
        
    }

    return 0;
}