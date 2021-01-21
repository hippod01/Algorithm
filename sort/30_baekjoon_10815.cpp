//https://www.acmicpc.net/problem/10815

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 500001;
const int M = 10000001;

int a[N];
int d[M];

int search(int start, int end, int target){
    if(start>end) return -1;
    int mid = (start+end)/2;
    if(a[mid]==target) return mid;
    else if(a[mid]>target) return search(start, mid-1, target);
    else return search(mid+1,end ,  target);
}

int main(void){
    int n,m;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    
    cin >> m;
    for(int i=0; i<m; i++){
        cin >> d[i];
    }

    sort(a,a+n);
    
    for(int i=0; i<m; i++){
        int result = search(0,n-1,d[i]);
        if(result == -1){
            cout << "0 ";
        } else {
            cout << "1 ";
        }
    }

}