//https://www.acmicpc.net/problem/1654

#include <iostream>
#include <algorithm>

using namespace std;


long long length[10001];

int main(void){

    int n, k;
    //K : 이미 가지고 있는 랜선의 개수
    //N : 필요한 랜선의 개수 (모두 같은 길이)
    cin >> k >> n;

    //가지고 있는 랜선의 길이
    for(int i=0; i < k; i++){        
        cin >> length[i]; 
    }

    sort(length, length+k);

    long long start = 1;
    long long end = length[k-1];
    long long result = 0;
    int cnt = 0;
    
    while(start <= end){
        long long mid = (start + end) / 2;
        cnt = 0;
        for(int i = 0; i < k; i++){
            cnt += length[i]/ mid; 
        }
        
        if(cnt >= n){
            if(result < mid){
                result = mid;
            }
            start = mid + 1;
        } else {
            end  = mid - 1;
        }
    }
    cout << result << '\n';

    return 0;
}

