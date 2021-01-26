//https://www.acmicpc.net/problem/1946

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<pair<int, int>> score;

int main(void){
    int t;
    cin >> t;

    while(t--){
        score.clear();
        cin >> n;
        for(int i=0; i<n; i++){
            int a, b;
            cin >> a >> b;
            score.push_back(make_pair(a,b));
        }
        sort(score.begin(), score.end());

        int result = 0;
        int min = 100001;
        for(int i=0; i<n; i++){
            if(min > score[i].second){
                min = score[i].second;
                result++;
            }
             
        }
        cout << result <<'\n'; 
    }
       
    return 0;
}