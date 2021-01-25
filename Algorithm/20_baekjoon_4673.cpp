//https://www.acmicpc.net/problem/4673

#include <iostream>
#define MAX 10001

using namespace std;

int a[MAX];

int getNext(int x){
    
    int sum = x;
    int temp = x;
    //자리수 
    int cipher = 1;

    while(temp>=10){
        cipher++;
        temp /= 10;
    }

    for(int i=0; i<cipher; i++){
        sum += x %10;
        x /= 10;
    }

    return sum; 

}


int main(void){

    for(int i=1; i<MAX; i++){
        for(int j= getNext(i); j<MAX; j = getNext(j)){
            if(a[j] == 1) continue;
            else a[j] = 1;
        }
    }

    for(int i=1; i<MAX; i++){
        if(a[i] == 0) cout << i << '\n';
    }

    return 0;
}