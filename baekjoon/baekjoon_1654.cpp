//https://www.acmicpc.net/problem/1654

#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
int length[10000];

int bs(){
    long long ret = 0, cnt = 0;
    long long left, right, mid;

    left = 1;
    right = INT_MAX;

    while(left<=right){
        mid = (right+left)/2;
        cnt = 0;
        for(int i=0; i<k; i++){
            cnt += length[i] / mid;
        }

        if(cnt <n){
            right = mid -1;
        } else {
            ret = mid;
            left = mid +1;
        }
    }
    return ret;
}


int main(void){

    //K : 이미 가지고 있는 랜선의 개수
    //N : 필요한 랜선의 개수 (모두 같은 길이)
    cin >> k >> n;

    int max = 0;
    for(int i=0; i<k; i++){
        //가지고 있는 랜선의 길이
        cin >> length[i]; 
        
    }

    cout << bs() << '\n';
    

    return 0;
}