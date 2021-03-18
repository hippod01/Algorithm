//https://www.acmicpc.net/problem/12015
//dp로 풀었던 문제 이분탐색으로도 풀기
//이분탐색, lower bound

#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

int search(int start, int end, int t){
    int ans = 0;
    while(start <= end){
        int mid = (start+end)/2;
        if(v[mid] >= t){
            ans = mid;
            end = mid -1;
        } else {
            start = mid+1;
        }
    }
    return ans;
}

int main(void){

    int cnt = 0;
    int n;
    cin >> n;

    v.push_back(0);
    
    //lower bound 이용

    // for(int i=0; i<n; i++){
    //     int temp;
    //     cin >> temp;
    //     if(temp > v.back()){
    //         v.push_back(temp);
    //         cnt++;
    //     } else {
    //         //lower bound를 찾아 그 위치에 temp값을 넣음
    //         vector<int>::iterator low = lower_bound(v.begin(), v.end(), temp);
    //         *low = temp;
    //     }
        
    // }
    //cout << cnt <<'\n';

    //일반 이분 탐색
    for(int i=0; i<n; i++)
    {
        int temp;
        cin >> temp;
        if(v.back() < temp){
            v.push_back(temp);
        } else {
            int idx = search(0,v.size(),temp);
            v[idx] = temp;

        }

    }
    cout << v.size()-1 << '\n';
    

    return 0;
}