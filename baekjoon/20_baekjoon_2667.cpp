//https://www.acmicpc.net/problem/2667

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, cnt;
int map[26][26];
bool v[26][26];
int dx[4] = { 0, 1, 0, -1};
int dy[4] = { -1, 0, 1, 0};
vector <int> ans;

void dfs(int x, int y){
    v[x][y] = true;
    cnt++;
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        // 단지 범위 안일 때
        if(0 <= nx && nx < n && 0 <= ny && ny < n){
            //방문 할 수 있는 집이고, 방문하지 않은 집
            if(map[nx][ny] == 1 && v[nx][ny] == false)
                dfs(nx, ny);
        }
    }

}

int main(void){
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%1d",&map[i][j]);
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(v[i][j] == false && map[i][j] == 1){
                //0.0부터 방문하지 않은 단지 탐색
                cnt = 0;
                dfs(i,j);
                ans.push_back(cnt);
                
            }
        }

    }

    //단지 수
    cout << ans.size() << '\n';
    //단지 내 집의 수 오름차순 정렬 한 줄씩 출력
    sort(ans.begin(), ans.end());
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << '\n';
    }
    return 0;

}