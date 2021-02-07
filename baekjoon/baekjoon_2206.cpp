//https://www.acmicpc.net/problem/2206

#include <iostream>
#include <queue>

using namespace std;

int n, m;
int map[1001][1001];
bool v[1001][1001][2];
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};


int bfs(){
    //(x,y),(벽 뚫기 여부,이동거리)
    queue <pair < pair<int,int>, pair<int,int> > > q;
    q.push(make_pair(make_pair(0,0), make_pair(0,1)));

    while(!q.empty()){

        int y = q.front().first.first;
        int x = q.front().first.second;
        int block = q.front().second.first;
        int cnt = q.front().second.second;
        q.pop();
        
        //목적지 도착
        if(y == n-1 && x == m-1){
            return cnt;
        }

        for(int i=0; i<4; i++){

            int nx = x + dx[i];
            int ny = y + dy[i];

            if( 0 <= ny && ny < n && 0 <= nx && nx < m){
                
                //벽이 있고(1), 벽 부술 기회가 있다면
                if(map[ny][nx] == 1 && block == 0){
                    v[ny][nx][block+1] = true;
                    q.push(make_pair(make_pair(ny,nx),make_pair(block+1,cnt+1)));
                    
                }
                //벽이 없고(0)방문하지 않은 곳
                //그냥 if 쓰니까 계속 틀림..ㅠ 앞에 계속 틀린 것도 체크해보기
                else if(map[ny][nx] == 0 && v[ny][nx][block] == false){
                    // printf("%d %d %d\n", ny, nx, block);
                    v[ny][nx][block] = true;
                    q.push(make_pair(make_pair(ny,nx), make_pair(block,cnt+1)));
                    
                }
            }
        }
    }

    return -1;


}

int main(void){

    cin >> n >> m;

    //cin %1d 로 받기
    for (int i = 0; i < n; i++){
        string Inp;
        cin >> Inp;
        for (int j = 0; j < m; j++){
            int Tmp = Inp[j] - '0';
            map[i][j] = Tmp;
        }
    }

    int result = bfs();
    cout << result << '\n';

    return 0;
}