//https://www.acmicpc.net/problem/2512

#include <iostream>
#include <algorithm>

using namespace std;

int n,m;


int main(void){

    //지방의 수
    cin >> n;

    //지방의 예산 요청 금액
    int budget[n];
    int sum;
    for(int i=0; i<n; i++){
        cin >> budget[i];
        sum += budget[i];
    }

    sort(budget, budget+n);

    //국가의 총 예산
    cin >> m; 

    // (국가의 예산 >= 지방의 예산 요청 금액 합) 일 때 예산 요청 금액 그대로 배정
    if(sum <= m){
        cout << budget[n-1] << '\n';

    } else{
        int start = 0;
        int end = budget[n-1];
        int result = 0;
        
        while(start <= end){
            //상한액을 BS
            int mid = (start + end) / 2;
            int sum = 0;

            for(int i = 0; i < n; i++){
                if(budget[i] > mid){
                    sum += mid;
                } else {
                    sum += budget[i];
                }
            }
            
            if (sum <= m){
                start = mid + 1;
                if(result < mid){
                    result = mid;
                }
            } else{
                end = mid - 1;
            }

        }
         cout << result << '\n';
    
    }


    return 0;
}