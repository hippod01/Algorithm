#include <iostream>
#include <algorithm>

using namespace std;

int w[1001];
int target =1;

int main(void){

    //저울추의 개수
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> w[i];
    }

    sort(w,w+n);

    for(int i=0; i<n; i++){
        if(target <w[i]) break;
        target += w[i];
    }

    cout << target;

    return 0;
}