#include <bits/stdc++.h>

using namespace std;

int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> v;
    vector<int> odd;

    int sum = 0;

    for(int i=0; i<7; i++){
        int temp;
        cin >> temp;
        v.push_back(temp);
        if(temp % 2 != 0){
            sum += temp;
            odd.push_back(temp);
        }
    }

    if(sum != 0){
        //홀 수 합
        cout << sum << "\n";
        //최솟값
        cout << *min_element(odd.begin(),odd.end()) << "\n";
    } else {
        cout << "-1";
    }


    return 0;
}