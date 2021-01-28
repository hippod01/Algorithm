//https://www.acmicpc.net/problem/11502

#include <iostream>
#define MAX 1001

using namespace std;

int a[MAX];

int main(void){

    a[1] = 1;
    for(int i=2; i<MAX; i++){
        if(a[i] == 1) continue;
        for(int j = i*2; j<MAX; j+=i){
            a[j] = 1;
        }
    }

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        bool chk = false;
        for(int i=2; i<=n; i++){
            if(a[i] == 1) continue;
            for(int j=2; j<=n; j++){
                if(a[j] == 1) continue;
                for(int k = 2; k<=n; k++){
                    if(a[k] == 1) continue;

                    if(n == (i+j+k)){
                        printf("%d %d %d\n",i,j,k);
                        chk = true;
                        break;
                    }
                }
                if(chk) break;
            }
            if(chk) break;
        }

    }

} 