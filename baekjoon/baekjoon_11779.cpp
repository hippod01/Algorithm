//https://www.acmicpc.net/problem/11779

#include <iostream>
#include <queue>
#include <vector>
#define INF 987654321

using namespace std;

int n, m, start, End;
int d[1001];
int Route[1001];
vector<pair<int,int> > v[1001];

void dijkstra(){

    priority_queue< pair <int, int> > pq;
    pq.push(make_pair(0,start));
    d[start] = 0;

    while(!pq.empty()){

        int cur = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();

        //printf("cur : %d, cost : %d\n",cur, cost);

        for(int i = 0; i < v[cur].size(); i++){

            int next = v[cur][i].first;
            int nextCost = v[cur][i].second + cost;
           
            if(d[next] > nextCost){

                Route[next] = cur;
                d[next] = nextCost;
                pq.push(make_pair(-nextCost, next));   
                //printf("next : %d, nextCost : %d, d[%d] : %d\n",next, nextCost,next, d[next]);
            }
        }
    }
    
}

int main(void){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a,b,c;
        cin >> a >> b >> c;
        v[a].push_back(make_pair(b,c));
    }
    cin >> start >> End;

    for(int i = 1; i <= n; i++){
        d[i] = INF;
    }

    dijkstra();

    vector<int> wayback;

    cout << d[End] << '\n';

    int temp = End;
    while(temp){
        wayback.push_back(temp);
        temp = Route[temp];
    }
    
    cout << wayback.size() << '\n';
    for(int i= wayback.size()-1; i >= 0; i--){
        //" "를  ' '로 해서 계속 틀렸었다......
        cout << wayback[i] << " ";
    }


    return 0;
}