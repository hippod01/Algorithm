// 백준 문제 https://www.acmicpc.net/problem/1181

#include <iostream>
#include <algorithm>

using namespace std;

string a[20000];
int n;

bool compare(string a, string b){
    if(a.length() < b.length()){
        return 1;

    } else if(a.length() > b.length()){
        return 0;

     //길이가 같으면 사전순으로 정렬   
    } else{
        return a < b;
    }
}


int main(void){

    //입력
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }

    //정렬
    sort(a, a+n, compare);

    //출력
    for(int i =0; i<n; i++){
        // 동일한 단어는 패스하고 출력
        if(i>0 && a[i] == a[i-1]) 
            continue;
        cout << a[i] << '\n';
    }
    return 0;
}