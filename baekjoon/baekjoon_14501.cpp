//https://www.acmicpc.net/problem/14501

#include <iostream>
#include <algorithm>
using namespace std;

int main(void){

    //남은 N일
    int n, ans = 0;;
    cin >> n; 

    //걸리는 시간, 금액 저장
    int t[17], p[17], dp[17];

    for(int i = 1; i <= n; i++){
        cin >> t[i] >> p[i];
        dp[i] = p[i];
    }

    for(int i=2; i<=n; i++){
        for(int j=1; j<i; j++){
            if(i-j >= t[j]){
                dp[i] = max(p[i]+dp[j], dp[i]);
            }
        }
    }

    for(int i=1; i<=n; i++){
        if(i + t[i] <= n + 1){
            if(ans < dp[i]) ans = dp[i];
        }
    }

    cout << ans << '\n';

    return 0;
}