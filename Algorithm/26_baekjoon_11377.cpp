//https://www.acmicpc.net/problem/11377

#include <iostream>
#include <vector>
#define MAX 1001

using namespace std;

vector<int> a[MAX];
int n,m,s;
//특정 정점을 처리했는지 여부
bool c[MAX];
//특정 정점을 선택하고 있는 노드의 정보
int d[MAX];


bool dfs(int x){
    
    for(int i=0; i<a[x].size(); i++){

        int t = a[x][i];
        if(c[t]) continue;
        c[t] = true;
        
        //비어있거나 점유 노드에 더 들어갈 공간이 있는 경우
        if(d[t] == 0 || dfs(d[t])){
            d[t] = x;
            
            return true;
        }
    }    
    
    return false;
}


int main(void){
    int k;
    //직원 수, 일의 개수, 2개의 일을 할 수 있는 직원 수
    scanf("%d %d %d",&n,&m,&k);

    for(int i=1; i<=n; i++){
        // 특정 직원이 할 수 있는 일의 개수
        scanf("%d", &s);

        for(int j=1; j<=s; j++){
            //특정 직원이 할 수 있는 일의 번호
            int t;
            scanf("%d", &t);
            a[i].push_back(t);
        }
    }

    int count = 0;
    for(int i=1; i<=n; i++){
        fill(c,c+MAX, false);
        if(dfs(i)) count++;
    }


    //2번 작업을 할 수 있는 사람
    int extra = 0;
    for(int i = 1; i <= n && extra <k; i++){
        fill(c,c+MAX, false);
        if(dfs(i)) extra++;
    }

    printf("%d\n",count+extra);

    return 0;

}