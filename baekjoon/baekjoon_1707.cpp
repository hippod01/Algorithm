//https://www.acmicpc.net/problem/1707

#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int k, n, e;
vector<int> a[20001];
//0:방문X, 1:빨, 2:파
int v[20001];

void dfs(int start){
    if(!v[start]){
        v[start] = 1;
    }

    for(int i=0; i<a[start].size(); i++){
        int next = a[start][i];
        if(!v[next]){
            if(v[start] == 1){
                v[next] = 2;
            } else if(v[start] == 2){
                v[next] = 1;
            }
            dfs(next);
        }
    }
}

void bfs(int start){
    queue<int> q;
    int color = 1;
    q.push(start);
    v[start] = color;

    while(!q.empty()){
        int now = q.front();
        q.pop();

        if(v[now] == 1){
            color = 2;
        } else if(v[now] == 2){
            color = 1;
        }

        for(int i=0; i<a[now].size(); i++){
            int next = a[now][i];
            if(!v[next]){
                v[next] = color;
                q.push(next);
            }
        }
    }
}

bool bipartiteGraph(){
    for(int i=1; i<=n; i++){
        for(int j=0; j<a[i].size(); j++){
            int next = a[i][j];
            if(v[i] == v[next]){
                return 0;
            }
        }
    }
    return 1;
}

int main(void){

    cin >> k;

    while(k--){

        cin >> n >> e;

        for(int i=0; i<e; i++){
            int x, y;
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
        }

        for(int i=1; i<=n; i++){
            if(!v[i]){
                dfs(i);
                // bfs(i);
            }
        }

        if(bipartiteGraph()){
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }

        //초기화
        for (int i = 0; i <= n; i++) {
            a[i].clear();
        }
        memset(v,false,sizeof(v));

    }



    return 0;
}