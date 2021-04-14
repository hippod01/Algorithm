//stl 사용
#include <bits/stdc++.h>

using namespace std;

int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;
    

    while(tc--){
        string inpw;
        cin >> inpw;

        list<char> L;
        auto t = L.begin();
        
        for(auto s : inpw){
            if(s == '<'){
                if(t != L.begin()){
                    t--;
                }
            } else if(s == '>'){
                if(t != L.end()){
                    t++;
                }
            } else if(s == '-'){
                if(t != L.begin()){
                    t--;
                    t = L.erase(t);
                }
            } else {
                L.insert(t, s);
            }
        }

        for(auto s : L){
            cout << s;
        }

        cout <<"\n";
    }
    
    


    return 0;
}