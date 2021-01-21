//https://www.acmicpc.net/problem/1920

#include <iostream>
#include <algorithm>
#define NUMBER 100001

using namespace std;

int a[NUMBER];
int d[NUMBER];

int search(int start, int end, int target){
    if(start>end) return -1;
    int mid = (start+end)/2;
    if(a[mid] == target) return mid;
    else if(a[mid]>target) return search(start, mid-1, target);
    else return search(mid+1, end, target);
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
        int result =  search(0, n, d[i]);
        
        if(result != -1){
            cout << "1" << "\n";
        } else {
            cout << "0" << "\n";

        }
        
    }

    
    


}