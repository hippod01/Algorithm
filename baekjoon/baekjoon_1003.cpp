#include <iostream>

using namespace std;

int d[41];

int dp(int x){
    
    //    피보나치 값         0의개수    1의 개수
    //   ---------------------------------
    //0   0                 1        0
    //1   1                 0        1
    //2   1                 1        1
    //3   2                 1        2
    //n   dp(n-1)+dp(n-2)   dp(n-1)  dp(n)

    if(x <= 0){
        d[0] = 0;
        return 0;
    } else if(x == 1){
        d[1] = 1;
        return 1;
    } 

    if(d[x] != 0){
        return d[x];
    }else{
        return d[x] = dp(x-1) + dp(x-2);
    }

}

int main(void){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;

    while(tc--){

        int n;
        cin >> n;

        if(n == 0){
            printf("1 0\n");
        } else if(n == 1){
            printf("0 1\n");
        } else{
            dp(n);
            printf("%d %d\n", dp(n-1), dp(n));
        }
        
    }
    return 0;
}