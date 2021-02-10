//https://www.acmicpc.net/problem/2110
//https://m.blog.naver.com/PostView.nhn?blogId=vjhh0712v&logNo=221683269377&proxyReferer=https:%2F%2Fwww.google.com%2F 참고

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int c,n;

int calc_count(int mid, vector<int> &v){
    int std = v[0];
    int cnt = 1;

    for(int i=1; i<v.size(); i++){
        if(v[i]-std >= mid){
            cnt++;
            std = v[i];
        }
    }
    
    return cnt;
}


int main(void){

    //집의 개수, 공유기의 개수 
    cin >> n >> c;

    vector<int> house(n);

    for(int i=0; i<n; i++){
        //집의 좌표
        cin >> house[i];
    }

    // 좌표 순서대로 정렬
    sort(house.begin(), house.end());

    //간격을 BS
    //low 최소 간격 , high 최대 간격
    int start = 1;
    int end = house[n-1];
    int result = 0;


    while(start <= end) {

        int mid = (start+end)/2;
        //mid 간격일 때 공유기 cnt
        int cnt = calc_count(mid, house);

        if(cnt >= c){
            result = max(result, mid);
            start = mid +1;
        
        } else{
            end = mid - 1;
        }

    }

    cout << result << '\n';

    return 0;
}