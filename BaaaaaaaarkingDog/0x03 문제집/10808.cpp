#include <bits/stdc++.h>

using namespace std;

int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    //배열 지역변수로 선언하면 초기화를 따로 해야함
    //전역 변수로 선언하면 알아서 0으로 채워짐
    int arr[26];
    fill(arr, arr+26, 0);

    for(int i=0; i<s.length(); i++){
        int num = s[i] - 'a';
        arr[num]++;
    }

    for(int i=0; i<26; i++){
        cout << arr[i] << " ";
    }

    return 0;
}