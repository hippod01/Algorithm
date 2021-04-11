#include <bits/stdc++.h>

using namespace std;

int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> v;
    int cnt =0;
    int tc=3;

    while(tc--){
        v.clear();

        for(int i=0; i<4; i++){
            int temp;
            cin >> temp;
            v.push_back(temp);
            if(i==3){
                cnt = count(v.begin(), v.end(),0);
            }
        }

        if(cnt == 0) cout << "E" << "\n";
        else if(cnt == 1) cout << "A" << "\n";
        else if(cnt == 2) cout << "B" << "\n";
        else if(cnt == 3) cout << "C" << "\n";
        else cout << "D" << "\n";
    }


    return 0;
}