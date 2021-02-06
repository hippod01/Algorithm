//https://www.acmicpc.net/problem/7562

// #include <iostream>
// #include <queue>
// #include <cstring>
// #include <vector>
// using namespace std;

// int l;
// bool v[301][301];

// int dx[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
// int dy[] = { -2, -1, 1, 2, 2, 1, -1, -2 };

// pair <int, int> start, destination;
// vector<int> result;

// void bfs(int y, int x){

//     queue< pair< pair<int, int>, int> > q;
//     q.push(make_pair(make_pair(y,x), 0));
//     v[y][x] = true;
    
//     while(!q.empty()){
//         int y = q.front().first.first;
//         int x = q.front().first.second;
//         int cnt = q.front().second;
//         q.pop();
        
//         if(y == destination.first && x == destination.second){
//             result.push_back(cnt);
//         //    cout << cnt << '\n';
//            return;
//         }

//         for(int i=0; i<8; i++){
//             int nx = x + dx[i];
//             int ny = y + dy[i];

//             if(0 <= nx && nx < l && 0 <ny && ny < l){
//                 if(!v[ny][nx]){
//                     v[ny][nx] = true;
//                     q.push(make_pair(make_pair(ny,nx),cnt+1));
//                 }    
//             }
//         }


//     }
    
// }

// int main(void){

//     int t;
//     cin >> t;

//     while(t--){
//         memset(v,false,sizeof(v));
        
//         cin >> l;
//         //현재 있는 칸
//         cin >> start.first >> start.second;
//         // 이동하려고 하는 칸
//         cin >> destination.first >> destination.second;

//         bfs(start.first, start.second);
//     }

//     for(int i=0; i < result.size(); i++){
//         cout << result[i] << '\n';
//     }

//     return 0;
// }


#include<iostream>
#include<cstring>
#include<queue>
 
#define endl "\n"
#define MAX 300
using namespace std;
 
int l;
bool Visit[MAX][MAX];
 
int dx[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int dy[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
 
pair<int, int> Start, End;
 
void Initialize()
{
    memset(Visit, false, sizeof(Visit));
}
 
void Input()
{
    cin >> l;
    cin >> Start.first >> Start.second;
    cin >> End.first >> End.second;
}
 
void BFS(int a, int b)
{
    queue<pair<pair<int, int>, int > > Q;
    Q.push(make_pair(make_pair(a, b), 0));
    Visit[a][b] = true;
 
    while (Q.empty() == 0)
    {
        int x = Q.front().first.first;
        int y = Q.front().first.second;
        int Cnt = Q.front().second;
        Q.pop();
 
        if (x == End.first && y == End.second)
        {
            cout << Cnt << endl;
            return;
        }
 
        for (int i = 0; i < 8; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx >= 0 && ny >= 0 && nx < l && ny < l)
            {
                if (Visit[nx][ny] == false)
                {
                    Visit[nx][ny] = true;
                    Q.push(make_pair(make_pair(nx, ny), Cnt + 1));
                }
            }
        }
    }
}
 
void Solution()
{
    BFS(Start.first, Start.second);
}
 
void Solve()
{
    int Tc;
    cin >> Tc;
    for (int T = 1; T <= Tc; T++)
    {
        Initialize();
        Input();
        Solution();
    }
}
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    //freopen("Input.txt", "r", stdin);
    Solve();
 
    return 0;
}


