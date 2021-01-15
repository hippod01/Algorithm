//https://www.acmicpc.net/problem/1671

#include <iostream>
#include <vector>
#define MAX 51

using namespace std;

vector<int> a[MAX];
int shark[MAX][3];
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
    int n;
    //상어 수
    scanf("%d",&n);

    //상어 능력
    for(int i=1; i<=n; i++){
        scanf("%d %d %d", &shark[i][0], &shark[i][1], &shark[i][2]);
    }

    //특정 상어가 다른 상어를 먹을 수 있는 경우
    
        for(int i=1; i<=n-1; i++){
            for(int j=1+i; j<=n; j++){
                if(shark[i][0]==shark[j][0] && shark[i][1]==shark[j][1] && shark[i][2]==shark[j][2]){
                    a[i].push_back(j);
                } else if(shark[i][0]>=shark[j][0] && shark[i][1]>=shark[j][1] && shark[i][2]>=shark[j][2]){
                    a[i].push_back(j);     
                } else if(shark[i][0]<=shark[j][0] && shark[i][1]<=shark[j][1] && shark[i][2]<=shark[j][2]){
                    a[j].push_back(i);
                }

            }
        
        }
    
    

    int count = 0;
    for(int k=0; k<2; k++){
        for(int i=1; i<=n; i++){
            fill(c,c+MAX, false);
            if(dfs(i)) count++;
        }
    }   
    //count는 상어를 잡아 먹은 수
    //n-count : 살아남은 상어 수
    printf("%d",n-count);

    return 0;

}