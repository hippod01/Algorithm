#include <bits/stdc++.h>

using namespace std;

int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> v;
    for(int i=0; i<9; i++){
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    //vector 가장 큰 수
    int maxNum = *max_element(v.begin(),v.end());
    cout << maxNum << "\n";
    //vecotor 가장 큰 수의 인덱스
    int maxNumIndex = max_element(v.begin(), v.end()) - v.begin();
    cout << maxNumIndex+1 << "\n";


    return 0;
}