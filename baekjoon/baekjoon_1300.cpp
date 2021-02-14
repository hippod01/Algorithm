//https://www.acmicpc.net/problem/1300

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main(void){
    int n, k;
    cin >> n >> k;

    int start = 1;
    int end = k;
    int result = 0;

    while(start <= end){
        int mid = (start + end) / 2;
        int cnt = 0;

        for(int i=1; i<=n; i++){
            cnt += min(mid/i, n);        
        }

        if(cnt < k){
            start = mid + 1; 
        } else {
            end = mid - 1;
            result = mid;
        }
    }

    cout << result << '\n';

    
    


    return 0;
}