//https://www.acmicpc.net/problem/1260

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define NUMBER 1001
using namespace std;

bool c[NUMBER];
vector<int> a[NUMBER];

void bfs(int x){
    
    queue<int> q;
    q.push(x);
    c[x] = true;

    while(!q.empty()){
        int x = q.front();
        sort(a[x].begin(),a[x].end());
        q.pop();
        cout << x << ' ';
        for(int i=0; i<a[x].size(); i++){
            int y = a[x][i];
            if(!c[y]){
                q.push(y);
                c[y] = true;
            }
        }
    }


}

void dfs(int x){
    if(c[x]) return;
    c[x] = true;
    cout << x << ' ';
    for(int i=0; i<a[x].size(); i++){
        sort(a[x].begin(),a[x].end());
        int y = a[x][i];
        dfs(y);
    }
}

int main(void){

    int n, m, v;
    cin >> n >> m >> v;

    for(int i=1; i<=m; i++){
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    
    dfs(v);
    cout << '\n';
    fill_n(c,NUMBER, false);
    bfs(v);

}