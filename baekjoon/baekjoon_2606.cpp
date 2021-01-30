//https://www.acmicpc.net/problem/2606
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> a[101];
int v[101];
int n,m,cnt;

void bfs(int x){
    queue<int> q;
    cnt = 0;

    q.push(x);
    v[x] = true;

    while(!q.empty()){
        int x = q.front();
        q.pop();

        for(int i=0; i<a[x].size(); i++){
            int y = a[x][i];
            if(!v[y]){
                q.push(y);
                v[y] = true;
                cnt++;
            }
        }


    }
}

int main(void){
    cin >> n;
    cin >> m;

    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y; 
        a[x].push_back(y);
        a[y].push_back(x);
    }

    bfs(1);
    cout << cnt;



    return 0;
}

