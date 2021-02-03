//https://www.acmicpc.net/problem/2583

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m,k,cnt = 0;
int map[101][101];
bool v[101][101];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
vector<int> result;

void dfs(int x, int y){
    v[x][y] = true;
    cnt++;
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(0 <= nx && nx < n && 0 <= ny && ny < m){
            if(map[nx][ny] == 0 && !v[nx][ny]){
                dfs(nx,ny);
            }
        }
    }
}

int main(void){

    cin >> m >> n >> k;

    for(int i=0; i<k; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        for(int j=a; j<c; j++){
            for(int k=b; k<d; k++){
                map[j][k] = 1;
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map[i][j] == 0 && !v[i][j]){
                cnt = 0;
                dfs(i,j);
                result.push_back(cnt);
            }
        }
    }
    sort(result.begin(),result.end());
    cout << result.size() << '\n';
    for(int i=0; i<result.size(); i++){
        cout << result[i] << ' '; 
    }

    return 0;
}
