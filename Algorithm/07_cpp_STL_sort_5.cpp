// 변수가 3개일 때 두 개의 변수를 기준으로 정렬하는 방법
// 성적이 동일한 경우 나이가 더 어린 학생이 우선순위가 높게 정렬

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


bool compare(pair<string, pair<int,int>> a,
            pair<string, pair<int,int>> b){
    if(a.second.first == b.second.first){
        return a.second.second > b.second.second;
    } else{
        return a.second.first > b.second.first;
    }

}

int main(void){

    vector<pair<string, pair<int,int>>> v;
    v.push_back(pair<string, pair<int,int>>("나동빈",make_pair(90,19961222)));
    v.push_back(pair<string, pair<int,int>>("이태일",make_pair(97,19930518)));
    v.push_back(pair<string, pair<int,int>>("박한울",make_pair(95,19930203)));
    v.push_back(pair<string, pair<int,int>>("이상욱",make_pair(90,19921207)));
    v.push_back(pair<string, pair<int,int>>("강종구",make_pair(88,19900302)));

    sort(v.begin(), v.end(), compare);
    for(int i=0; i<v.size(); i++){
        cout << v[i].first << " ";
    }

    return 0;
}