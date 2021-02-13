//https://www.acmicpc.net/problem/1764

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n,m;
vector<string> a;
vector<string> b;
vector<string> result;

void bs(int start, int end, string target){
    if(start>end) return ;

    int mid = (start+end)/2;

    if(a[mid] == target) {
       result.push_back(target);
       
    }    
    else if(a[mid] > target) return bs(start, mid-1, target);
    else return bs(mid+1, end, target);
}

int main(void){

    cin >> n >> m;

    for(int i=0; i<n; i++){
        string name;
        cin >> name;
        a.push_back(name);
    }

    sort(a.begin(), a.end());

    for(int i=0; i<m; i++){
        string name;
        cin >> name;
        b.push_back(name);
        bs(0, n, b[i]);
    }

    sort(result.begin(),result.end());

    cout << result.size() << '\n';
    for(int i=0; i<result.size(); i++){
        cout << result[i] << '\n';
    }

    return 0;
}