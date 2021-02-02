//https://www.acmicpc.net/problem/11724

#include <iostream>
#include <vector>
using namespace std;

int n, m, cnt = 0;
vector<int> a[1001];
bool v[1001];

void dfs(int x){
    v[x] = true;    
    
    for(int i=0; i<a[x].size(); i++){
        int nx = a[x][i];
        if(!v[nx]){
            dfs(nx);
        }
       
    }
}

int main(void){
    cin >> n >> m;

    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }

   for(int i=1; i<=n; i++){
       if(!v[i]){
           dfs(i);
           cnt++;
       }
   }

    cout << cnt;
    



}