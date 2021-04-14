//stl 사용
#include <bits/stdc++.h>

using namespace std;

int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    list<char> L;
    for(int i=0; i<s.length(); i++){
        L.push_back(s[i]);
    }

    // 명령 수행 전 커서는 문장의 맨 뒤에 위치
    auto t = L.end();

    //명령 수행
    int m;
    cin >> m;
    for(int i=0; i<m; i++){
        char c;
        cin >> c;

        if(c == 'L'){
            if(t != L.begin()){
                t--;
            }
        } else if (c == 'D'){
            if(t != L.end()){
                t++;
            }
        } else if( c == 'B'){
            if(t != L.begin()){
                t--;
                t = L.erase(t);
            }
        } else if( c == 'P'){
            char in;
            cin >> in;
            L.insert(t, in);
        }
    }

    for(auto a : L){
        cout << a; 
    }
    


    return 0;
}