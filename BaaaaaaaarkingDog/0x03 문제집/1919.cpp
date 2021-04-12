#include <bits/stdc++.h>

using namespace std;

int arr1[26];
int arr2[26];

int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);

    string s1, s2;
    cin >> s1 >> s2;

    for(auto t : s1){
        arr1[t-'a']++;
    }

    for(auto t : s2){
        arr2[t-'a']++;
    }
    
    int cnt = 0;
    for(int i=0; i<26; i++){
        if(arr1[i] != arr2[i]){
            //*
            cnt += abs(arr1[i] - arr2[i]);
        }
    }

    cout << cnt << "\n";

    return 0;
}