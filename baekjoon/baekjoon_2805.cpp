//https://www.acmicpc.net/problem/2805
//LowerBound(이진 탐색 변형) 사용

#include <iostream>
#include <algorithm>

using namespace std;

long long tree[1000001];

int main(void){
    long long n, m;

    //나무의 수, 필요한 나무 길이
    cin >> n >> m;

    //나무 높이
    for(int i=0; i<n; i++){
        cin >> tree[i];
    }

    sort(tree, tree+n);

    long long start = 0;
    long long end = tree[n-1];
    long long result = 0;
    long long sum = 0;
    
    while(start <= end){
        long long mid = (start + end)/2;
        sum =0;

        for(int i=0; i<n; i++){
            if(tree[i] > mid){
                sum += tree[i]-mid;
            } 
        }
        
        if(sum >= m){
            if(result < mid){
                result = mid;
            }
            start = mid +1;
        } else {
            end = mid - 1;
        }
    }

    cout << result << '\n';
    
    return 0;
}