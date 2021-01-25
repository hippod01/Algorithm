//https://www.acmicpc.net/problem/1298

#include <vector>
#include <iostream>
#define MAX 5001

using namespace std;

vector<int> v[MAX];
int d[MAX];
bool c[MAX];

bool dfs(int x){
    for(int i =0; i<v[x].size(); i++){
        int t = v[x][i];
        if(c[t]) continue;
        c[t] = true;

        if(d[t] == 0 || dfs(d[t])){
            d[t] = x;
            return true;
        }
    }
    return false;
}

int main(void){

    //사람 수, 노트북 수
    int n,m;
    scanf("%d %d",&n,&m);

    for(int i=1 ;i<=m; i++){
        int a,b;
        scanf("%d %d",&a,&b);
        v[a].push_back(b);
    }

    int count = 0;
    for(int i=1; i<=n; i++){
        fill(c,c+MAX,false);
        if(dfs(i)) count++;
    }

    printf("%d",count);


}