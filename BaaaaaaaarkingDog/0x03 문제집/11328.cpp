#include <bits/stdc++.h>

using namespace std;

int arr1[26];
int arr2[26];

int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc; 

    while(tc--){    
        fill(arr1, arr1+26, 0);
        fill(arr2, arr2+26, 0);

        string bs, as;
        cin >> bs >> as;

        for(auto s : bs){
            arr1[s-'a']++;
        }

        for(auto s : as){
            arr2[s-'a']++;
        }

        int result=0;

        for(int i=0; i<26; i++){
            if(arr1[i] != arr2[i]){
                result = 1;
            } 
        }

        if(result){
            cout << "Impossible" << "\n";
        } else {
            cout << "Possible" << "\n";
        }
            

    }
    

    return 0;
}