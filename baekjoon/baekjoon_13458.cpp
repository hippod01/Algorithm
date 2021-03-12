//https://www.acmicpc.net/problem/13458

#include <iostream>
using namespace std;

int n,b,c;
long long result;

int main(void){

    //시험장 수
    cin >> n;

    int a[n];
    //각 시험장에 있는 응시자 수
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    //총감독관, 부감독관이 감시할 수 있는 응시자 수
    cin >> b >> c;

    for(int i=0; i<n; i++){
        int an = a[i];
        
        //총감독관
        an = an - b;
        result += 1;

        //부감독관 
        if(an > 0){
            if(an%c != 0){
                an = (an/c)+1;
            } else {
                an = an/c;
            }
            result += an;
        }

        
        
    }
    cout << result << '\n';

    return 0;
}