//https://www.acmicpc.net/problem/10816
// lower bound, upper bound 사용해야 함
// lower bound: 찾고자 하는 값 이상이 처음 나타나는 위치
// upper bound: 찾고자 하는 값보다 큰 값이 처음으로 나오는 위치
//upper bound - lower bound 같은 숫자 개수


#include <iostream>
#include <algorithm>
#define NUMBER 10000001
using namespace std;

int n,m;
int a[NUMBER];
int d[NUMBER];
int result[NUMBER];

int LB(int arr[], int target, int size){
    int mid, start, end;
    start = 0; 
    end = size -1;

    while(end > start){
        mid = (start+end)/2;
        if(arr[mid] >= target){
            end = mid;
        } else start = mid+1;
    }
    return end;
}

int UB(int arr[], int target, int size){
    int mid, start, end;
    start = 0; 
    end = size -1;

    while(end > start){
        mid = (start+end)/2;
        if(arr[mid] > target){
            end = mid;
        } else start = mid+1;
    }
    return end;
}

int main(void){

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
        int lower = LB(a,d[i],n);
        int upper = UB(a,d[i],n);
        if(upper == n-1 && a[n-1] == d[i]){
            upper++;
        }
        result[i] = upper-lower;
    }
    
   
    for(int i=0; i<m; i++){
        cout << result[i] << ' ';
    }

    return 0;
    
}