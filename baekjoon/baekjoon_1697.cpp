//https://www.acmicpc.net/problem/1697

#include <iostream>
#include <queue>
using namespace std;

int n, k, cnt;
int v[100001];
queue<int> q;
void check(int);

int bfs(int n, int k){
    
    q.push(n);
    v[n] = true;

    while(!q.empty()){
        int s = q.size();
        for(int i=0; i<s; i++){
            int cur = q.front();
            q.pop();
            if(cur == k){
                return cnt;
            }
            check(cur+1);
            check(cur-1);
            check(cur*2);
        }
        cnt++;
    }
    
}

void check(int x){
    if(0<= x && x <= 100000 && v[x] == false){
        v[x] = true;
        q.push(x);
    }
}


int main(void){

    cin >> n >> k;
       
    cout << bfs(n, k);
    return 0;

}