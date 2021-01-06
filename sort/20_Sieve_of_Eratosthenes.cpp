//에라토스테네스의 체 : 소수를 판별하는 알고리즘
#include <stdio.h>

//소수 판별 함수 : O(N)

// bool isPrimeNumber(int x){
//     for(int i = 2; i<x; i++){
//         //약수 존재하면
//         if(x%i == 0) return false;
//     }
//     return true;
// }


//O(n/2)
//약수는 대칭이라 제곱근까지만 구해도 되므로
// #include <math.h>
// bool isPrimeNumber(int x){
//     int end = (int) sqrt(x);
//     for(int i=2 ; i <=end; i++){
//         if( x %2 == 0) return false;
        
//     }
//     return true;
// }

// int main(void){
//     printf("%d", isPrimeNumber(97));
// }

//에라토스테네스의 체 : 대량의 소수를 한꺼번에 판별하고자 할 때 사용
// ① 이차원 배열을 생성하여 값을 초기화합니다.
// ② 2부터 시작해서 특정 숫자의 배수에 해당하는 숫자들을 모두 지웁니다.
// ③ 이미 지워진 숫자의 경우 건너뜁니다.
// ④ 2부터 시작하여 남아있는 숫자들을 출력합니다.

int number = 100000;
int a[100001];

void primeNumberSieve(){
    //1
    for(int i = 2; i <=number; i++){
        a[i]=i;
    }
    //2, 3
    for(int i=2; i<=number; i++){
        if(a[i] == 0) continue;
        for(int j= i+i; j<=number; j+=i){
            a[j] = 0;
        }
    }
    //4
    for(int i=2; i<=number; i++){
        if(a[i] != 0){
            printf("%d ",a[i]);
        }
    }

}

int main(void){
    primeNumberSieve();
}




