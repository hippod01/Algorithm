//https://www.acmicpc.net/problem/1149

// #include <iostream>

// using namespace std;

// int main(void){

//     ios::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);

//     int n;
//     int price[1001][3];
//     int dp[1001][3];

//     cin >> n;

//     for(int i=0; i<n; i++){
//         for(int j=0; j<3; i++){
//             //i번째 집, 0빨강, 1초록, 2파랑으로 칠하는 비용
//             cin >> price[i][j];
//         }
//     }

//     dp[0][0] = price[0][0];
//     dp[0][1] = price[0][1];
//     dp[0][2] = price[0][2];

//     for(int i=1; i<n; i++){
//         dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + price[i][0];
//         dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + price[i][1];
//         dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + price[i][2];
//     }

//     int MAX = __INT_MAX__;

//     for(int i=0; i<3; i++){
//         if(dp[n-1][i] < MAX){
//             MAX = dp[n-1][i];
//         }
//     }
    
//     cout << MAX << '\n';


//     return 0;
// }

#include <iostream>
//#include <cstdio>
#include <algorithm>
using namespace std;

 
int DP[1001][3]; //0 R, 1 G, 2 B
int cost[1001][3];  //n번째 집을 m 색깔로 칠했을 때의 min cost


int main() {

    int n;
    //scanf("%d", &n);
    cin >> n;

    for (int i = 1; i <= n; ++i){
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
        //scanf("%d %d %d", &cost[i][0], &cost[i][1], &cost[i][2]);
    } 

    for (int i = 1; i <= n; ++i) {
        DP[i][0] = min(DP[i - 1][1], DP[i - 1][2]) + cost[i][0];
        DP[i][1] = min(DP[i - 1][0], DP[i - 1][2]) + cost[i][1];
        DP[i][2] = min(DP[i - 1][0], DP[i - 1][1]) + cost[i][2];
    }

    //printf("%d\n", min(min(DP[n][0], DP[n][1]), DP[n][2]));
    cout << min(min(DP[n][0], DP[n][1]), DP[n][2]) << '\n';

    return 0;

}
